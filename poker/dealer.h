#ifndef dealh
#define dealh

class Player;

class Dealer {
private:
    int Card;
public:
    void GetCard(int index, int card[]);

    void DealCard(Player &P, int index);

    void CheckPlayer(Player &P);

    void DetermineWinner(Player &P1, Player &P2);

    void Totals(Player &P1, Player &P2);

    int StraightFlush(Player &P);

    int FourOfAKind(Player &P);

    int FullHouse(Player &P);

    int Flush(Player &P);

    int Straight(Player &P);

    int ThreeOfAKind(Player &P);

    int TwoPairsOfCards(Player &P);

    int OnePairOfCards(Player &P);

    int HighestCardInHand(Player &P);
};

#endif