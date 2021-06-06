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
    card_ptr = new Cards[AMOUNT];
    vector<Cards> player;
    ifstream in_stream;
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
        card_ptr[i].display_card();
    }
    cout << "See?" << endl;
    int test;
    cin >> test;
    in_stream.close();

}
