#include "Version.h"
#include <algorithm>
#include <locale>

int Version::Compare(const Version & other) const {
    const int to = std::min(Value.size(), other.Value.size());
    for (int i = 0; i < to; ++i) {
        if (Value[i] > other.Value[i]) return 1;
        if (Value[i] < other.Value[i]) return -1;
    }
    return Value.size() > other.Value.size() ? 1 : Value.size() < other.Value.size() ? -1 : 0;
}

bool Version::operator==(const Version &other) const {
    return Compare(other) == 0;
}

bool Version::operator>(const Version &other) const {
    return Compare(other) == 1;
}

bool Version::operator<(const Version &other) const {
    return Compare(other) == -1;
}

Version::operator std::wstring() const {
    return View;
}

void Version::PushBuffer(std::wstring & buffer) {
    if (!buffer.empty()) {
        Value.push_back(std::stoi(buffer));
        View.append(buffer);
        View.push_back(L'.');
        buffer.clear();
    }
}

inline Version::Version(const std::wstring_view &line) {
    std::wstring buffer;
    const std::locale unicode("");
    for (const auto &i : line) {
        if (std::isdigit(i, unicode)) {
            buffer.push_back(i);
            continue;
        }
        PushBuffer(buffer);
    }
    PushBuffer(buffer);
    View.erase(View.size() - 1);
}
