#ifndef PLAYLISTITEM_H
#define PLAYLISTITEM_H

#include <chrono>
#include <string>

class PlaylistItem
{
public:
    [[nodiscard]] virtual std::chrono::seconds getTotalTime() const = 0;
    [[nodiscard]] virtual std::string getTypeName() const = 0;

    [[nodiscard]] virtual std::vector<std::string> getItems() const { return {}; }
    [[nodiscard]] virtual std::size_t getSize() const { return 1; }

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
