// TODO: change data type to be unsigned int

#include "C:\raylib\w64devkit\x86_64-w64-mingw32\include\raylib.h"
#include "walk.h"
#include <stdio.h>

int main() {
	const int SCREENWIDTH = 900, SCREENHEIGHT = 700;
	int num_steps = 50000;
	int num_people = 10;
	int step_length = 1;
	int current_step = 0;
	int step_adder = 1000;
	char buffer[20]; // buffer to hold converted integer
	Color background_color = {4, 13, 18};
	RandomWalk randomWalk = RandomWalk(SCREENWIDTH, SCREENHEIGHT, num_steps, num_people, step_length);
	randomWalk.random_walk();

	InitWindow(SCREENWIDTH, SCREENHEIGHT, "Random Walk");
	while (!WindowShouldClose()) {
		if (IsKeyPressed(KEY_SPACE)) {
			randomWalk.random_walk();
			current_step = 0;
		}
		sprintf(buffer, "Steps: %d", current_step);
		BeginDrawing();
			ClearBackground(background_color);			
			randomWalk.draw_walk(current_step);
			DrawText("Press <SPACE> for rewalk", 10, 10, 20, RAYWHITE);
			DrawText(buffer, 10, 40, 20, RAYWHITE);
		EndDrawing();
		if (current_step + step_adder <= num_steps) current_step += step_adder;
	}
	CloseWindow();
	return 0;
}
