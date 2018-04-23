#include "Repository.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iterator>
#include "Path.h"
#include "App.h"
#include "SafeIO.h"

bool Repository::IsOldVersion(const std::wstring &appName, const std::filesystem::path &file) {
    return App::IsAppFile(file) && App::GetAppName(file) == appName;
}

void Repository::DeleteOldVersions(const std::wstring &appName) {
    std::wcout << L"Удаляем старые версии программы '" << appName << "'" << std::endl;
    const std::filesystem::recursive_directory_iterator begin(Path::GetRepositoryPath()), end;
    for (auto i = begin; i != end; ++i)
        if (IsOldVersion(appName, *i))
            SafeIO::DeleteFile(*i);
}

std::vector<std::filesystem::path> Repository::GetOldVersions(const std::wstring &appName) {
    std::wcout << L"Ищем старые версии программы '" << appName << "'" << std::endl;
    std::vector<std::filesystem::path> result;
    const std::filesystem::recursive_directory_iterator begin(Path::GetRepositoryPath()), end;
    std::copy_if(begin, end, std::back_inserter(result), [&appName](const auto &i) {
        return IsOldVersion(appName, i);
    });
    return result;
}

void Repository::Append(const std::filesystem::path &app) {
    std::wcout << L"Перемещаем новую версию программы в репозиторий" << std::endl;
    SafeIO::MoveFile(app, Path::GetRepositoryPath().append(app.filename()));
}

void Repository::SetUpdateFile(const std::filesystem::path &newVersion) {
    std::wcout << L"Найдена новая программа '" << newVersion.filename() << "'" << std::endl;
    DeleteOldVersions(App::GetAppName(newVersion));

    Append(newVersion);
    std::wcout << std::endl;
}

void Repository::UpdateAllFromDownloads() {
    const auto downloads = Path::GetDownloadsPath();
    std::wcout << L"Сканируем папку загрузок '" << downloads << "'\n" << std::endl;
    const std::filesystem::recursive_directory_iterator end;
    for (auto i = std::filesystem::recursive_directory_iterator(downloads); i != end; ++i)
        if (App::IsAppFile(*i))
            SetUpdateFile(*i);
    std::wcout << L"Сканирование успешно завершено!" << std::endl;
    std::wcin.get();
}

std::vector<std::filesystem::path> Repository::GetRepositoryFiles() {
    const std::filesystem::directory_iterator begin(Path::GetRepositoryPath()), end;
    return std::vector<std::filesystem::path>(begin, end);
}

#include <functional>
std::vector<std::filesystem::path> CheckRepository(const std::function<bool(const std::filesystem::path&)> &func) {
    std::vector<std::filesystem::path> result;
    const std::filesystem::directory_iterator begin(Path::GetRepositoryPath()), end;
    std::copy_if(begin, end, std::back_inserter(result), func);
    return result;
}

bool IsUpdateFor(const std::wstring_view &name, const Version &version, const std::filesystem::path &path) {
    const auto[otherName, otherVersion] = App::NameVersion(path);
    return name == otherName && version > otherVersion;
}



bool Repository::IsUpdate(const std::filesystem::path &file)
{
    const auto[name, version] = App::NameVersion(file);
    auto reslut = CheckRepository([&name, &version](const std::filesystem::path &i) {
        const auto[otherName, otherVersion] = App::NameVersion(i);
        return otherName == name && otherVersion < version;
    });
}
