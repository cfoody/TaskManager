#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>

using namespace std;

class Todo {
public:
	vector<Task> tasks;
};

class Task {
public:
	string task;
	time_t dueDate;

	Task() {
	}

	Task(string taskName, time_t date) {
		task = taskName;
		dueDate = date;
	}
};

static void clearInput() {
	cin.clear();
	cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
}

static time_t parseTime(string dateStr) {
	int month, day, year;

	char slash;
	stringstream ss(dateStr);
	ss >> month >> slash >> day >> slash >> year;

	tm t = {};
	t.tm_year = year - 1900;
	t.tm_mon = month - 1;
	t.tm_mday = day;

	return mktime(&t);
}

static Task getTaskFromUser() {
	Task task;
	string due;
	cout << "Enter your task: ";
	clearInput();
	getline(cin, task.task);
	cout << "\n";
	cout << "When is the task due: ";
	clearInput();
	getline(cin, due);

	task.dueDate = parseTime(due);
	return task;
}

static void printTasks(vector<string>& tasks) {
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

static void removeTask(vector<string>& tasks) {
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
	Todo tasks;
	int option;
	Task temp;
	while (true)
	{
		system("cls");
		cout << "Welcome to the task manager! Please enter a number:\n1. Add a new task\n2. View tasks\n3. Mark a task as completed\n4. Exit\n";
		cin >> option;
		system("cls");
		switch (option) {
			case 1:
				temp = getTaskFromUser();
				tasks.tasks.push_back(temp);
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
