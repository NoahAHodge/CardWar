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

    deck(int num_face, int num_suit) {
        for (int f = 2; f <= num_face + 2; f++) {
            for (int s = 0; s < num_suit; s++) {
                cards.push_back(card(f, s));
            }
        }
    }

    // pull a new card from the top of the deck
    card& pull() {
        card res = cards[cards.size() - 1];
        cards.pop_back();
        return res;
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