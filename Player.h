#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"

using namespace std;
using namespace sf;

class Player
{
public:
	Player(std::string nameTexture, string controls, int health);
	~Player();

	void Update(float deltaTime);
	void Draw(RenderWindow& window);
	void OnCollision(Vector2f direction);
	
	Vector2f GetPosition() { 
		return body.getPosition();  }
	Collider GetCollider() { 
		return Collider(body);
	}

	void SetPosition(sf::Vector2f position);

	void die();
	bool alive();
	int getHealth();

	void setWin(bool state);
	bool isWinner();
private:
	Texture* texture;
	RectangleShape body;
	Animation* animation;

	unsigned int row;
	float speed;
	
	bool faceRight;

	// controles
	string controls;

	//Esto es lo de gravedad y salto
	Vector2f velocity;
	bool canJump;
	float jumpHeight;

	int health;

	// posicion incial del nivel en el que se encuentra
	Vector2f initialPosition;

	bool winner;
};