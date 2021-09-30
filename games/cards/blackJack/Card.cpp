#include <iostream>
#include <vector>
#include "Card.h"

Card::Card(Ranks r, Suits s) {
    this->rank = r;
    this->suit = s;
}

Card::Ranks Card::getRank() {
    return rank;
}

Card::Suits Card::getSuit() {
    return suit;
}

int Card::getValue() {
    if(rank <= TEN) {
        return static_cast<int>(rank);
    }
    else if(rank <= KING) {
        return 10;
    }
}

void Card::cardDisplay() {
    if(rank == ACE) {
        std::cout << "Ace";
    }
    else if(rank <= TEN) {
    std::cout << rank;
    }
    else if(rank == JACK) {
        std::cout << "Jack";
    }
    else if(rank == QUEEN) {
        std::cout << "Queen";
    }
    else {
        std::cout << "King";
    }

    if(suit == HEARTS) {
        std::cout << " of Hearts";
    }
    else if(suit == DIAMONDS) {
        std::cout << " of Diamonds";
    }
    else if(suit == CLUBS ) {
        std::cout << " of Clubs";
    }
    else {
        std::cout << " of Spades";
    }
}

/////////////////////////////////////////////////////

// Hand

void Hand::add(Card c) {
    if (c.getRank() == 1) {
        this->countAces++;
    }

    hand.push_back(c);
};

void Hand::clear() {
    (this->countAces) = 0;
    (this->hand).clear();
};

int Hand::getTotal() const {
    std::vector<Card> h = this->hand;

    int total = 0;
    for (Card card: h) {
        total += card.getValue();
    }

    int countA = this->countAces;

    while (total != 21 && countA > 0) {
        // Make aces count for 11 instead of 1
        if (total <= 11) {
            total += 10;
            countA -= 1;
        }
        else {
            break;
        }
    }

    return total;
};

std::vector<Card> Hand::getVecHand() {
    return this->hand;
}

void Hand::display_hand() const {
    for(int i = 0; i < hand.size(); i++) {
        Card cardCopy = hand[i];
        cardCopy.cardDisplay();
        if(i == 0) {
            std::cout << " and a ";
        }
        else {
            std::cout << "!";
        }

    }
}
