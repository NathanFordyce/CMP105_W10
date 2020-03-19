#include "Player.h"
Player::Player()
{
	scale = 200.f;
	gravity = sf::Vector2f(0, 9.8f) * scale;
	jumpVector = sf::Vector2f(0, -4.0f) * scale;
	isJumping = false;
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

	//Check if already jumping
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		if (!isJumping)
		{
			stepVelocity = jumpVector;
			isJumping = true;
		}
	}


}

void Player::update(float dt)
{
	sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt; //ut + 1/2at^2
	stepVelocity += gravity * dt; // v = u + at
	setPosition(getPosition() + pos);

	//Check for collision with floor
	if (getPosition().y >= 500)
	{
		isJumping = false;
		setPosition(getPosition().x, 500);
		stepVelocity = sf::Vector2f(0, 0);
	}
}

void Player::collisionResponse(GameObject* collider)
{
	velocity.y = 0;
	setPosition(getPosition().x, collider->getPosition().y - getSize().y);
}