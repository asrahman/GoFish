//
// Created by Shania Paul on 11/5/2018.
//
#include "player.h"
#include "card.h"
#include "deck.h"
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

Player::Player(){
    myName = "";
}

void Player::addCard(Card c){

}
void Player::bookCards(Card c1, Card c2){


}

bool Player::rankInHand(Card c) const{

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

Card Player::removeCardFromHand(Card c){

}

string Player::showHand() const{

}

string Player::showBooks() const{
    vector<Card>::const_iterator iter;
    string books;
    for(iter = myBook.begin(); iter != myBook.end(); iter++){
        books = books + (*iter).toString() + " " ;
    }
}

int Player::getHandSize() const{

}

int Player::getBookSize() const{

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
