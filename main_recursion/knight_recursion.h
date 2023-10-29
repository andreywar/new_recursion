#pragma once

#include <iostream>

using namespace std;


const int max_size = 10;


const int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
const int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };


bool isValidMove(int x, int y, int n, int* board[]) {
    return (x >= 0 && x < n && y >= 0 && y < n && board[x][y] == -1);
}


bool findKnightTour(int x, int y, int move, int n, int* board[]) {

    board[x][y] = move;
    cout << x << " " << y << " " << move << " " << n << " " << endl;

    if (move == n * n)
        return true;

    for (int i = 0; i < 8; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if (isValidMove(nextX, nextY, n, board)) {
            if (findKnightTour(nextX, nextY, move + 1, n, board))
                return true;
        }
    }

    board[x][y] = -1;
    return false;
}


void coutBoard(int n, int* board[]) {
    cout << "Your board:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << "\t";
        }
        cout << endl;
    }
}

void deskBoard_init(int n, int *deskBoard[]) {
    for (int i = 0; i < n; i++)
        deskBoard[i] = new int[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            deskBoard[i][j] = -1;
}

void knight() {
    int n, abscisStart, ordinateStart;
    cout << "Enter board size: ";
    cin >> n;
    cout << "Enter starting place of knight on board: "<< endl << "X: " << endl;
    cin >> abscisStart;
    cout << "Y: " << endl;
    cin >> ordinateStart;
    int **deskBoard = new int*[n];
    deskBoard_init(n, deskBoard);


    coutBoard(n, deskBoard);
    if (findKnightTour(abscisStart, ordinateStart, 1, n, deskBoard)) {
        cout << "Matrix of knight steps:" << endl;
        coutBoard(n, deskBoard);
    }
    else {
        cout << "Resheniya ne sushestvuet!" << endl;
    }
}