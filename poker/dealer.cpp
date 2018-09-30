#include "player.h"
#include "dealer.h"
#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
 
void Dealer::Totals(Player& P1, Player& P2)
{
   cout<<endl<<"Total game(s) won by Player "<<P1.ID<<" is "<<P1.howManyGamesWon<<"."<<endl;
   cout<<"Total game(s) won by Player "<<P2.ID<<" is "<<P2.howManyGamesWon<< "."<<endl;
   if (P1.howManyGamesWon > P2.howManyGamesWon)
     cout<<"Player "<<P1.ID<<" has won the most game(s)."<<endl;
   else
     cout<<"Player "<<P2.ID<<" has won the most game(s)."<<endl;
}
 
void Dealer::DetermineWinner(Player& P1, Player& P2)
{
  int DrawWinnerP1, DrawWinnerP2;
 
  cout << endl;
  DrawWinnerP1 = DrawWinnerP2 = 0;
  if ((P1.whatRank == 1) && (P2.whatRank == 1)) {
    if (P1.valueHand > P2.valueHand) {
      P1.howManyGamesWon += 1;
      cout <<"The Winner is "<<"player "<<P1.ID<<"."<<endl;
      cout <<"Player "<<P1.ID<<" has won "<<P1.howManyGamesWon<<" game(s)."<<endl;
      return;
    }
    else {
      P2.howManyGamesWon += 1;
      cout <<"The Winner is "<<"player "<<P2.ID<<"."<<endl;
      cout <<"Player "<<P2.ID<<" has won "<<P2.howManyGamesWon<<" game(s)."<<endl;
      return;
    }
  } else if (P1.whatRank > P2.whatRank) {
       P1.howManyGamesWon += 1;
       cout <<"The Winner is "<<"player "<<P1.ID<<"."<<endl;
       cout <<"Player "<<P1.ID<<" has won "<<P1.howManyGamesWon<<" game(s)."<<endl;
       return;
  } else if (P2.whatRank > P1.whatRank) {
       P2.howManyGamesWon += 1;
       cout <<"The Winner is "<<"player "<<P2.ID<<"."<<endl;
       cout <<"Player "<<P2.ID<<" has won "<<P2.howManyGamesWon<<" game(s)."<<endl;
       return;
  } else if (P2.whatRank == P1.whatRank) {
     DrawWinnerP1 = P1.itsThreeOfAKind + P1.itsPair1 + P1.itsPair2 + P1.itsStraight
            + P1.itsFlush + P1.itsFourOfAKind + P1.itsStraightFlush;
 
     DrawWinnerP2 = P2.itsThreeOfAKind + P2.itsPair1 + P2.itsPair2 + P2.itsStraight
            + P2.itsFlush + P2.itsFourOfAKind + P2.itsStraightFlush;
     if (DrawWinnerP1 > DrawWinnerP2) {
           P1.howManyGamesWon += 1;
		   cout <<"The Winner is "<<"player "<<P1.ID<<"."<<endl;
           cout <<"Player "<<P1.ID<<" has won "<<P1.howManyGamesWon<<" game(s)."<<endl;
           return;
         } else if (DrawWinnerP2 > DrawWinnerP1) {
           P2.howManyGamesWon += 1;
           cout <<"The Winner is "<<"player "<<P2.ID<<"."<<endl;
           cout <<"Player "<<P2.ID<<" has won "<<P2.howManyGamesWon<<" game(s)."<<endl;
           return;
         } else if (DrawWinnerP1 = DrawWinnerP2) {
           cout <<"This game is a DRAW."<<endl;
               return;
         }
   }
}
 
void Dealer::CheckPlayer(Player& P)
{
  cout << endl;
  if (StraightFlush(P) == 1) {
    cout << "Player " << P.ID << " has a Straight Flush.";
    P.whatRank = 9;
    return;
  } else if (FourOfAKind(P) == 1) {
       cout << "Player " << P.ID << " has a FourOfAKind.";
       P.whatRank = 8;
       return;
  } else if (FullHouse(P) == 1) {
       cout << "Player " << P.ID << " has a FullHouse.";
       P.whatRank = 7;
       return;
  } else if (Flush(P) == 1) {
       cout << "Player " << P.ID << " has a Flush.";
       P.whatRank = 6;
       return;
  } else if (Straight(P) == 1) {
       cout << "Player " << P.ID << " has a Straight.";
       P.whatRank = 5;
       return;
  } else if (ThreeOfAKind(P) == 1) {
       cout << "Player " << P.ID << " has a ThreeOfAKind.";
       P.whatRank = 4;
       return;
  } else if (TwoPairsOfCards(P) == 1) {
       cout << "Player " << P.ID << " has a TwoPairsOfCards.";
       P.whatRank = 3;
       return;
  } else if (OnePairOfCards(P) == 1) {
       cout << "Player " << P.ID << " has a OnePairOfCards." ;
       P.whatRank = 2;
       return;
  } else if (HighestCardInHand(P) == 1) {
       cout << "Player " << P.ID << " has no combinations.";
       P.whatRank = 1;
       return;
  }
  cout << endl;
  return;
}
 
