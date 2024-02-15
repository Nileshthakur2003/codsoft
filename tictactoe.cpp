#include<iostream>
#include<cstdlib>

using namespace std;


int check_if_same(char x, char y, char z);
int check_linear_combinations(char t);
int check_diagonal_combinations(char t);
int check_linear_vertical_combinations(char t);
int check_if_filled(int pos);

char matrix[3][3] = { {' ',' ',' '},{' ',' ',' '},{' ',' ',' '} };

int main() {

	int loopExitSignal = 0;
	int currentPrintRow;
	char currentPlayer = 'o';
	int pos = 1;
	int i;
	int noBlankPos = -1;
	int winStatus = 0;
	char winner;
	
	



	while (!loopExitSignal) {
		system("CLS");

		currentPrintRow = 0;

		for (i = 0; i < 7; i++) 
		{
			if (i == 2 || i == 4) {
				cout << "\t\t----+----+---" << endl;

			}else if (i == 0 || i == 6) {
				cout << "\t\t-------------" << endl;

			}
			else {
				cout << "\t\t| " << matrix[currentPrintRow][0]  << " | " << matrix[currentPrintRow][1] << " | " << matrix[currentPrintRow][2] << " | " << endl;
				currentPrintRow++;
			}

			
		}
		cout << endl << endl;
		if(winStatus==1){
			cout << "Player " << winner << " won!" << endl;
			loopExitSignal=1;

		}else{
		
		if(noBlankPos>0){
			cout << pos << " is already filled." << endl;
			noBlankPos=-1;
		}
		cout << "\x1B[34mCurrent Player : \033[0m " << currentPlayer << endl;

		cout << "Enter [-1] to exit the program" << endl;
		cout << "Enter a position [1,2,3,4,5,6,7,8,9]:";
		cin >> pos;

		if(check_if_filled(pos)){
			noBlankPos = pos;
			continue;
		}else if (pos == -1) {
			loopExitSignal = 1;
		}else{

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


		}
		

		// deciding winnner & updating winStatus
	if(check_diagonal_combinations('x') || check_linear_combinations('x') || check_linear_vertical_combinations('x')){
		winStatus=1;
		winner='x';
	}else if(check_diagonal_combinations('o') || check_linear_combinations('o')|| check_linear_vertical_combinations('o')){
		winStatus=1;
		winner='o';
	}
	}
	}
	


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

int check_linear_vertical_combinations(char t){
	int match = 0;
	int i;

	for (i = 0; i < 3; i++) {

		if (matrix[0][i] == t && matrix[1][i] == t && matrix[2][i] == t) {
			match = 1;
		}
	}

	return match;
}

int check_if_filled(int pos)
{	

	int result = 0;

	switch(pos) 
		{
		case 1:
			if(matrix[0][0]=='x' || matrix[0][0]=='o'){
				result = 1;
			}
			break;
		case 2:
			if(matrix[0][1]=='x' || matrix[0][1]=='o'){
				result = 1;
			}
			break;
		case 3:
			if(matrix[0][2]=='x' || matrix[0][2]=='o'){
				result = 1;
			}
			break;
		case 4:
			if(matrix[1][0]=='x' || matrix[1][0]=='o'){
				result = 1;
			}
			break;
		case 5:
			if(matrix[1][1]=='x' || matrix[1][1]=='o'){
				result = 1;
			}
			break;
		case 6:
			if(matrix[1][2]=='x' || matrix[1][2]=='o'){
				result = 1;
			}
			break;
		case 7:
			if(matrix[2][0]=='x' || matrix[2][0]=='o'){
				result = 1;
			}
			break;
		case 8:
			if(matrix[2][1]=='x' || matrix[2][1]=='o'){
				result = 1;
			}
			break;
		case 9:
			if(matrix[2][2]=='x' || matrix[2][2]=='o'){
				result = 1;
			}
			break;
		default:
			break;
		}

		return result;

}
