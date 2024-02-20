#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "card.h"

typedef enum HandRank{
	HIGH_CARD,
	PAIR,
	TWO_PAIRS,
	THREE_OF_A_KIND,
	STRAIGHT,
	FLUSH,
	FULL_HOUSE,
	FOUR_OF_A_KIND,
	STRAIGHT_FLUSH
}HandRank;

class Player{
	private:
		std::string name;
		std::vector<Card> cards;
		HandRank handRank;
		CardRank handValue;

        CardRank isStraightFlush();
        CardRank isFourOfAKind();
        CardRank isFullHouse();
        CardRank isFlush();
        CardRank isStraight();
        CardRank isThreeOfAKind();
        CardRank isTwoPairs();
        CardRank isPair();

	public:
		/********************************************************************
		 * @brief Constructor to instantiate Hand instance 
		*********************************************************************/
		Player();


		/********************************************************************
		 * @brief Sets player name 
		 * 
		 * @param[in] name Player's name
		*********************************************************************/
		void setName(const std::string &name);


		/********************************************************************
		 * @brief Fetches Player's Name
		 * 
		 * @return Player's Name
		*********************************************************************/
		std::string getName();

		/********************************************************************
		 * @brief Adds card
		 * 
		 * @param[in] card Card received from the dealer
		*********************************************************************/
		void addCard(Card card);

		/********************************************************************
		 * @brief Sets Hand Rank
		 * 
		 * @param[in] handRank Rank of the player's hand
		*********************************************************************/
		void setHandRank(HandRank handRank);


		/********************************************************************
		 * @brief Fetches Hand Rank
		 * 
		 * @return Rank of the hand
		*********************************************************************/
		HandRank getHandRank();


		/*********************************************************************
		 * @brief Sets hand value
		 * 
		 * @param[in] handValue Hand's value represented by the card with
		 * the highest rank
		*********************************************************************/
		void setHandValue(CardRank handValue);


		/********************************************************************
		 * @brief Fetches hand value
		 * 
		 * @return Hand's value represented by the card with
		 * the highest rank
		*********************************************************************/
		CardRank getHandValue();


        void findHand();


};

#endif
