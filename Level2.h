#pragma once
#include"Level.h"
#include"Platform.h"

class Level2 : public Level
{
public:
	Level2(std::vector<Player>& players) : Level(players) {
		for (Player& p : players) {
			p.SetPosition({100.0f, 0.0f});
		}

		label = "level 2";
	}

	std::vector<Platform> GetPlatforms() {
		platforms.push_back(Platform("Images/rock.jpg", Vector2f(500.0f, 100.0f), Vector2f(50.0f, 500.0f)));
		return platforms;
	}


	std::vector<Spike> GetSpikes() {
		spikes.push_back(Spike("pua_02", Vector2f(50.0f, 50.0f), Vector2f(120.0f, 490.0f)));
		return spikes;
	}
};