#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "cortina.h"
#include "playlistitem.h"
#include "tanda.h"

#include <concepts>
#include <cstdint>
#include <type_traits>
#include <variant>

using TandaSize = std::uint8_t;
using TandaDetails = std::pair<TandaType, TandaSize>;

template <typename T>
class CircularIndex
{
    T::size_type index{};
    const T &container;

public:
    CircularIndex(const T &container) : container(container){};
    operator typename T::size_type() const { return index; }
    CircularIndex &operator++()
    {
        index = ++index % container.size();
        return *this;
    }

    CircularIndex operator++(int)
    {
        CircularIndex old = *this;
        operator++();
        return old;
    }
};

using PatternIndex = CircularIndex<std::vector<TandaDetails>>;
namespace DefaultTandaSize
{
    constexpr TandaSize Tango = 4;
    constexpr TandaSize Vals = 3;
    constexpr TandaSize Milonga = 3;
}

class Playlist
{
    std::vector<TandaDetails> pattern = {{TandaType::Tango, DefaultTandaSize::Tango}, {TandaType::Tango, DefaultTandaSize::Tango}, {TandaType::Milonga, DefaultTandaSize::Milonga}, {TandaType::Tango, DefaultTandaSize::Tango}, {TandaType::Tango, DefaultTandaSize::Tango}, {TandaType::Vals, DefaultTandaSize::Vals}};

    PatternIndex index{pattern};
    std::vector<std::unique_ptr<PlaylistItem>> items;
    TandaDetails geNextTandaDetails() const;

public:
    Playlist() = default;
    ~Playlist() = default;
    void addNextCortina();
    void addNextTanda();
    std::size_t size() const { return items.size(); }
    const PlaylistItem *getItem(std::size_t i) const { return items[i].get(); }
};

#endif // PLAYLIST_H
