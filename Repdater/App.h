#pragma once
#include <filesystem>
#include <tuple>
#include "Cpp17Features.h"
#include "Version.h"

namespace App {

    bool IsApp(const std::wstring_view &name);

    bool IsApp(const std::filesystem::path &path);

    std::tuple<std::wstring, Version> NameVersion(const std::wstring_view &filename);

    std::tuple<std::wstring, Version> NameVersion(const std::filesystem::path &path);
}