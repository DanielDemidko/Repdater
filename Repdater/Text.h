#pragma once
#include <string>

namespace Text {

    std::wstring GetQuoted(const std::wstring_view &line);

    std::wstring GetDigits(const std::wstring_view &line);

    std::wstring CleanName(const std::wstring_view &line);
}