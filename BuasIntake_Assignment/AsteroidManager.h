#pragma once
#include <vector>
#include "Asteroid.h"

class AsteroidManager
{
private:
	std::vector<Asteroid> asteroids;
	int maxAsteroids = 30;
	float spawnTimer = 0.0f;
	float spawnInterval = static_cast<float>(GetRandomValue(2,6));

public:
	void Update(float deltaTime, Vector2 playerPosition);
	void Draw();
	void SpawnAsteroid(Vector2 playerPosition);
};

