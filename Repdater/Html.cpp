#include "Html.h"
#include <fstream>
#include <iterator>
#include "Text.h"


#include <iostream>
#include "App.h"
#include "Repository.h"

bool Html::IsHrefAttribute(const std::wstring &line)
{
    const static std::wstring href = L"href";
    return line.find(href) == 0;
}

std::vector<std::wstring> Html::ParseAppLinks(const std::filesystem::path &path) {
//    std::wifstream fileStream(path);
//    const std::istream_iterator<std::wstring, wchar_t> begin(fileStream), end;
//    for (auto i = begin; i != end; ++i) {
//        if (!IsHrefAttribute(*i)) continue;
//        const auto quotedText = Text::GetQuoted(*i);
//        if (!App::IsAppFile(quotedText)) continue;
//
//        const auto appName = App::GetAppName(quotedText);
//        const auto oldVersions = Repository::GetOldVersions(appName);
//        for (auto i : oldVersions) std::wcout << i << std::endl;
//    }
//
    return{};
}
