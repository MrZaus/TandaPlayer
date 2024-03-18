#ifndef PLAYLISTITEM_H
#define PLAYLISTITEM_H

class PlaylistItem
{
public:
    virtual ~PlaylistItem() = 0;
};
inline PlaylistItem::~PlaylistItem() = default;
#endif // PLAYLISTITEM_H
