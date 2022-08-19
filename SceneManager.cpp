#include "SceneManager.h"
#include"GameScene.h"
#include"MenuScene.h"
#include"ModeScene.h"
#include"LoseScene.h"
#include"WinScene.h"
#include"Health.h"

SceneManager* SceneManager::instance = NULL;
std::stack<Scene*> SceneManager::scenes = {};
std::stack<Scene*> SceneManager::trash = {};
int SceneManager::difficult = 2;

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
Scene* SceneManager::createGameScene(sf::RenderWindow* window, int cant_players, int difficult) { 
	GameScene * scene = new GameScene(window, difficult);
	Player* player;
	
	Health h;

	player = new Player("Images/DinitrioSprite.png","arrows",h(difficult));
	scene->addPlayers(*player);
	
	if (cant_players == 2) {
		player = new Player("Images/DinoncioSprite.png","letters",h(difficult));
		scene->addPlayers(*player);
	}

	return scene;
}

Scene* SceneManager::createMenuScene(sf::RenderWindow* window) { return new MenuScene(window); }
Scene* SceneManager::createModeScene(sf::RenderWindow* window) { return new ModeScene(window); }
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

void SceneManager::goToMenu() {
	while (scenes.size() > 0)
	{
		pop();
	}
}

void SceneManager::clean() {
	while (!trash.empty()) {
		Scene* deleted = trash.top();
		trash.pop();
		delete deleted;
	}
}

void SceneManager::setDifficult(int difficult) {
	SceneManager::difficult = difficult;
}

int SceneManager::getDifficult() {
	return difficult;
}
