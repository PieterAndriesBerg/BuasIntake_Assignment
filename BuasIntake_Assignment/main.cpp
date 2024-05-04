#include <cstdio>

#include "raylib.h"

int main()
{
	// Dimensions of game window;
	int windowWidth = 1280;
	int windowHeight = 720;
	Color backgroundColor = { 16,15,15,1 };
	
	InitWindow(windowWidth, windowHeight, "Spaceship Saviors: Asteroid Rescue");
	SetTargetFPS(60);

	//Game Loop
	while(!WindowShouldClose())
	{

		BeginDrawing();
		ClearBackground(backgroundColor);




		EndDrawing();
	}


	CloseWindow();
	return 0;
}