/* cpp file for dice

By: Mikey
Last modified: 2021-06-01
*/


#include <iostream>
//# include <string> was causing an ambiguity error.
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "diceRules.h"
#include "diceGame.h"

using namespace std;

void diceGame()
{
  int balance;
  int bettingAmount;
  int guess;
  string playerName;
  char choice;
  bool playing;
  int dice;
  ifstream in_stream;
  in_stream.open("balance.txt");
  in_stream >> balance;
  in_stream.close();

  

  do
  {
    diceRules();
    cout << "Your current balance is $" << balance << endl;
    cout << endl;

    do
    {
      cout << "Enter your bet ";
      cin >> bettingAmount;
      if(bettingAmount > balance)
      {
        cout << "That's more than what ya got! Try being a little reasonable" << endl;
      }
    }while(bettingAmount > balance);

    do
    {
      cout << "Go ahead and pick a number from 1 to 10: ";
      cin >> guess;

      if(guess <= 0 || guess > 10)
      {
        cout << "Please follow the rules and choose a correct number." << endl;
      }
    }while(guess <= 0 || guess > 10);

    dice = rand() % 10 + 1;
    if(dice == guess)
    {
      cout << "Correct! You've won $" << bettingAmount * 10 << "!" << endl;
      balance = balance + bettingAmount * 10;
    }
    else
    {
      cout << "Looks like you've guess wrong. You lost $" << bettingAmount << "." << endl;
      balance = balance - bettingAmount;
    }

    cout << "The correct number was " << dice << "." << endl;
    cout << "Ok, " << playerName << " your balance is $" << balance << endl;

    if(balance == 0)
    {
      cout << "Seems that you aren't as lucky as you lead me to believe." << endl;
      ofstream out_stream;
      out_stream.open("balance.txt");
      out_stream << balance << endl;
      out_stream.close();
      break;
    }
    

    cout << "Would you like to play again (y/n)?" 
         << " If you don't select either I'll just take it as a yes...";
    cin >> choice;

    if((choice == 'y') || (choice == 'Y'))
    {
      playing = true;
    }
    else if((choice == 'n') || (choice == 'N'))
    {
      ofstream out_stream;
      out_stream.open("balance.txt");
      out_stream << balance << endl;
      out_stream.close();
      playing = false;
    }
    
    
  }while(playing); //Something happening here that even when I select something other then y it would still loop.

  
}