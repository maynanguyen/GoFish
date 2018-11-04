//player.cpp
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

#include "player.h"
#include "card.h"

Player::Player(){
    myName = " ";
    myHand;
    myBook;
    unsigned int currentTime = (unsigned) time(0);
    srand(currentTime);  //seed the random number generator

};

Player::Player(string name) {
    myName = name;
    myHand;
    myBook;
    //unsigned int currentTime = (unsigned) time(0);
    srand(1541361910);
    //srand(currentTime);  //seed the random number generator
    //cout  << currentTime << endl;
}

string Player::getName() const {
    return myName;
}

//adds a card to the hand
void Player::addCard(Card c) {
    myHand.push_back(c);
}

//adds cards of same rank to book
void Player::bookCards(Card c1, Card c2){
    myBook.push_back(c1);
    myBook.push_back(c2);
}

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.
bool Player::checkHandForBook(Card &c1, Card &c2){
    int rank1 = c1.getRank();
    int rank2 = c2.getRank();

    if (rank1 == rank2){
        return true;
    }
}

//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
bool Player::rankInHand(Card c) const{
    for(int i = 0; i < myHand.size(); i++)
        if(myHand[i].getRank() == c.getRank()) {
            return true;
        }
    return false;
}

//uses some strategy to choose one card from the player's
//hand so they can say "Do you have a 4?"
Card Player::chooseCardFromHand() const{
    Card temp; //make a Card to temporarily choose
    int currentSize = myHand.size();
    // find random number to pick a card
    long num1 = (rand() % currentSize);
    temp = myHand.at(num1);
    return temp;

}

//Does the player have the card c in her hand?
bool Player::cardInHand(Card c) const{
    //  vector<Card>:: iterator iter;
    for(int i = 0; i < myHand.size(); i++)
    {
        if (myHand[i] == c){
            return true;
        }
    }
    return false;
}

//Remove the card c from the hand and return it to the caller
Card Player::removeCardFromHand(Card c){
    vector<Card>:: iterator iter;

    for(iter = myHand.begin(); iter < myHand.end(); iter++)
        if(*iter == c){
            myHand.erase(iter);
            return c;
        }

}

string Player::showHand() const {
    string hand;
    int HandSize = getHandSize();
    for (int i=0; i < HandSize; i++){
        string card = myHand[i].toString();
        hand = hand + card + " ";
    }
    return hand;
}

string Player::showBooks() const{
    string book;
    int BookSize = getBookSize();
    for (int i=0; i<BookSize*2; i++){
        string card = myBook[i].toString();
        book = book + card;
    }
    return book;
}

int Player::getHandSize() const{
    int HandSize = myHand.size();
    return HandSize;
}

int Player::getBookSize() const{
    int BookSize = myBook.size();
    return BookSize/2;
}

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

bool Player::checkHandForPair(Card &c1, Card &c2){

    for(int i = 0; i < myHand.size(); i++){
        c1 = myHand[i];
        for (int j = 0; j< myHand.size(); j++){
            if(myHand[j] == c1){
                c2 = myHand[j];
                return true;
            }
        }
    }
    return false;

}

//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
//e.g. will return true if the player has a 7d and the parameter is 7c

bool Player::sameRankInHand(Card c) const{
    for(int i = 0; i < myHand.size(); i++)
        if(myHand[i].getRank() == c.getRank()) {
            return true;
        }
    return false;
}

//NEW FUNCTION
//check for books without passing any cards in
void Player::bookCardsHelper() {
    int HandSize = getHandSize();
    Card c1;
    Card c2;
    bool status;
    int k=0;

    for (int i=0; i<HandSize; i++){
        for (int j=i+1; j<HandSize; j++){
            c1 = myHand[i];
            c2 = myHand[j];
            status = checkHandForBook(c1, c2);
            if (status == true){
                bookCards(c1, c2);
                removeCardFromHand(c1);
                removeCardFromHand(c2);
                j = 0;
                HandSize = HandSize-2;
            }
        }
    }
}

Card Player::findCard(Card c){
    int Handsize;
    int i=0;
    Card currentCard;
    Handsize = getHandSize();

    for (i=0; i<Handsize; i++){
        currentCard = myHand[i];
        if (currentCard.getRank() == c.getRank()){
            return currentCard;
        }
    }
}