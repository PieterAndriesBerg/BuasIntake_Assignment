#pragma once
#include "../lib/raylib.h"
class Spaceship
{
public:

	// Constants
	static constexpr float ACCELERATION = 25.0f;
	static constexpr float DECELERATION = 0.95f;
	static constexpr float MAX_SPEED = 100.0f;
	static constexpr float SCALE_FACTOR = 1.2f;


	// Attributes
	float speed;
	float x;
	float y;
	float velocityX;
	float velocityY;
	float scaleFactor;
	float rotation;
	float rotationRadians;
	Texture2D texture;

	// Constructor
	Spaceship();
	
	

	// Destructor
	~Spaceship();

	void Update(float deltaTime);
	void Draw();
	void HandleInput(float deltaTime);
};

