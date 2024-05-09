#include "Asteroid.h"

#include <cmath>
#include <iostream>

//TODO: Asteroid Movement (random to player)
//TODO: Asteroid Collision (with player spaceship or laser from spaceship)
//TODO: Load Texture for asteroid // in place but seems to load spaceShip texture
//TODO: Implement Asteroid Rotation
//TODO: Implement Asteroid Destruction (when hit by player laser big asteroids should become 2 smaller)

Asteroid::Asteroid(Vector2 playerPosition)
{
	texture = LoadTexture("../assets/Asteroid/Asteroid.png");

	if (texture.id <= 0)
	{
		std::cerr << "Failed to load texture!" << std::endl;
		// Handle failure, perhaps provide a default texture or exit the program
		CloseWindow();
	}

	position = Vector2{ static_cast<float>(GetRandomValue(0, GetScreenWidth())), static_cast<float>(GetRandomValue(0, GetScreenHeight()) )};

	velocity = Vector2{ static_cast<float>(GetRandomValue(-100, 100)), static_cast<float>(GetRandomValue(-100, 100)) };

	size = static_cast<float>(GetRandomValue(1, 3));
	
}

void Asteroid::Update(float deltaTime)
{
	position.x += velocity.x * deltaTime;
	position.y += velocity.y * deltaTime;
	// add screen wrapping or bounds checking
}

void Asteroid::Draw()
{
	DrawTextureEx(texture, position, 0.0f, size, WHITE);
}

Asteroid::~Asteroid()
{
	UnloadTexture(texture);
}

