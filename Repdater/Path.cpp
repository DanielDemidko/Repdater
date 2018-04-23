#include "Path.h"
#include <fstream>
#include <iostream>

const std::filesystem::path ConfigPath = "repository_config.ini";

bool Path::HasRepositoryPath() {
    return std::filesystem::exists(ConfigPath);
}

std::filesystem::path Path::ReadRepositoryPath() {
    std::wcout << L"Введите папку репозитория: ";
    std::filesystem::path repPath;
    std::wcin >> repPath;
    return repPath;
}

void Path::SetRepositoryPath(const std::filesystem::path &repPath) {
    try {
        std::wofstream(ConfigPath) << repPath;
    }
    catch (...) {
        std::wcerr <<
            L"Не удалось сохранить настройки нового пути для репозитория.\n"
            L"Возможно у приложения недостаточно прав."
            << std::endl;
    }
}

std::filesystem::path Path::SetRepositoryPathFromConsole() {
    const auto path = ReadRepositoryPath();
    SetRepositoryPath(path);
    return path;
}

std::filesystem::path Path::GetRepositoryPath() {
    if (!HasRepositoryPath()) return SetRepositoryPathFromConsole();
    std::wstring line;
    std::wifstream(ConfigPath) >> line;
    return line;
}

std::filesystem::path Path::GetDownloadsPath() {
    return std::filesystem::path(_wgetenv(L"USERPROFILE")).append("Downloads");
}

