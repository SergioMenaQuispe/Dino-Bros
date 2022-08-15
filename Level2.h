#pragma once
#include"Level.h"
#include"Platform.h"

class Level2 : public Level
{
public:
	Level2(std::vector<Player>& players) : Level(players) {
		for (Player& p : players) {
			p.SetPosition({300.0f, 300.0f});
		}

		label = "level 2";
	}

	std::vector<Platform> GetPlatforms() {
		platforms.push_back(Platform("Images/rock.jpg", Vector2f(20.0f, 1200.0f), Vector2f(100.0f, 600.0f)));
		return platforms;
	}
};