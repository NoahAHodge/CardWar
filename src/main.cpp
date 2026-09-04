#include <iostream>

#include "card.h"
#include "deck.h"

using std::cout;

int main() {
    
    //will want main deck of actual cards, with split decks with card references
    deck d = deck(12, 4);


    int num_cards = d.size();
    cout << "Size of deck: " << num_cards << "\n";
    cout << "Deck Before Shuffle: \n";
    cout << d;
    d.shuffle();
    cout << "\nDeck After Shuffle: \n";
    cout << d;
    cout << "Size of deck: " << d.size() << "\n";
}