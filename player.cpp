//
// Created by Shania Paul on 11/5/2018.
//

#include "player.h"
#include <algorithm>
#include <iterator>


using namespace std;

void Player::addCard(Card c) {
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);
    myBook.push_back(c2);
}

bool Player::rankInHand(Card c) const {
    vector<Card>::const_iterator it;
    bool found = false;
    for (it = myHand.begin(); it != myHand.end(); it++) {
        if (c.getRank() == (*it).getRank()) {
            found = true;
        }
    }
    return found;
}


Card Player::removeCardFromHand(Card c) {
    Card tempCard;
    vector<Card>::iterator it;
    it = find(myHand.begin(), myHand.end(), c);
    tempCard = *it;
    myHand.erase(it);
    return tempCard;
}

int Player::getHandSize() const {
    int size;
    size = myHand.size();
    return size;
}

//returns number of cards
int Player::getBookSize() const {
    return myBook.size();
}

string Player::showHand() const {
    string hand;
    vector<Card>::const_iterator it;
    for (it = myHand.begin(); it != myHand.end(); it++) {
        hand = hand + (*it).toString() + "  ";
    }
    return hand;
}

