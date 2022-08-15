#pragma once
#include<SFML/Graphics.hpp>
#include"Scene.h"


class MenuScene : public Scene
{
private:
	int opc;
	sf::Sprite pointer;
	sf::Texture txr_pointer;
	sf::Vector2f pointer_position;
public:
	MenuScene(sf::RenderWindow* window);
	void draw();
	void events();
};

