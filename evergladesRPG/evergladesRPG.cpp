/*
Kasim D. Liburd
Unit One Lab
fileName.cpp
Lost in the Everglades
Lost in the Everglades in an RPG (Role-Playing-Game) between a player and the computer.
A group of tourists has been lost in the Everglades and a ranger must rescue them before time runs out.
The Everglades are represented by a 5x5 matrix. 
The ranger (R) starts the rescue at the upper-left cornerof the park, the group of tourists (T) are lost at the lower-right corner. 
The ranger has 12 gongs of time tofind and rescue the tourists before they perish.
During the journey, the ranger might find dangers (hungry alligator, swarm of giant mosquitoes, venomousspider, or python).
When the ranger finds a danger, they can choose to fight them, or hide and wait for them to leave.
*/

/****************************************************************************************************
Pseudocode:
* Display introduction and menu
	Instructions
	Play
	Quit
* 
* Instructions
	Game objective
	How to move
	Conditions for losing
*
*Play
*	Get players move
		Is it a valid move
		Is there danger
			Deal with danger
			Update display
		Move and Update Display
*	Is game over
		Check remaining moves
		Did you find tourist
*	End game
		Victory Message
		Losing Messge
		Return to main menu
*
* Quit
	Exit Message
	End Program
****************************************************************************************************/

//Header Files
#include <iostream>
#include <string>
#include <iomanip>
#include <random>
#include <ctime>

using namespace std;

constexpr int MIN = 1;
constexpr int MAX = 3;
constexpr int MAX2 = 2;
constexpr int RANDOM_COUNT = 23;

struct LOCATION {
	int row = 0;
	int col = 0;
	int gong = 12;
};

//Function Prototypes
string menu();
void intro();
void instructions();
void play();
void playerView(string[6][6], LOCATION);
string threat(string);
//void setUp();