int Dealer::StraightFlush(Player& P) {
  int i = 0, j = 0, min, max, holdnum[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
 
  if (P.playerSuit[0] != P.playerSuit[1])
    return 0;
  else if (P.playerSuit[0] != P.playerSuit[2])
    return 0;
  else if (P.playerSuit[0] != P.playerSuit[3])
    return 0;
  else if (P.playerSuit[0] != P.playerSuit[4])
    return 0;
  else {
 
    min = max = P.playerValue[0];
    for (i = 0; i < 5; i++) {
       if (P.playerValue[i] < min)
         min = P.playerValue[i];
       else if (P.playerValue[i] > max)
          max = P.playerValue[i];
    }
    if ((max-min) != 4)
      return 0;
    else {
      for (i = 0; i < 5; i++)
    holdnum[P.playerValue[i]] += 1;
      for (i = 0; i < 13; i++)
     if (holdnum[i] > 0)
           j = i;
      P.itsStraightFlush = j;
      return 1;
    }
 
    return 1;
  }
}
 
int Dealer::FourOfAKind(Player& P) {
  int i, holdnum[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
 
  for (i = 0; i < 5; i++)
    holdnum[P.playerValue[i]] += 1;
  for (i = 0; i < 13; i++)
     if (holdnum[i] == 4) {
       P.itsFourOfAKind = i;
       return 1;
     }
  return 0;
}
 
int Dealer::ThreeOfAKind(Player& P) {
  int i, holdnum[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
 
  for (i = 0; i < 5; i++)
    holdnum[P.playerValue[i]] += 1;
  for (i = 0; i < 13; i++)
     if (holdnum[i] == 3) {
       P.itsThreeOfAKind = i;
       return 1;
     }
  return 0;
}
 
int Dealer::Flush(Player& P) {
  int i, holdnumV[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
  int j, holdnumS[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
 
  for (i = 0; i < 5; i++)
    holdnumV[P.playerValue[i]] += 1;
 
  for (i = 0; i < 5; i++)
    holdnumS[P.playerSuit[i]] += 1;
 
  for (i = 0; i < 13; i++)
     if (holdnumS[i] == 5) {
       for (j = 0; j < 13; j++)
          if (holdnumV[j] > 0)
        P.itsFlush += j;
          return 1;
 
     }
  return 0;
}
 
int Dealer::FullHouse(Player& P) {
  int i, holdnum[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
  int isItThreeOfAKind, isItTwoOfAKind;
 
  isItThreeOfAKind = isItTwoOfAKind = 0;
  for (i = 0; i < 5; i++)
    holdnum[P.playerValue[i]] += 1;
 
  for (i = 0; i < 13; i++)
     if (holdnum[i] == 3) {
       P.itsThreeOfAKind = i;
       isItThreeOfAKind = 1;
     }
  for (i = 0; i < 13; i++)
     if (holdnum[i] == 2) {
       P.itsPair1 = i;
       isItTwoOfAKind = 1;
     }
 
  if ((isItThreeOfAKind == 1) && (isItTwoOfAKind == 1))
    return 1;
  return 0;
}
 
int Dealer::Straight(Player& P) {
  int i, holdnum[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
 
  for (i = 0; i < 5; i++)
    holdnum[P.playerValue[i]] += 1;
 
  for (i = 0; i < 13; i++) {
    if (holdnum[i] == 1)
      break;
  }
  if (holdnum[i+1] == 1)
    if (holdnum[i+2] == 1)
      if (holdnum[i+3] == 1)
    if (holdnum[i+4] == 1) {
          P.itsStraight = i+4;
          return 1;
        }          // a straight!!
  return 0;
}
 
int Dealer::TwoPairsOfCards(Player& P) {
  int i, j, holdnum[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
  int foundFirstPair = 0, foundSecondPair = 0;
  int whereWasFirst = 0;
 
  for (i = 0; i < 5; i++)
    holdnum[P.playerValue[i]] += 1;
 
  for (i = 0; i < 13; i++) {
     if (holdnum[i] == 2) {
       foundFirstPair = 1;
       P.itsPair1 = whereWasFirst = i;
       i = 14;
     }
  }
  for (j = 0; j < 13; j++) {
     if (j == whereWasFirst)
       j++;
     if (holdnum[j] == 2) {
       foundSecondPair = 1;
       P.itsPair2 = i;
       j = 14;
     }
  }
  if ((foundFirstPair == 1) && (foundSecondPair == 1))
    return 1;
  return 0;
}
 
int Dealer::OnePairOfCards(Player& P) {
  int i, holdnum[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
 
  for (i = 0; i < 5; i++)
    holdnum[P.playerValue[i]] += 1;
  for (i = 0; i < 13; i++)
     if (holdnum[i] == 2) {
       P.itsPair1 = i;
       return 1;
     }
  return 0;
}
 
int Dealer::HighestCardInHand(Player& P) {
  int i, j, holdnum[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
 
  j = i =0;
  for (i = 0; i < 5; i++)
    holdnum[P.playerValue[i]] += 1;
  for (i = 0; i < 13; i++)
     if (holdnum[i] > 0)
       if (i > j)
         j = i;
  P.valueHand = j;
 
  return 1;
}
 
 
void Dealer::GetCard(int index,int card[]) {
    Card=card[index];
}
 
void Dealer::DealCard(Player& p, int index) {
    p.playerSuit[index] = Card / 13;
    p.playerValue[index] = Card % 13;
}