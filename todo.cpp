#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct date_time {
	int year;
	int month;
	int day;

	int mm;
	int ss;
	int hh;
};


struct tasker {
	char* task_name;
	int task_id;
	int task_status;
};

typedef date_time dtm;
typedef tasker task;

string prompt = "tasker$ ";
string user_input;

vector<string> splitString(string args);


int main() {
	
	int loopExitControl = 0;


	while (!loopExitControl) {


		cout << prompt;
		getline(cin, user_input);

		cout << splitString(user_input)[1] << endl;
		

		if (user_input == "exit") {
			loopExitControl = 1;
		}else if (user_input=="add") {
			
			cout << "Tasker :: Add a task" << endl;
			cout << "Enter the task : " << endl;

		}else if (user_input == "delete") {
			cout << "Tasker :: Delete a task" << endl;
		}else if (user_input == "edit") {
			cout << "Tasker :: Edit a task" << endl;
		}else if (user_input == "show") {
			cout << "Tasker :: Show all task" << endl;
		}else if (user_input == "showtask") {
			cout << "Tasker :: Show a Specific task" << endl;
		}else if (user_input == "mark") {
			cout << "Tasker :: Mark a task as done!!" << endl;
		}
	}






	return 0;
}
/*
string getCommand(string args) {

	string command = "";
	int i = 0;
	int findres = args.find(' ');

	if (findres != -1) {

		for (i = 0; i < findres; i++) {
			command[i] = args[i];
		}
	}
	return command;

}

string getResidual(string args) {

	string residual = "";
	int i = 0;
	int j = 0;
	int findres = args.find(' ');

	if (findres != -1) {

		for (i = findres; i<args.length();j++,i++) {
			residual[j] = args[i];
		}
	}

	return residual;


}
*/

vector<string> splitString(string args) {

	vector<string> list_of_strings;
	char delimiter = ' ';
	int i;
	int last_space_flag = 0;
	int len = args.length();
	string tempString;

	if (args.find(' ') > 0) {

		for (i = 0; i < len; i++) {
			if (args.at(i) == ' ') {
				tempString = args.substr(last_space_flag, (i - last_space_flag));
				list_of_strings.push_back(tempString);
			}
		}
	}
	else {
		list_of_strings.push_back(args);
	}

	return list_of_strings;
}