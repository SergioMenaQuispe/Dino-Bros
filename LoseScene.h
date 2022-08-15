#pragma once
#include"Scene.h"
#include<SFML/Graphics.hpp>
class LoseScene : Scene
{
public: 
	LoseScene(sf::RenderWindow* window);
	void draw();
	void events();
};

