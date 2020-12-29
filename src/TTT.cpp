#include <iostream>
#include <string>
std::string O = "\u26AA";
std::string X = "\u274C";
std::string E = "\u2B1B";
#define N 3

int count = 0;
void switchPlayer();
void print();
void initialiseLocalBoard();
bool solveXO(std::string grid[N][N]);
bool isthereWinner(std::string grid[N][N]);
std::string localBoard[N][N] =
    {E, E, E,
     E, E, E,
     E, E, E};
std::string player;

int boardChoice;
void initialiseLocalBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            localBoard[i][j] = E;
        }
    }
}
void print() {
    std::cout << "Winner is : " << player << "\n\n\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << localBoard[i][j];
        }
        std::cout << "\n";
    }
}

bool solveXO(std::string grid[N][N]) {
    //bool found = false;

    if (isthereWinner(grid)) {
        print();  //put print() after ||grid[i][j] = player;|| near line 50 to print ALL steps
                  // count++;

        return true;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == E) {
                grid[i][j] = player;
                switchPlayer();
                solveXO(grid);
                //if () {
                //    found = true;
                grid[i][j] = E;
                switchPlayer();
                // }
            }
        }
    }
    return false;
}

bool isthereWinner(std::string grid[N][N]) {
    if (

        (((localBoard[0][0] == localBoard[1][1]) && (localBoard[1][1] == localBoard[2][2])) ||
         (localBoard[0][2] == localBoard[1][1]) && (localBoard[1][1] == localBoard[2][0])) &&
        (localBoard[1][1] != E)) {
        count++;
        return true;
    }
    for (int i = 0; i < N; i++)
        if (((grid[i][0] == grid[i][1]) && (grid[i][1] == grid[i][2]) && (grid[i][0] != E)) ||
            ((grid[0][i] == grid[1][i]) && (grid[1][i] == grid[2][i]) && (grid[0][i] != E))) {
            count++;
            return true;
        }
    return false;
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
    if (player == X) {
        player = O;
    } else {
        player = X;
    }
}

int main(int argc, char *argv[]) {
    // int *localBIndex;
    // int x, y;
    // initialiseLocalBoard();
    // print();
    // while (gameState == "Playing") {
    //     std::cout << "Enter the X coordinates where you want to place X\n";
    //     std::cin >> x;
    //     std::cout << "Enter the Y coordinates where you want to place X\n";
    //     std::cin >> y;
    //     while (x > 2 || x < 0 || y > 2 || y < 0) {
    //         std::cout << "Invalid Input! Please enter coordinates within the board : \n";
    //         std::cout << "Enter the X coordinates where you want to place X\n";
    //         std::cin >> x;
    //         std::cout << "Enter the Y coordinates where you want to place X\n";
    //         std::cin >> y;
    //     }
    //     playerX(x, y);
    //     print();
    //     checkLocalWinX();
    //     if (gameState != "Playing") break;

    //     std::cout << "Enter the X coordinates where you want to place O\n";
    //     std::cin >> x;
    //     std::cout << "Enter the Y coordinates where you want to place O\n";
    //     std::cin >> y;
    //     while (x > 2 || x < 0 || y > 2 || y < 0) {
    //         std::cout << "Invalid Input! Please enter coordinates within the board (0,1, or 2): ";
    //         std::cout << "Enter the X coordinates where you want to place O\n";
    //         std::cin >> x;
    //         std::cout << "Enter the Y coordinates where you want to place O\n";
    //         std::cin >> y;
    //     }
    //     playerO(x, y);
    //     print();
    //     checkLocalWinO();
    //     if (gameState != "Playing") break;
    // }
    // std::cout << "Game winner is : Player " << gameState << "\n";

    player = X;

    if (solveXO(localBoard)) {
        std::cout << "\nThe grid entered has already won\n";
        std::cout << "Winner is : " << player << "\n";
    } else {
        std::cout << "Winner is : " << player << "\n\n";

        std::cout << "The number of solutions found is : " << count << "\n";
    }
}
