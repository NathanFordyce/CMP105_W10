#include "Player.h"
Player::Player()
{

}

Player::~Player()
{

}

void Player::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::D))
	{
		move(velocity * dt);
	}
	else if (input->isKeyDown(sf::Keyboard::A))
	{
		move(-velocity * dt);
	}

}

void Player::update(float dt)
{

}