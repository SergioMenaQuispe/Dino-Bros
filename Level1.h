#pragma once
#include"Level.h"
#include"Platform.h"

class Level1 : public Level
{
public:
	Level1(std::vector<Player>& players) : Level(players){
		for (Player& p : players) {
			p.SetPosition({206.0f, 206.0f});
		}

		label = "level 1";
	}
	
	std::vector<Platform> GetPlatforms() {
		platforms.push_back(Platform("Images/rock.jpg", Vector2f(1200.0f, 200.0f), Vector2f(0.0f, 540.0f)));
		return platforms;
	}
};

