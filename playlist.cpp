#include "playlist.h"

#include <memory>

TandaDetails Playlist::geNextTandaDetails() const
{
    return pattern[index];
}

void Playlist::addNextCortina()
{
    items.push_back(std::make_unique<Cortina>());
}

void Playlist::addNextTanda()
{
    const auto [type, count] = geNextTandaDetails();
    items.push_back(std::make_unique<Tanda>(type, count));
    ++index;
    addNextCortina();
}
