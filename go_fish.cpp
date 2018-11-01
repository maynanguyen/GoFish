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




    int main( )
    {
        Deck d;
        //d.shuffle();
        Card c1(2,(Card::spades));
        cout<< c1 << endl;
        cout << "Rank: " << c1.getRank() << endl;

        Card c2 = d.dealCard();
        cout << "deal test " << c2 << endl;
        Card c3 = d.dealCard();
        cout << "deal test " << c3 << endl;
        Card c4 = d.dealCard();
        cout << "deal test " << c4 << endl;


      //  cout << endl;

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



    void dealHand(Deck &d, Player &p, int numCards)
    {
        for (int i=0; i < numCards; i++)
            p.addCard(d.dealCard());
    }
