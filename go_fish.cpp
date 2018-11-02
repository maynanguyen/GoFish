//
// Created by Mayna on 10/28/2018.
//
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);




int main( ) {

    int HandSize;
    int bookSize;
    string hand;
    string book;
    bool checkBook;


    //test player constructors
    Player p1("Sarah");
    Player p2("Mayna");
    string name1 = p1.getName();
    string name2 = p2.getName();
    cout << "Player 1 is " << name1 << endl;
    cout << "Player 2 is " << name2 << endl;
    cout << " " << endl;

    //test deck constructor
    Deck d;

    //test book stuff
    Card c20 = Card(2,Card::spades);
    cout<< c20 << endl;

    Card c21 = Card(2, Card::hearts);
    cout<< c21 << endl;
    cout << " " << endl;

    p1.addCard(c20);
    p1.addCard(c21);

    checkBook = p1.checkHandForBook(c20, c21);
    if (checkBook == true) {
        cout << "Book found" << endl;
        p1.bookCards(c20,c21);
    }
    else{
        cout << "Book not found" << endl;
    }

    cout << "Sarah's books" << endl;
    book = p1.showBooks();
    cout << book << endl;

    cout << "Book's book size" << endl;
    bookSize = p1.getBookSize();
    cout << bookSize << endl;



    cout << " " << endl;
    cout << " " << endl;
    cout << " " << endl;
    cout << " " << endl;
    cout << " " << endl;
    cout << " " << endl;


    //deal ordered cards to player
    dealHand(d, p1, 7);
    cout << "Sarah's cards (ordered)" << endl;
    hand = p1.showHand();
    cout << hand << endl;

    dealHand(d, p2, 7);
    cout << "Maynas's cards (ordered)" << endl;
    hand = p2.showHand();
    cout << hand << endl;
    cout << " " << endl;

    //test deal card
    cout << "Test deal card" << endl;
    Card c1 = d.dealCard();
    cout<< c1 << endl;

    Card c2 = d.dealCard();
    cout<< c2 << endl;
    cout << " " << endl;


    //test add card, getHandSize, showHand
    p1.addCard(c1);
    p1.addCard(c2);

    cout << "Number of cards in Sarah's hand" << endl;
    HandSize = p1.getHandSize();
    cout << HandSize << endl;
    cout << "Current cards in Mayna's hand" << endl;
    HandSize = p2.getHandSize();
    cout << HandSize << endl;
    cout << " " << endl;

    //test deck size
    int size = d.size();
    cout << "Current size of deck" << endl;
    cout<< size << endl;
    cout << " " << endl;

    //test shuffle
    d.shuffle();
    cout << "Results of shuffled deck" << endl;
    Card c3 = d.dealCard();
    cout<< c3 << endl;

    Card c4 = d.dealCard();
    cout<< c4 << endl;

    Card c5 = d.dealCard();
    cout<< c5 << endl;

    Card c6 = d.dealCard();
    cout<< c6 << endl;

    Card c7 = d.dealCard();
    cout<< c7 << endl;

    Card c8 = d.dealCard();
    cout<< c8 << endl;

    Card c9 = d.dealCard();
    cout<< c9 << endl;

    Card c10 = d.dealCard();
    cout<< c10 << endl;

    Card c11 = d.dealCard();
    cout<< c11 << endl;

    Card c12 = d.dealCard();
    cout<< c12 << endl;

    Card c13 = d.dealCard();
    cout<< c13 << endl;
    cout<< " " << endl;

    size = d.size();
    cout<< "Size of current deck" << endl;
    cout<< size << endl;

    // Test remove card
    hand = p1.showHand();
    cout << hand << endl;
    Card c14 = p1.removeCardFromHand(c1);
    cout << "Card removed:" << c14 << endl;
    hand = p1.showHand();
    cout << hand << endl;

    //Test cardInHand

    cout<< p1.cardInHand(c20) << endl;
    Card c22 = Card(7,Card::clubs);
    cout<< p1.cardInHand(c22) << endl;

    //Test same rank in hand
    cout<< p1.sameRankInHand(c22) << endl;


    //Test choose card from hand
    cout<< p1.chooseCardFromHand() << endl;
    cout<< p1.chooseCardFromHand() << endl;
    cout<< p1.chooseCardFromHand() << endl;
    cout<< p1.chooseCardFromHand() << endl;
    cout<< p1.chooseCardFromHand() << endl;
    cout<< p1.chooseCardFromHand() << endl;
    cout<< p1.chooseCardFromHand() << endl;
    cout<< p1.chooseCardFromHand() << endl;
    cout<< p1.chooseCardFromHand() << endl;
    cout<< p1.chooseCardFromHand() << endl;



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