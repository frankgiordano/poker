#include "player.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Player::Player(int newID) {
    int i;
    for (i = 0; i < 5; i++) {
        playerSuit[i] = 0;
        playerValue[i] = 0;
    }
    whatRank = -1;
    valueHand = -1;
    ID = newID;
    howManyGamesWon = 0;
    itsThreeOfAKind = 0;
    itsFlush = 0;
    itsPair1 = 0;
    itsPair2 = 0;
    itsStraightFlush = 0;
    itsStraight = 0;
    itsFourOfAKind = 0;
    valueHand = 0;
}

void Player::Re_initialize() {
    whatRank = itsThreeOfAKind = itsPair1 = itsStraightFlush = 0;
    itsPair2 = itsStraight = itsFourOfAKind = valueHand = itsFlush = 0;
}

void Player::Display() {
    int i;
    char nameOfCard[20];

    std::cout << std::endl;
    std::cout << "Player " << ID << ": cards are: " << std::endl;
    for (i = 0; i < 5; i++) {
        if (playerValue[i] == 0) strcpy_s(nameOfCard, "two");
        if (playerValue[i] == 1) strcpy_s(nameOfCard, "three");
        if (playerValue[i] == 2) strcpy_s(nameOfCard, "four");
        if (playerValue[i] == 3) strcpy_s(nameOfCard, "five");
        if (playerValue[i] == 4) strcpy_s(nameOfCard, "six");
        if (playerValue[i] == 5) strcpy_s(nameOfCard, "seven");
        if (playerValue[i] == 6) strcpy_s(nameOfCard, "eight");
        if (playerValue[i] == 7) strcpy_s(nameOfCard, "nine");
        if (playerValue[i] == 8) strcpy_s(nameOfCard, "ten");
        if (playerValue[i] == 9) strcpy_s(nameOfCard, "jack");
        if (playerValue[i] == 10) strcpy_s(nameOfCard, "queen");
        if (playerValue[i] == 11) strcpy_s(nameOfCard, "king");
        if (playerValue[i] == 12) strcpy_s(nameOfCard, "ace");
        switch (playerSuit[i]) {
            case 0:
                std::cout << "card : " << nameOfCard << " of " << "Clubs" << std::endl;
                break;
            case 1:
                std::cout << "card : " << nameOfCard << " of " << "Diamonds" << std::endl;
                break;
            case 2:
                std::cout << "card : " << nameOfCard << " of " << "Hearts" << std::endl;
                break;
            case 3:
                std::cout << "card : " << nameOfCard << " of " << "Spades" << std::endl;
                break;
            default:
                std::cout << "wrong suit" << std::endl;
        }

    }
}