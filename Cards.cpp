/*----
  File for class: Cards

  by: Mikey
  last modified: 2021-06-02
----*/

#include <string>
#include "Cards.h"
#include <iostream>

//Constructor
Cards::Cards()
{
    card_numb = 2;
    suit = "Diamond";
}

Cards::Cards(int init_numb, string init_suit, string init_face)
{
    card_numb = init_numb;
    suit = init_suit;
    face = init_face;
}

//Mutators
void Cards::set_numb(int new_numb)
{
    card_numb = new_numb;
}

void Cards::set_suit(string new_suit)
{
    suit = new_suit;
}

void Cards::set_face(string new_face)
{
    face = new_face;
}

//Other Methods
void Cards::display_card() const
{
    cout << "Card number: " << card_numb << endl;
    cout << "Card Suit: " << suit << endl;
    cout << "Card Face: " << face << endl;
}