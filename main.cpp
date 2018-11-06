#include <iostream>
#include "card.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    Card();
    int num = 11;
    Card card1(num,Card::diamonds);
    cout<<card1.toString();

    return 0;
}