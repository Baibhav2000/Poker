#include "card.h"

void Card::setCardValue(char cardValue){
	this->cardValue = cardValue;
}

char Card::getCardValue(){
	return this->cardValue;
}

void Card::setCardSuit(char cardSuit){
	this->cardSuit = cardSuit;
}

char Card::getCardSuit(){
	return this->cardSuit;
}

void Card::setCardRank(){

	switch(this->cardValue){

		case '2':
			this->cardRank = TWO;
			break;
		
		case '3':
			this->cardRank = THREE;
			break;
		
		case '4':
			this->cardRank = FOUR;
			break;
		
		case '5':
			this->cardRank = FIVE;
			break;

		case '6':
			this->cardRank = SIX;
			break;

		case '7':
			this->cardRank = SEVEN;
			break;

		case '8':
			this->cardRank = EIGHT;
			break;

		case '9':
			this->cardRank = NINE;
			break;

		case 'T':
			this->cardRank = TEN;
			break;

		case 'J':
			this->cardRank = JACK;
			break;

		case 'Q':
			this->cardRank = QUEEN;
			break;

		case 'K':
			this->cardRank = KING;
			break;

		case 'A':
			this->cardRank = ACE;
			break;
		
        default:
            this->cardRank = ZERO;
	}
}

CardRank Card::getCardRank(){
	return this->cardRank;
}
