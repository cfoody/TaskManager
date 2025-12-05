#include <iostream>
#include <string>
#include <vector>

using namespace std;

void clearInput() {
	cin.clear();
	cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
}

string getTaskFromUser() {
	string task;
	cout << "Enter your task: ";
	clearInput();
	getline(cin, task);
	cout << "\n";
	return task;
}

void printTasks(vector<string>& tasks) {
	cout << "YOUR TASKS:\n";
	if (tasks.empty()) {
		cout << "No tasks yet. \n";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.get();
		return;
	}
	for (int i = 0; i < tasks.size(); i++) {
		cout << i << ". " << tasks.at(i) << "\n";
	}
	cout << "Press enter to continue.\n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
}

void removeTask(vector<string>& tasks) {
	int option;
	cout << "Enter the number of task you want to remove:\n";
	for (int i = 0; i < tasks.size(); i++) {
		cout << i << ". " << tasks.at(i) << "\n";
	}
	cin >> option;
	if (cin.fail() || option < 0 || option >= tasks.size()) {
		cout << "\nInvalid option.\n\n";
		clearInput();
		return;
	}
	tasks.erase(tasks.begin() + option);
}

int main()
{
	vector<string> tasks;
	int option;
	string temp;
	while (true)
	{
		system("cls");
		cout << "Welcome to the task manager! Please enter a number:\n1. Add a new task\n2. View tasks\n3. Mark a task as completed\n4. Exit\n";
		cin >> option;
		system("cls");
		switch (option) {
			case 1:
				temp = getTaskFromUser();
				tasks.push_back(temp);
				break;
			case 2:
				printTasks(tasks);
				break;
			case 3:
				removeTask(tasks);
				break;
			case 4:
				break;
			default:
				cout << "\nInvalid option\n";
				break;
		}
		if (option == 4) {
			break;
		}
	}

	return 0;
}
