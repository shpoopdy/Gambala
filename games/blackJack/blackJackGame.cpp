/* cpp file for blackJackGame

By: Mikey
Last modified: 2021-09-29
*/
// Could make the check for bust by placing them in the Hand Class

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include "blackJackRules.h"
#include "blackJackGame.h"
#include "../cards/Card.h"
#include "../cards/Deck.h"

void blackJackGame() {
    Card *card_ptr = NULL;
    int bettingAmount;
    char choice;
    bool playing = true;
    int balance;
    Hand player;
    Hand dealer;
    int hit;
    bool playerBust = false;
    bool dealerBust = false;
    bool hasAce = false;
    std::ifstream in_stream;
    in_stream.open("balance.txt");
    in_stream >> balance;
    in_stream.close();

    // This displays your current balance and rules in terminal
    do {
      blackJackRules();
      std::cout << "Your current balance is $" << balance << std::endl;
      std::cout << std::endl;
      srand (time (0));
      Deck deck;
      deck.Shuffle();

      //Check to make sure they have enough funds.
      do {
        std::cout << "Enter your bet $";
        std::cin >> bettingAmount;
        if(bettingAmount > balance)
        {
          std::cout << "That's more than what ya got! Try being a little reasonable \n";
        }
      }while(bettingAmount > balance);

      // Maybe make deal a function in Card class
      // have it called dealBlackJack.
      // Deals two cards to the player
      for(int i = 0; i < 2; i++) {
        card_ptr = deck.TopCard();
        player.add(*card_ptr);
        delete card_ptr;
        deck.PopCard();
        card_ptr = NULL;
      }

      std::cout << "You have "; player.display_hand();

      // Maybe I can make this a draw card function
      card_ptr = deck.TopCard();
      dealer.add(*card_ptr);
      deck.PopCard();
      std::cout << std::endl;

      std::cout << "Dealer has a "; card_ptr->cardDisplay();
      std::cout << ".\n";
      delete card_ptr;
      card_ptr = NULL;

      // Hit or pass phase
      do {
        std::cout << "Your total is " << player.getTotal() << ".\n";
        std::cout << "Press 1 for another card or 2 to stay: ";
        std::cin >> hit;
        if(hit == 1) {
          card_ptr = deck.TopCard();
          std::cout << "You received a ";
          card_ptr->cardDisplay();
          std::cout << std::endl;
          player.add(*card_ptr);
          deck.PopCard();
          if(player.getTotal() > 21) {
            std::cout << "Oof, looks like you bust son.\n";
            playerBust = true;
          }
          delete card_ptr;
          card_ptr = NULL;
        }
        else if(hit == 2) {
          do {
            card_ptr = deck.TopCard();
            std::cout << "Dealer received a ";
            card_ptr->cardDisplay();
            dealer.add(*card_ptr);
            deck.PopCard();
            std::cout << std::endl;
            std::cout << "Dealer total is " << dealer.getTotal() << ".\n";


            if(dealer.getTotal() > 21) {
              std::cout << "Dealer has bust!\n";
              dealerBust = true;
            }
            delete card_ptr;
            card_ptr = NULL;
          }while(dealer.getTotal() < 17 && dealerBust == false);
        }
      }while(hit == 1 && playerBust == false);

      if(playerBust == true) {
        std::cout << "Sorry, but you bust. You lost $" << bettingAmount << ".\n";
        balance -= bettingAmount;
      }
      else if(dealerBust == true) {
        std::cout << "Dealer bust! You've won $" << bettingAmount * 2 << ".\n";
        balance += bettingAmount * 2;
      }
      else if(player.getTotal() > dealer.getTotal()) {
        std::cout << "You won with " << player.getTotal() << "! "
             << "You've earned $" << bettingAmount * 2 << ".\n";
        balance += bettingAmount * 2;
      }
      else if(player.getTotal() == dealer.getTotal()) {
        std::cout << "It's a push! You get your money back.";
      }
      else {
        std::cout << "House wins! Sorry, but you've lost $" << bettingAmount << ".\n";
        balance -= bettingAmount;
      }


      if(balance == 0) {
        std::cout << "Looks like you've reached your end..." << std::endl;
        playing = false;
      }
      else {
        std::cout << "To continue enter y, otherwise any key will take you out:  ";
        std::cin >> choice;
        player.clear();
        dealer.clear();
        if((choice == 'y') || (choice == 'Y')) {
          playing = true;
        }
        else {
          std::ofstream out_stream;
          out_stream.open("balance.txt");
          out_stream << balance << std::endl;
          out_stream.close();
          delete card_ptr;
          card_ptr = NULL;
          playing = false;
        }
      }
    }while(playing);
}
