#include<iostream>	//standerd input output stream
#include<cmath>		//using rand() function
#include<string>	//using string to hold string values
#include<ctime>		//for using time()
#include <cstdlib>

/*
Raj Jani
Tic Tac Toe CPP mini project
Features : 
1. Simgle player vs Computer
2. Two player game mode
3. Select player name and x or o to play
4. host to check moves and declare winner and moves 

*/

using namespace std;



/*class that contains all function and variable of tic tac tho game */

class TicTactToh {


//variable section
public:
	string playerName = "";
	string playerTowName = "";
	char ch = '0'; //variable for choise 
	char gameBoard[3][3]; //game board
	int board_size = 3;

	char playerOne, playerTow; // varibole to hold X Or O

//public function section 
public :
	void displayBanner();	//function for display banner

	void getUserName(); //function for getting player name

	void initGameboard(); // function for initialize game board

	void playWithHuman(); // function for playing with human 

	void showGameboard(); //function to show gameboard

	char isOccupid(int row,int col); //function for cheking wether bame board postion is occupid or not

	bool placeXorO(int row, int col, char opt); //function to place x or O at right empty place

	void setPlayer(); //setting player x OR O for tow 

	void setOnePlayer(); // setting only one player and seocnd one computer

	bool isFull(); //function for cheching wether game board is full or not

	char check();// functio to check game over and winner 

	void playWithComputer(); //function for play with computer



	


};

//function to display banner 
void TicTactToh::displayBanner() {
	cout <<"****************************************" <<endl;
	cout <<"*    Welcome to Tic-Tac-Doh!           *" <<endl;
	cout <<"****************************************" << endl;
}

//function for getting player name 
void TicTactToh::getUserName() {
	cout << endl;
	cout << "Enter your name plaese:  "; cin >> playerName;
}

//function for initialize game board 
void TicTactToh::initGameboard() {
	
	for (int i = 0; i < board_size; i++)
	{
		for (int j = 0; j < board_size; j++)
		{
			gameBoard[i][j] = '-';
		}
	}

}

void TicTactToh::showGameboard() {
	for (int i = 0; i < board_size; i++)
	{
		for (int j = 0; j < board_size; j++)
		{
			cout << gameBoard[i][j]<<"\t";
		}
		cout << endl;
	}
}

//function for checking gameoard postion and accepts row and col as peramiter
// it return T as true if postion is occupid
// F as false
char TicTactToh::isOccupid(int row, int col) {
	if (gameBoard[row][col] == '-') {
		return 'F';
	}
	else {
		return 'T';
	}
}

//function for placing x or O at empty postion 
//if postion is not empty then aagain ask for place
//opt is for x or O
//retunrs true if successfull move
bool TicTactToh::placeXorO(int row, int col, char opt) {
	if (gameBoard[row][col] == '-') {

		gameBoard[row][col] = opt;
		return true;
	}
	else
	{
		cout << "Postion is not empty"<<endl;
		return false;
	}


}
//function for setting players x or o 
//one paramiter number X or O 
void TicTactToh::setPlayer() {
	int ch = 0;

	//geting tow player names
	cout << "Please Enter Player one Name: "; cin >> playerName;
	cout << "Please Enter player Tow Name: "; cin >> playerTowName;
	cout << "Select X Or O for player one (type number 1 = X / 2 = O): "; cin >> ch;
	if (ch == 1) {
		playerOne = 'X';
		playerTow = 'O';
	}
	else {
		playerOne = 'O';
		playerTow = 'X';
	}

}

//function for playing wiht human 
void TicTactToh::playWithHuman() {
	int row, col;
	int exit = 1;
	int turn = 0;
	char win = 'f';
	initGameboard();
	
	showGameboard();
	setPlayer();
	do {
	
		if (turn == 0 || turn == 2) {
			turn = 1;
			cout <<playerName<< "'s turn ("<<playerOne<<")";
		}
		else
		{
			turn = 2; 
			cout <<playerTowName<< "'s turn (" << playerTow << ")";
		}
		
		cout << "select row(1-3)"; cin >> row; 
		cout << " select col(1-3)"; cin >> col;
		row = row - 1; 
		col = col - 1;
		if ((row >= 0 && row <= 2) && (col >= 0 && col <= 2)) {
			cout << "Nice move"<<endl;
			if (turn == 1) {
				if (placeXorO(row, col, playerOne) == false) {
					turn = 2;
				}
				
			}				
			else
			{
				if (placeXorO(row, col, playerTow) == false) {
					turn = 1;
				}
			}
			showGameboard();
		}
		else {
			cout << "select range bettwen 1 to 3"; 

		}

		//calling function to check wether game is over or not 
		if (isFull() == true) {
			cout << "No places left on the borad"<<endl;
			cout << "match draw" << endl;
			cout << "Game over areu you want to play again (0 = exit)"; cin >> exit;
		}
		else {
			win = check();
			if (win == playerOne) {
				cout <<playerName<< " Win the Game (" << playerOne << ")" << endl;
				exit = 0;
			}
			else if(win == playerTow)
			{
				cout <<playerTowName<< "Win the Game (" << playerTow << ")" << endl;
				exit = 0;
			}
		}
	} while (exit != 0);

}
//function for checking game board is full or not 
//return true if full
//retunr false if empty 

