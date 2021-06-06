/* cpp file for blackJackGame

By: Mikey
Last modified: 2021-06-05
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



      player.push_back(card_ptr[randomOne]);
      player.push_back(card_ptr[randomTwo]);

      cout << player[0].get_numb() << endl;
      cout << player[1].get_numb() << endl;
      getchar();

      do
      {
        cout << "Enter your bet ";
        cin >> bettingAmount;
        if(bettingAmount > balance)
        {
          cout << "That's more than what ya got! Try being a little reasonable" << endl;
        }
      }while(bettingAmount > balance);

      cout << "Want to continue?";
      cin >> choice;
      player.clear();

      if((choice == 'y') || (choice == 'Y'))
      {
        playing = true;
      }

    } while(playing);

}
