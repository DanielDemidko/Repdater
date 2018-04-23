#pragma once
#include <filesystem>
#include "Cpp17Features.h"

namespace Web {

    void Download(const std::wstring &link, const std::filesystem::path &filename);
}
