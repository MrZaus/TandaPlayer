#ifndef TANDA_H
#define TANDA_H

#include "playlistitem.h"
#include "track.h"

#include <chrono>
#include <cstdint>
#include <vector>

enum class TandaType
{
    Tango,
    Vals,
    Milonga,
    Other
};

class Tanda : public PlaylistItem
{
public:
    Tanda(TandaType type, std::uint8_t maxSize = 4);
    ~Tanda() override = default;
    const TandaType type{TandaType::Tango};
    std::uint8_t maxSize{4};

private:
    std::chrono::seconds interspace{1};
    std::chrono::seconds totalTime{};
    std::vector<Track> tracks;
};
#endif // TANDA_H
