#include <gtest/gtest.h>

#include "card.h"

class CardTest : public testing::Test{
	protected:
		void SetUp() override{
			card.setCardValue('2');
			card.setCardSuit('H');
			card.setCardRank();
		}

		void TearDown() override {}

		Card card;
};


TEST_F(CardTest, CardValueTest) {
    EXPECT_EQ('2', card.getCardValue());
}


TEST_F(CardTest, CardSuitTest) {
    EXPECT_EQ('H', card.getCardSuit());
}

TEST_F(CardTest, CardRankTest) {
    EXPECT_EQ(TWO, card.getCardRank());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
