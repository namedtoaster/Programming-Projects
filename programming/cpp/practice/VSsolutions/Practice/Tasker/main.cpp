#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>

int main() {
	// init
		// load the file with all of the tasks
	std::ifstream input;
	input.open("tasks");
	
		// put each task into the task vector (just strings)
	std::vector<std::string> tasks;
	std::string line;
	
	while (getline(input, line)) {
		tasks.push_back(line);
	}

	// run
	srand(time(NULL));

		// pick a random number between 0 and vector.size
	int randNum = rand() % tasks.size();

		// display that task
	std::cout << tasks[randNum] << std::endl;

	return 0;
}