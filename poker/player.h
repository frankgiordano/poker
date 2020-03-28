#ifndef playh
#define play

class Dealer;

class Player {
private:
    int ID;
    int howManyGamesWon;
    int playerSuit[5];
    int playerValue[5];
    // 1 = highest card in hand option , 2 = has one pair of cards,
    // 3 = has two pairs of cards, 4 = has a three of a kind,
    // 5 = has a straight, 6 = has a flush, 7 = has a full house,
    // 8 = has a four of a Kind, 9 = has a straight flush
    int whatRank;
    int itsThreeOfAKind;
    int itsPair1;
    int itsPair2;
    int itsStraight;
    int itsStraightFlush;
    int itsFlush;
    int itsFourOfAKind;
    int valueHand; // this holds the value of the hand if option 1 of whatRank is on
public:
    Player(int newID);

    void Display();

    void Re_initialize();

    friend Dealer;
};

#endif