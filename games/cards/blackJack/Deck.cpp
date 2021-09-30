/* cpp file for Deck

By: Mikey
Last modified: 2021-09-29
*/

#include "Deck.h"
#include <iostream>
#include <algorithm>

Deck::Deck()
    : deck() {
    for(Card::Ranks r=Card::ACE; r <= Card::KING; r = static_cast<Card::Ranks>(static_cast<int>(r) + 1)) {
        for(Card::Suits s=Card::HEARTS; s <= Card::SPADES; s = static_cast<Card::Suits>(static_cast<int>(s) + 1)) {
            deck.push_back(new Card(r, s));
        }
    }
}

Deck::~Deck() {
    for(Card* card : deck) {
        delete card;
    }
    deck.clear();
}

void Deck::testPrint() {
    for(Card* card : deck) {
        card->test();
        std::cout << " ";
    }
}

void Deck::Shuffle() {
    std::random_shuffle(deck.begin(), deck.end());
}

Card* Deck::TopCard() {
    return deck.front();
}

void Deck::PopCard() {
    deck.erase(deck.begin());
}

void Deck::sizeTest() {
    std::cout << "Deck size is: " << deck.size();
}
