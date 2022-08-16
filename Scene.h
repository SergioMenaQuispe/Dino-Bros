#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class Scene {
protected:
	sf::Event* event;
	sf::RenderWindow* window;
	sf::Texture txr_background;
	sf::RectangleShape background;
public:
	virtual ~Scene() { delete event; }
	virtual void draw() = 0;
	virtual void events() = 0;
	sf::RenderWindow* GetWindow() { return this->window;  }
};
