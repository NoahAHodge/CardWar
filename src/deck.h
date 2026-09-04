#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <vector>
using std::vector;

class deck {
    public:
    deck() {
        cards = vector<card>();
    }

    // pull a new card from the top of the deck
    card& pull() {
        return cards.pop_back();
    }

    // add a pool of won cards to the deck
    void add_cards(const vector<card> &pool) {
        cards.insert(cards.begin(), pool.begin(), pool.end());
    }

    // return number of cards in deck
    int size () {return cards.size();}

    private:
    // deck is represented from bottom to top like a vector implemented queue
    vector<card> cards;
};

#endif