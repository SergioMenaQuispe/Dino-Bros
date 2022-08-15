#pragma once
#include"Platform.h"
#include"Player.h"
#include<vector>

class Level
{
public:
	Level(std::vector<Player> &players) : players(players){}
	virtual ~Level() = default;
	virtual std::vector<Platform> GetPlatforms() = 0;
	std::string GetLabel() { return this->label; }
protected:
	std::vector<Platform> platforms;
	std::vector<Player> players;
	std::string label;
};
