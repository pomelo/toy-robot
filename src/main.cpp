#include <iostream>

#include "toy_robot.h"

using namespace std;

void play_toy() {
	string command, direction;
	char delimitator;		// only used to pass the commas in PLACE command
	int x, y;

	toy_robot robot;

	while (true) {
		cin >> command;
		// case sensitive
		if (command == "PLACE") {
			// NOT accept the form of `PLACE 0 1 NORTH`
			cin >> x >> delimitator >> y >> direction;
			direction.erase(0, direction.find_first_not_of(" ,"));
			robot.place(x, y, direction);
		} else if (command == "MOVE") {
			robot.move();
		} else if (command == "LEFT") {
			robot.left();
		} else if (command == "RIGHT") {
			robot.right();
		} else if (command == "REPORT") {
			robot.report(cout);
			// End the game
			break;
		} else {
			// Or, end here
			break;
		}
		command.clear();
		direction.clear();
	}
}

int main() {
	play_toy();
}
