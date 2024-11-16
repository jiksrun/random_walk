#ifndef WALK_H_INCLUDED
#define WALK_H_INCLUDED

#include "C:\raylib\w64devkit\x86_64-w64-mingw32\include\raylib.h"

class RandomWalk {
	private:
		Vector2** pos;
		Color* colors;
		int SCREENWIDTH, SCREENHEIGHT;
		int num_steps;
		int num_people;
		int step_length;
		Vector2* makePos1D();
		Vector2** makePos();
		Color* makeColor();
	public:
		RandomWalk(const int SCREENWIDTH, const int SCREENHEIGHT, int num_steps, int num_people, int step_length);
		void random_walk();
		void draw_walk(int step);
		~RandomWalk();
};

#endif // WALK_H_INCLUDED
