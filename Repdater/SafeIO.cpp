#include "SafeIO.h"
#include <iostream>
#include <fstream>
#include <iterator>

void SafeIO::DeleteFile(const std::filesystem::path &file) {
    std::wcout << L"������� ���� '" << file << "'" << std::endl;
    try {
        std::filesystem::remove(file);
    }
    catch (...) {
        std::wcout << L"���� ���� ������� �� �������!" << std::endl;
    }
}

void SafeIO::CopyFile(const std::filesystem::path &oldPath, const std::filesystem::path &newPath) {
    std::wcout << L"�������� ���� '" << oldPath<< L"' -> '"<< newPath << L"'" << std::endl;
    try {
        std::filesystem::copy_file(oldPath, newPath);
    }
    catch (...) {
        std::wcout << L"�� ������� ����������� ���� '" << oldPath << "'" << std::endl;
    }
}

void SafeIO::MoveFile(const std::filesystem::path & oldPath, const std::filesystem::path & newPath)
{
    std::wcout << L"���������� ���� '" << oldPath << L"' -> '" << newPath << L"':\n  ";
    CopyFile(oldPath, newPath);
    std::wcout << "  ";
    DeleteFile(oldPath);
}

void SafeIO::WriteAllLines(const std::filesystem::path &textFile, const std::vector<std::wstring>& lines)
{
    std::wofstream text(textFile);
    std::unique_copy(
        lines.cbegin(),
        lines.cend(),
        std::ostream_iterator<std::wstring, wchar_t>(text, L"\n"));
}
