#include <iostream>
#include "card.h"
#include "deck.h"
#include "player.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Card();
    int num = 11;
    Card card1(num,Card::diamonds);
    //cout<<card1.toString();

    Deck d;
    d.shuffle();

    return 0;
}