#pragma once
#include "raylib.h"
class Asteroid
{
public:
	// Attributes
	Vector2 position;
	Vector2 velocity;
	float size;
	Texture2D texture_asteroid;

	Asteroid(Vector2 playerPosition);
	~Asteroid();

	void Update(float deltaTime);
	void Draw();

};
