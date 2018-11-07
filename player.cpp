//
// Created by Shania Paul on 11/5/2018.
//


#include "player.h"
#include "card.h"
#include "deck.h"
#include <algorithm>
#include <iterator>
#include <random>
#include <ctime>


using namespace std;

Player::Player(){
    myName = "";
}

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


Card Player::chooseCardFromHand() const{
    srand(time(NULL)); //random seed for generator
    int num = getHandSize();
    int index = rand() % num;
    return myHand[index];
}

bool Player::cardInHand(Card c) const {
    vector<Card>::const_iterator iter;
    iter= find(myHand.begin(), myHand.end(), c);
    if(iter == myHand.end()){
        return false;
    }else{
        return true;
    }
}

string Player::showBooks() const{
    vector<Card>::const_iterator iter;
    string books;
    for(iter = myBook.begin(); iter != myBook.end(); iter++){
        books = books + (*iter).toString() + " " ;
    }
    return books;
}

bool Player::checkHandForPair(Card &c1, Card &c2){
    vector<Card>::const_iterator iter1;
    vector<Card>::const_iterator iter2;
    for(iter1 = myHand.begin(); iter1 != myHand.end(); iter1++) {
        for(iter2 = iter1+1; iter2 != myHand.end(); iter2++) {
            if(*iter1 == *iter2){
                c1 = *iter1;
                c2 = *iter2;
                return true;
            }
        }
    }
    return false;
}

