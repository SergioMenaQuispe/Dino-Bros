#pragma once
#include"Player.h"
#include"Platform.h"
#include"Spike.h"
#include"Door.h"
#include<vector>

/* el estado abstracto (patron state)*/
class Level
{
public:
	Level() {}
	virtual ~Level() = default;
	virtual void setPlayersPosition(std::vector<Player>& players) = 0;
	
	void setObjects(std::vector<Platform>& platforms, std::vector<Spike>& spikes, std::vector<Door>& doors) {
		platforms = GetPlatforms();
		spikes = GetSpikes();
		doors = GetDoors();
	}

	void setBackground(sf::RectangleShape &background) {
		background.setTexture(&txr_background);
	}

	virtual std::vector<Platform> GetPlatforms() = 0;
	virtual std::vector<Spike> GetSpikes() = 0;
	virtual std::vector<Door> GetDoors() = 0;
	std::string GetLabel() { return this->label; }
	

protected:
	std::vector<Platform> platforms;
	std::vector<Spike> spikes;
	std::vector<Door> doors;
	std::string label;
	sf::Texture txr_background;
};
