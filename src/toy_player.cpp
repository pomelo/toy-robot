#include <iostream>

#include "toy_player.h"
#include "toy_robot.h"

using namespace std;

toy_player::toy_player() {
	robot = new toy_robot();
}

toy_player::~toy_player() {
	if (robot) {
		delete robot;
		robot = nullptr;
	}
}

void toy_player::play(istream &input, ostream &output) {
	string command, direction;
	char delimitator; // only used to pass the commas in PLACE command
	int x, y;

	if (!robot) {
		return;
	}

	while (true) {
		input >> command;
		// case sensitive
		if (command == "PLACE") {
			// NOT accept the form of `PLACE 0 1 NORTH`
			input >> x >> delimitator >> y >> direction;
			direction.erase(0, direction.find_first_not_of(" ,"));
			robot->place(x, y, direction);
		} else if (command == "MOVE") {
			robot->move();
		} else if (command == "LEFT") {
			robot->left();
		} else if (command == "RIGHT") {
			robot->right();
		} else if (command == "REPORT") {
			robot->report(output);
			// End the game
			break;
		} else {
			// Or, end with an invalid command
			break;
		}
		command.clear();
		direction.clear();
	}
}
