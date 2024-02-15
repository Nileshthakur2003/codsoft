#include<iostream>
#include<cstdlib>

using namespace std;


int check_if_same(char x, char y, char z);
int check_linear_combinations(char t);
int check_diagonal_combinations(char t);

char matrix[3][3] = { {' ',' ',' '},{' ',' ',' '},{' ',' ',' '} };

int main() {
	int loopExitSignal = 0;
	int currentPrintRow;
	char currentPlayer = 'o';
	int pos = 1;
	int i;

	int winStatus = 0;
	char winnner;
	
	



	while (!loopExitSignal) {
		system("CLS");
		cout << "Value of ch  = " << currentPlayer << endl;
		cout << "Value of pos  = " << pos << endl;

		currentPrintRow = 0;

		for (i = 0; i < 7; i++) 
		{
			if (i == 2 || i == 4) {
				cout << "----+----+---" << endl;

			}else if (i == 0 || i == 6) {
				cout << "-------------" << endl;

			}
			else {
				cout << "| " << matrix[currentPrintRow][0]  << " | " << matrix[currentPrintRow][1] << " | " << matrix[currentPrintRow][2] << " | " << endl;
				currentPrintRow++;
			}

			
		}
		cout << endl << endl;

		cout << "Current Player : " << currentPlayer << endl;

		cout << "Enter [-1] to exit the program!" << endl;
		cout << "Enter a position [1,2,3,4,5,6,7,8,9]:";
		cin >> pos;

		switch (pos) 
		{
		case 1:
			matrix[0][0] = currentPlayer;
			break;
		case 2:
			matrix[0][1] = currentPlayer;
			break;
		case 3:
			matrix[0][2] = currentPlayer;
			break;
		case 4:
			matrix[1][0] = currentPlayer;
			break;
		case 5:
			matrix[1][1] = currentPlayer;
			break;
		case 6:
			matrix[1][2] = currentPlayer;
			break;
		case 7:
			matrix[2][0] = currentPlayer;
			break;
		case 8:
			matrix[2][1] = currentPlayer;
			break;
		case 9:
			matrix[2][2] = currentPlayer;
			break;
		default:
			break;
		}

		if (currentPlayer == 'o') {
			currentPlayer = 'x';
		}
		else {
			currentPlayer = 'o';
		}


		if (pos == -1) {
			loopExitSignal = 1;
		}
	}
	// deciding winnner & updating winStatus


	return 0;
}


int check_if_same(char x, char y, char z) {


	if (x == y && x == z) {
		return 1;
	}
	else {
		return 0;
	}

}

int check_linear_combinations(char t) {
	

	int match = 0;
	int i;

	for (i = 0; i < 3; i++) {

		if (matrix[i][0] == t && matrix[i][1] == t && matrix[i][2] == t) {
			match = 1;
		}
	}

	return match;
}

int check_diagonal_combinations(char t){
	

	//1st diag combination - 00 - 11 - 22.

	int match = 0;

	if (matrix[0][0] == t && matrix[1][1] == t && matrix[2][2] == t) {
		match = 1;
	}else if (matrix[0][2] == t && matrix[1][1] == t && matrix[2][1] == t) {
		match = 1;
	}


	return match;
}

