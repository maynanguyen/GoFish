//deck.cpp
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

#include "deck.h"
#include "card.h"

using namespace std;

// pristine, sorted deck
Deck::Deck(){

    unsigned int currentTime = (unsigned) time(0);
    srand(currentTime);  //seed the random number generator

    myIndex = 0;

    for(int i=0; i<13; i++){
        myCards[i] = Card(i+1,(Card::spades));
    }

    for(int i=13; i<26; i++){
        myCards[i] = Card(i-12,(Card::hearts));
    }

    for(int i=26; i<39; i++){
        myCards[i] = Card(i-25,(Card::diamonds));
    }

    for(int i=39; i<52; i++){
        myCards[i] = Card(i-38,(Card::clubs));
    }
}

// shuffle the deck, all 52 cards present
void Deck::shuffle() {

    Card temp; //store card to swap
    int currentSize = size();

    for (int i = 0; i < (2 * currentSize); i++) {
        long num1 = (rand() % currentSize);
        long num2 = (rand() % currentSize);

        temp = myCards[num1];
        myCards[num1] = myCards[num2];
        myCards[num2] = temp;
    }
}

// get a card, after 52 are dealt, fail
Card Deck::dealCard(){
    Card c = myCards[myIndex];
    myIndex++;
    return c;
}

// # cards left in the deck
int  Deck::size() const{
    int deckSize = SIZE - myIndex;
    return deckSize;
}