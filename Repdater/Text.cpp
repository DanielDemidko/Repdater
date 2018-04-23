#include "Text.h"
#include <algorithm>
#include <locale>

std::wstring Text::GetQuoted(const std::wstring_view &line) {
    if (const auto first = line.find(L'"'), sec = line.find(L'"', first + 1); (first != -1) && (sec != -1)) {
        const auto cbeg = line.cbegin();
        return { cbeg + first + 1, cbeg + sec };
    }
    return {};
}

std::wstring Text::GetDigits(const std::wstring_view &line) {
    std::wstring result;
    std::copy_if(line.cbegin(), line.cend(), std::back_inserter(result), [loc = std::locale("")](const auto i) {
        return std::isdigit(i, loc);
    });
    return result;
}

std::wstring Text::CleanName(const std::wstring_view &line) {
    return { line.cbegin(), std::find_if(line.crbegin(), line.crend(),[loc = std::locale("")](const auto i) {
        return std::isalpha(i, loc);
    }).base() };
}
