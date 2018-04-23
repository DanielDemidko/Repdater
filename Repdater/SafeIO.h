#pragma once
#include <filesystem>
#include <vector>
#include "Cpp17Features.h"

namespace SafeIO 
{
    void DeleteFile(const std::filesystem::path &file);

    void CopyFile(const std::filesystem::path &oldPath, const std::filesystem::path &newPath);

    void MoveFile(const std::filesystem::path &oldPath, const std::filesystem::path &newPath);

    [[deprecated]]
    void WriteAllLines(const std::filesystem::path &textFile, const std::vector<std::wstring> &lines);
}
