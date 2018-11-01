//
// Created by Mayna on 10/28/2018.
//
#include "card.h"
#include <string>
#include <iostream>
using namespace std;


// default, ace of spades
Card::Card(){
    myRank = 1;
    mySuit = spades;


}

Card::Card(int rank, Suit s){
    myRank = rank;
    mySuit = s;

}
// return string version e.g. Ac 4h Js
string Card::toString()              const
{
     string rank = rankString(myRank);
     string suit = suitString(mySuit);
     return rank+suit;

}
// true if suit same as c
bool Card::sameSuitAs(const Card& c) const
{
     if (mySuit == c.mySuit)
         return true;
}
// return rank, 1..13
int Card::getRank()                 const
{
   return myRank;
}
// return "s", "h",...
string Card::suitString(Suit s)      const{
    if(mySuit == spades){
        return "s";
    }
    if(mySuit == hearts){
        return "h";
    }
    if(mySuit == diamonds){
        return "d";
    }
    if(mySuit == clubs){
        return "c";
    }
}
// return "A", "2", ..."Q"
string Card::rankString(int r)       const {
    if (myRank==1){
        return "A";
    }
    else if (myRank==11){
        return "J";
    }
    else if (myRank==12){
        return "Q";
    }
    else if (myRank==13){
        return "K";
    }
    else return to_string(r);
}


bool Card::operator == (const Card& rhs) const{
    return(myRank == rhs.myRank &&
           mySuit == rhs.mySuit );

}
bool Card::operator != (const Card& rhs) const {
    if (myRank != rhs.myRank ||
        mySuit != rhs.mySuit) {
        return true;
    }
}
ostream& operator << (ostream& out, const Card& c)
{
    out << c.toString() << " ";
    return out;
} 

