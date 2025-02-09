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

[[nodiscard]] std::string Tanda::getTypeName() const  { return tandaTypeToString(type); }

[[nodiscard]] std::vector<std::string> Tanda::getItems() const
{
    std::unreachable(); // TODO implement
    return {};
}

[[nodiscard]] std::size_t Tanda::getSize() const
{
    return maxSize;
}

[[nodiscard]]
std::chrono::seconds Tanda::getTotalTime() const
{
    std::unreachable(); // TODO implement
    return {};
}