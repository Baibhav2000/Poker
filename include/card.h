#ifndef CARD_H
#define CARD_H

typedef enum CardRank{
	ZERO,
    TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING,
	ACE
}CardRank;

class Card{
	private:
		char cardValue;
		char cardSuit;
		CardRank cardRank;

	public:
		/*******************************************************
		 * @brief Sets Card Salue
		 * 
		 * @param[in] cardValue 
		********************************************************/
		void setCardValue(char cardValue);


		/*******************************************************
		 * @brief Fetches Card Value
		 * 
		 * @return Card Value
		********************************************************/
		char getCardValue() const;


		/*******************************************************
		 * @brief Sets Card Suit
		 * 
		 * @param[in] cardSuit
		********************************************************/
		void setCardSuit(char cardSuit);


		/*******************************************************
		 * @brief Fetches Card Suit
		 * 
		 * @return Card Suit
		********************************************************/
		char getCardSuit() const;


		/*******************************************************
		 * @brief Sets Card Rank
		********************************************************/
		void setCardRank();


		/********************************************************
		 * @brief Fetches Card Rank
		*********************************************************/
		CardRank getCardRank() const;
};

#endif