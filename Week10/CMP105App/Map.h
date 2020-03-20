#pragma once
#include "Framework/TileMap.h"
#include "Framework/Collision.h"
#include "Player.h"

class Map:public TileMap
{
public:
	Map();
	~Map();

	void render(sf::RenderWindow* window);
	void collisionDetection(GameObject* player);

private:
	TileMap tileMap;
	Player player;
	std::vector<GameObject> tiles;
	std::vector<GameObject>* world;

};

