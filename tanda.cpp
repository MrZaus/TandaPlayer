#include "tanda.h"

#include <functional>
#include <utility>

std::string tandaTypeToString(TandaType type)
{
    switch (type)
    {
    case TandaType::Tango:
        return "Tango";
    case TandaType::Vals:
        return "Vals";
    case TandaType::Milonga:
        return "Milonga";
    case TandaType::Other:
        return "Other";
    }
}

Tanda::Tanda(TandaType type, std::uint8_t maxSize) : type(type), maxSize(maxSize)
{
}

std::chrono::seconds Tanda::getTotalTime() const
{
    std::unreachable(); // TODO implement
    return {};
}