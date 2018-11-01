// FILE:  player.h
// written by Roger Priebe
// 1/22/08 (revised 9/2/08)
// This class represents a player in a card game that takes "tricks"
// The "Books" represent a container for holding tricks

#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <string>
#include <vector>

#include "card.h"

using namespace std;

class Player {

public:

    //FUNCTION- Player
    //default constructor for player
    //input- none
    //output- none
    Player();

    //FUNCTION- Player
    //constructor for player with specified name
    //input- name of player
    //output- none
    Player(string name);

    //FUNCTION- string getName
    //return name of player
    //input- player
    //output- name
    string getName() const;

    //FUNCTION- addCard
    //adds card to player's hand
    //input- card
    //output- none
    void addCard(Card c);  //adds a card to the hand

    //FUNCTION- bookCards
    //puts two cards together if they have the same rank
    //input- 2 cards of the same rank
    //output- none
    void bookCards(Card c1, Card c2);

    //OPTIONAL
    //FUNCTION- bool checkHandForBook
    //this function will check a players hand for a pair.
    //If a pair is found, it returns true and populates the two variables with the cards that make the pair.
    //input- 2 cards to be check
    //output- true if the cards are a book, false if not
    bool checkHandForBook(Card &c1, Card &c2);

    //OPTIONAL
    // comment out if you decide to not use it
    //Does the player have a card with the same rank as c in her hand?
    bool rankInHand(Card c) const;

    //uses some strategy to choose one card from the player's
    //hand so they can say "Do you have a 4?"
    Card chooseCardFromHand() const;

    //Does the player have the card c in her hand?
    bool cardInHand(Card c) const;

    //Remove the card c from the hand and return it to the caller
    Card removeCardFromHand(Card c);

    //FUNCTION- string showHand
    //returns the cards in the hand of the player
    //input- none
    //output- string version of cards in hand
    string showHand() const;

    //FUNCTION- string showBook
    //returns the number of books the player has
    //input- none
    //output- string version of books of the player
    string showBooks() const;

    //FUNCTION- int getHandSize
    //determines the number of cards player has
    //input- none
    //output- number of cards player has
    int getHandSize() const;

    //FUNCTION- int getBookSize
    //determines the number of books player has
    //input- none
    //output- number of books player has
    int getBookSize() const;

    //OPTIONAL
    //FUNCTION- bool checkHandForPair
    // comment out if you decide to not use it
    //this function will check a players hand for a pair.
    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.
    //input- 2 cards to be checked
    //output- true if the cards have the same rank, false if not
    bool checkHandForPair(Card &c1, Card &c2);

    //OPTIONAL
    // comment out if you decide to not use it
    //Does the player have a card with the same rank as c in her hand?
    //e.g. will return true if the player has a 7d and the parameter is 7c

    bool sameRankInHand(Card c) const;


private:

    vector <Card> myHand;
    vector <Card> myBook;
    string myName;

};


#endif