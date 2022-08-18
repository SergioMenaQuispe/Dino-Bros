#include "Spike.h"
#include"SceneManager.h"

Spike::Spike(std::string nameTexture, Vector2f size, Vector2f position)
{
	texture = new Texture;
	texture->loadFromFile(nameTexture);

	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setTexture(texture);
	body.setPosition(position);
}

Spike::~Spike()
{

}

void Spike::OnCollision(Player& player, Vector2f direction, float push) {
	if (GetCollider().CheckCollider(player.GetCollider(), direction, 6.0f))
	{
		player.OnCollision(direction);
		player.die();
	}
}
