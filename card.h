//File Name: card.h
//
//Written by Owen Astrachan and Roger Priebe
// This class represents a playing card, i.e., "ace of spades"
// a Card is constructed from a rank (int in range 1..13)
// and a suit (Card::spades, Card::hearts, Card::diamonds,
// Card::clubs)
//
// Cards should be created by a Deck (see deck.h), a Deck returns
// good cards
// The function toString() converts a card to a string, e.g., to print
//
// Accessor functions include
//
// int GetRank()      -- returns 1, 2, ..., 13 for ace, two, ..., king
//
// bool SameSuitAs(c) -- returns true if same suit as Card c
//
// string suitString() -- returns "s", "h", "d" or "c"
//
// Note that the Ace is represented by 1 and the King by 13

#ifndef _CARD_H
#define _CARD_H

#include <iostream>
#include <string>
using namespace std;

class Card {

public:

    enum Suit {spades, hearts, diamonds, clubs};

    //FUNCTION- Card
    //default constructor- creates Ace of Spaces
    //sets card index to 0
    //input- none
    //output- none
    Card();          // default, ace of spades

    //FUNCTION- Card
    //constructor with rank and suit
    //creates card of the specified rank and suit
    //sets card index to 0
    //input- rank and suit
    //output- none
    Card(int rank, Suit s);

    //FUNCTION- toString
    //returns the rank and suit of a card as a string
    //ace=A, hearts=h, diamonds=d, clubs=c
    //jack=J, queen=Q, king=K
    //all order ranks follow regular logic
    //input- valid card
    //output- string version of card
    string toString() const;  // return string version e.g. Ac 4h Js

    //FUNCTION- sameSuitAs
    //determines if two cards have the same suit
    //input- valid card
    //output- true if the cards are the same, false if not
    bool sameSuitAs(const Card& c) const;  // true if suit same as c

    //FUNCTION- getRank
    //finds the rank of the specified card (1, 2, ... 13)
    //input- none
    //output- rank of card
    int  getRank() const;  // return rank, 1..13

    //FUNCTION- suitString
    //returns rank of card as string ("s", "h", "d", "c")
    //ace=A, hearts=h, diamonds=d, clubs=c
    //input- suit
    //output- suit as string
    string suitString(Suit s) const;  // return "s", "h",...

    //FUNCTION- rankString
    //returns rank of card as string
    //1=1, 2=2, ... etc
    //ace=A, jack=J, queen=Q, king=K
    //input- rank number
    //output- rank as string
    string rankString(int r) const;  // return "A", "2", ..."Q"

    //FUNCTION- bool operator ==
    //check if two cards are equal
    //input- card to be checked
    //output- true if cards are equal, false if not
    bool operator == (const Card& rhs) const;

    //FUNCTION- bool operator !=
    //check if two cards are not equal
    //input- card to be checked
    //output- true if cards are not equal, false if are equal
    bool operator != (const Card& rhs) const;


private:

    int myRank;
    Suit mySuit;

};

ostream& operator << (ostream& out, const Card& c);


#endif