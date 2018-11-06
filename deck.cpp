//
// Created by Ayesha Rahman on 11/4/18.
//

#include "deck.h"
#include <random>
#include <ctime>

Deck::Deck() {
    int tempSuit;
    int tempRank;  //for creating new cards
    int index = 0;
    for (tempSuit = 0; tempSuit < 4; tempSuit++) {
        for (tempRank = 1; tempRank < 14; tempRank++) {
            myCards[index] = Card(tempRank, Card::Suit(tempSuit));
            index++;
        }
    }
}

void Deck::shuffle(){
    srand(time(NULL));          //random seed for generator
    int num = SIZE;
    for(int i=0; i<num/2;i++){
        int index1 = rand() % num;
        int index2 = rand() % num;
        Card temp = myCards[index1];
        myCards[index1] = myCards[index2];
        myCards[index2] = temp;
    }
}

Card Deck::dealCard() {
    Card tempCard(0,Card::Suit(0));
    if (size() > 0) {
        tempCard = myCards[myIndex];
        myIndex++;
    }
    return tempCard;
}


int  Deck::size() const{

}