bool TicTactToh::isFull() {

	for (int i = 0; i < board_size; i++)
	{
		for (int j = 0; j < board_size; j++)
		{
			if (gameBoard[i][j] == '-') {
				return false;
			}
		}
		
	}
	return true;
}



//function for checking wether otr not game is over
//return true if game over and declare winer
//retunr false if turs are left
char TicTactToh::check()
{
	int i;

	for (i = 0; i<3; i++)  /* check rows */
		if (gameBoard[i][0] == gameBoard[i][1] &&
			gameBoard[i][0] == gameBoard[i][2]) return gameBoard[i][0];

	for (i = 0; i<3; i++)  /* check columns */
		if (gameBoard[0][i] == gameBoard[1][i] &&
			gameBoard[0][i] == gameBoard[2][i]) return gameBoard[0][i];

	/* test diagonals */
	if (gameBoard[0][0] == gameBoard[1][1] &&
		gameBoard[1][1] == gameBoard[2][2])
		return gameBoard[0][0];

	if (gameBoard[0][2] == gameBoard[1][1] &&
		gameBoard[1][1] == gameBoard[2][0])
		return gameBoard[0][2];

	return ' ';
}

// setting only one player and seocnd one computer
//
void TicTactToh::setOnePlayer() {
	int ch = 0;
	//geting one player name
	cout << "Enter Player Name:"; cin >> playerName;
	playerTowName = "Com";
	cout << "Select X Or O for player one (type number 1 = X / 2 = O): "; cin >> ch;
	if (ch == 1) {
		playerOne = 'X';
		playerTow = 'O';
	}
	else {
		playerOne = 'O';
		playerTow = 'X';
	}

}



//functio for play with computer
//compuert will ramdomly select postion and take turn
//
void TicTactToh::playWithComputer() {

	int row, col;
	int exit = 1;
	int turn = 0;
	char win = 'f';

	//seting random seeds for random number ganaratore
	srand(time(NULL));

	initGameboard();

	showGameboard();
	setOnePlayer();
	do {

		if (turn == 0 || turn == 2) {
			turn = 1;
			cout << "players One's turn (" << playerOne << ")";

			//geting input from one player
			cout << "select row(1-3)"; cin >> row;
			cout << " select col(1-3)"; cin >> col;
		}
		else
		{
			turn = 2;
			cout << "Computer's turn (" << playerTow << ")"<<endl;
			cout << "Computer Thinking...." << endl;

			//getting input from computer
			row = (rand() % 3) + 1;
			col = (rand() % 3) + 1;
		}

		
		row = row - 1;
		col = col - 1;
		if ((row >= 0 && row <= 2) && (col >= 0 && col <= 2)) {
			cout << "Nice move" << endl;
			if (turn == 1) {
				if (placeXorO(row, col, playerOne) == false) {
					turn = 2;
				}

			}
			else
			{
				if (placeXorO(row, col, playerTow) == false) {
					turn = 1;
				}
			}
			showGameboard();
		}
		else {
			cout << "select range bettwen 1 to 3";

		}

		//calling function to check wether game is over or not 
		if (isFull() == true) {
			cout << "No places left on the borad" << endl;
			cout << "match draw" << endl;
			cout << "Game over areu you want to play again (0 = exit)"; cin >> exit;
		}
		else {
			win = check();
			if (win == playerOne) {
				cout <<playerName<< " Win the Game (" << playerOne << ")" << endl;
				exit = 0;
			}
			else if (win == playerTow)
			{
				cout << "Player Computer Win the Game (" << playerTow << ")" << endl;
				exit = 0;
			}
		}
	} while (exit != 0);



}


//main function 
int main() {

	char choice;
	TicTactToh game;

	game.displayBanner();
	//game.getUserName();

	cout << "Welcome to the game " << endl;
	cout << "Play with human (h) " << endl;
	cout << "play with computer (c)" << endl;
	cout << "Exit (e)"<<endl;
	cout << "please Enter your choice: ";
	//cin >> choice;

	do{
		system("cls");
		
		game.displayBanner();
		//game.getUserName();

		cout << "Welcome to the game " << endl;
		cout << "Play with human (h) " << endl;
		cout << "play with computer (c)" << endl;
		cout << "Exit (e)" << endl;
		cout << "please Enter your choice: ";
		//cin >> choice;


		if(cin >> choice)
		{
			switch (choice)
			{
			case 'h':
			case 'H':
					cout << "How are playing two players game. Good luck" << endl;
					cout << endl;
					game.playWithHuman();
					cout << endl;
					system("pause");
	
				break;
				case 'c':
				case 'C':
					game.playWithComputer();
					cout << endl;
					cout << endl;
					system("pause");
					break;
					
				case 'E':
				case 'e':
					exit(0);
					break;

				default:
					cout << "Somthing went wrong use only specefid options." << endl;
					cout << endl;
					break;
					
			}
		}
		else
		{
			cout<<"\n\t Input only Char please ! Press Enter To continue";
			//getch();
			cin.clear();
		 	cin.ignore();
			choice = 15 ;
		}
		

			
	}while(choice != 'e' || choice != 'E');

	cout << endl;
	system("pause");
	return 0;
}


