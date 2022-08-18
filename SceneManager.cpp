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
Scene* SceneManager::createGameScene(sf::RenderWindow* window, int cant_players, Level * level) { 
	GameScene * scene = new GameScene(window);
	Player* player;
	player = new Player("Images/DinitrioSprite.png","arrows",scene);
	scene->addPlayers(*player);
	
	if (cant_players == 2) {
		player = new Player("Images/DinoncioSprite.png","letters",scene);
		scene->addPlayers(*player);
	}

	if (level) {
		scene->setLevel(level);
	}

	return scene;
}

Scene* SceneManager::createMenuScene(sf::RenderWindow* window) { return new MenuScene(window); }
Scene* SceneManager::createLoseScene(sf::RenderWindow* window, GameScene* game) { return new LoseScene(window,game); }
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

void SceneManager::goToFirst() {
	while (scenes.size() > 1)
	{
		scenes.pop();
	}
}