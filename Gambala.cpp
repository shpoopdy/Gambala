/*----
  File for function: Gambala

  by: Mikey
  last modified: 2021-06-01

  To compile, type the following into the terminal:
  g++ diceRules.cpp diceGame.cpp Gambala.cpp -o Gambala

  To run, type:
  ./Gambala
----*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "diceGame.h"
using namespace std;


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

  ifstream in_stream;
  in_stream.open("balance.txt");
  if(in_stream)
  {
    in_stream >> balance;
    in_stream.close();
  }
  else
  {
    balance = 0;
    ofstream out_stream;
    out_stream.open("balance.txt");
    out_stream << balance << endl;
    out_stream.close();
  }


  if(balance == 0)
  {
    cout << "HO HO! A fine name indeed. As a matter of fact, I like that name "
         << "sooo much I'm gonna give you $100 to get you started!" << endl;
    balance = 100;
    ofstream out_stream;
    out_stream.open("balance.txt");
    out_stream << balance << endl;
    out_stream.close();
  }
  else
  {
    cout << "HO HO! A fine name indeed my friend, OH! Looks like you have $"
         << balance << "...care to gamble a little??" << endl;
  }


  cout << "When you're ready press 1 to play dice. " << endl;
  cin >> test;

  if(test == 1)
  {
    diceGame();
  }


};


int main()
{
    Gambala();



    return EXIT_SUCCESS;
}
