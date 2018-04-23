#pragma once
#include <vector>

class Version {
    std::vector<int> Value;
    std::wstring View;

    // 1 if self > other, 0 if self = other, -1 if self < other 
    int Compare(const Version &other) const;

    void PushBuffer(std::wstring &buffer);

public:

    bool operator==(const Version &other) const;

    bool operator>(const Version &other) const;

    bool operator<(const Version &other) const;

    operator std::wstring() const;

    Version(const std::wstring_view &line);
};