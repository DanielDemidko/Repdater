#pragma once
#include <string>
#include <tuple>

// TODO: перенести всё в App
namespace Filename {

    std::wstring_view::const_iterator Split(const std::wstring_view &line);

    std::tuple<std::wstring, std::wstring> NameVersion(const std::wstring_view &line);
}



