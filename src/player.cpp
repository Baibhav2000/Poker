#include <algorithm>
#include <map>
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

CardRank Player::isStraightFlush() {
    // Sort the cards in the player's hand by rank
    std::sort(cards.begin(), cards.end(), [](const Card &a, const Card &b) {
        return a.getCardRank() > b.getCardRank();
    });

    // Check if all cards have the same suit
    char suit = cards[0].getCardSuit();
    for (const Card& card : cards) {
        if (card.getCardSuit() != suit) {
            return ZERO; // Not a straight flush, return ZERO
        }
    }

    // Check if the cards form a straight
    for (int i = 1; i < cards.size(); ++i) {
        if (cards[i].getCardRank() != cards[i - 1].getCardRank() - 1) {
            return ZERO; // Not a straight flush, return ZERO
        }
    }

    // Return the rank of the highest-ranking card of the straight flush
    return cards[0].getCardRank();
}

CardRank Player::isFourOfAKind() {
    // Count the frequency of each rank
    std::map<CardRank, int> rankCount;
    for (const Card& card : cards) {
        rankCount[card.getCardRank()]++;
    }

    // Check if any rank has four cards
    for (const auto& pair : rankCount) {
        if (pair.second == 4) {
            return pair.first; // Return the rank of the four cards
        }
    }

    return ZERO; // Four of a kind not found, return ZERO
}

CardRank Player::isFullHouse() {
    // Count the frequency of each rank
    std::map<CardRank, int> rankCount;
    for (const Card& card : cards) {
        rankCount[card.getCardRank()]++;
    }

    CardRank tripletRank = ZERO;
    CardRank pairRank = ZERO;

    // Check if any rank has three cards or two cards
    for (const auto& pair : rankCount) {
        if (pair.second == 3) {
            tripletRank = pair.first; // Found the triplet
        } else if (pair.second == 2) {
            pairRank = pair.first; // Found the pair
        }
    }

    // Return the rank of the triplet forming the full house
    return tripletRank;
}

CardRank Player::isFlush(){
	// Check if all cards have the same suit
    char suit = cards[0].getCardSuit();
    for (const Card& card : cards) {
        if (card.getCardSuit() != suit) {
            return ZERO; // Not a straight flush, return ZERO
        }
    }

	return cards[0].getCardRank();
}

CardRank Player::isStraight(){
	// Check if the cards form a straight
    for (int i = 1; i < cards.size(); ++i) {
        if (cards[i].getCardRank() != cards[i - 1].getCardRank() - 1) {
            return ZERO; // Not a straight flush, return ZERO
        }
    }

    // Return the rank of the highest-ranking card of the straight flush
    return cards[0].getCardRank();
}

CardRank Player::isThreeOfAKind() {
    // Count the frequency of each rank
    std::map<CardRank, int> rankCount;
    for (const Card& card : cards) {
        rankCount[card.getCardRank()]++;
    }

    CardRank tripletRank = ZERO;

    // Check if any rank has three cards
    for (const auto& pair : rankCount) {
        if (pair.second == 3) {
            tripletRank = pair.first; // Found the triplet
            break; // No need to continue checking
        }
    }

    // Return the rank of the triplet forming the three of a kind
    return tripletRank;
}

CardRank Player::isTwoPairs() {
    // Count the frequency of each rank
    std::map<CardRank, int> rankCount;
    for (const Card& card : cards) {
        rankCount[card.getCardRank()]++;
    }

    CardRank higherPairRank = ZERO;
    int pairCount = 0;

    // Check if any rank has two cards
    for (const auto& pair : rankCount) {
        if (pair.second == 2) {
            higherPairRank = std::max(higherPairRank, pair.first); // Update the higher pair
            pairCount++;
        }
    }

    // Return the rank of the higher pair
    return (pairCount == 2) ? higherPairRank : ZERO;
}

CardRank Player::isPair() {
    // Count the frequency of each rank
    std::map<CardRank, int> rankCount;
    for (const Card& card : cards) {
        rankCount[card.getCardRank()]++;
    }

    CardRank pairRank = ZERO;

    // Check if any rank has two cards
    for (const auto& pair : rankCount) {
        if (pair.second == 2) {
            pairRank = pair.first; // Found the pair
            break;
        }
    }

    // Return the rank of the pair
    return pairRank;
}

void Player::findHand(){
	std::sort(this->cards.begin(), this->cards.end(), [](const Card &a, const Card &b){
		return a.getCardRank() > b.getCardRank();
	});

	if(this->isStraightFlush() != ZERO){
		this->setHandRank(STRAIGHT_FLUSH);
		this->setHandValue(this->isStraightFlush());
	}

	else if(this->isFourOfAKind() != ZERO){
		this->setHandRank(FOUR_OF_A_KIND);
		this->setHandValue(this->isFourOfAKind());
	}

	else if(this->isFullHouse() != ZERO){
		this->setHandRank(FULL_HOUSE);
		this->setHandValue(this->isFullHouse());
	}

	else if(this->isFlush() != ZERO){
		this->setHandRank(FLUSH);
		this->setHandValue(this->isFlush());
	}

	else if(this->isStraight() != ZERO){
		this->setHandRank(STRAIGHT);
		this->setHandValue(this->isStraight());
	}

	else if(this->isThreeOfAKind() != ZERO){
		this->setHandRank(THREE_OF_A_KIND);
		this->setHandValue(this->isThreeOfAKind());
	}

	else if(this->isTwoPairs() != ZERO){
		this->setHandRank(TWO_PAIRS);
		this->setHandValue(this->isTwoPairs());
	}

	else if(this->isPair() != ZERO){
		this->setHandRank(PAIR);
		this->setHandValue(this->isPair());
	}

	else{
		this->setHandRank(HIGH_CARD);
		this->setHandValue(this->cards[0].getCardRank());
	}
}
