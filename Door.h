#pragma once
#include"Platform.h"
#include<SFML/Graphics.hpp>
class Door : public Object
{
public:
	Door(std::string nameTexture, sf::Vector2f size, sf::Vector2f position);
	~Door();
	void OnCollision(Player& player, Vector2f direction, float push);

};
