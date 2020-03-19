#pragma once
#include "Framework/TileMap.h"
class Map:public TileMap
{
public:
	Map();
	~Map();

	void render(sf::RenderWindow* window);

	TileMap tileMap;


};

