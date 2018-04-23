#include "Web.h"
#include <urlmon.h>

void Web::Download(const std::wstring&link, const std::filesystem::path &filename) {
    URLDownloadToFile(0, link.c_str(), filename.c_str(), 0, 0);
}