#pragma once
#include<SFML/Graphics.hpp>
#include"Collider.h"
#include"Player.h"

class Object
{
public:
	~Object(){}
	void Draw(sf::RenderWindow& window) 
	{
		window.draw(body);
	}

	Collider GetCollider() { return Collider(body); }
	virtual void OnCollision(Player& player, sf::Vector2f direction, float push) = 0;
protected:
	sf::Texture* texture;
	sf::RectangleShape body;
};
