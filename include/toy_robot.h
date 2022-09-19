#ifndef TOY_ROBOT_H
#define TOY_ROBOT_H

enum class facing_enum { east = 0, south = 1, west = 2, north = 3 };

class toy_robot {
	// can expand into a factory pattern design.
private:
	/* properties */
	int pos_x, pos_y;
	facing_enum facing;
	// flag indicating the robot's status
	bool created;

private:
	std::string get_facing();

public:
	toy_robot();
	~toy_robot();

    // action commands
	void place(int x, int y, std::string direction);
	void move();
	void left();
	void right();
	void report(std::ostream &std_output);
};

#endif // TOY_ROBOT_H
