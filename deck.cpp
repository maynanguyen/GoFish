//
// Created by Mayna on 10/28/2018.
//

#include "deck.h"
#include "card.h"

// pristine, sorted deck
Deck::Deck(){
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
void Deck::shuffle(){

}
// get a card, after 52 are dealt, fail
Card Deck::dealCard(){
    Card c = myCards[myIndex];
    myIndex++;
    return c;
}

// # cards left in the deck
int  Deck::size() const{

}

