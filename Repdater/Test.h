#pragma once
#include <iostream>
#include <iterator>

namespace Test {
    template <typename T> void ConsoleFunc(T (&func)(const std::wstring&)) {
        while (std::wcout << func(*std::istream_iterator<std::wstring, wchar_t>(std::wcin)) << std::endl);
    }
}