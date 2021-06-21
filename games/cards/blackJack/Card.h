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
            HEARTS = 3,
            DIAMONDS,
            CLUBS,
            SPADES
        };

        enum Ranks
        {
            TWO = 2,
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
            ACE
        };

        Card(Ranks RANK, Suits SUIT);

        Ranks getRank();
        Suits getSuit();

        int getFaceValue();

        void test();
    private:
        Ranks Rank;
        Suits Suit;
};


#endif