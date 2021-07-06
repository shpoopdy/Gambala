/* cpp file for blackJackGame

By: Mikey
Last modified: 2021-06-18
*/


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include "blackJackRules.h"
#include "blackJackGame.h"
#include "Card.h"
#include "Deck.h"

void blackJackGame()
{
    Card *card_ptr = NULL;
    int bettingAmount;
    char choice;
    bool playing = true;
    int balance;
    Hand player;
    Hand dealer;
    std::ifstream in_stream;
    in_stream.open("balance.txt");
    in_stream >> balance;
    in_stream.close();
    
    
    
    

    do {
      blackJackRules();
      std::cout << "Your current balance is $" << balance << std::endl;
      std::cout << std::endl;
      srand (time (0));
      int hit;
      bool playerBust = false;
      bool dealerBust = false;
      bool hasAce = false;
      Deck deck;
      deck.Shuffle();
      




      do
      {
        //Check to make sure they have enough funds.
        std::cout << "Enter your bet ";
        std::cin >> bettingAmount;
        if(bettingAmount > balance)
        {
          std::cout << "That's more than what ya got! Try being a little reasonable" << std::endl;
        }
      }while(bettingAmount > balance);


      int playerTotal = 0;
      int dealerTotal = 0;
      for(int i = 0; i < 2; i++)
      {
        //Deals two cards to the player.
        card_ptr = deck.TopCard();
        player.add(*card_ptr);
        delete card_ptr;
        deck.PopCard();
        card_ptr = NULL;
      }
    
      std::cout << "You have "; player.display_hand();

      card_ptr = deck.TopCard();
      dealer.add(*card_ptr);
      deck.PopCard();
      

      std::cout << " Dealer has a "; card_ptr->test();
      std::cout << ".\n";
      delete card_ptr;
      card_ptr = NULL;
      //dealerTotal = dealer.getTotal();
      




      do {
        std::cout << "Your total is " << player.getTotal() << ".\n";
        std::cout << "Press 1 for another card or 2 to stay: ";
        std::cin >> hit;
        if(hit == 1)
        {
          card_ptr = deck.TopCard();
          std::cout << "You received a ";
          card_ptr->test();
          std::cout << std::endl;
          player.add(*card_ptr);
          //playerTotal = player.getTotal();
          deck.PopCard();
          if(player.getTotal() > 21)
          {
            std::cout << "Oof, looks like you bust son.\n";
            playerBust = true;
          }
          delete card_ptr;
          card_ptr = NULL;
        }
        else if(hit == 2)
        {
          do {
            card_ptr = deck.TopCard();
            std::cout << "Dealer received a ";
            card_ptr->test();
            dealer.add(*card_ptr);
            //dealerTotal = dealer.getTotal();
            deck.PopCard();
            std::cout << std::endl;
            std::cout << "Dealer total is " << dealer.getTotal() << ".\n";
            

            if(dealer.getTotal() > 21)
            {
              std::cout << "Dealer has bust!\n";
              dealerBust = true;
            }
            delete card_ptr;
            card_ptr = NULL;
          }while(dealer.getTotal() < 17 && dealerBust == false);
        }
      }while(hit == 1 && playerBust == false);

      if(playerBust == true)
      {
        std::cout << "Sorry, but you bust. You lost $" << bettingAmount << ".\n";
        balance -= bettingAmount;
      }
      else if(dealerBust == true)
      {
        std::cout << "Dealer bust! You've won $" << bettingAmount * 2 << ".\n";
        balance = balance + (bettingAmount * 2);
      }
      else if(player.getTotal() > dealer.getTotal())
      {
        std::cout << "You won with " << player.getTotal() << "! "
             << "You've earned $" << bettingAmount * 2 << ".\n";
        balance = balance + (bettingAmount * 2);
      }
      else if(player.getTotal() == dealer.getTotal())
      {
        std::cout << "It's a push! You get your money back.";
      }
      else
      {
        std::cout << "House wins! Sorry, but you've lost $" << bettingAmount << ".\n";
        balance -= bettingAmount;
      }


      std::cout << "To continue enter y, otherwise any key will take you out:  ";
      std::cin >> choice;
      player.clear();
      dealer.clear();

      if(balance == 0)
      {
        std::cout << "Looks like you've reached your end..." << std::endl;
        playing = false;
      }
      else if((choice == 'y') || (choice == 'Y'))
      {
        playing = true;
      }
      else
      {
        std::ofstream out_stream;
        out_stream.open("balance.txt");
        out_stream << balance << std::endl;
        out_stream.close();
        delete card_ptr;
        card_ptr = NULL;
        playing = false;
      }

    }while(playing);

}