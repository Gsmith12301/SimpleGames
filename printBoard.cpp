//----------------------------------------------------------------//
// printBoard.cpp
//----------------------------------------------------------------//
#include <iostream> 
using namespace std;
#include "tictactoe.h"

void printBoard(char array[3][3]) {
    putchar('\n');
    for (int i=0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (array[i][j] != ('X') && array[i][j] != ('O')) {
             cout<< "  " << '*' << " ";
            }
            else {
                cout<< "  " << array[i][j] << " ";
            }
        }
    putchar('\n');
    }
    putchar('\n');
}
