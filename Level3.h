#pragma once
#include"Level.h"
#include"Platform.h"

class Level3 : public Level
{
public:
	Level3(std::vector<Player>& players) : Level(players) {
		for (Player& p : players) {
			p.SetPosition({ 406.0f, 406.0f });
		}

		label = "level 3";
	}

	std::vector<Platform> GetPlatforms() {
		platforms.push_back(Platform("Images/rock.jpg", Vector2f(20.0f, 1200.0f), Vector2f(600.0f, 600.0f)));
		return platforms;
	}


	std::vector<Spike> GetSpikes() {
		spikes.push_back(Spike("pua_02", Vector2f(50.0f, 50.0f), Vector2f(120.0f, 490.0f)));
		return spikes;
	}
};

