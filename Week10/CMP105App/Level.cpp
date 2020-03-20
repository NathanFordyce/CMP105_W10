#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	sprite.loadFromFile("gfx/Mushroom.png");
	player.setTexture(&sprite);
	player.setSize(sf::Vector2f(50, 50));
	player.setPosition(0, 200);
	player.setCollisionBox(sf::FloatRect(0, 0, 50, 50));
	player.setVelocity(100, 0);
	player.setInput(input);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	player.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	player.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(player);
	map.render(window);
	map.collisionDetection(&player);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}