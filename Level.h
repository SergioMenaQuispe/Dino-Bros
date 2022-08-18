#pragma once
#include"Platform.h"
#include"Player.h"
#include"Spike.h"
#include<vector>

/* el estado abstracto (patron state)*/
class Level
{
public:
	Level() {}
	virtual ~Level() = default;
	virtual void setPlayersPosition(std::vector<Player>& players) = 0;
	
	void setObjects(std::vector<Platform>& platforms, std::vector<Spike>& spikes) {
		platforms = GetPlatforms();
		spikes = GetSpikes();
	}

	void setBackground(sf::RectangleShape &background) {
		background.setTexture(&txr_background);
	}
	virtual std::vector<Platform> GetPlatforms() = 0;
	virtual std::vector<Spike> GetSpikes() = 0;
	std::string GetLabel() { return this->label; }
protected:
	std::vector<Platform> platforms;
	std::vector<Spike> spikes;
	std::string label;

	sf::Texture txr_background;
};
