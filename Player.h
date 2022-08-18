#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"
#include"GameScene.h"

using namespace std;
using namespace sf;

class Player
{
public:
	Player(std::string nameTexture,string controls, GameScene * game);
	~Player();

	void Update(float deltaTime);
	void Draw(RenderWindow& window);
	void OnCollision(Vector2f direction);
	
	Vector2f GetPosition() { 
		return body.getPosition();  
	}
	Collider GetCollider() { 
		return Collider(body);
	}

	void SetPosition(sf::Vector2f position);

	void setGame(GameScene* game);
	GameScene* getGame();

	void die();
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

	//vidas
	int health;
	
	// game
	GameScene* game;
};