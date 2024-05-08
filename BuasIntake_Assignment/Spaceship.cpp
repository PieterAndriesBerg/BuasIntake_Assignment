#include "Spaceship.h"
#include <cmath>
#include <iostream>


//TODO: Implement Health and Damage
//TODO: Implement Shooting
//TODO: Implement Collisions
//TODO: Implement Scoring
//TODO: Implement Game Over ( Lifes 3x then Game Over)
//TODO: Implement Powerups (maybe if enough time)

Spaceship::Spaceship():
	speed(0.0f), x(GetScreenWidth() / 2), y(GetScreenHeight() / 2), velocityX(0.0f), velocityY(0.0f), scaleFactor(SCALE_FACTOR), rotation(0.0f), rotationRadians(0.0f)
{
	texture = LoadTexture("../assets/Spaceship/Spaceship-full-health.png");
	SetTextureFilter(texture, TEXTURE_FILTER_TRILINEAR); // Makes the texture smoother when upscaled
}

Spaceship::~Spaceship()
{
	UnloadTexture(texture);
}

void Spaceship::Update(float deltaTime)
{
    // Recalculate rotationRadians based on the current rotation
    rotationRadians = rotation * (PI / 180.0f);

    // Apply deceleration
    velocityX *= DECELERATION;
    velocityY *= DECELERATION;

    // Update position based on velocity
    x += velocityX;
    y += velocityY;

		
    std::cout << "Position: (" << x << ", " << y << "), Rotation: " << rotation << std::endl;

    // Screen boundaries
    if (x < 0) 
    {
        x = 0;
    }
    else if (x > GetScreenWidth() - texture.width) 
    {
		x = GetScreenWidth() - texture.width;
    }

	if (y < 0)
	{
		y = 0;
	}
	else if (y > GetScreenHeight() - texture.height)
	{
		y = GetScreenHeight() - texture.height;
	}

}

void Spaceship::Draw()
{
    // Calculate the center of the texture
    Vector2 origin = { texture.width / 2.0f * SCALE_FACTOR, texture.height / 2.0f * SCALE_FACTOR };

    // Define the source rectangle (use the entire texture)
    Rectangle sourceRec = { 0.0f, 0.0f, static_cast<float>(texture.width), static_cast<float>(texture.height) };

    // Define the destination rectangle
    Rectangle destRec = { x + origin.x, y + origin.y, texture.width * SCALE_FACTOR, texture.height * SCALE_FACTOR };

    // Adjust rotation to match the sprite's orientation
    float adjustedRotation = rotation + 90.0f;

    // Draw the texture rotated around its center
    DrawTexturePro(texture, sourceRec, destRec, origin, adjustedRotation, WHITE);
}

void Spaceship::HandleInput(float deltaTime)
{
    // Movement
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
    {
        // Accelerate the spaceship in the direction it's currently facing
        velocityX += cos(rotationRadians) * ACCELERATION * deltaTime;
        velocityY += sin(rotationRadians) * ACCELERATION * deltaTime;

        // Clamp velocity to maxSpeed
        speed = sqrt(velocityX * velocityX + velocityY * velocityY);
        if (speed > MAX_SPEED)
        {
            velocityX = (velocityX / speed) * MAX_SPEED;
            velocityY = (velocityY / speed) * MAX_SPEED;
        }
    }
    // Rotation controls
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
    {
        rotation -= 200.0f * deltaTime;
    }
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
    {
        rotation += 200.0f * deltaTime;
    }

}
