/* Header file for Card class

By: Mikey
Last modified: 2021-06-19
 */

#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

class Card 
{
    public:
        enum Suits
        {
            HEARTS,
            DIAMONDS,
            CLUBS,
            SPADES
        };

        enum Ranks
        {
            ACE = 1,
            TWO,
            THREE,
            FOUR,
            FIVE,
            SIX,
            SEVEN,
            EIGHT,
            NINE,
            TEN,
            JACK,
            QUEEN,
            KING,
        };

        Card(Ranks RANK, Suits SUIT);

        Ranks getRank();
        Suits getSuit();

        int getFaceValue();

        void test();
    private:
        Ranks rank;
        Suits suit;
};


#endif