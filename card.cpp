//card.cpp
// -- EE 312 Project 6

//Student information for project:
//Replace <NAME> with your name.
//On my honor, Sarah Bi & Mayna Nguyen, this programming project is my own work
//and I have not provided this code to any other student.
//Name: Sarah Bi, Mayna Nguyen
//email address: sarahbi876@utexas.edu, maynanguyen@utexas.edu
//UTEID: sb48785, mhn436
//Section 5 digit ID: 16240

//Created by Sarah Bi and Mayna Nguyen 10/31/2018.

#include "card.h"
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <sstream>


using namespace std;

// default card constructor, ace of spades
Card::Card(){
    myRank = 1;
    mySuit = spades;
}

//specified card constructor
Card::Card(int rank, Suit s){
    myRank = rank;
    mySuit = s;
}

// return string version e.g. Ac 4h Js
string Card::toString() const {
    string rank = rankString(myRank);
    string suit = suitString(mySuit);
    return rank+suit;
}

// true if suit same as c
bool Card::sameSuitAs(const Card& c) const {
    if (mySuit == c.mySuit)
        return true;
}

// return rank, 1..13
int Card::getRank() const {
    return myRank;
}

// return "s", "h",...
string Card::suitString(Suit s) const{
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
string Card::rankString(int r) const {
    if (myRank == 1){
        return "A";
    }
    else if (myRank == 11){
        return "J";
    }
    else if (myRank == 12){
        return "Q";
    }
    else if (myRank == 13){
        return "K";
    }
   	//else return std::to_string(r);
    std::ostringstream ss;
    long num = (long) r;
    ss << num;
    return ss.str();

}

//check if two cards are equal
bool Card::operator == (const Card& rhs) const{
    return(myRank == rhs.myRank &&
           mySuit == rhs.mySuit );
}

//check if two cards are not equal
bool Card::operator != (const Card& rhs) const {
    if (myRank != rhs.myRank ||
        mySuit != rhs.mySuit) {
        return true;
    }
}

//override output to print card
ostream& operator << (ostream& out, const Card& c) {
    out << c.toString() << " ";
    return out;
}
