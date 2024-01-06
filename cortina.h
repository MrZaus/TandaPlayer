#ifndef CORTINA_H
#define CORTINA_H

#include <string>
#include <chrono>
#include "track.h"

enum class CortinaMode {
    RandomFromFolder,
    File
};

class Cortina
{
    CortinaMode mode;
    std::string folderPath;
    Track track;
    std::chrono::seconds totalTime;
    std::chrono::seconds pauseBefore;
    std::chrono::seconds pauseAfter;
    bool fadeout;

public:
    Cortina();
};

#endif // CORTINA_H