int main() {
	//Declare variables
	string choice = "";
	intro();
	do {
		choice = menu();

		switch (stoi(choice)) {
		case 1:
			play();
			break;
		case 2:
			instructions();
			break;
		default:
			cout << "\n\nGood Bye ... \n\n";
			break;
		}
	} while (choice != "3");
	return 0;
}
/**********
 string threat(string)
 This function processes the player's decision during a threat 
 and returns the outcome.
//**********/
string threat(string type) {
	//Declare variables
	string danger = "", outcome = "";
	int choice = 0;
	//Identify danger
	if (type == "A")
		danger = " an alligator up ahead!";
	else if (type == "P")
		danger = "a python over there!!";
	else
		danger = "a mosquito swarm, look out!!!";
	//Display danger message
	cout << "There is "<< danger << "\nWhat do you do?\n\t" << 
		"1. Wait for it to move away.\n\t" <<
		"2. Fight." << endl;
	//Get users choice
	cin >> choice;
	if (choice == 1) {
		outcome = "Wait";
		cout << "It's safe to move now, but a lot of time has passed.\n";
	}
	else {
		//calculate battle outcome
		int battle = rand() % MAX;
		if (battle < 2) {
			outcome = "Win";
			cout << "You fought bravely. Continue with your mission\n";
		}
		else {
			outcome = "Lose";
			cout << "That was a close one. You almost died.\n";
		}
	}
	return outcome;
}
/**********
 void move(string[][])
 This function moves the ranger through the board
//**********/
void move(string mboard[6][6], LOCATION rang) {
	//Declare variables
	const int ROWS = 6, COLS = 6;
	int move1, move2, newRow = rang.row, newCol = rang.col;
	string newBoard[ROWS][COLS], result = "";
	//Copy mboard to newBoard
	for (int r = 0; r < ROWS; r++) {
		for (int c = 0; c < COLS; c++) {
			newBoard[r][c] = mboard[r][c];
		}
	}
//	cout << "Ranger location is: " << rang.row << " " << rang.col << endl;//test
	//Move ranger
		cout << "Enter a move: \nROW: ";
		cin >> move1;
		move1 += 1; //calibrates movement to game board
		cout << "COLUMN: ";
		cin >> move2;
		move2 += 1; //calibrates movement to game board
		if (mboard[move1][move2] == "| T "){
			cout << "You win.";
			rang.gong = 0;
		}
		else if (mboard[move1][move2] == "| A ") {
			result = threat("A");
			if (result == "Wait") {
				newBoard[move1][move2] = "| R ";
				newBoard[newRow][newCol] = "|   ";
				//update ranger location
				rang.row = move1;
				rang.col = move2;
				rang.gong -= 5;
			}
			else if (result == "Win") {
				newBoard[move1][move2] = "| R ";
				newBoard[newRow][newCol] = "|   ";
				//update ranger location
				rang.row = move1;
				rang.col = move2;
				rang.gong -= 2;
			}
			else {
				newBoard[move1][move2] = "| a ";
				rang.gong -= 3;
			}
		}
		else if (mboard[move1][move2] == "| M ") {
			result = threat("M");
			if (result == "Wait") {
				newBoard[move1][move2] = "| R ";
				newBoard[newRow][newCol] = "|   ";
				//update ranger location
				rang.row = move1;
				rang.col = move2;
				rang.gong -= 5;
			}
			else if (result == "Win") {
				newBoard[move1][move2] = "| R ";
				newBoard[newRow][newCol] = "|   ";
				//update ranger location
				rang.row = move1;
				rang.col = move2;
				rang.gong -= 2;
			}
			else {
				newBoard[move1][move2] = "| m ";
				rang.gong -= 3;
			}
		}
		else if (mboard[move1][move2] == "| P ") {
			result = threat("P");
			if (result == "Wait") {
				newBoard[move1][move2] = "| R ";
				newBoard[newRow][newCol] = "|   ";
				//update ranger location
				rang.row = move1;
				rang.col = move2;
				rang.gong -= 5;
			}
			else if (result == "Win") {
				newBoard[move1][move2] = "| R ";
				newBoard[newRow][newCol] = "|   ";
				//update ranger location
				rang.row = move1;
				rang.col = move2;
				rang.gong -= 2;
			}
			else {
				newBoard[move1][move2] = "| p ";
				rang.gong -= 3;
			}
		}
		else {
			newBoard[move1][move2] = "| R ";
			newBoard[newRow][newCol] = "|   ";
			//update ranger location
			rang.row = move1;
			rang.col = move2;
			rang.gong -= 1;
		}
		if (rang.gong > 0) {
			cout << "Gongs Left: " << rang.gong << endl;
		}
		//Ends function to function loop when time has run out
		if (rang.gong > 0) {
			playerView(newBoard, rang);
		}
}
/**********
 void playerView(string[][]);
 This function sets up the game board seen by the player
//**********/
void playerView(string board[6][6], LOCATION parkRanger) {
	//Declare variables
	const int ROWS = 6, COLS = 6;
	string view[ROWS][COLS];
	for (int r = 0; r < ROWS; r++) {
		for (int c = 0; c < COLS; c++) {
			//Clear block 1
			if (r == 0 && c == 0) {
				view[r][c] = "    ";
				cout << view[r][c];
			}
			//Number the columns
			else if (r == 0 && c > 0) {
				view[r][c] = board[r][c];
				cout << "  " << view[r][c] << " ";
			}
			//Number the rows
			else if (r > 0 && c == 0) {
				view[r][c] = board[r][c];
				cout << "  " << view[r][c] << " ";
			}
			else {
				cout << view[r][c];
				//Display ranger and tourist
				if (board[r][c] == "| R " || board[r][c] == "| T ") {
					view[r][c] = board[r][c];
					cout << view[r][c];
				}
				else if (board[r][c] == "| r ") {
					cout << "| R ";
				}
				else if (board[r][c] == "| a ") {
					cout << "| A ";
				}
				else if (board[r][c] == "| p ") {
					cout << "| P ";
				}
				else if (board[r][c] == "| m ") {
					cout << "| M ";
				}
				//update ranger location
				else if (board[r][c] == "|   ") {
					cout << "|   ";
				}
				else if (view[r][c] == "") {
					cout << "| * ";
					view[r][c] = "| * ";
				}
			}
			//Move down at the end of each row
			if (c == 5)
				cout << endl;
		}
	}
//	cout << "New Ranger location is: " << parkRanger.row << " " << parkRanger.col << endl;//test
	move(board, parkRanger);
}
/**********
*void setUp();
 This function sets up the game board unseen by the player
*/
void setUp() {
	//Declare variables
	const int ROWS = 6, COLS = 6;
	int rowNum = 0, colNum = 0, pick, randBlock = 1;
	string everglades[ROWS][COLS];
	LOCATION ranger;
	ranger.row = 1;
	ranger.col = 1;
	//Create random engine
	std::srand(std::time(nullptr));
	//Create game board 
	for (int r = 0; r < ROWS; r++) {
		for (int c = 0; c < COLS; c++) {
			//Make block elegible for a threat
			pick = rand() % MAX2;
			//Clear block 1
			if (r == 0 && c == 0) {
				everglades[r][c] = "    ";
//				cout << everglades[r][c];//test
			}
			//Number the columns
			else if (r == 0 && c > 0) {
				everglades[r][c] = to_string(rowNum);
				rowNum++;
//				cout << "  " << everglades[r][c] << " ";//test
			}
			//Number the rows
			else if (r > 0 && c == 0) {
				everglades[r][c] = to_string(colNum);
				colNum++;
//				cout << "  " << everglades[r][c] << " ";//test
			}
			//Set rangers start
			else if (r == 1 && c == 1) {
				everglades[r][c] = "| R ";
//				cout << everglades[r][c];//test
			}
			//Place tourist
			else if (r == 5 && c == 5) {
				everglades[r][c] = "| T ";
//				cout << everglades[r][c];//test
			}
			//Assign threats to random blocks
			else if (pick == 1 && randBlock <= 10) {
				int block = rand() % MAX;
				//Assign Alligator
				if (block == 0) {
					everglades[r][c] = "| A ";
//					cout << everglades[r][c];//test
				}
				//Assign Pythons
				else if (block == 1) {
					everglades[r][c] = "| P ";
//					cout << everglades[r][c];//test
				}
				//Assign Mosquitoes
				else {
					everglades[r][c] = "| M ";
//					cout << everglades[r][c];//test
				}
				randBlock++;
			}
/*			else {
				cout << "| * ";//test
			}
			if (c == 5)
				cout << endl;//test
*/		}
	}
	playerView(everglades, ranger);
}
/*void play()
* This function houses all of the functions that run the game.
*/
void play() {
	setUp();
}
/*void instructions()
* This function provides the instructions on how to play the game.
*/
void instructions() {
	cout << "A group of tourists has been lost in the Everglades and a ranger must rescue them before time runs out.\n" << endl;
	cout << "The Everglades are represented by a 5x5 matrix.\n" <<
		"The ranger(R) starts the rescue at the upper - left cornerof the park, \n" <<
		"the group of tourists(T) are lost at the lower - right corner.\n" <<
		"The ranger has 12 gongs of time to find and rescue the tourists before they perish." << endl;
	cout << "During the journey, the ranger might find dangers (hungry alligator, swarm of giant mosquitoes, venomousspider, or python.\n" << endl;
	cout << "When the ranger finds a danger, they can choose to fight them, or hide and wait for them to leave." << endl <<
		"If the Ranger waits the ranger moves to the desired cell and loses 5 gongs of time." << endl <<
		"If the Ranger fights and wins, the ranger moves to the desired cell and losses 2 gongs of time." << endl <<
		"If the Ranger fight and losses, the ranger does not move, losses 3 gongs of time and the threat remains." << endl <<
		"If there is no danger, the ranger moves to the desired cell and losses 1 gong of time" << endl;
	cout << "The game ends when either the ranger rescues the group of tourist or time expires." << endl;
	cout << "\n*****************************************************************************************************************************\n" << endl <<
		"The numbers on the left are \"Rows\" and the numbers across the top are \"Columns\"." << endl <<
		"To move enter the coodinates of an adjacent cell.\nFirst enter the ROW and press enter.\nThen enter the COLUMN and press enter." << endl;
}
/*string menu()
* This function does the following:
* Displays the menu options
* Gets the user's choice and returns the user's choice
//**********/
string menu() {
	//Declare variables
	string choice;
	//Display menu
	cout << "\nChoose one of the following options\n" <<
		"\t1. Play Lost in the Everglades\n" <<
		"\t2. Display Instructions\n" <<
		"\t3. Quit.\n" <<
		">>> ";
	//Validate choice
	do {
		//Get user info
		cin >> choice;
		//Actual choice validation
		if (choice != "1" && choice != "2" && choice != "3") {
			cout << "\nINVALID CHOICE ... \nSelect from 1, 2, or 3 >>> ";
		}
	} while (choice != "1" && choice != "2" && choice != "3");

	return choice;
}
void intro() {
	cout << "**************************************\n" <<
		"\tLOST IN THE EVERGLADES\n" <<
		"**************************************\n" << endl;
}