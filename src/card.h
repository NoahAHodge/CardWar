#ifndef CARD_H
#define CARD_H

enum Suit {clubs, spades, hearts, diamonds}; 
enum Face {Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace};

class card {
    public:
    
    card() {}
    card(int face, int suit) : face(face), suit(suit) {}
    
    int getSuit() { return suit; }
    int getFace() {return face; }

    private:
    int     face; // 2 - 13 (11 - jack, 12 - queen, 13 - king, 14 - ace)
    int     suit; // 0 - clubs, 1 - spades, 2 - hearts, 3 - diamonds
};

#endif
