#ifndef TOY_PLAYER_H
#define TOY_PLAYER_H

class toy_robot;

class toy_player {
	// a simple factory
private:
	toy_robot *robot;

public:
	toy_player();
	~toy_player();

	/**
	 * read from input (file/stdin) and play the toy
	 *
	 * using input/output streams as param so that this can read from file or
	 * command line, and a good way to adopt the testing framework
	 *
	 * @param input the input stream
	 * @param output the output stream
	 */
	void play(std::istream &input, std::ostream &output);
};

#endif // TOY_PLAYER_H
