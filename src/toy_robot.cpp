#include <iostream>
#include <map>
#include <string>

#include "toy_robot.h"

using namespace std;

// used to get direction enum from input string
map<string, facing_enum> direction_map = {{"NORTH", facing_enum::north},
										  {"SOUTH", facing_enum::south},
										  {"EAST", facing_enum::east},
										  {"WEST", facing_enum::west}};

toy_robot::toy_robot() {
	created = false;
}

toy_robot::~toy_robot() {
}

string toy_robot::get_facing() {
	// or using a reversed map
	for (auto &it : direction_map) {
		if (it.second == facing) {
			return it.first;
		}
	}

	return "Incorrect direction";
}

void toy_robot::place(int x, int y, string direction) {
	auto dir = direction_map.find(direction);
    
	if (x >= 0 && x <= 4 && y >= 0 && y <= 4 && dir != direction_map.end()) {
		pos_x = x;
		pos_y = y;
		facing = dir->second;
		created = true;
	} else {
		created = false;
	}
}

void toy_robot::move() {
	if (!created) {
		return;
	}

	switch (facing) {
	case facing_enum::north:
		pos_y++;
		break;

	case facing_enum::south:
		pos_y--;
		break;

	case facing_enum::east:
		pos_x++;
		break;

	case facing_enum::west:
		pos_x--;
		break;

	default:
		break;
	}

	// ignore invalid move
	pos_x = min(max(0, pos_x), 4);
	pos_y = min(max(0, pos_y), 4);
}

void toy_robot::left() {
	if (created) {
		facing = static_cast<facing_enum>((static_cast<int>(facing) + 3) % 4);
	}
}

void toy_robot::right() {
	if (created) {
		facing = static_cast<facing_enum>((static_cast<int>(facing) + 5) % 4);
	}
}

void toy_robot::report(ostream &std_output) {
	if (!created) {
		std_output << "Please place the robot to a proper spot first." << endl;
	} else {
		std_output << pos_x << "," << pos_y << "," << get_facing() << endl;
	}
}
