#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "cortina.h"
#include "playlistitem.h"
#include "tanda.h"

#include <cstdint>
#include <variant>

class Playlist
{
    std::vector<std::pair<TandaType, std::uint8_t>> pattern;
    std::vector<std::unique_ptr<PlaylistItem>> items;

public:
    Playlist();
};

#endif // PLAYLIST_H
