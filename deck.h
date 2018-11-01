// FILE: deck.h
// written by Owen Astrachan and Roger Priebe
// this class respresents a deck of cards
// When a Deck is constructed, it contains 52 cards
// in a "regular" order (aces, twos, threes, ... , kings)
//
// Shuffling a deck makes it consist of 52 cards in a random order
//
// dealCard() returns a card from the deck and decreases the
// number of cards in the deck (returned by size())
// The idea is that after shuffling, calling dealCard() 52 times
// returns each card in the deck after shuffling.


#ifndef _DECK_H
#define _DECK_H

#include "card.h"


class Deck {

    static const int SIZE = 52; //size of deck

public:

    //FUNCTION- deck
    //sorts deck in order of Ace to King
    //in order of spaces, hearts, diamonds, clubs
    //input- none
    //output- none
    Deck();           // pristine, sorted deck

    //FUNCTION- shuffle
    //shuffles the current deck in a random order
    //input- none
    //output- none
    void shuffle();   // shuffle the deck, all 52 cards present

    //FUNCTION- Card dealCard
    //deals card from top of deck to player and decreases the size of the deck by  1
    //input- none
    //output- card from the top of the stack
    Card dealCard();   // get a card, after 52 are dealt, fail 

    //FUNCTION- int size
    //finds the current size of the deck
    //input- none
    //output- current size of the deck
    int  size() const; // # cards left in the deck

private:

    Card myCards[SIZE];
    int myIndex;  // current card to deal

};

#endif