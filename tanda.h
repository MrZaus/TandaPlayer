#ifndef TANDA_H
#define TANDA_H

#include <cstdint>
#include <chrono>
#include <vector>
#include "track.h"

enum class TandaType {
    Tango,
    Vals,
    Milonga,
    Other
};


class Tanda {
    TandaType type;
    std::uint8_t count;
    std::chrono::seconds interspace;
    std::chrono::seconds totalTime;
    std::vector<Track> tracks;
};

#endif // TANDA_H
