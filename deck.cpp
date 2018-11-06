//
// Created by Ayesha Rahman on 11/4/18.
//

#include "deck.h"
#include <random>
#include <ctime>

Deck::Deck() {

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

Card Deck::dealCard(){

}

int  Deck::size() const{

}