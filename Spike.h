#pragma once
#include"Platform.h"
#include<SFML/Graphics.hpp>
class Spike : public Object
{
public:
	Spike(std::string nameTexture, sf::Vector2f size, sf::Vector2f position);
	~Spike();
	void OnCollision(Player& player, Vector2f direction, float push);

};

