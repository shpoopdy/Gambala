/*----
  File for function: Gambala

  by: Mikey
  last modified: 2021-06-01

  To compile, type the following into the terminal:
  g++ games/dice/diceRules.cpp games/dice/diceGame.cpp games/cards/blackJack/blackJackRules.cpp games/cards/blackJack/blackJackGame.cpp games/cards/blackJack/Card.cpp games/cards/blackJack/Deck.cpp Gambala.cpp -o Gambala

  To run, type:
  ./Gambala
----*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "games/dice/diceRules.h"
#include "games/dice/diceGame.h"
#include "games/cards/blackJack/blackJackGame.h"
#include "games/cards/blackJack/Card.h"
#include "games/cards/blackJack/Deck.h"
using namespace std;


void Gambala()
{
  int balance;
  int guess;
  string playerName;
  int bettingAmount;
  int game_choice;
  char ch;
  srand(time(0));

  cout << "========== Gambala ==========" << endl;
  cout << "Welcome to Gambala you lucky ducky! What is thy name??" << endl;
  getline(cin, playerName);

  ifstream in_stream;
  ofstream out_stream;


  //Checking if you have the two necessary txt files.
  //=================================================
  in_stream.open("balance.txt");
  if(!in_stream)
  {
    out_stream.open("balance.txt");
    balance = 0;
    out_stream << balance;
    out_stream.close();
  }
  in_stream.close();

  in_stream.open("tmp.txt");
  if(!in_stream)
  {
    out_stream.open("tmp.txt");
    out_stream.close();
  }
  in_stream.close();


  //Decrypter
  //==============
  if(balance != 0)
  {
    out_stream.open("balance.txt");
    in_stream.open("tmp.txt");
    while(in_stream >> ch)
    {
      ch = ch - 100;
      out_stream << ch;
    }
    out_stream.close();
    in_stream.close();
  }

  in_stream.open("balance.txt");
  in_stream >> balance;
  in_stream.close();


  if(balance == 0)
  {
    cout << "HO HO! A fine name indeed. As a matter of fact, I like that name "
         << "sooo much I'm gonna give you $100 to get you started!" << endl;
    balance = 100;
    out_stream.open("balance.txt");
    out_stream << balance << endl;
    out_stream.close();
  }
  else
  {
    cout << "HO HO! A fine name indeed my friend, OH! Looks like you have $"
         << balance << "...care to gamble a little??" << endl;
  }


  do {
    in_stream.open("balance.txt");
    in_stream >> balance;
    in_stream.close();
    cout << "To play Dice enter 1, enter 2 for Blackjack. "
         << "If you'd like to leave then enter 3: ";
    cin >> game_choice;
    if(game_choice == 1)
    {
      diceGame();
    }
    else if(game_choice == 2)
    {
      blackJackGame();
    }
  }while(game_choice != 3);


  // Encrypter
  //==============================
  in_stream.open("balance.txt");
  if(in_stream)
  {
    out_stream.open("tmp.txt");
    while(in_stream >> ch)
    {
      ch = ch+100;
      out_stream << ch;
    }
    in_stream.close();
    out_stream.close();
  }

  out_stream.open("balance.txt");
  in_stream.open("tmp.txt");
  while(in_stream >> ch)
  {
    out_stream << ch;
  }
  out_stream.close();
  in_stream.close();

};


int main()
{
    Gambala();



    return EXIT_SUCCESS;
}
