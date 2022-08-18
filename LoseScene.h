#pragma once
#include"Scene.h"
#include"GameScene.h"
#include<SFML/Graphics.hpp>
class LoseScene : public Scene
{
public:
	LoseScene(sf::RenderWindow* window);
	void draw();
	void events();
private:
	GameScene* game;
};

