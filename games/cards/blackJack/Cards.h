/* Header file for Card class

By: Mikey
Last modified: 2021-06-02
 */

#ifndef CARDS_H
#define CARDS_H

#include <string>
using namespace std;

class Cards
{
    public:
        //Constructor
        Cards();

        Cards(int init_numb, string init_suit, string init_face);

        //Accessors
        int get_numb() const;

        //Mutators
        void set_numb(int new_numb);
        void set_suit(string new_suit);
        void set_face(string new_face);

        //Other Methods
        void display_card() const;

    private:
        int card_numb;
        string suit;
        string face;
};

#endif
