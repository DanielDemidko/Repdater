#include "Encoding.h"
#include <locale>

void Encoding::SetUnicode()
{
    std::locale::global(std::locale(""));
}
