#include "App.h"
#include "Filename.h"
#include "Text.h"

bool App::IsApp(const std::wstring_view &name) {
    const static std::vector<std::wstring> appExtensions{
        L".exe", L".rar", L".zip", L".apk", L".7z", L".msi", L".jar", L".json"
    };
    return std::any_of(appExtensions.cbegin(), appExtensions.cend(), [&name](const auto &i) {
        const auto rfind = name.rfind(i);
        return rfind != -1 && rfind == name.size() - i.size();
    });
}

bool App::IsApp(const std::filesystem::path &path) {
    return IsApp(std::wstring_view(std::wstring(path.extension()))) && std::filesystem::is_regular_file(path);
}

std::tuple<std::wstring, Version> App::NameVersion(const std::wstring_view &filename) {
    const auto split = std::find_if(filename.cbegin(), filename.cend(), [loc = std::locale("")](const auto i) {
        return std::isdigit(i, loc);
    });
    return { Text::CleanName(std::wstring(filename.cbegin(), split)), Version(std::wstring(split, filename.cend())) };
}

std::tuple<std::wstring, Version> App::NameVersion(const std::filesystem::path & path) {
    return NameVersion(std::wstring_view(std::wstring(path.stem())));
}
