#include <iostream>
#include "Repository.h"
#include "App.h"


int main() {
    std::locale::global(std::locale(""));
    for (auto &&i : Repository::GetRepositoryFiles()) {
        const auto[name, version] = App::NameVersion(i);
        std::wcout << i << " -> " << name << ": " << std::wstring(version) << std::endl;
    }
}

