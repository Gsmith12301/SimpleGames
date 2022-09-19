//----------------------------------------------------------------//
// tictactoe.cpp
//----------------------------------------------------------------//
#include <iostream>
#include <random> 
#include <unistd.h>
#include "tictactoe.h"
using namespace std;

int main() {
    char board[3][3];

    board[0][0] = 'a';
    board[0][1] = 'b';
    board[0][2] = 'c';
    board[1][0] = 'd';
    board[1][1] = 'e';
    board[1][2] = 'f';
    board[2][0] = 'g';
    board[2][1] = 'h';
    board[2][2] = 'i';

    cout << "Lets play TicTacToe! Press enter to begin!";
    cin.ignore();
    printBoard(board);
    sleep(1); //pauses for 1 seconds. Just for visual appeal
    cout << "You are player X. Enter the location where you would \nlike to put your X.\n"; 
    putchar('\n');
    cout << " 0 0  0 1  0 2 \n 1 0  1 1  1 2 \n 2 0  2 1  2 2\n";
    putchar('\n');
    cout << "Enter your choice as a two numbers with a space, like [1 0] \n";
    putchar('\n');

    int row;
    int column;
    cin >> row >> column;
    board[row][column] = 'X';
    printBoard(board); 

    bool isThereAWinner = false;
    isThereAWinner = checkForWinner(board);

    while (isThereAWinner == false) { 
        cout << "My turn!\n";
        sleep(1);  

        constexpr int MIN = 0;
        constexpr int MAX = 2;
        std::random_device rd;
        std::mt19937 eng(rd());
        std::uniform_int_distribution<int> distr(MIN, MAX);

        row = distr(eng);
        column = distr(eng);

        while ((board[row][column] == 'X') || (board[row][column] == 'O')) {
            row = distr(eng);
            column = distr(eng);
        }
        
        board[row][column] = 'O';
        printBoard(board);

        cout << "Your turn!\n";
        putchar('\n');
        cout << " 0 0  0 1  0 2 \n 1 0  1 1  1 2 \n 2 0  2 1  2 2\n";
        putchar('\n');
        cin >> row >> column;

        while ((board[row][column] == 'X') || (board[row][column] == 'O')) {
            cout << "That spot is unavailable! try again. \n";
            printBoard(board);
            putchar('\n');
            cout << " 0 0  0 1  0 2 \n 1 0  1 1  1 2 \n 2 0  2 1  2 2\n";
            putchar('\n');
            cin >> row >> column;
        }
        board[row][column] = 'X';

        isThereAWinner = checkForWinner(board);
        printBoard(board);
        sleep(1); 
    }
    cout << "We have a winner!";

    return 0;
}
