#include <iostream>
#include "card.h"
#include "deck.h"
#include "player.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    Card card0;
    int num = 11;
    Card card1(num,Card::diamonds);

//    cout<<card0.toString()<<endl;
    Deck();

    Deck d;
    d.shuffle();

    return 0;
}