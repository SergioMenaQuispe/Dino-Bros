#include<iostream>
#include<SFML/Graphics.hpp>
#include"SceneManager.h"
#include"Scene.h"
using namespace sf;

int main() {

	RenderWindow* window = new RenderWindow(VideoMode(800, 600), "SFML", Style::Close | Style::Resize);

	SceneManager* manager = SceneManager::getInstance();

	manager->push(SceneManager::createMenuScene(window));

	while (window->isOpen())
	{
		manager->top()->draw();
		window->display();
	}

	delete window;
	delete manager;

	return 0;
}

