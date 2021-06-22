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
    int AMOUNT = 52;
    Card *card_ptr = NULL;
    int bettingAmount;
    char choice;
    bool playing = true;
    int balance;
    vector<Card> player;
    vector<Card> dealer;
    ifstream in_stream;
    in_stream.open("balance.txt");
    in_stream >> balance;
    in_stream.close();
    
    
    
    

    do {
      blackJackRules();
      std::cout << "Your current balance is $" << balance << std::endl;
      std::cout << std::endl;
      srand (time (0));
      int hit;
      bool bust = false;
      bool dealerBust = false;
      Deck deck;
      deck.Shuffle();
      




      do
      {
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
        card_ptr = deck.TopCard();
        player.push_back(*card_ptr);
        delete card_ptr;
        deck.PopCard();
        card_ptr = NULL;
      }
    
      
      std::cout << "You have " << player[0].getFaceValue() << " and ";
      std::cout << player[1].getFaceValue() << endl;
      playerTotal = player[0].getFaceValue() + player[1].getFaceValue();

      card_ptr = deck.TopCard();
      dealer.push_back(*card_ptr);
      delete card_ptr;
      deck.PopCard();
      card_ptr = NULL;

      std::cout << "Dealer has a " << dealer[0].getFaceValue() << "." << std::endl;
      dealerTotal += dealer[0].getFaceValue();
      




      do {
        int loopRand = rand() % 52;
        cout << "Your total is " << playerTotal << "." << endl;
        cout << "Press 1 for another card or 2 to stay: ";
        std::cin >> hit;
        if(hit == 1)
        {
          card_ptr = deck.TopCard();
          cout << "You received a " << card_ptr->getFaceValue() << "!\n";
          player.push_back(*card_ptr);
          playerTotal += card_ptr->getFaceValue();
          if(playerTotal > 21)
          {
            cout << "Oof, looks like you bust son." << endl;
            bust = true;
          }
          delete card_ptr;
          card_ptr = NULL;
        }
        else if(hit == 2)
        {
          card_ptr = deck.TopCard();
          do {
            cout << "Dealer received a " << card_ptr->getFaceValue() << "!\n";
            dealer.push_back(*card_ptr);
            dealerTotal += card_ptr->getFaceValue();
            cout << "Dealer total is " << dealerTotal << "." << endl;
            

            if(dealerTotal > 21)
            {
              cout << "Dealer has bust!" << endl;
              dealerBust = true;
            }
          }while(dealerTotal < 17 && dealerBust == false);
        }
      }while(hit == 1 && bust == false);

      if(bust == true)
      {
        cout << "Sorry, but you bust. You lost $" << bettingAmount << ".\n";
        balance -= bettingAmount;
      }
      else if(dealerBust == true)
      {
        cout << "Dealer bust! You've won $" << bettingAmount * 3 << ".\n";
        balance = balance + (bettingAmount * 3);
      }
      else if(playerTotal > dealerTotal)
      {
        cout << "You won with " << playerTotal << "! "
             << "You've earned $" << bettingAmount * 3 << ".\n";
        balance = balance + (bettingAmount * 3);
      }
      else
      {
        cout << "House wins! Sorry, but you've lost $" << bettingAmount << ".\n";
        balance -= bettingAmount;
      }


      cout << "To continue enter y, otherwise any key will take you out:  ";
      std::cin >> choice;
      player.clear();
      dealer.clear();

      if((choice == 'y') || (choice == 'Y'))
      {
        playing = true;
      }
      else
      {
        ofstream out_stream;
        out_stream.open("balance.txt");
        out_stream << balance << endl;
        out_stream.close();
        delete card_ptr;
        card_ptr = NULL;
        playing = false;
      }

    }while(playing);

}
