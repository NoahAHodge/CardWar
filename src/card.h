#ifndef CARD_H
#define CARD_H

std::string suit_Lookup [4] = {"clubs", "spades", "hearts", "diamonds"}; 
std::string face_Lookup [13] =  {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

class card {
    public:
    
    card() {}
    card(int face, int suit) : face(face), suit(suit) {}
    
    int getSuit() const { return suit; }
    int getFace() const { return face; }

    friend std::ostream& operator<<(std::ostream& out, const card& c);

    private:
    int     face; // 2 - 13 (11 - jack, 12 - queen, 13 - king, 14 - ace)
    int     suit; // 0 - clubs, 1 - spades, 2 - hearts, 3 - diamonds
};

std::ostream& operator<<(std::ostream& out, const card& c)
{
   return out << face_Lookup[c.face - 2] << " of " << suit_Lookup[c.suit];
}

#endif
