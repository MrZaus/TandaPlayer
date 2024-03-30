#include "tanda.h"

#include <functional>
#include <utility>

Tanda::Tanda(TandaType type, std::uint8_t maxSize) : type(type), maxSize(maxSize)
{
}

std::chrono::seconds Tanda::getTotalTime() const
{
    std::unreachable(); // TODO implement
    return {};
}