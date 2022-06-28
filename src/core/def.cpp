
#include "def.h"


void _LogManager::log(const String& info)
{
    ::puts(info.data());
}

void _LogManager::warning(const String& info)
{
    ::puts(info.data());
}

void _LogManager::error(const String& info)
{
    ::puts(info.data());
}
