#include "walk.h"
#include <iostream>

RandomWalk::RandomWalk(const int SCREENWIDTH, const int SCREENHEIGHT, int num_steps, int num_people, int step_length) {
    SetRandomSeed(time(NULL));
	this->num_steps = num_steps; 
	this->num_people = num_people;
	this->SCREENWIDTH = SCREENWIDTH;
	this->SCREENHEIGHT = SCREENHEIGHT;
	this->step_length = step_length;
	this->colors = makeColor();
    pos = makePos();
}

RandomWalk::~RandomWalk() {
	for (int i = 0; i < num_people; ++i) delete[] pos[i];
	delete[] pos;
}

Vector2* RandomWalk::makePos1D() {
	Vector2* position1D = new Vector2[num_steps];
	return position1D;
}

Vector2** RandomWalk::makePos() {
	Vector2** positions2D = new Vector2*[num_people];
	for (int i = 0; i < num_people; ++i) {
		positions2D[i] = makePos1D();
		(positions2D[i])[0].x = SCREENWIDTH / 2.0;
		(positions2D[i])[0].y = SCREENHEIGHT / 2.0;
	}
	return positions2D;
}

Color* RandomWalk::makeColor() {
	Color* colors = new Color[num_people];
	int r,g,b;
	for (int i = 0; i < num_people; ++i) {
		r = GetRandomValue(0, 255);
		g = GetRandomValue(0, 255);
		b = GetRandomValue(0, 255);
		colors[i] = {(unsigned char)r, (unsigned char)g, (unsigned char)b, 255};
	}
	return colors;
}

void RandomWalk::random_walk() {
	for (int i = 0; i < num_steps-1; ++i) {
		for (int j = 0; j < num_people; ++j) {
			Vector2* endPos = &((pos[j])[i]);
			switch (GetRandomValue(0, 3)) {
				case 0:
					endPos->x += step_length;
					break;
				case 1:
					endPos->x -= step_length;
					break;
				case 2:
					endPos->y += step_length;
					break;
				case 3:
					endPos->y -= step_length;
					break;
			}
			(pos[j])[i+1] = *endPos;
		}
	}
}

void RandomWalk::draw_walk(int step) {
	for (int i = 0; i < step-1; ++i) {
		for (int j = 0; j < num_people; ++j) {
			DrawLineV(pos[j][i], pos[j][i+1], colors[j]);
		}
	}
}
