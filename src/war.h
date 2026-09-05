#ifndef WAR_H
#define WAR_H

#include "card.h"
#include "deck.h"
#include <iostream>

using std::cout;

const int deck_size = 52;
const int num_suits = 4;
const int num_faces = deck_size/num_suits;
const int num_players = 4;
const bool on_interact = false;
const int max_rounds = 10;
const int war_cards = 3;

class war {
    public:

    void go_To_War() {
        for (auto player : player_decks) {
            for (int i = 0; i < war_cards; i++) {
                if (player.size() > 0){
                    pool.push_back(player.pull());
                } 
            }
        }
        run_round();
    }

    void run_round() {
        card c;
        int highest = 0;
        int winner = -1; // code for no winner
        bool tie = false;
        for (int p = 0; p < player_decks.size(); p++) {
            if (player_decks[p].size() > 0){
                c = player_decks[p].pull(); 
                pool.push_back(c); // note - adds cards in order at time added to pool
                // ex) player 1, 2, ... card 1, player 1, 2, ... card 2, ...
                cout << "Player " << p + 1 << " pulls " << c << "\n";
                if (c.getFace() > highest) {
                    // found new highest
                    highest = c.getFace();
                    winner = p;
                } else if (c.getFace() == highest) {
                    winner = -2; // have a tie
                }
            } 
        }
        if (winner == -1) {
            cout << "Error: No Cards Played\n";
        } else if (winner == -2) {
            cout << "Tie! Go to War!"; // tied players can lose to a 3rd party
            // go_To_War();
        } else {
            cout << "Player " << winner+1 << " wins round " << round_num << ".\n\n";
            player_decks[winner].add_cards(pool);
            if (player_decks[winner].size() == 52) 
                finished = true;
            pool.clear();
        }
    }

    war() {
        // create and shuffle deck
        deck main_deck = deck(num_faces, num_suits);
        // cout << main_deck;
        main_deck.shuffle();

        // deal to players
        for (int num_decks = 1; num_decks < num_players; num_decks++) {
            player_decks.push_back(main_deck.split(deck_size/num_players));
            cout << "Player " << num_decks;
            cout << player_decks[num_decks-1];
        }
        player_decks.push_back(main_deck);
        cout << "Player " << num_players;
        cout << player_decks[num_players-1];


        // run rounds
        round_num = 1;
        finished = false;
        while (round_num <= 1 && !finished) {
            cout << "Round " << round_num << "\n";
            run_round();
            for (int i = 0; i < player_decks.size(); i++) {
                cout << "Player " << i;
                cout << player_decks[i];
            }
            round_num++;
        }
    }

    private:
    vector<deck> player_decks;
    vector<card> pool;
    bool finished;
    int round_num;
};

#endif
