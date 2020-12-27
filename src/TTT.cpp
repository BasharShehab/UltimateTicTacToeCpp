#include <iostream>
#include <string>
int playing = 1;

std::string O = "\u26AA";
std::string X = "\u274C";
std::string E = "\u2B1B";
std::string gameState = "Playing";
std::string localBoard[3][3] = {E, E, E, E, E, E, E, E, E};
std::string *player;
int boardChoice;
void initialiseLocalBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            localBoard[i][j] = E;
        }
    }
}
void print() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << localBoard[i][j];
        }
        std::cout << "\n";
    }
}
void checkLocalWinX() {
    if (

        (localBoard[0][0] == X && localBoard[0][1] == X && localBoard[0][2] == X) ||

        (localBoard[1][0] == X && localBoard[1][1] == X && localBoard[1][2] == X) ||

        (localBoard[2][0] == X && localBoard[2][1] == X && localBoard[2][2] == X) ||

        (localBoard[0][0] == X && localBoard[1][0] == X && localBoard[2][0] == X) ||

        (localBoard[0][1] == X && localBoard[1][1] == X && localBoard[2][1] == X) ||

        (localBoard[0][2] == X && localBoard[1][2] == X && localBoard[2][2] == X) ||

        (localBoard[0][0] == X && localBoard[1][1] == X && localBoard[2][2] == X) ||

        (localBoard[0][2] == X && localBoard[1][1] == X && localBoard[2][0] == X)) {
        gameState = X;
    }
}

void checkLocalWinO() {
    if (

        (localBoard[0][0] == O && localBoard[0][1] == O && localBoard[0][2] == O) ||

        (localBoard[1][0] == O && localBoard[1][1] == O && localBoard[1][2] == O) ||

        (localBoard[2][0] == O && localBoard[2][1] == O && localBoard[2][2] == O) ||

        (localBoard[0][0] == O && localBoard[1][0] == O && localBoard[2][0] == O) ||

        (localBoard[0][1] == O && localBoard[1][1] == O && localBoard[2][1] == O) ||

        (localBoard[0][2] == O && localBoard[1][2] == O && localBoard[2][2] == O) ||

        (localBoard[0][0] == O && localBoard[1][1] == O && localBoard[2][2] == O) ||

        (localBoard[0][2] == O && localBoard[1][1] == O && localBoard[2][0] == O)) {
        gameState = O;
    }
}
void playerX(int x, int y) {
    localBoard[x][y] = X;
}
void playerO(int x, int y) {
    localBoard[x][y] = O;
}

bool isNotFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (localBoard[i][j] == E) {
                return true;
            }
        }
    }

    return false;
}

void switchPlayer() {
    if (*player == X) {
        *player = O;
    } else {
        *player = X;
    }
}

// bool solveTTT() {
//     playing = 1;

//     checkLocalWinX();
//     checkLocalWinO();

//     if (gameState != "Playing") {
//         playing = 0;
//         return true;
//     }
//     for (int i = 0; i < 3; i++) {
//         for (int j = 0; j < 3; j++) {
//             if (localBoard[i][j] == E) {
//                 localBoard[i][j] = *player;
//                 switchPlayer();
//                 bool tmp = isNotFull();
//                 if ((playing == 1) && (tmp == false)) {
//                     localBoard[i][j] == "failed";
//                     return false;
//                 }
//                 solveTTT();
//             }
//         }
//     }
//     return false;
// }

int main(int argc, char *argv[]) {
    // if (solveTTT()) {
    //     std::cout << "\nFound solution\n";
    // } else {
    //     std::cout << "\nDIDNT Found solution\n";
    // }

    // print();

    int *localBIndex;
    int x, y;
    initialiseLocalBoard();
    print();
    while (gameState == "Playing") {
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
        playerX(x, y);
        print();
        checkLocalWinX();
        if (gameState != "Playing") break;

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
        playerO(x, y);
        print();
        checkLocalWinO();
        if (gameState != "Playing") break;
    }
    std::cout << "Game winner is : Player " << gameState << "\n";
}
