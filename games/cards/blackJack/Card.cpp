#include <iostream>
#include "Card.h"

Card::Card(Ranks RANK, Suits SUIT)
        : Rank(RANK),
        Suit(SUIT)
{

}

Card::Ranks Card::getRank()
{
    return Rank;
}

Card::Suits Card::getSuit()
{
    return Suit;
}

int Card::getFaceValue()
{
    if(Rank <= TEN)
        return static_cast<int>(Rank);

    if(Rank <= KING)
        return 10;
    

    return 11;
}

void Card::test()
{
    if(Rank <= TEN)
    {
    std::cout << Rank;
    } 
    else if(Rank == JACK)
    {
        std::cout << "Jack";
    }
    else if(Rank == QUEEN)
    {
        std::cout << "Queen";
    }
    else if(Rank == KING)
    {
        std::cout << "King";
    }
    else
    {
        std::cout << "Ace";
    }

    if(Suit == HEARTS)
    {
        std::cout << "Hearts";
    }
    else if(Suit == DIAMONDS)
    {
        std::cout << "Diamond";
    }
    else if(Suit == CLUBS )
    {
        std::cout << "Clubs";
    }
    else
    {
        std::cout << "Spades";
    }
}