#include <cstdio>

#include "raylib.h"
#include "Spaceship.h"

int main()
{
	// Dimensions of game window;
	int windowWidth = 1920;
	int windowHeight = 1080;
	Color backgroundColor = { 16,15,15,1 };
	
	InitWindow(windowWidth, windowHeight, "Spaceship Saviors: Asteroid Rescue");
	SetTargetFPS(60);

	// Load game objects here
	Spaceship spaceship = Spaceship();

	//Game Loop
	while(!WindowShouldClose())
	{

		//Calculate delta time
		float deltaTime = GetFrameTime();

		BeginDrawing();
		ClearBackground(backgroundColor);

		// Handle Input
		spaceship.HandleInput(deltaTime);


		// Draw game objects here
		spaceship.Draw();


		// Update game objects here
		spaceship.Update(deltaTime);
		

		



		EndDrawing();
	}


	CloseWindow();
	return 0;
}