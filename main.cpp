#include<iostream>
#include<SFML/Graphics.hpp>
#include"SceneManager.h"
#include"Scene.h"
#include<memory>
using namespace sf;

class Main {
	
};

int main() {


	RenderWindow* window = new RenderWindow(VideoMode(800, 600), "SFML", Style::Close | Style::Resize);
	
	std::unique_ptr<SceneManager> manager{SceneManager::getInstance()};

	manager->push(SceneManager::createMenuScene(window));
	while (window->isOpen())
	{
		manager->top()->draw();
		window->display();
	}
	
	delete window;

	return 0;
}

