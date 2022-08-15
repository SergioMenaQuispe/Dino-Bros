#pragma once
#include"Scene.h"
#include<SFML/Graphics.hpp>
class WinScene : Scene
{
public:
	WinScene(sf::RenderWindow* window);
	void draw();
	void events();
};

