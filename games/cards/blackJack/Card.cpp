#include <iostream>
#include "Card.h"

Card::Card(Ranks r, Suits s)
{
    this->rank = r;
    this->suit = s;
}

Card::Ranks Card::getRank()
{
    return rank;
}

Card::Suits Card::getSuit()
{
    return suit;
}

int Card::getFaceValue()
{
    if(rank <= TEN)
    {
        return static_cast<int>(rank);
    }
    else if(rank <= KING)
    {
        return 10;
    }
    else
    {
        return 11;
    }
}

void Card::test()
{
    if(rank <= TEN)
    {
    std::cout << rank;
    } 
    else if(rank == JACK)
    {
        std::cout << "Jack";
    }
    else if(rank == QUEEN)
    {
        std::cout << "Queen";
    }
    else if(rank == KING)
    {
        std::cout << "King";
    }
    else
    {
        std::cout << "Ace";
    }

    if(suit == HEARTS)
    {
        std::cout << " Hearts";
    }
    else if(suit == DIAMONDS)
    {
        std::cout << " Diamond";
    }
    else if(suit == CLUBS )
    {
        std::cout << " Clubs";
    }
    else
    {
        std::cout << " Spades";
    }
}