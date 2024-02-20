#include "player.h"

Player::Player(){
	// Sets default attribute values
	this->handRank = HIGH_CARD;
	this->handValue = ZERO;
}

void Player::setName(const std::string &name){
	this->name = name;
}

std::string Player::getName(){
	return this->name;
}

void Player::addCard(Card card){
	this->cards.push_back(card);
}

void Player::setHandRank(HandRank handRank){
	this->handRank = handRank;
}

HandRank Player::getHandRank(){
	return this->handRank;
}

void Player::setHandValue(CardRank handValue){
	this->handValue = handValue;
}

CardRank Player::getHandValue(){
	return this->handValue;
}
