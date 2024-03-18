#ifndef PLAYLISTITEM_H
#define PLAYLISTITEM_H

#include <chrono>

class PlaylistItem
{
public:
    [[nodiscard]] virtual std::chrono::seconds getTotalTime() const = 0;

    virtual ~PlaylistItem() = 0;
};

inline PlaylistItem::~PlaylistItem() = default;
#endif // PLAYLISTITEM_H
