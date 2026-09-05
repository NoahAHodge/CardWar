#include <iostream>

#include "card.h"
#include "deck.h"

using std::cout;

int main() {
    
    //will want main deck of actual cards, with split decks with card references
    deck d = deck(12, 4);


    int num_cards = d.size();
    cout << "Size of deck: " << num_cards << "\n";
    cout << "Deck Before Split: \n";
    cout << d;

    deck d2 = d.split(26);
    cout << "\nSize of deck: " << d.size() << "\n";
    cout << "Original Deck After Split: \n";
    cout << d;

    cout << "\nSize of new deck: " << d2.size() << "\n";
    cout << "New Deck After Split: \n";
    cout << d2;

    deck d3 = d2.split(13);

    cout << "\nSize of new deck: " << d2.size() << "\n";
    cout << "New Deck After Split: \n";
    cout << d2;

    cout << "\nSize of new new deck: " << d3.size() << "\n";
    cout << "New New Deck After Split: \n";
    cout << d3;
}