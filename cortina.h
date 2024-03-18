#ifndef CORTINA_H
#define CORTINA_H

#include "track.h"
#include "playlistitem.h"

#include <chrono>
#include <string>

enum class CortinaMode
{
    RandomFromFolder,
    File
};

class Cortina: public PlaylistItem
{
    CortinaMode mode{CortinaMode::RandomFromFolder};
    std::string folderPath;
    Track track{};
    std::chrono::seconds totalTime{};
    std::chrono::seconds pauseBefore{1};
    std::chrono::seconds pauseAfter{1};
    bool fadeout{true};

public:
    Cortina() = default;
    ~Cortina() override = default;
};

#endif // CORTINA_H
