#pragma once
#include "SFML/Graphics.hpp"
#include "Collider.h"
#include "Player.h"
#include"Object.h"

using namespace sf;

class Platform : public Object
{
public:
	Platform(std::string nameTexture, Vector2f size, Vector2f position);
	~Platform();
	void OnCollision(Player &player, Vector2f direction, float push);
};


