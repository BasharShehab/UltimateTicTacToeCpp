#include <string.h>

#include <iostream>

class GlobalBoard {
   public:
    std::string localBoard[3][3];
};
std::string gameState = "Playing";
GlobalBoard game[3][3];
std::string O = "\u26AA";
std::string X = "\u274C";
std::string E = "\u2B1B";

std::string globalWinner[3][3];
void printGame() {
    int count = 0;
    for (int k = 0; k < 3; k++) {
        for (int s = 0; s < 3; s++) {
            for (int i = 0; i < 3; i++) {
                if (i == 3 && count < 9) {
                    count++;
                    i = 0;
                    continue;
                }
                for (int j = 0; j < 3; j++) {
                    std::cout << game[k][i].localBoard[s][j];
                }
                std::cout << "  ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void initialiseLocalBoard(int x, int y) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            game[x][y].localBoard[i][j] = E;
        }
    }
}

void initialiseGlobalBoard() {
    initialiseLocalBoard(0, 0);
    initialiseLocalBoard(0, 1);
    initialiseLocalBoard(0, 2);
    initialiseLocalBoard(1, 0);
    initialiseLocalBoard(1, 1);
    initialiseLocalBoard(1, 2);
    initialiseLocalBoard(2, 0);
    initialiseLocalBoard(2, 1);
    initialiseLocalBoard(2, 2);
}

void changeBoardChoice(int &boardChoice, int xCoo, int yCoo) {
    if (xCoo == 0 && yCoo == 0)
        boardChoice = 1;
    else if (xCoo == 0 && yCoo == 1)
        boardChoice = 2;
    else if (xCoo == 0 && yCoo == 2)
        boardChoice = 3;
    else if (xCoo == 1 && yCoo == 0)
        boardChoice = 4;
    else if (xCoo == 1 && yCoo == 1)
        boardChoice = 5;
    else if (xCoo == 1 && yCoo == 2)
        boardChoice = 6;
    else if (xCoo == 2 && yCoo == 0)
        boardChoice = 7;
    else if (xCoo == 2 && yCoo == 1)
        boardChoice = 8;
    else if (xCoo == 2 && yCoo == 2)
        boardChoice = 9;
}
void checkLocalWinX(int board) {
    int x, y;
    switch (board) {
        case 1:
            x = 0;
            y = 0;
            break;
        case 2:
            x = 0;
            y = 1;
            break;
        case 3:
            x = 0;
            y = 2;
            break;
        case 4:
            x = 1;
            y = 0;
            break;
        case 5:
            x = 1;
            y = 1;
            break;
        case 6:
            x = 1;
            y = 2;
            break;
        case 7:
            x = 2;
            y = 0;
            break;
        case 8:
            x = 2;
            y = 1;
            break;
        case 9:
            x = 2;
            y = 2;
            break;
    }
    if (
        (game[x][y].localBoard[0][0] == X &&
         game[x][y].localBoard[0][1] == X &&
         game[x][y].localBoard[0][2] == X) ||
        (game[x][y].localBoard[1][0] == X &&
         game[x][y].localBoard[1][1] == X &&
         game[x][y].localBoard[1][2] == X) ||
        (game[x][y].localBoard[2][0] == X &&
         game[x][y].localBoard[2][1] == X &&
         game[x][y].localBoard[2][2] == X) ||
        (game[x][y].localBoard[0][0] == X &&
         game[x][y].localBoard[1][0] == X &&
         game[x][y].localBoard[2][0] == X) ||
        (game[x][y].localBoard[0][1] == X &&
         game[x][y].localBoard[1][1] == X &&
         game[x][y].localBoard[2][1] == X) ||
        (game[x][y].localBoard[0][2] == X &&
         game[x][y].localBoard[1][2] == X &&
         game[x][y].localBoard[2][2] == X) ||
        (game[x][y].localBoard[0][0] == X &&
         game[x][y].localBoard[1][1] == X &&
         game[x][y].localBoard[2][2] == X) ||
        (game[x][y].localBoard[0][2] == X &&
         game[x][y].localBoard[1][1] == X &&
         game[x][y].localBoard[2][0] == X))
        globalWinner[x][y] = X;
}

void checkLocalWinO(int board) {
    int x, y;
    switch (board) {
        case 1:
            x = 0;
            y = 0;
            break;
        case 2:
            x = 0;
            y = 1;
            break;
        case 3:
            x = 0;
            y = 2;
            break;
        case 4:
            x = 1;
            y = 0;
            break;
        case 5:
            x = 1;
            y = 1;
            break;
        case 6:
            x = 1;
            y = 2;
            break;
        case 7:
            x = 2;
            y = 0;
            break;
        case 8:
            x = 2;
            y = 1;
            break;
        case 9:
            x = 2;
            y = 2;
            break;
    }
    if (
        (game[x][y].localBoard[0][0] == O &&
         game[x][y].localBoard[0][1] == O &&
         game[x][y].localBoard[0][2] == O) ||
        (game[x][y].localBoard[1][0] == O &&
         game[x][y].localBoard[1][1] == O &&
         game[x][y].localBoard[1][2] == O) ||
        (game[x][y].localBoard[2][0] == O &&
         game[x][y].localBoard[2][1] == O &&
         game[x][y].localBoard[2][2] == O) ||
        (game[x][y].localBoard[0][0] == O &&
         game[x][y].localBoard[1][0] == O &&
         game[x][y].localBoard[2][0] == O) ||
        (game[x][y].localBoard[0][1] == O &&
         game[x][y].localBoard[1][1] == O &&
         game[x][y].localBoard[2][1] == O) ||
        (game[x][y].localBoard[0][2] == O &&
         game[x][y].localBoard[1][2] == O &&
         game[x][y].localBoard[2][2] == O) ||
        (game[x][y].localBoard[0][0] == O &&
         game[x][y].localBoard[1][1] == O &&
         game[x][y].localBoard[2][2] == O) ||
        (game[x][y].localBoard[0][2] == O &&
         game[x][y].localBoard[1][1] == O &&
         game[x][y].localBoard[2][0] == O))
        globalWinner[x][y] = O;
}

void checkGlobalWinX(std::string &gameState) {
    if (
        ((globalWinner[0][0] == X &&
          globalWinner[0][1] == X &&
          globalWinner[0][2] == X) ||
         (globalWinner[1][0] == X &&
          globalWinner[1][1] == X &&
          globalWinner[1][2] == X) ||
         (globalWinner[2][0] == X &&
          globalWinner[2][1] == X &&
          globalWinner[2][2] == X) ||
         (globalWinner[0][0] == X &&
          globalWinner[1][0] == X &&
          globalWinner[2][0] == X) ||
         (globalWinner[0][1] == X &&
          globalWinner[1][1] == X &&
          globalWinner[2][1] == X) ||
         (globalWinner[0][2] == X &&
          globalWinner[1][2] == X &&
          globalWinner[2][2] == X) ||
         (globalWinner[0][0] == X &&
          globalWinner[1][1] == X &&
          globalWinner[2][2] == X) ||
         (globalWinner[0][2] == X &&
          globalWinner[1][1] == X &&
          globalWinner[2][0] == X))) {
        gameState = X;
    }
}

void playerX(int &boardChoice, int xCoo, int yCoo) {
    switch (boardChoice) {
        case 1:
            if (game[0][0].localBoard[xCoo][yCoo] == E)
                game[0][0].localBoard[xCoo][yCoo] = X;
            else {
                std::cout << "Please choose an empty space\n";
                int x, y;
                std::cout << "Enter the X coordinates where you want to place X\n";
                std::cin >> x;
                std::cout << "Enter the Y coordinates where you want to place X\n";
                std::cin >> y;
                playerX(boardChoice, x, y);
            }
            break;
        case 2:
            if (game[0][1].localBoard[xCoo][yCoo] == E)
                game[0][1].localBoard[xCoo][yCoo] = X;
            else {
                std::cout << "Please choose an empty space\n";
                int x, y;
                std::cout << "Enter the X coordinates where you want to place X\n";
                std::cin >> x;
                std::cout << "Enter the Y coordinates where you want to place X\n";
                std::cin >> y;
                playerX(boardChoice, x, y);
            }
            break;
        case 3:
            if (game[0][2].localBoard[xCoo][yCoo] == E)
                game[0][2].localBoard[xCoo][yCoo] = X;
            else {
                std::cout << "Please choose an empty space\n";
                int x, y;
                std::cout << "Enter the X coordinates where you want to place X\n";
                std::cin >> x;
                std::cout << "Enter the Y coordinates where you want to place X\n";
                std::cin >> y;
                playerX(boardChoice, x, y);
            }
            break;
        case 4:
            if (game[1][0].localBoard[xCoo][yCoo] == E)
                game[1][0].localBoard[xCoo][yCoo] = X;
            else {
                std::cout << "Please choose an empty space\n";
                int x, y;
                std::cout << "Enter the X coordinates where you want to place X\n";
                std::cin >> x;
                std::cout << "Enter the Y coordinates where you want to place X\n";
                std::cin >> y;
                playerX(boardChoice, x, y);
            }
            break;
        case 5:
            if (game[1][1].localBoard[xCoo][yCoo] == E)
                game[1][1].localBoard[xCoo][yCoo] = X;
            else {
                std::cout << "Please choose an empty space\n";
                int x, y;
                std::cout << "Enter the X coordinates where you want to place X\n";
                std::cin >> x;
                std::cout << "Enter the Y coordinates where you want to place X\n";
                std::cin >> y;
                playerX(boardChoice, x, y);
            }
            break;
        case 6:
            if (game[1][2].localBoard[xCoo][yCoo] == E)
                game[1][2].localBoard[xCoo][yCoo] = X;
            else {
                std::cout << "Please choose an empty space\n";
                int x, y;
                std::cout << "Enter the X coordinates where you want to place X\n";
                std::cin >> x;
                std::cout << "Enter the Y coordinates where you want to place X\n";
                std::cin >> y;
                playerX(boardChoice, x, y);
            }
            break;
        case 7:
            if (game[2][0].localBoard[xCoo][yCoo] == E)
                game[2][0].localBoard[xCoo][yCoo] = X;
            else {
                std::cout << "Please choose an empty space\n";
                int x, y;
                std::cout << "Enter the X coordinates where you want to place X\n";
                std::cin >> x;
                std::cout << "Enter the Y coordinates where you want to place X\n";
                std::cin >> y;
                playerX(boardChoice, x, y);
            }
            break;
        case 8:
            if (game[2][1].localBoard[xCoo][yCoo] == E)
                game[2][1].localBoard[xCoo][yCoo] = X;
            else {
                std::cout << "Please choose an empty space\n";
                int x, y;
                std::cout << "Enter the X coordinates where you want to place X\n";
                std::cin >> x;
                std::cout << "Enter the Y coordinates where you want to place X\n";
                std::cin >> y;
                playerX(boardChoice, x, y);
            }
            break;
        case 9:
            if (game[2][2].localBoard[xCoo][yCoo] == E)
                game[2][2].localBoard[xCoo][yCoo] = X;
            else {
                std::cout << "Please choose an empty space\n";
                int x, y;
                std::cout << "Enter the X coordinates where you want to place X\n";
                std::cin >> x;
                std::cout << "Enter the Y coordinates where you want to place X\n";
                std::cin >> y;
                playerX(boardChoice, x, y);
            }
            break;
    }
    changeBoardChoice(boardChoice, xCoo, yCoo);
    printGame();
    checkLocalWinX(boardChoice);
}

void playerO(int &boardChoice, int xCoo, int yCoo) {
    switch (boardChoice) {
        case 1:
            if (game[0][0].localBoard[xCoo][yCoo] == E)
                game[0][0].localBoard[xCoo][yCoo] = O;
            else {
                std::cout << "Please choose an empty space\n";
                int x, y;
                std::cout << "Enter the X coordinates where you want to place O\n";
                std::cin >> x;
                std::cout << "Enter the Y coordinates where you want to place O\n";
                std::cin >> y;
                playerO(boardChoice, x, y);
            }
            break;
        case 2:
            if (game[0][1].localBoard[xCoo][yCoo] == E)
                game[0][1].localBoard[xCoo][yCoo] = O;
            else {
                std::cout << "Please choose an empty space\n";
                int x, y;
                std::cout << "Enter the X coordinates where you want to place O\n";
                std::cin >> x;
                std::cout << "Enter the Y coordinates where you want to place O\n";
                std::cin >> y;
                playerO(boardChoice, x, y);
            }
            break;
        case 3:
            if (game[0][2].localBoard[xCoo][yCoo] == E)
                game[0][2].localBoard[xCoo][yCoo] = O;
            else {
                std::cout << "Please choose an empty space\n";
                int x, y;
                std::cout << "Enter the X coordinates where you want to place O\n";
                std::cin >> x;
                std::cout << "Enter the Y coordinates where you want to place O\n";
                std::cin >> y;
                playerO(boardChoice, x, y);
            }
            break;
        case 4:
            if (game[1][0].localBoard[xCoo][yCoo] == E)
                game[1][0].localBoard[xCoo][yCoo] = O;
            else {
                std::cout << "Please choose an empty space\n";
                int x, y;
                std::cout << "Enter the X coordinates where you want to place O\n";
                std::cin >> x;
                std::cout << "Enter the Y coordinates where you want to place O\n";
                std::cin >> y;
                playerO(boardChoice, x, y);
            }
            break;
        case 5:
            if (game[1][1].localBoard[xCoo][yCoo] == E)
                game[1][1].localBoard[xCoo][yCoo] = O;
            else {
                std::cout << "Please choose an empty space\n";
                int x, y;
                std::cout << "Enter the X coordinates where you want to place O\n";
                std::cin >> x;
                std::cout << "Enter the Y coordinates where you want to place O\n";
                std::cin >> y;
                playerO(boardChoice, x, y);
            }
            break;
        case 6:
            if (game[1][2].localBoard[xCoo][yCoo] == E)
                game[1][2].localBoard[xCoo][yCoo] = O;
            else {
                std::cout << "Please choose an empty space\n";
                int x, y;
                std::cout << "Enter the X coordinates where you want to place O\n";
                std::cin >> x;
                std::cout << "Enter the Y coordinates where you want to place O\n";
                std::cin >> y;
                playerO(boardChoice, x, y);
            }
            break;
        case 7:
            if (game[2][0].localBoard[xCoo][yCoo] == E)
                game[2][0].localBoard[xCoo][yCoo] = O;
            else {
                std::cout << "Please choose an empty space\n";
                int x, y;
                std::cout << "Enter the X coordinates where you want to place O\n";
                std::cin >> x;
                std::cout << "Enter the Y coordinates where you want to place O\n";
                std::cin >> y;
                playerO(boardChoice, x, y);
            }
            break;
        case 8:
            if (game[2][1].localBoard[xCoo][yCoo] == E)
                game[2][1].localBoard[xCoo][yCoo] = O;
            else {
                std::cout << "Please choose an empty space\n";
                int x, y;
                std::cout << "Enter the X coordinates where you want to place O\n";
                std::cin >> x;
                std::cout << "Enter the Y coordinates where you want to place O\n";
                std::cin >> y;
                playerO(boardChoice, x, y);
            }
            break;
        case 9:
            if (game[2][2].localBoard[xCoo][yCoo] == E)
                game[2][2].localBoard[xCoo][yCoo] = O;
            else {
                std::cout << "Please choose an empty space\n";
                int x, y;
                std::cout << "Enter the X coordinates where you want to place O\n";
                std::cin >> x;
                std::cout << "Enter the Y coordinates where you want to place O\n";
                std::cin >> y;
                playerO(boardChoice, x, y);
            }
            break;
    }
    changeBoardChoice(boardChoice, xCoo, yCoo);
    printGame();
    checkLocalWinO(boardChoice);
}

int main(int argc, char *argv[]) {
    int boardChoice, x, y;
    std::cout << "\n";
    initialiseGlobalBoard();
    printGame();
    std::cout << "\n";

    std::cout << "Player X Starts!\n";
    std::cout << "Choose starting board : \n";
    std::cin >> boardChoice;
    while (boardChoice < 1 || boardChoice > 9) {
        std::cout << "Please enter a valid board (1-9) : \n";
        std::cin >> boardChoice;
    }

    while (gameState == "Playing") {
        std::cout << "Board #" << boardChoice << std::endl;
        std::cout << "Enter the X coordinates where you want to place X\n";
        std::cin >> x;
        std::cout << "Enter the Y coordinates where you want to place X\n";
        std::cin >> y;
        while (x > 2 || x < 0 || y > 2 || y < 0) {
            std::cout << "Invalid Input! Please enter coordinates within the board : \n";
            std::cout << "Enter the X coordinates where you want to place X\n";
            std::cin >> x;
            std::cout << "Enter the Y coordinates where you want to place X\n";
            std::cin >> y;
        }
        playerX(boardChoice, x, y);
        checkGlobalWinX(gameState);

        std::cin.clear();
        std::cout << "Board #" << boardChoice << std::endl;

        std::cout << "Enter the X coordinates where you want to place O\n";
        std::cin >> x;
        std::cout << "Enter the Y coordinates where you want to place O\n";
        std::cin >> y;
        while (x > 2 || x < 0 || y > 2 || y < 0) {
            std::cout << "Invalid Input! Please enter coordinates within the board (0,1, or 2): ";
            std::cout << "Enter the X coordinates where you want to place O\n";
            std::cin >> x;
            std::cout << "Enter the Y coordinates where you want to place O\n";
            std::cin >> y;
        }
        playerO(boardChoice, x, y);
        checkGlobalWinX(gameState);

        std::cin.clear();
        std::cout << "global";

        checkLocalWinX(boardChoice);
        checkLocalWinO(boardChoice);
        std::cout << "global";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << globalWinner[i][j];
            }
            std::cout << "\n";
        }
    }

    std::cout << "Winner is : " << gameState << std::endl;
}