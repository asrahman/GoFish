//
// Created by Shania Paul and Ayesha Rahman on 11/3/18.
//

#include "card.h"

using namespace std;

Card::Card() {
    myRank = 1;
    mySuit = Card::Suit(0);
    //cout<<suitString(mySuit)<<endl;  //comment out later
}

Card::Card(int rank, Suit s) {
    myRank = rank;
    mySuit = s;
}

bool Card::sameSuitAs(const Card &c) const {
    return mySuit == c.mySuit;
}

int Card::getRank() const {
    return myRank;
}

string Card::suitString(Suit s) const {
    string suit;
    if (s == spades) {
        suit = 's';
    }
    else if (s == hearts) {
        suit = 'h';
    }
    else if (s == diamonds) {
        suit = 'd';
    }
    else {
        suit = 'c';
    }
    return suit;
}

string Card::rankString(int r) const {
    string rankArray[13] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    //string rank;
    //if (r == 1) {
    //    rank = 'A';
    //}
    //else if (r == 11) {
    //    rank = 'J';
    //}
    //else if (r == 12) {
    //    rank = 'Q';
    //}
    //else if (r == 13) {
    //    rank = 'K';
    //}
    //else {
      //  rank = to_string(r);
    ///}
    return rankArray[r-1];
}

string Card::toString() const {
    return rankString(myRank) + suitString(mySuit);
}

bool Card::operator == (const Card &rhs) const {
    return mySuit == rhs.mySuit && myRank == rhs.myRank;
}

bool Card::operator!=(const Card &rhs) const {
    return mySuit != rhs.mySuit && myRank != rhs.myRank;
}

ostream& operator << (ostream& out, const Card& c) {
    out << c.toString();
    return out;
}