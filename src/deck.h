#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <vector>
#include <random>

using std::vector;
using std::cout;


class deck {
    public:
    deck() {
        cards = vector<card>();
    }

    deck(int num_face, int num_suit) {
        for (int f = 2; f < num_face + 2; f++) {
            for (int s = 0; s < num_suit; s++) {
                cards.push_back(card(f, s));
            }
        }
    }

    // pull a new card from the top of the deck
    card& pull() {
        // cout << "before pull: " << cards.size() << "\n";
        card res = cards[cards.size() - 1];
        cards.pop_back();
        // cout << "after pull: " << cards.size() << "\n";
        return res;
    }

    // add a pool of won cards to the deck
    void add_cards(const vector<card> &pool) {
        cards.insert(cards.begin(), pool.begin(), pool.end());
    }

    // return number of cards in deck
    int size () {return cards.size();}

    // randomize the order of the cards in the deck
    void shuffle() {
        int num_to_sample = cards.size();
        card c;
        while (num_to_sample > 1) { // do not need to sample final time
            int index = cards.size() - num_to_sample;
            double d_s = num_to_sample * (std::rand() / (RAND_MAX + 1.0));
            int s = index + d_s;
            // cout << cards[index] << " - " << cards[s] << "\n"; 
            if (index != s) {
                c = cards[index];
                cards[index] = cards[s];
                cards[s] = c;
            }
            // cout << cards[index] << " - " << cards[s] << "\n\n"; 
            // cout << index << " swaps with " << s << " (" << d_s << ", " << sample << ")" << "\n";
            num_to_sample--;
        }
    }

    // returns a new deck consisting of n cards from the top??? of the deck
    // removing them from the original deck
    deck split(int n) {
        // cout << "take top " << n << "\n";
        vector<card> top_split(std::make_move_iterator(cards.end() - n), 
            std::make_move_iterator(cards.end()));
        // cout << "top size " << top_split.size() << "\n";
        cards.erase(cards.end() - n, cards.end());
        // cout << "main size " << cards.size() << "\n";
        deck res = deck();
        res.cards = top_split;
        return res;
    }

    // return the sum of all card vvalues in hand - treating face cards as having increasing value
    int sum() const {
        int s = 0;
        for (auto card : cards) {
            s += card.getFace();
        }
        return s;
    }

    friend std::ostream& operator<<(std::ostream& out, const deck& d);

    private:
    // deck is represented from bottom to top like a vector implemented queue
    vector<card> cards;
};

std::ostream& operator<<(std::ostream& out, const deck& d)
{
    out << "\nSize of deck: " << d.cards.size() << "\n";
    out << "Sum of deck: " << d.sum() << "\n";
    int card_num = 1;
    for (auto c : d.cards) {
        out << card_num << ". " << c << "\n";
        card_num++;
    }
    return out << "\n";
}

#endif