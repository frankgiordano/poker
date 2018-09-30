#include "player.h"
#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
Player::Player(int newID)
{
    int i;
    for (i = 0; i < 5; i++) {
       playerSuit[i]=0;
       playerValue[i]=0;
    }
    whatRank = -1; valueHand = -1;
    ID = newID;
    howManyGamesWon = 0; itsThreeOfAKind = 0; itsFlush = 0;
    itsPair1 = 0; itsPair2 = 0; itsStraightFlush = 0;
    itsStraight = 0; itsFourOfAKind = 0; valueHand = 0;
}
 
void Player::Re_initialize()
{
   whatRank = itsThreeOfAKind = itsPair1 = itsStraightFlush = 0;
   itsPair2 = itsStraight = itsFourOfAKind = valueHand = itsFlush = 0;
}
 
void Player::Display() {
    int i;
    char nameOfCard[20];
 
    cout << endl;
    cout << "Player " << ID << ": cards are: " << endl;
    for (i = 0; i < 5; i++) {
      if (playerValue[i] == 0)  strcpy(nameOfCard, "two");
      if (playerValue[i] == 1)  strcpy(nameOfCard, "three");
      if (playerValue[i] == 2)  strcpy(nameOfCard, "four");
      if (playerValue[i] == 3)  strcpy(nameOfCard, "five");
      if (playerValue[i] == 4)  strcpy(nameOfCard, "six");
      if (playerValue[i] == 5)  strcpy(nameOfCard, "seven");
      if (playerValue[i] == 6)  strcpy(nameOfCard, "eight");
      if (playerValue[i] == 7)  strcpy(nameOfCard, "nine");
      if (playerValue[i] == 8)  strcpy(nameOfCard, "ten");
      if (playerValue[i] == 9)  strcpy(nameOfCard, "jack");
      if (playerValue[i] == 10) strcpy(nameOfCard, "queen");
      if (playerValue[i] == 11) strcpy(nameOfCard, "king");
      if (playerValue[i] == 12) strcpy(nameOfCard, "ace");
      switch (playerSuit[i]) {
        case 0:
           cout << "card : " << nameOfCard << " of " << "Clubs" << endl;
           break;
        case 1:
           cout << "card : " << nameOfCard << " of " << "Diamonds" << endl;
           break;
        case 2:
           cout << "card : " << nameOfCard << " of " << "Hearts" << endl;
           break;
        case 3:
           cout << "card : " << nameOfCard << " of " << "Spades" << endl;
           break;
        default:
           cout << "wrong suit" << endl;
      }
    }
 
}