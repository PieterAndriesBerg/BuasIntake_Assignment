#include "AsteroidManager.h"

void AsteroidManager::Update(float deltaTime, Vector2 playerPosition)
{
	spawnTimer += deltaTime;

	if (spawnTimer >= spawnInterval)
	{
		SpawnAsteroid(playerPosition);
		spawnTimer = 0.0f;
		spawnInterval = static_cast<float>(GetRandomValue(2, 6));
	}

	for (auto& asteroid : asteroids)
	{
		asteroid.Update(deltaTime);
	}

}

void AsteroidManager::Draw()
{
	for (auto& asteroid : asteroids) {
		asteroid.Draw();
	}
}

void AsteroidManager::SpawnAsteroid(Vector2 playerPosition)
{
	if (asteroids.size() < maxAsteroids)
	{
		asteroids.push_back(Asteroid(playerPosition));
	}
}
