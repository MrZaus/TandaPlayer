#ifndef TANDA_H
#define TANDA_H

#include "playlistitem.h"
#include "track.h"

#include <chrono>
#include <cstdint>
#include <string>
#include <vector>

enum class TandaType
{
    Tango,
    Vals,
    Milonga,
    Other
};
std::string tandaTypeToString(TandaType type);
class Tanda : public PlaylistItem
{
public:
    Tanda(TandaType type, std::uint8_t maxSize = 4);
    ~Tanda() override = default;
    Tanda() = default;
    Tanda(const Tanda &) = default;
    Tanda(Tanda &&) noexcept = default;
    // since type is const as we don't want to change it due to strictly  following the playlist pattern, we don't want to allow it to be copied nor assigned
    Tanda &operator=(const Tanda &) = delete;
    Tanda &operator=(Tanda &&) = delete;

    const TandaType type{TandaType::Tango};

    // PlaylistItem
    [[nodiscard]] std::chrono::seconds getTotalTime() const override;
    [[nodiscard]] std::string getTypeName() const override;
    [[nodiscard]] std::vector<std::string> getItems() const override;
    [[nodiscard]] std::size_t getSize() const override;

private:
    std::uint8_t maxSize{4};
    std::chrono::seconds interspace{1};
    std::chrono::seconds totalTime{};
    std::vector<Track> tracks;
};
#endif // TANDA_H
