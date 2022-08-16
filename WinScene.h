#pragma once
#include"Scene.h"
#include<SFML/Graphics.hpp>
class WinScene : public Scene
{
public:
	WinScene(sf::RenderWindow* window);
	void draw();
	void events();
};

