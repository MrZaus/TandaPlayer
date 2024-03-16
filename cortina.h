#ifndef CORTINA_H
#define CORTINA_H

#include "track.h"
#include <chrono>
#include <string>

enum class CortinaMode
{
    RandomFromFolder,
    File
};

class Cortina
{
    CortinaMode mode{CortinaMode::RandomFromFolder};
    std::string folderPath;
    Track track{};
    std::chrono::seconds totalTime{};
    std::chrono::seconds pauseBefore{1};
    std::chrono::seconds pauseAfter{1};
    bool fadeout{true};

public:
    Cortina();
};

#endif // CORTINA_H
