#include <gtest/gtest.h>

#include "../cortina.h"
#include "../playlist.h"

TEST(CircularIndexTest, RestartsFromZeroWhenIndexIsEqualToContainerSize)
{
    const auto c = std::vector{1, 2, 3};
    CircularIndex i(c);
    ASSERT_EQ(++i, 1);
    ASSERT_EQ(++i, 2);
    ASSERT_EQ(++i, 0);
    ASSERT_EQ(i++, 0);
    EXPECT_EQ(i, 1);
}

TEST(PlaylistTests, ContainsTangoTandaAndCortinaWhenAddNextTanda)
{
    auto p = Playlist();

    p.addNextTanda();
    const auto *item = dynamic_cast<const Tanda *>(p.getItem(0));
    ASSERT_NE(item, nullptr);
    EXPECT_EQ(item->type, TandaType::Tango);
    EXPECT_EQ(item->getSize(), 4);
    EXPECT_EQ(p.size(), 2);
    EXPECT_NE(dynamic_cast<const Cortina *>(p.getItem(1)), nullptr);
}

TEST(PlaylistTests, FollowsPatternWhenSequentiallyAddNextTanda)
{

    auto p = Playlist();

    p.addNextTanda(); // T
    p.addNextTanda(); // T
    p.addNextTanda(); // M
    p.addNextTanda(); // T
    p.addNextTanda(); // T
    p.addNextTanda(); // V
    p.addNextTanda(); // T again

    ASSERT_EQ(p.size(), 14);

    constexpr auto TangosTandaSize = 4u;
    constexpr auto MilongaTandaSize = 3u;
    constexpr auto ValsTandaSize = 3u;

    auto index = 0u;
    const auto *item = dynamic_cast<const Tanda *>(p.getItem(index));
    ASSERT_NE(item, nullptr);
    EXPECT_EQ(item->type, TandaType::Tango);
    EXPECT_EQ(item->getSize(), TangosTandaSize);

    index += 2;
    item = dynamic_cast<const Tanda *>(p.getItem(index));
    ASSERT_NE(item, nullptr);
    EXPECT_EQ(item->type, TandaType::Tango);
    EXPECT_EQ(item->getSize(), TangosTandaSize);

    index += 2;
    item = dynamic_cast<const Tanda *>(p.getItem(index));
    ASSERT_NE(item, nullptr);
    EXPECT_EQ(item->type, TandaType::Milonga);
    EXPECT_EQ(item->getSize(), MilongaTandaSize);

    index += 2;
    item = dynamic_cast<const Tanda *>(p.getItem(index));
    ASSERT_NE(item, nullptr);
    EXPECT_EQ(item->type, TandaType::Tango);
    EXPECT_EQ(item->getSize(), TangosTandaSize);

    index += 2;
    item = dynamic_cast<const Tanda *>(p.getItem(index));
    ASSERT_NE(item, nullptr);
    EXPECT_EQ(item->type, TandaType::Tango);
    EXPECT_EQ(item->getSize(), TangosTandaSize);

    index += 2;
    item = dynamic_cast<const Tanda *>(p.getItem(index));
    ASSERT_NE(item, nullptr);
    EXPECT_EQ(item->type, TandaType::Vals);
    EXPECT_EQ(item->getSize(), ValsTandaSize);

    index += 2;
    item = dynamic_cast<const Tanda *>(p.getItem(index));
    ASSERT_NE(item, nullptr);
    EXPECT_EQ(item->type, TandaType::Tango);
    EXPECT_EQ(item->getSize(), TangosTandaSize);
}
