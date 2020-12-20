#include <iostream>
#include <string>
using namespace std;

class GlobalBoard {
	public : 
		string localBoard[3][3];
};

GlobalBoard game[3][3];
int boardChoice;
string O = "\u26AA";
string X = "\u274C";

void printGame(){
	int count =0;
	for (int k = 0 ; k< 3; k++){
		for (int s= 0 ; s < 3 ; s++){
			for (int i = 0; i< 3; i++){
				if(i==3 && count <9){
					count++;
					i=0;
					continue;
				}
				for (int j = 0; j < 3; j++){
					cout << game[k][i].localBoard[s][j];
				}
				cout << "  " ;
			}
		cout << endl;
		}
		cout << endl;
	}	
}

void initialiseLocalBoard(int x, int y){
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			game[x][y].localBoard[i][j] = "\u2B1B";	
		}
	}
}

void initialiseGlobalBoard(){
	initialiseLocalBoard(0,0);
	initialiseLocalBoard(0,1);
	initialiseLocalBoard(0,2);
	initialiseLocalBoard(1,0);
	initialiseLocalBoard(1,1);
	initialiseLocalBoard(1,2);
	initialiseLocalBoard(2,0);
	initialiseLocalBoard(2,1);
	initialiseLocalBoard(2,2);
}


void playerX(int &boardChoice, int xCoo, int yCoo){
	switch (boardChoice)
	{
	case 1:
		game[0][0].localBoard[xCoo][yCoo] = X;
		boardChoice = 1;
		break;
	case 2:
		game[0][1].localBoard[xCoo][yCoo] = X;
		boardChoice =2;
		break;
	case 3:
		game[0][2].localBoard[xCoo][yCoo] = X;
		boardChoice = 3;
		break;
	case 4:
		game[1][0].localBoard[xCoo][yCoo] = X;
		boardChoice = 4;
		break;
	case 5:
		game[1][1].localBoard[xCoo][yCoo] = X;
		boardChoice = 5;
		break;
	case 6:
		game[1][2].localBoard[xCoo][yCoo] = X;
		boardChoice = 6;
		break;
	case 7:
		game[2][0].localBoard[xCoo][yCoo] = X;
		boardChoice = 7;
		break;
	case 8:
		game[2][1].localBoard[xCoo][yCoo] = X;
		boardChoice = 8;
		break;
	case 9:
		game[2][2].localBoard[xCoo][yCoo] = X;
		boardChoice = 9;
		break;
	}
	printGame();
}

void playerO(int &boardChoice, int xCoo, int yCoo){
	switch (boardChoice)
	{
	case 1:
		game[0][0].localBoard[xCoo][yCoo] = O;
		boardChoice = 1;
		break;
	case 2:
		game[0][1].localBoard[xCoo][yCoo] = O;
		boardChoice = 2;
		break;
	case 3:
		game[0][2].localBoard[xCoo][yCoo] = O;
		boardChoice = 3;
		break;
	case 4:
		game[1][0].localBoard[xCoo][yCoo] = O;
		boardChoice = 4;
		break;
	case 5:
		game[1][1].localBoard[xCoo][yCoo] = O;
		boardChoice = 5; 
		break;
	case 6:
		game[1][2].localBoard[xCoo][yCoo] = O;
		boardChoice = 6;
		break;
	case 7:
		game[2][0].localBoard[xCoo][yCoo] = O;
		boardChoice = 7;
		break;
	case 8:
		game[2][1].localBoard[xCoo][yCoo] = O;
		boardChoice = 8;
		break;
	case 9:
		game[2][2].localBoard[xCoo][yCoo] = O;
		boardChoice = 9;
		break;
	}
	printGame();
}

int main(int argc, char *argv[])
{
	cout << endl;
	initialiseGlobalBoard();
	printGame();
	cout << endl;

	cout << "Choose starting board : ";
	boardChoice = 5;

	cout << "Player X starts! " << endl;
	playerX(boardChoice, 1,1) ;

}
