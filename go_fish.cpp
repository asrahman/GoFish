//
// Created by Ayesha Rahman on 11/6/18.
//

#include <iostream>    // Provides cout and cin
#include <fstream>
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

void dealHand(Deck &d, Player &p, int numCards);

Player* checkTurn(int turn, Player* p1, Player* p2);

string message(Player const p, int index, Card c);

static const int ASK = 0;
static const int GOFISH = 1;
static const int DRAWS = 2;
static const int YES = 3;
static const int BOOKS = 4;

static const int JOE = 0;
static const int JANE = 1;

int main() {
    ofstream myfile ("gofish_results.txt");

    int numCards = 7;
    int turn = 0;  //Joe is 0, jane is 1
    Card c1, c2, current;
    Player p1("Joe");
    Player p2("Jane");
    //Player* p;

    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    if (myfile.is_open()) {
        myfile << "Go Fish"<<endl;
    }

    cout<<p1.getName()<<"'s Hand: "<<p1.showHand()<<endl;
    cout<<p2.getName()<<"'s hand: "<<p2.showHand()<<endl;

    while (p1.checkHandForPair(c1, c2) == true) {
        p1.bookCards(c1,c2);
        p1.removeCardFromHand(c1);
        p1.removeCardFromHand(c2);
    }

    while (p2.checkHandForPair(c1, c2) == true) {
        p2.bookCards(c1,c2);
        p2.removeCardFromHand(c1);
        p2.removeCardFromHand(c2);
    }

    int count = 0;
    while (d.size() != 0 && p1.getHandSize() != 0 && p2.getHandSize() != 0 && count < 5) {
      Player* p = checkTurn(turn, &p1, &p2);
      Player* other = checkTurn(((turn+1)%2),&p1,&p2);
      //p->addCard(d.dealCard());
      //cout<<"p: "<<p->showHand()<<endl;
      //cout<<"p1: "<<p1.showHand()<<endl;

      cout<<p->getName()<<"'s Hand: "<<p->showHand()<<endl;
      cout<<other->getName()<<"'s hand: "<<other->showHand()<<endl;
      cout<<endl;
      cout<<p->getName()<<"'s Book: "<<p->showBooks()<<endl;
      cout<<other->getName()<<"'s Book: "<<other->showBooks()<<endl;
      current = p->chooseCardFromHand();
      cout<<message(*checkTurn(turn,&p1,&p2), ASK, current)<<endl;

      if (other->rankInHand(current)) {
          other->removeCardFromHand(current);
          p->addCard(current);
          if (p->checkHandForPair(c1,c2)) {
              cout<<message(*other,YES,current)<<endl;
              p->bookCards(c1,c2);
              cout<<message(*p,BOOKS,current)<<endl;
              cout<<p->getName()<<"'s Book: "<<p->showBooks()<<endl;
          }
      }
      else {
          cout<<message(*other,GOFISH,current)<<endl;
          Card newCard = d.dealCard();
          p->addCard(newCard);
          cout<<message(*p,DRAWS,newCard)<<endl;
          if (p->checkHandForPair(c1,c2)) {
              p->bookCards(c1,c2);
              cout<<message(*p,BOOKS,newCard)<<endl;
              cout<<p->getName()<<"'s Book: "<<p->showBooks()<<endl;
          }
          turn = (turn+1)%2;

      }

     // cout<<message(*checkTurn(((turn+1)%2),&p1,&p2), ASK, current)<<endl;
    cout<<endl;
    count++;
    }

    if (p1.getBookSize() > p2.getBookSize()) {
        myfile << p1.getName() << "wins!"<<endl;
    }
    else if (p2.getBookSize() > p1.getBookSize()) {
        myfile << p2.getName() << "wins!"<<endl;
    }

    else {
        myfile << "It's a tie!"<<endl;
    }



    myfile.close();
    return EXIT_SUCCESS;
}

void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}

string message(Player const p, int index, Card c) {
    string output;
    string MessageArray[5] = {" asks -- Do you have a ", " says - Go fish"," draws ", " says - Yes, I have a ", " books the "};
    if (index == ASK)  {
        output = p.getName() + MessageArray[index] + c.rankString(c.getRank()) + '?';
    }
    else if (index == GOFISH){
        output = p.getName() + MessageArray[1];
    }

    else if (index == DRAWS) {
        output = p.getName() + MessageArray[index] + c.toString();
    }

    else if (index == YES) {
        output = p.getName() + MessageArray[index] + c.rankString(c.getRank());
    }

    else if (index == BOOKS) {
        output = p.getName() + MessageArray[index] + c.rankString(c.getRank());
    }

    return output;
}

Player* checkTurn(int turn, Player* p1, Player* p2) {
    if (turn == JOE) {  //checks turn
        return p1;
    }
    else {
        return p2;
    }
}




