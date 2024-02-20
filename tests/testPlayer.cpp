#include <gtest/gtest.h>

#include "player.h"

class PlayerTestFixture : public testing::Test{
    protected:
        void SetUp() override{
            player.setName("Baibhav");
            player.setHandRank(STRAIGHT_FLUSH);
            player.setHandValue(EIGHT);
        }

        Player player;
};

TEST_F(PlayerTestFixture, PlayerHandRankTest){
    EXPECT_EQ(STRAIGHT_FLUSH, player.getHandRank());
}

TEST_F(PlayerTestFixture, PlayerHandValueTest){
    EXPECT_EQ(EIGHT, player.getHandValue());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
