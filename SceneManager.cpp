#include "SceneManager.h"
#include"GameScene.h"
#include"MenuScene.h"
#include"LoseScene.h"
#include"WinScene.h"

SceneManager* SceneManager::instance = NULL;
std::stack<Scene*> SceneManager::scenes = {};
std::stack<Scene*> SceneManager::trash = {};

SceneManager::~SceneManager() {
	while (!scenes.empty())
	{
		SceneManager::pop();
	}

	clean();
}

SceneManager* SceneManager::getInstance() {
	if (!instance) {
		instance = new SceneManager;
	}

	return instance;
}

/* Creador de escenas */
Scene* SceneManager::createGameScene(sf::RenderWindow* window, int cant_players) { 
	GameScene * scene = new GameScene(window);
	Player* player;
	player = new Player("Images/DinitrioSprite.png", Vector2u(3, 2), "arrows", 0.3f, { 206.0f, 206.0f });
	scene->addPlayers(*player);
	
	if (cant_players == 2) {
		player = new Player("Images/DinoncioSprite.png", Vector2u(3, 2), "letters", 0.3f, { 206.0f, 206.0f });
		scene->addPlayers(*player);
	}

	return scene;
}

Scene* SceneManager::createMenuScene(sf::RenderWindow* window) { return new MenuScene(window); }
Scene* SceneManager::createLoseScene(sf::RenderWindow* window) { return new LoseScene(window); }
Scene* SceneManager::createWinScene(sf::RenderWindow* window) { return new WinScene(window); }


void SceneManager::push(Scene* newScene) {
	scenes.push(newScene);
}

Scene* SceneManager::top() {
	return scenes.top();
}

void SceneManager::pop() {
	Scene* deleted = SceneManager::top();
	scenes.pop();
	trash.push(deleted);
}

void SceneManager::clean() {
	while (!trash.empty()) {
		Scene* deleted = trash.top();
		trash.pop();
		delete deleted;
	}
}