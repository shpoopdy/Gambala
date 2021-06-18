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
#include "Cards.h"

void blackJackGame()
{
    int AMOUNT = 52;
    Cards *card_ptr = NULL;
    int bettingAmount;
    char choice;
    card_ptr = new Cards[AMOUNT];
    bool playing = true;
    int balance;
    vector<Cards> player;
    vector<Cards> dealer;
    ifstream in_stream;
    in_stream.open("balance.txt");
    in_stream >> balance;
    in_stream.close();
    in_stream.open("Cards.txt");
    for(int i = 0; i < AMOUNT; i++)
    {
        int temp_int;
        string first;
        string next;
        in_stream >> temp_int;
        in_stream >> first;
        in_stream >> next;

        card_ptr[i].set_numb(temp_int);
        card_ptr[i].set_suit(first);
        card_ptr[i].set_face(next);
    }

    in_stream.close();

    do {
      blackJackRules();
      cout << "Your current balance is $" << balance << endl;
      cout << endl;
      srand (time (0));
      int randomOne = rand() % 52;
      int randomTwo = rand() % 52;
      int randomThree = rand() % 52;
      int hit;
      bool bust = false;
      bool dealerBust = false;




      do
      {
        cout << "Enter your bet ";
        cin >> bettingAmount;
        if(bettingAmount > balance)
        {
          cout << "That's more than what ya got! Try being a little reasonable" << endl;
        }
      }while(bettingAmount > balance);


      int playerTotal = 0;
      int dealerTotal = 0;
      player.push_back(card_ptr[randomOne]);
      player.push_back(card_ptr[randomTwo]);
      dealer.push_back(card_ptr[randomThree]);
      cout << "You have " << player[0].get_numb() << " and ";
      cout << player[1].get_numb() << endl;
      playerTotal = player[0].get_numb() + player[1].get_numb();

      cout << "Dealer has " << dealer[0].get_numb() << "." << endl;
      dealerTotal += dealer[0].get_numb();
      cout << "Dealer total " << dealerTotal << "." << endl;




      do {
        int loopRand = rand() % 52;
        cout << "Your total is " << playerTotal << "." << endl;
        cout << "Press 1 for another card or 2 to stay: ";
        cin >> hit;
        if(hit == 1)
        {
          cout << "You received a " << card_ptr[loopRand].get_numb() << "!\n";
          player.push_back(card_ptr[loopRand]);
          playerTotal += card_ptr[loopRand].get_numb();
          if(playerTotal > 21)
          {
            cout << "Oof, looks like you bust son." << endl;
            bust = true;
          }
        }
        else if(hit == 2)
        {
          do {
            int dealLoop = rand() % 52;
            cout << "Dealer received a " << card_ptr[dealLoop].get_numb() << "!\n";
            dealer.push_back(card_ptr[dealLoop]);
            dealerTotal += card_ptr[dealLoop].get_numb();
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
      cin >> choice;
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
