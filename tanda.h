#ifndef TANDA_H
#define TANDA_H

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

class Tanda
{
    TandaType type{TandaType::Tango};
    std::uint8_t count{4};
    std::chrono::seconds interspace{1};
    std::chrono::seconds totalTime{};
    std::vector<Track> tracks;
};

#endif // TANDA_H
