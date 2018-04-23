#pragma once
#include <vector>
#include <filesystem>
#include "Cpp17Features.h"

namespace Html 
{
    bool IsHrefAttribute(const std::wstring &line);

    std::vector<std::wstring> ParseAppLinks(const std::filesystem::path&);
}