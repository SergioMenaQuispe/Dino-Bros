#pragma once
#include"Level.h"
#include"Platform.h"


/* El estado 2*/
class Level2 : public Level
{
public:
	Level2() {
		label = "level 2";
	}

	void setPlayersPosition(std::vector<Player>& players) {
		for (Player& p : players) {
			p.SetPosition({ 100.0f, 0.0f });
		}
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