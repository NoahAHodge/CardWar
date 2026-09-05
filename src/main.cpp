#include <iostream>

#include "card.h"
#include "deck.h"

using std::cout;

int main() {
    
    //will want main deck of actual cards, with split decks with card references
    deck d = deck(12, 4);


    int num_cards = d.size();
    cout << "Deck Before Split: \n";
    cout << d;

    deck d2 = d.split(26);
    cout << "Original Deck After Split: \n";
    cout << d;
    cout << d.pull() << "\n";

    cout << "New Deck After Split: \n";
    cout << d2;

    deck d3 = d2.split(13);

    cout << "New Deck After Split: \n";
    cout << d2;
    cout << d2.pull() << "\n";

    cout << "New New Deck After Split: \n";
    cout << d3;
    cout << d3.pull() << "\n";
}