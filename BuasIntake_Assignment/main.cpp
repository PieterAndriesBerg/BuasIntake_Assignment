#include <cstdio>
#include <vector>
#include "raylib.h"
#include "Asteroid.h"
#include "AsteroidManager.h"
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
	Spaceship spaceship;
	AsteroidManager asteroidManager;

	float asteroidSpawnTimer = 0.0f; // Timer to keep track of when to spawn an asteroid
	float asteroidSpawnInterval = 2.0f; // Spawn an asteroid every 2 seconds
	

	//Game Loop
    while (!WindowShouldClose())
    {
        //Calculate delta time
        float deltaTime = GetFrameTime();

        // Handle Input
        spaceship.HandleInput(deltaTime);

        // Update game objects here
        spaceship.Update(deltaTime);
		asteroidManager.Update(deltaTime, Vector2{ spaceship.x,spaceship.y });


        // Drawing
        BeginDrawing();
        ClearBackground(backgroundColor);

        // Draw game objects here
        spaceship.Draw();
		asteroidManager.Draw();

        EndDrawing();
    }


	spaceship.~Spaceship();
	CloseWindow();
	return 0;
}