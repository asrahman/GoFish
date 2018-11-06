//
// Created by Ayesha Rahman on 11/4/18.
//

#include "deck.h"

Deck::Deck() {
    myIndex = 0; //initial value of index

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

Card Deck::dealCard() {
    Card tempCard(0,Card::Suit(0));
    if (size() > 0) {
        tempCard = myCards[myIndex];
        myIndex++;
    }
    return tempCard;
}

