#include "Filename.h"
#include <locale>
#include <algorithm>

std::wstring_view::const_iterator Filename::Split(const std::wstring_view &line) {
    return std::find_if(line.cbegin(), line.cend(), [loc = std::locale("")](const auto i) {
        return std::isdigit(i, loc);
    });
}

std::tuple<std::wstring, std::wstring> Filename::NameVersion(const std::wstring_view & line) {
    const auto split = Split(line);
    return { { line.cbegin(), split }, { split, line.cend() } };
}
