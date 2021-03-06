#include "player.h"
#include "dealer.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//   C++ PROJECT      NAME: Frank Giordano 
//                    5-CARD POKER
//
//   I have hard-coded 5 decks of cards. I tried to test as many combinations as possible.
//

void flushInput() {
    std::cin.clear();
    while (std::cin.peek() != '\n') {
        std::cin.get();
    }
    std::cin.clear();
}

int main() {
    int cardA[52] = {1, 13, 2, 16, 3, 15, 4, 19, 5, 17,
                     1, 13, 3, 16, 5, 15, 8, 19, 12, 17,
                     0, 1, 13, 14, 26, 27, 39, 40, 5, 17,
                     1, 13, 2, 14, 3, 15, 4, 16, 5, 17,
                     2, 1, 13, 14, 27, 10, 28, 32, 42, 22, 44, 45};
    int cardB[52] = {1, 49, 14, 6, 28, 10, 41, 8, 5, 9,
                     1, 10, 2, 23, 3, 36, 4, 32, 5, 45,
                     0, 13, 2, 16, 26, 15, 39, 19, 5, 17,
                     26, 12, 39, 25, 13, 0, 1, 4, 14, 6,
                     4, 5, 17, 18, 30, 31, 43, 45, 6, 8, 50, 51};
    int cardC[52] = {1, 13, 3, 17, 21, 15, 6, 40, 7, 50,
                     0, 11, 13, 25, 26, 38, 42, 51, 6, 22,
                     0, 26, 13, 39, 1, 27, 14, 40, 7, 21,
                     0, 1, 13, 14, 26, 27, 15, 28, 2, 41,
                     27, 1, 14, 40, 23, 10, 28, 32, 42, 22, 44, 45};
    int cardD[52] = {1, 13, 3, 17, 21, 15, 5, 49, 8, 44,
                     0, 27, 13, 40, 12, 11, 30, 47, 6, 22,
                     2, 26, 14, 39, 1, 27, 14, 40, 7, 21,
                     2, 26, 15, 39, 1, 27, 14, 40, 7, 21,
                     1, 13, 3, 17, 21, 15, 5, 49, 9, 44, 46, 45};
    int j = 0, i = 0, k = 0, l = 9;
    char answer;


    Player p1(1), p2(2);
    Dealer d;

    std::cout << std::endl << "5-CARD POKER" << std::endl;
    std::cout << std::endl << "ACE IS HIGH" << std::endl;
    std::cout << std::endl << "Options: DeckA, DeckB, DeckC, or DeckD.";
    std::cout << std::endl << "Which deck would you like to play with, A, B, C or D?" << std::endl;
    std::cin >> answer;

    for (k = 0; k < 5; k++) {
        flushInput();
        std::cout << std::endl << "Game(s): " << k + 1 << std::endl;
        if (i == 10) l = 19;
        if (i == 20) l = 29;
        if (i == 30) l = 39;
        if (i == 40) l = 49;

        switch (answer) {
            case 'A':
                for (; i < l; i += 2) {
                    d.GetCard(i, cardA);
                    d.DealCard(p1, j);
                    d.GetCard(i + 1, cardA);
                    d.DealCard(p2, j);
                    j++;
                }
                break;
            case 'B':
                for (; i < l; i += 2) {
                    d.GetCard(i, cardB);
                    d.DealCard(p1, j);
                    d.GetCard(i + 1, cardB);
                    d.DealCard(p2, j);
                    j++;
                }
                break;
            case 'C':
                for (; i < l; i += 2) {
                    d.GetCard(i, cardC);
                    d.DealCard(p1, j);
                    d.GetCard(i + 1, cardC);
                    d.DealCard(p2, j);
                    j++;
                }
                break;
            case 'D':
                for (; i < l; i += 2) {
                    d.GetCard(i, cardD);
                    d.DealCard(p1, j);
                    d.GetCard(i + 1, cardD);
                    d.DealCard(p2, j);
                    j++;
                }
                break;
            default:
                std::cout << std::endl << "No Deck chosen!" << std::endl;
                exit(1);
        }

        j = 0;

        p1.Display();
        p2.Display();

        d.CheckPlayer(p1);
        d.CheckPlayer(p2);

        d.DetermineWinner(p1, p2);

        p1.Re_initialize();
        p2.Re_initialize();

        std::cout << std::endl << "Press RETURN to continue!" << std::endl;
        flushInput();
        std::cin.get();
    }

    d.Totals(p1, p2);
}