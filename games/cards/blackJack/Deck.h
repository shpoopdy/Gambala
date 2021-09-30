#ifndef DECK_H
#define DECK_H

#include <deque>
#include "Card.h"

class Deck {
    public:
        Deck();
        ~Deck();

        void testPrint();
        void Shuffle();

        Card* TopCard();
        void PopCard();
        void sizeTest();
    private:
        std::deque<Card*> deck;
};

#endif
