/* Header file for Card class

By: Mikey
Last modified: 2021-06-19
 */

#ifndef CARD_H
#define CARD_H

#include <string>
#include <vector>

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

        Card(Ranks r, Suits s);

        Ranks getRank();
        Suits getSuit();

        int getValue();

        void test();
    private:
        Ranks rank;
        Suits suit;
};


class Hand
{

    // Field
    private: 
        std::vector<Card> hand;
        int countAces = 0;

    // Methods
    public:
        std::vector<Card> getVecHand();
        void add(Card c);
        void clear();
        int getTotal() const;
        void display_hand() const;
};


#endif