#pragma once
#include<SFML/Graphics.hpp>
#include"Scene.h"


class ModeScene : public Scene
{
private:
	int opc;
	sf::Sprite pointer;
	sf::Texture txr_pointer;
	sf::Vector2f pointer_position;
public:
	ModeScene(sf::RenderWindow* window);
	void draw();
	void events();
};