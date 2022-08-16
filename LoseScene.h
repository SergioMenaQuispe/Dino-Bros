#pragma once
#include"Scene.h"
#include<SFML/Graphics.hpp>
class LoseScene : public Scene
{
public: 
	LoseScene(sf::RenderWindow* window);
	void draw();
	void events();
};

