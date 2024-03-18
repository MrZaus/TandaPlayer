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

class Cortina : public PlaylistItem
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
    Cortina(const Cortina &) = default;
    Cortina &operator=(const Cortina &) = default;
    Cortina(Cortina &&) noexcept = default;
    Cortina &operator=(Cortina &&) noexcept = default;

    // PlaylistItem
    [[nodiscard]] std::chrono::seconds getTotalTime() const override;
};
#endif // CORTINA_H