#ifndef PLAYLISTITEM_H
#define PLAYLISTITEM_H

#include <chrono>

class PlaylistItem
{
public:
    [[nodiscard]] virtual std::chrono::seconds getTotalTime() const = 0;

    virtual ~PlaylistItem() = 0;
protected:
    PlaylistItem() = default;
    PlaylistItem(const PlaylistItem &) = default;
    PlaylistItem(PlaylistItem &&) = default;
    PlaylistItem &operator=(const PlaylistItem &) = default;
    PlaylistItem &operator=(PlaylistItem &&) = default;
};

inline PlaylistItem::~PlaylistItem() = default;
#endif // PLAYLISTITEM_H
