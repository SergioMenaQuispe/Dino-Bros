#pragma once
#include"Scene.h"
#include"Level.h"
#include"GameScene.h"
#include<stack>

// funciona como singleton y como abstract factory

class SceneManager
{
private:
	static SceneManager* instance;
	static std::stack<Scene*>scenes;
	static std::stack<Scene*>trash;
public:
	~SceneManager();

	static SceneManager* getInstance();

	static Scene* createGameScene(sf::RenderWindow* window, int cant_players, Level * level);
	static Scene* createMenuScene(sf::RenderWindow* window);
	static Scene* createLoseScene(sf::RenderWindow* window, GameScene * game);
	static Scene* createWinScene(sf::RenderWindow* window);

	static void clean();

	static void push(Scene* newScene);
	static Scene* top();
	static void pop();
	static void goToFirst();
};

