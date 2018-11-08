//
// Created by Mayna on 10/28/2018.
//
#include <iostream>    // Provides myfile and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"
#include <string>
#include <fstream>

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);


//DO NOT DELETE!!!!
int main() {

    ofstream myfile;  //output results to textfile
    myfile.open("Go_Fish.txt");

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
    int iter = 1;
    Card card;
    bool checkBook;
    bool status;


    //create players
    Player p1("Sarah");
    Player p2("Mayna");
    string name1 = p1.getName();
    string name2 = p2.getName();
    myfile << "Player 1 is " << name1 << endl;
    myfile << "Player 2 is " << name2 << endl;
    myfile << " " << endl;

    //create deck
    Deck d;
    d.shuffle();

    //deal 7 cards to each player
    dealHand(d, p1, 7);
    myfile << "Cards dealt to " << p1.getName() << endl;
    //myfile << p1.getName() << "'s cards" << endl;
    hand = p1.showHand();
    myfile << hand << endl;


    dealHand(d, p2, 7);
    myfile << "Cards dealt to " << p2.getName() << endl;
    hand = p2.showHand();
    myfile << hand << endl;
    myfile << " " << endl;

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
    myfile << p1.getName() << "'s Books" << endl;
    myfile << book << endl;

    book = p2.showBooks();
    myfile << p2.getName() << "'s Books" << endl;
    myfile << book << endl;
    myfile << " " << endl;

    myfile << p1.getName() << "'s cards (after books)" << endl;
    hand = p1.showHand();
    myfile << hand << endl;

    myfile << p2.getName() << "'s cards (after books)" << endl;
    hand = p2.showHand();
    myfile << hand << endl;
    myfile << " " << endl;


    //myfile << p1.getBookSize() + p2.getBookSize() << endl;


    myfile << "Start of game" << endl;
    myfile << " " << endl;
//*************  START GAME ***********
    while ((p1.getBookSize() + p2.getBookSize()) != 26) {

    myfile << "*********** ROUND " << iter << " ***********" << endl;
        // ******************* PLAYER 1'S TURN *******************
        //1-  ask for a card
        //2- if p2 has card,  get card from p2
        //3- if no card, draw card from deck
        //4- check for books

        //1- ask for card
        if (p1.getHandSize() != 0) {
            checkCard = p1.chooseCardFromHand();
            //checkCard = Card(4, Card::spades);
            myfile << p1.getName() << ": Do you have a(n) " << checkCard.rankString(checkCard.getRank())<< endl;

            //2- if p1 has card, get card from p2
            if (p2.rankInHand(checkCard)) {
                myfile << p2.getName() << ": Yes" << endl;
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
                myfile << p2.getName() << ": Go fish" << endl;
                if (d.size() > 0) {
                    card = d.dealCard();
                    myfile << p1.getName() << " draws a(n) " << card << endl;
                    p1.addCard(card);
                }
            }
        }

            //if p1 has no cards in hand- draw from deck
        else {
            if (d.size() > 0) {
                card = d.dealCard();
                myfile << p1.getName() << " has no cards right now. She/he must draw a card" << endl;
                myfile << p1.getName() << " draws a(n) " << card << endl;
                p1.addCard(card);
            }
        }


        //4- check for books
        while (p1.checkHandForBook(c1, c2)) {
            p1.bookCards(c1, c2);
            myfile << p1.getName() << " books the " << c1.rankString(c1.getRank()) << "'s" << endl;

            p1.removeCardFromHand(c1);
            p1.removeCardFromHand(c2);
        }

        myfile << " " << endl;
        myfile << "Results after " << p1.getName() << "'s turn" << endl;
        myfile << p1.getName() << "'s books" << endl;
        myfile << p1.showBooks() << endl;

        myfile << p1.getName() << "'s books size" << endl;
        myfile << p1.getBookSize() << endl;

        myfile << p1.getName() << "'s cards" << endl;
        hand = p1.showHand();
        myfile << hand << endl;

        myfile << " " << endl;

        myfile << p2.getName() << "'s books" << endl;
        myfile << p2.showBooks() << endl;

        myfile << p2.getName() << "'s books size" << endl;
        myfile << p2.getBookSize() << endl;

        myfile << p2.getName() << "'s cards" << endl;
        hand = p2.showHand();
        myfile << hand << endl;
        myfile << " " << endl;


//    // ******************* PLAYER 2'S TURN *******************
        //1-  ask for a card
        //1-  ask for a card
        //2- if p2 has card,  get card from p2
        //3- if no card, draw card from deck
        //4- check for books

        //1- ask for card
        if (p2.getHandSize() != 0) {
            checkCard = p2.chooseCardFromHand();
            //checkCard = Card(4, Card::spades);
            myfile << p2.getName() << ": Do you have a(n) " << checkCard.rankString(checkCard.getRank()) << endl;


            //2- if p2 has card, get card from p1
            if (p1.rankInHand(checkCard)) {
                myfile << p1.getName() << ": Yes" << endl;
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
                myfile << p1.getName() << ": Go fish" << endl;
                if (d.size() > 0) {
                    card = d.dealCard();
                    myfile << p2.getName() << " draws a(n) " << card << endl;
                    p2.addCard(card);
                }
            }
        }

            //if p2 has no cards in hand- draw from deck
        else {
            if (d.size() > 0) {
                card = d.dealCard();
                myfile << p2.getName() << " has no cards right now. She/he must draw a card." << endl;
                myfile << p2.getName() << " draws a(n) " << card << endl;
                p2.addCard(card);
            }
        }

        //4- check for books
        while (p2.checkHandForBook(c1, c2)) {
            p2.bookCards(c1, c2);
            myfile << p2.getName() << " books the " << c1.rankString(c1.getRank()) << "'s" << endl;
            p2.removeCardFromHand(c1);
            p2.removeCardFromHand(c2);
        }

        myfile << " " << endl;
        myfile << "Results after " << p2.getName() << "'s turn" << endl;
        myfile << p1.getName() << "'s books" << endl;
        myfile << p1.showBooks() << endl;

        myfile << p1.getName() << "'s books size" << endl;
        myfile << p1.getBookSize() << endl;

        myfile << p1.getName() << "'s cards" << endl;
        hand = p1.showHand();
        myfile << hand << endl;

        myfile << " " << endl;

        myfile << p2.getName() << "'s books" << endl;
        myfile << p2.showBooks() << endl;

        myfile << p2.getName() << "'s books size" << endl;
        myfile << p2.getBookSize() << endl;

        myfile << p2.getName() << "'s cards" << endl;
        hand = p2.showHand();
        myfile << hand << endl;
        myfile << " " << endl;

        iter = iter + 1;



//        myfile << "Sarah's end books" << endl;
//        myfile << p1.showBooks() << endl;
//
//        myfile << "Maynas's end books" << endl;
//        myfile << p2.showBooks() << endl;
//
//        myfile << d.size() << endl;
//        //return 0;
    }

    myfile << "*********** END OF GAME ***********" << endl;

    if (p1.getBookSize() > p2.getBookSize()){
        myfile << p1.getName() << " wins" << endl;
    }
    else if (p2.getBookSize() > p1.getBookSize()){
        myfile << p2.getName() << " wins" << endl;
    }
    else {
        myfile << p1.getName() << " and " << p2.getName() << " tie" << endl;
    }

    myfile << p1.getName() << "'s end books" << endl;
    myfile << p1.showBooks() << endl;

    myfile << p2.getName() << "'s end books" << endl;
    myfile << p2.showBooks() << endl;

    myfile.close();

    return EXIT_SUCCESS;
}


void dealHand(Deck &d, Player &p, int numCards) {
    for (int i = 0; i < numCards; i++)
        p.addCard(d.dealCard());
}


