/*----
  cpp file for Gambala

  by: Mikey
  last modified: 2021-10-13
----*/

#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include "Gambala.h"
#include "games/dice/diceRules.h"
#include "games/dice/diceGame.h"
#include "games/cards/blackJack/blackJackGame.h"
#include "games/cards/blackJack/Card.h"
#include "games/cards/blackJack/Deck.h"

using namespace std;


void Gambala() {
  int balance;
  string playerName;
  int bettingAmount;
  int game_choice;
  char ch;
  srand(time(0));

  ifstream in_stream;
  ofstream out_stream;

  //Checking if you have the three necessary txt files.
  //=================================================
  in_stream.open("user.txt");
  if(!in_stream) {
    out_stream.open("user.txt");
    cout << "========== Gambala ==========" << endl;
    cout << "Welcome to Gambala you lucky ducky! What is thy name??" << endl;
    getline(cin, playerName);
    out_stream << playerName;
    out_stream.close();
  }
  else {
    in_stream >> playerName;
  }
  in_stream.close();

  in_stream.open("balance.txt");
  if(!in_stream) {
    out_stream.open("balance.txt");
    balance = 0;
    out_stream << balance;
    out_stream.close();
  }
  in_stream.close();

  in_stream.open("tmp.txt");
  if(!in_stream) {
    out_stream.open("tmp.txt");
    out_stream.close();
  }
  in_stream.close();


  //Decrypter
  //==============
  if(balance != 0) {
    out_stream.open("balance.txt");
    in_stream.open("tmp.txt");
    while(in_stream >> ch) {
      ch = ch - 100;
      out_stream << ch;
    }
    out_stream.close();
    in_stream.close();
  }

  in_stream.open("balance.txt");
  in_stream >> balance;
  in_stream.close();


  if(balance == 0) {
    balance = 50;
    out_stream.open("balance.txt");
    out_stream << balance;
    out_stream.close();
  }


  do {
    in_stream.open("balance.txt");
    in_stream >> balance;
    in_stream.close();
    system("cls");
    cout << "========== Gambala ==========\n";
    cout << "Press 1 to play Dice\n";
    cout << "Press 2 to play Blackjack\n";
    cout << "Press 3 to exit Gambala\n";
    cout << playerName << "'s balance $" << balance << endl;
    cin >> game_choice;
    if(game_choice == 1) {
      diceGame();
    }
    else if(game_choice == 2) {
      blackJackGame();
    }
  }while(game_choice != 3);


  // Encrypter
  //==============================
  in_stream.open("balance.txt");
  if(in_stream) {
    out_stream.open("tmp.txt");
    while(in_stream >> ch) {
      ch = ch+100;
      out_stream << ch;
    }
    in_stream.close();
    out_stream.close();
  }

  out_stream.open("balance.txt");
  in_stream.open("tmp.txt");
  while(in_stream >> ch) {
    out_stream << ch;
  }
  out_stream.close();
  in_stream.close();

};
