#pragma once
#include<SFML/Graphics.hpp>
#include"Scene.h"
#include"Player.h"
#include"Platform.h"
#include"Spike.h"
#include"Level.h"
#include<vector>

class GameScene : public Scene
{
private:
	vector<Player> players;
	vector<Platform> platforms;
	vector<Spike> spikes;

	sf::View* view;
	float deltaTime;
	sf::Clock clock;
	float VIEW_HEIGHT;

	Level* level;
	int wins;

public:
	GameScene(sf::RenderWindow* window, int difficult);
	void draw();
	void events();

	void addPlayers(Player &p);
	void ResizeView();

	void setLevel(Level* level);

	void changeLevel();

	template<typename structure>
	void CheckCollisions(std::vector<structure> collection);
	
	int difficult;

};

