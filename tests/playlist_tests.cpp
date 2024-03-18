#include <gtest/gtest.h>

#include "../playlist.h"

#include <cassert>
#include <print>
#include <ranges>
#include <vector>

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
    EXPECT_EQ(item->maxSize, 4);
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

    const auto *item = dynamic_cast<const Tanda *>(p.getItem(0));
    ASSERT_NE(item, nullptr);
    EXPECT_EQ(item->type, TandaType::Tango);
    EXPECT_EQ(item->maxSize, 4);

    item = dynamic_cast<const Tanda *>(p.getItem(2));
    ASSERT_NE(item, nullptr);
    EXPECT_EQ(item->type, TandaType::Tango);
    EXPECT_EQ(item->maxSize, 4);

    item = dynamic_cast<const Tanda *>(p.getItem(4));
    ASSERT_NE(item, nullptr);
    EXPECT_EQ(item->type, TandaType::Milonga);
    EXPECT_EQ(item->maxSize, 3);

    item = dynamic_cast<const Tanda *>(p.getItem(6));
    ASSERT_NE(item, nullptr);
    EXPECT_EQ(item->type, TandaType::Tango);
    EXPECT_EQ(item->maxSize, 4);

    item = dynamic_cast<const Tanda *>(p.getItem(8));
    ASSERT_NE(item, nullptr);
    EXPECT_EQ(item->type, TandaType::Tango);
    EXPECT_EQ(item->maxSize, 4);

    item = dynamic_cast<const Tanda *>(p.getItem(10));
    ASSERT_NE(item, nullptr);
    EXPECT_EQ(item->type, TandaType::Vals);
    EXPECT_EQ(item->maxSize, 3);

    item = dynamic_cast<const Tanda *>(p.getItem(12));
    ASSERT_NE(item, nullptr);
    EXPECT_EQ(item->type, TandaType::Tango);
    EXPECT_EQ(item->maxSize, 4);
}
