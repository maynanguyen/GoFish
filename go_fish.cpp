//
// Created by Mayna on 10/28/2018.
//
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"
#include <string>

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);


//DO NOT DELETE!!!!
int main() {

    Card::Suit suits[4] = {Card::spades, Card::hearts, Card::diamonds, Card::clubs};
    int HandSize;
    Card c1;
    Card c2;
    Card checkCard;
    Card currentCard;
    Card matchCard;
    int bookSize;
    int i = 0;
    int j = 0;
    string hand;
    string book;

    Card card;
    bool checkBook;
    bool status;


    //create players
    Player p1("Sarah");
    Player p2("Mayna");
    string name1 = p1.getName();
    string name2 = p2.getName();
    cout << "Player 1 is " << name1 << endl;
    cout << "Player 2 is " << name2 << endl;
    cout << " " << endl;

    //create deck
    Deck d;
    d.shuffle();

    //deal 7 cards to each player
    dealHand(d, p1, 7);
    cout << "Sarah's cards" << endl;
    hand = p1.showHand();
    cout << hand << endl;

    dealHand(d, p2, 7);
    cout << "Maynas's cards" << endl;
    hand = p2.showHand();
    cout << hand << endl;
    cout << " " << endl;

    //check books for each player

    c1 = Card();
    c2 = Card();

    while (p1.checkHandForBook(c1, c2)) {
        p1.bookCards(c1, c2);
        p1.removeCardFromHand(c1);
        p1.removeCardFromHand(c2);
    }

    while (p2.checkHandForBook(c1, c2)) {
        p2.bookCards(c1, c2);
        p2.removeCardFromHand(c1);
        p2.removeCardFromHand(c2);
    }

    book = p1.showBooks();
    cout << "Sarah's Books" << endl;
    cout << book << endl;

    book = p2.showBooks();
    cout << "Mayna's Books" << endl;
    cout << book << endl;
    cout << " " << endl;

    cout << "Sarah's cards (after books)" << endl;
    hand = p1.showHand();
    cout << hand << endl;

    cout << "Maynas's cards (after books)" << endl;
    hand = p2.showHand();
    cout << hand << endl;
    cout << " " << endl;



   // while ((p1.getBookSize() + p2.getBookSize()) != 26) {


        // ******************* PLAYER 1'S TURN *******************
        //1-  ask for a card
        //2- if p2 has card,  get card from p2
        //3- if no card, draw card from deck
        //4- check for books

        //1- ask for card
        checkCard = p1.chooseCardFromHand();
        //checkCard = Card(4, Card::spades);
        cout << "Sarah: Do you have a(n) " << checkCard.getRank() << endl;
        cout << " " << endl;


        //2- if p2 has card, get card from p2
        if (p2.rankInHand(checkCard)) {
            cout << "Mayna: Yes" << endl;
            i = checkCard.getRank();
            for (j = 0; j < 4; j++) {
                matchCard = Card(i, suits[j]);
                if (p2.cardInHand(matchCard)) {
                    p2.removeCardFromHand(matchCard);
                    p1.addCard(matchCard);
                }
            }
        }

            //3- if no card, draw card from deck
        else {
            cout << "Mayna: Go fish" << endl;
            card = d.dealCard();
            cout << "Sarah draws a(n) " << card << endl;
            p1.addCard(card);
        }

        //4- check for books
        while (p1.checkHandForBook(c1, c2)) {
            p1.bookCards(c1, c2);
            cout << "Sarah books the " << c1.getRank() << "s" << endl;
            p1.removeCardFromHand(c1);
            p1.removeCardFromHand(c2);
        }

        cout << "Sarah's cards (after Sarah's turn)" << endl;
        hand = p1.showHand();
        cout << hand << endl;


        cout << "Maynas's cards (after Sarah's turn)" << endl;
        hand = p2.showHand();
        cout << hand << endl;
        cout << " " << endl;

//    // ******************* PLAYER 2'S TURN *******************
        //1-  ask for a card
        //2- if p2 has card,  get card from p2
        //3- if no card, draw card from deck
        //4- check for books

        //1- ask for card
        checkCard = p2.chooseCardFromHand();
        //checkCard = Card(4, Card::spades);
        cout << "Mayna: Do you have a(n) " << checkCard.getRank() << endl;
        cout << " " << endl;


        //2- if p2 has card, get card from p2
        if (p1.rankInHand(checkCard)) {
            cout << "Sarah: Yes" << endl;
            i = checkCard.getRank();
            for (j = 0; j < 4; j++) {
                matchCard = Card(i, suits[j]);
                if (p1.cardInHand(matchCard)) {
                    p1.removeCardFromHand(matchCard);
                    p2.addCard(matchCard);
                }
            }
        }

            //3- if no card, draw card from deck
        else {
            cout << "Sarah: Go fish" << endl;
            card = d.dealCard();
            cout << "Mayna draws a(n) " << card << endl;
            p2.addCard(card);
        }

        //4- check for books
        while (p2.checkHandForBook(c1, c2)) {
            p2.bookCards(c1, c2);
            cout << "Mayna books the " << c1.getRank() << "s" << endl;
            p2.removeCardFromHand(c1);
            p2.removeCardFromHand(c2);
        }

        cout << "Sarah's cards (after Mayna's turn)" << endl;
        hand = p1.showHand();
        cout << hand << endl;

        cout << "Maynas's cards (after Mayna's turn)" << endl;
        hand = p2.showHand();
        cout << hand << endl;
        cout << " " << endl;



//round 2
    //1- ask for card
    //checkCard = p1.chooseCardFromHand();
    checkCard = Card(13, Card::clubs);
    cout << "Sarah: Do you have a(n) " << checkCard.getRank() << endl;
    cout << " " << endl;


    //2- if p2 has card, get card from p2
    if (p2.rankInHand(checkCard)) {
        cout << "Mayna: Yes" << endl;
        i = checkCard.getRank();
        for (j = 0; j < 4; j++) {
            matchCard = Card(i, suits[j]);
            if (p2.cardInHand(matchCard)) {
                p2.removeCardFromHand(matchCard);
                p1.addCard(matchCard);
            }
        }
    }

        //3- if no card, draw card from deck
    else{
        cout << "Mayna: Go fish" << endl;
        card = d.dealCard();
        cout << "Sarah draws a(n) " << card << endl;
        p1.addCard(card);
    }

    //4- check for books
    while (p1.checkHandForBook(c1, c2)){
        p1.bookCards(c1, c2);
        cout << "Sarah books the " << c1.getRank() << "s" << endl;
        p1.removeCardFromHand(c1);
        p1.removeCardFromHand(c2);
    }

    cout << "Sarah's cards (after Sarah's turn)" << endl;
    hand = p1.showHand();
    cout << hand << endl;


    cout << "Maynas's cards (after Sarah's turn)" << endl;
    hand = p2.showHand();
    cout << hand << endl;
    cout << " " << endl;




//    //test deal card
//    cout << "Test deal card" << endl;
//    Card c1 = d.dealCard();
//    cout<< c1 << endl;
//
//    Card c2 = d.dealCard();
//    cout<< c2 << endl;
//    cout << " " << endl;
//
//
//    //check each player for books
//    Card c20 = Card(2,Card::spades);
//    cout<< c20 << endl;
//
//    Card c21 = Card(2, Card::hearts);
//    cout<< c21 << endl;
//    cout << " " << endl;
//
//    p1.addCard(c20);
//    p1.addCard(c21);

//    checkBook = p1.checkHandForBook(c20, c21);
//    if (checkBook == true) {
//        cout << "Book found" << endl;
//        p1.bookCards(c20,c21);
//    }
//    else{
//        cout << "Book not found" << endl;
//    }
//
//    cout << "Sarah's books" << endl;
//    book = p1.showBooks();
//    cout << book << endl;
//
//    cout << "Book's book size" << endl;
//    bookSize = p1.getBookSize();
//    cout << bookSize << endl;
//
//
//
//    cout << " " << endl;
//    cout << " " << endl;
//    cout << " " << endl;
//    cout << " " << endl;
//    cout << " " << endl;
//    cout << " " << endl;
//
//
//
//
//
//    //test add card, getHandSize, showHand
//    p1.addCard(c1);
//    p1.addCard(c2);
//
//    cout << "Number of cards in Sarah's hand" << endl;
//    HandSize = p1.getHandSize();
//    cout << HandSize << endl;
//    cout << "Current cards in Mayna's hand" << endl;
//    HandSize = p2.getHandSize();
//    cout << HandSize << endl;
//    cout << " " << endl;
//
//    //test deck size
//    int size = d.size();
//    cout << "Current size of deck" << endl;
//    cout<< size << endl;
//    cout << " " << endl;
//
//    //test shuffle
//    d.shuffle();
//    cout << "Results of shuffled deck" << endl;
//    Card c3 = d.dealCard();
//    cout<< c3 << endl;
//
//    Card c4 = d.dealCard();
//    cout<< c4 << endl;
//
//    Card c5 = d.dealCard();
//    cout<< c5 << endl;
//
//    Card c6 = d.dealCard();
//    cout<< c6 << endl;
//
//    Card c7 = d.dealCard();
//    cout<< c7 << endl;
//
//    Card c8 = d.dealCard();
//    cout<< c8 << endl;
//
//    Card c9 = d.dealCard();
//    cout<< c9 << endl;
//
//    Card c10 = d.dealCard();
//    cout<< c10 << endl;
//
//    Card c11 = d.dealCard();
//    cout<< c11 << endl;
//
//    Card c12 = d.dealCard();
//    cout<< c12 << endl;
//
//    Card c13 = d.dealCard();
//    cout<< c13 << endl;
//    cout<< " " << endl;
//
//    size = d.size();
//    cout<< "Size of current deck" << endl;
//    cout<< size << endl;


//    Card c1 = d.dealCard();
//    cout<< c1 << endl;

//    size = d.size();
//    cout<< size << endl;






//        Card c = d.dealCard();
//        cout << "deal test " << c << endl;
//        cout << endl;

//        Player p("Joe");
//        cout << p.getName() << endl;
//        p.addCard(c);
//        p.addCard(d.dealCard());
//        cout << p.showHand() << endl;
//
//
//        int numCards = 5;
//
//        vector <Card> cards(numCards);
//
//        srand((unsigned)time(0));  //seed the random number generator
//
//        for (int i = 0; i < numCards; i++) {
//            int rank = (rand() % 13) + 1;
//            int suit = (rand() % 4) + 1;
//            Card c(rank,(Card::Suit)suit);
//            cout << "rank - " << rank << "  "  << c <<  endl;
//            cards[i] = c;
//        }
//
//        for (int i = 0; i < cards.size(); i++)
//            cout << cards[i] << endl;
//
//        cards.erase(cards.begin()+2);
//
//        cout <<"after"<<endl;
//
//        for (int i = 0; i < cards.size(); i++)
//            cout << cards[i] << endl;

    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards) {
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}


////
//// Created by Mayna on 10/28/2018.
////
//#include <iostream>    // Provides cout and cin
//#include <cstdlib>     // Provides EXIT_SUCCESS
//#include "card.h"
//#include "player.h"
//#include "deck.h"
//
//using namespace std;
//
//
//// PROTOTYPES for functions used by this demonstration program:
//void dealHand(Deck &d, Player &p, int numCards);
//
//
//
//
//int main( )
//{
//    int numCards = 5;
//
//    Player p1("Joe");
//    Player p2("Jane");
//
//    Deck d;  //create a deck of cards
//    d.shuffle();
//
//    dealHand(d, p1, numCards);
//    dealHand(d, p2, numCards);
//
//    cout << p1.getName() <<" has : " << p1.showHand() << endl;
//    cout << p2.getName() <<" has : " << p2.showHand() << endl;
//
//    return EXIT_SUCCESS;
//}
//
//
//
//void dealHand(Deck &d, Player &p, int numCards)
//{
//    for (int i=0; i < numCards; i++)
//        p.addCard(d.dealCard());
//}