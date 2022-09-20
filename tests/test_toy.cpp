#include <iostream>

#include <gtest/gtest.h>

#include "toy_player.h"
#include "toy_robot.h"

using namespace std;

TEST(toy_robot_suite, invalid_place_toy) {
	// test the toy should ignore all command until a valid PLACE command comes

	string expected = "Please place the robot to a proper spot first.\n";
	ostringstream fake_cout;

	toy_robot robot;

	robot.place(-1, 0, "NORTH"); // out of boundary
	robot.place(1, 5, "NORTH");  // out of boundary
	robot.left();				 // not placed
	robot.move();				 // not placed
	robot.report(fake_cout);
	EXPECT_EQ(fake_cout.str(), expected);
}

TEST(toy_robot_suite, place_toy) {
	// place the toy
	string expected = "2,3,NORTH\n";
	ostringstream fake_cout;

	toy_robot robot;
	robot.place(2, 3, "NORTH");
	robot.report(fake_cout);
	EXPECT_EQ(fake_cout.str(), expected);
}

TEST(toy_robot_suite, move_toy) {
	// move the toy robot
	string expected = "2,4,SOUTH\n";
	ostringstream fake_cout;

	toy_robot robot;
	robot.place(2, 3, "NORTH");
	robot.move();
	robot.move();
	robot.right();
	robot.right();
	robot.report(fake_cout);
	EXPECT_EQ(fake_cout.str(), expected);
}

TEST(toy_play_suite, play_1) {
	// play toy robot by commands
	string test_input = "PLACE 0,0,NORTH\nMOVE\nREPORT\n";
	string expected = "0,1,NORTH\n";
	stringstream fake_cin(test_input);
	ostringstream fake_cout;

	toy_player player;
	player.play(fake_cin, fake_cout);
	EXPECT_EQ(fake_cout.str(), expected);
}

TEST(toy_play_suite, play_2) {
	// play toy robot by commands
	string test_input = "PLACE 0,0,NORTH\nLEFT\nREPORT\n";
	string expected = "0,0,WEST\n";
	stringstream fake_cin(test_input);
	ostringstream fake_cout;

	toy_player player;
	player.play(fake_cin, fake_cout);
	EXPECT_EQ(fake_cout.str(), expected);
}

TEST(toy_play_suite, play_3) {
	// play toy robot by commands
	string test_input = "PLACE 1,2,EAST\nMOVE\nMOVE\nLEFT\nMOVE\nREPORT";
	string expected = "3,3,NORTH\n";
	stringstream fake_cin(test_input);
	ostringstream fake_cout;

	toy_player player;
	player.play(fake_cin, fake_cout);
	EXPECT_EQ(fake_cout.str(), expected);
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
