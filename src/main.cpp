#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include "card.h"
#include "player.h"

int compareTwoPairs(Player &p1, Player p2){
    CardRank higherPairRank1 = p1.isTwoPairs();
    CardRank higherPairRank2 = p1.isTwoPairs();

    if(higherPairRank1 != higherPairRank2)
        return higherPairRank1 - higherPairRank2;
    
    CardRank lowerPairRank1 = p1.getLowerPairRank(higherPairRank1);
    CardRank lowerPairRank2 = p2.getLowerPairRank(higherPairRank2);

    if (lowerPairRank1 != lowerPairRank2) {
        return lowerPairRank1 - lowerPairRank2; // Compare lower pairs
    }

    return p1.getRemainingCardRank(higherPairRank1, lowerPairRank1) - 
               p2.getRemainingCardRank(higherPairRank2, lowerPairRank2);   
}

int comparePairs(Player &p1, Player &p2){
    CardRank higherPairRank1 = p1.isPair();
    CardRank higherPairRank2 = p1.isPair();

    if(higherPairRank1 != higherPairRank2)
        return higherPairRank1 - higherPairRank2;

    return p1.getRemainingCardRank(higherPairRank1) - p2.getRemainingCardRank(higherPairRank2);
}

int compareHighCard(Player &p1, Player &p2){
    std::vector<Card> p1Cards = p1.getCards();
    std::vector<Card> p2Cards = p2.getCards();

    std::sort(p1Cards.begin(), p1Cards.end(), [](const Card &a, const Card &b){
		return a.getCardRank() > b.getCardRank();
	});
    
    std::sort(p2Cards.begin(), p2Cards.end(), [](const Card &a, const Card &b){
		return a.getCardRank() > b.getCardRank();
	});

    int i=0;
    while(i < p1Cards.size()){
        if(p1Cards[i].getCardRank() != p2Cards[i].getCardRank()){
            return p1Cards[i].getCardRank() - p2Cards[i].getCardRank();
        }
        i++;
    }

    return 0;
}

int main(){
    std::ifstream file("../data/input.txt");

    if(file.is_open()){
        std::string line;

        while(std::getline(file, line)){
            std::string token;
            std::stringstream ss(line);

            Player player1, player2;
            player1.setName("Black");
            player2.setName("White");

            int idx = 0;

            while(std::getline(ss, token, ' ')){
                if(idx / 5 == 0){
                    Card card;
                    card.setCardSuit(token.at(1));
                    card.setCardValue(token.at(0));
                    card.setCardRank();

                    player1.addCard(card);
                }
                else if(idx / 5 == 1){
                    Card card;
                    card.setCardSuit(token.at(1));
                    card.setCardValue(token.at(0));
                    card.setCardRank();

                    player2.addCard(card);
                }
                idx++;
            }

            player1.findHand();
            player2.findHand();

            if(player1.getHandRank() > player2.getHandRank()){
                std::cout<<player1.getName()<<" wins\n";
            }

            else if(player1.getHandRank() < player2.getHandRank()){
                std::cout<<player2.getName()<<" wins\n";
            }

            else{
                if(player1.getHandRank() == TWO_PAIRS){
                    if(compareTwoPairs(player1, player2) > 0)
                        std::cout<<player1.getName()<<" wins\n";

                    else if(compareTwoPairs(player1, player2) < 0)
                        std::cout<<player1.getName()<<" wins\n";
                }
                else if(player1.getHandRank() == PAIR){
                    if(comparePairs(player1, player2) > 0)
                        std::cout<<player1.getName()<<" wins\n";
                    else if(comparePairs(player1, player2) > 0)
                        std::cout<<player2.getName()<<" wins\n";
                }
                else if(player1.getHandRank() == HIGH_CARD){
                    if(compareHighCard(player1, player2) > 0)
                        std::cout<<player1.getName()<<" wins\n";
                    else if(compareHighCard(player1, player2) < 0)
                        std::cout<<player2.getName()<<" wins\n";

                    else
                        std::cout<<"Tie\n";
                }
                else{
                    if(player1.getHandValue() > player2.getHandValue()){
                        std::cout<<player1.getName()<<" wins\n";
                    }
                    else if(player1.getHandValue() < player2.getHandValue()){
                        std::cout<<player2.getName()<<" wins\n";
                    }
                }
            }
        }
    }
    else{
        std::cerr<<"Error opening file "<<std::endl;
        exit(0);
    }
    file.close();

    return 0;
}