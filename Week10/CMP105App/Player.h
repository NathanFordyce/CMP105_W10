#pragma once
#include "Framework/GameObject.h"
class Player:public GameObject
{
public:
	Player();
	~Player();

	void handleInput(float dt) override;
	void update(float dt) override;
	void collisionResponse(GameObject* collider);

	float scale;
	sf::Vector2f gravity;
	sf::Vector2f stepVelocity;
	sf::Vector2f jumpVector;
	bool isJumping;
};

