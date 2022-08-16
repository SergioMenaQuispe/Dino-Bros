#pragma once
#include"Level.h"
#include"Platform.h"
#include"Spike.h"

class Level1 : public Level
{
public:
	Level1(std::vector<Player>& players) : Level(players){
		for (Player& p : players) {
			p.SetPosition({106.0f, 106.0f});
		}

		label = "level 1";
	}
	
	std::vector<Platform> GetPlatforms() {
		platforms.push_back(Platform("Images/rock.jpg", Vector2f(1200.0f, 200.0f), Vector2f(0.0f, 540.0f)));
		return platforms;
	}

	std::vector<Spike> GetSpikes() {
		spikes.push_back(Spike("Images/pua_02.png", Vector2f(50.0f, 50.0f), Vector2f(120.0f, 300.0f)));
		return spikes;
	}
};

