/*----
  File for function: Gambala

  by: Mikey
  last modified: 2021-05-31

  To compile, type the following into the terminal:
  g++ diceRules.cpp diceGame.cpp Gambala.cpp -o Gambala

  To run, type:
  ./Gambala
----*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "diceGame.h"
using namespace std;

void rules()
{
  system("cls");
  cout << "========== Dice Game Rules ==========" << endl;
  cout << "1. Choose a number from 1 to 10." << endl;
  cout << "2. If ya win, you get 10 times what ya bet!" << endl;
  cout << "3. If ya lose though, well that's just how it goes." << endl;
  getchar(); //To give the player time to read the rules.
}

void Gambala()
{
  int balance;
  int guess;
  string playerName;
  int bettingAmount;
  int dice;
  char choice;
  int test;
  srand(time(0));

  cout << "========== Gambala ==========" << endl;
  cout << "Welcome to Gambala you lucky ducky! What is thy name??" << endl;
  getline(cin, playerName);
  cout << "HO HO! A fine name indeed. As a matter of fact, I like that name "
       << "sooo much I'm gonna give you $100 to get you started!" << endl;
  balance = 100;

  cout << "When you're ready press 1 to play dice. " << endl;
  cin >> test;

  if(test == 1)
  {
    diceGame();
  }
};

/*
  do
  {
    rules();
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
      break;
    }

    cout << "Would you like to play again (y/n)?";
    cin >> choice;
  }while(choice == 'y' || 'Y');
  
  if(balance == 0)
  {
    cout << "Not a good night it seems, sorry..." << endl;
  }
  else
  {
    cout << "I hope you enjoyed your time. You had a balance of $" << balance;
  }

  
}
*/



int main()
{
    Gambala();

    

    return EXIT_SUCCESS;
}
