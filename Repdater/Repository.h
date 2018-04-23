#pragma once
#include <filesystem>
#include "Cpp17Features.h"

namespace Repository
{
    bool IsOldVersion(const std::wstring &appName, const std::filesystem::path &file);

    void DeleteOldVersions(const std::wstring &appName);

    std::vector<std::filesystem::path> GetOldVersions(const std::wstring &appName);

    void Append(const std::filesystem::path &app);

    void SetUpdateFile(const std::filesystem::path &newVersion);

    void UpdateAllFromDownloads();

    [[deprecated]]
    std::vector<std::filesystem::path> GetRepositoryFiles();


    bool IsUpdate(const std::filesystem::path &file);
}
