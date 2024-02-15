#include<iostream>
#include<cstdlib>


using namespace std;

int generate_random_number();


int main() {

	int user_guess,currentSecret,replayConfirmation;
	int guessRight;
	int guess_count = 3;
	int user_count = 0;
	int loopExitSignal = 0;

	cout << "Welcome to the number guessing game " << endl;
	while (!loopExitSignal) {

		currentSecret = generate_random_number();
		cout << "\x1B[36mI have got a secret number between [1-100]." << endl << "Now its your turn to guess it!\033[0m" << endl;
		user_count = 0;
		guessRight = 0;

		while (!(user_count >= guess_count)) {
			cout << "Enter your guess : ";
			cin >> user_guess;
			user_count++;

			if (user_guess == 404) {
				break;
			}
			else if (user_guess == currentSecret) {
				cout << "What a Guess!! you have hit the target in dark!" << endl;
				guessRight = 1;
			}
			else if (user_guess < currentSecret) {
				cout << "Guess Higher!!" << endl;
			}
			else if (user_guess > currentSecret) {
				cout << "Guess Lower!!" << endl;
			}
			
			cout << "\x1B[31mRemaining Guesses: \033[0m" << (guess_count - user_count) << endl;

		}
		if (!guessRight) {
			cout << "Bad Luck! Try Next Time!" << endl << endl;
		}
		cout << "Want to play again (0/1)? {0=No|1=Yes} ";
		cin >> replayConfirmation;

		if (!replayConfirmation) {
			loopExitSignal = 1;
			cout << "Exiting !! Bye Bye";
		}
		
	}

	return 0;
}


int generate_random_number()
{
	return rand()%100;
}
