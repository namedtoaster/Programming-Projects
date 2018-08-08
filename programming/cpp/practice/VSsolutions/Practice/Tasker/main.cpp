#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>

const char* tasksFile = "tasks";
std::vector<std::string> tasks;
int startSize;

void init() {
	// load the file with all of the tasks
	std::ifstream input;
	input.open(tasksFile);

	// put all saved tasks into the vector
	std::string line;
	while (getline(input, line)) {
		tasks.push_back(line);
	}

	// record how big the vector is so you know where to start saving from after you add new tasks
	startSize = tasks.size();
}

void printRandTask() {
	srand(time(NULL));

	// pick a random number between 0 and vector.size
	int randNum = rand() % tasks.size();

	// display that task
	std::cout << tasks[randNum] << std::endl;
}

void addNewTask() {
	for (int i = 0; i < tasks.size(); i++) {
		std::cout << tasks[i] << std::endl;
	}

	std::cout << "Task: ";
	std::string input;
	getline(std::cin, input);
	tasks.push_back(input);
}

void saveTasks() {
	if (tasks.size() > startSize) {
		std::ofstream output;
		output.open(tasksFile, std::ios::app);

		for (int i = startSize; i < tasks.size(); i++) {
			output << '\n' << tasks[i];
		}
	}
}

int main() {
	// init
	init();

	// print a task
	//printRandTask();

	// add a task
	addNewTask();

	// save new tasks
	saveTasks();

	return 0;
}