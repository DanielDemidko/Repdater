#pragma once
#include <filesystem>
#include "Cpp17Features.h"

namespace Path
{
    bool HasRepositoryPath();

    std::filesystem::path ReadRepositoryPath();

    void SetRepositoryPath(const std::filesystem::path&);

    std::filesystem::path SetRepositoryPathFromConsole();

    std::filesystem::path GetRepositoryPath();

    std::filesystem::path GetDownloadsPath();
}
