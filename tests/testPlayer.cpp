#include <gtest/gtest.h>

#include "card.h"
#include "player.h"

class PlayerTestFixture : public testing::Test{
    protected:
        void SetUp() override{
            player.setName("Baibhav");

            Card card1;
            card1.setCardSuit('H');
            card1.setCardValue('2');
            card1.setCardRank();
            player.addCard(card1);

            Card card2;
            card2.setCardSuit('D');
            card2.setCardValue('3');
            card2.setCardRank();
            player.addCard(card2);

            Card card3;
            card3.setCardSuit('D');
            card3.setCardValue('4');
            card3.setCardRank();
            player.addCard(card3);

            Card card4;
            card4.setCardSuit('C');
            card4.setCardValue('4');
            card4.setCardRank();
            player.addCard(card4);

            Card card5;
            card5.setCardSuit('C');
            card5.setCardValue('5');
            card5.setCardRank();
            player.addCard(card5);

            player.findHand();

        }

        Player player;
};

TEST_F(PlayerTestFixture, PlayerHandRankTest){
    EXPECT_EQ(PAIR, player.getHandRank());
}

TEST_F(PlayerTestFixture, PlayerHandValueTest){
    EXPECT_EQ(FOUR, player.getHandValue());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
