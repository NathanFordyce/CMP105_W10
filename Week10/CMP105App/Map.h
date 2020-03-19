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

	TileMap tileMap;
	Player player;

};

