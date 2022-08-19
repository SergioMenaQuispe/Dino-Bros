#include "Player.h"
#include<iostream>
using namespace sf;

Player::Player(std::string nameTexture, std::string controls, int health)
{
		this->controls = controls;
		this->speed = 200.0f;
		this->jumpHeight = 100.0f;

		row = 0;
		faceRight = true;

		texture = new Texture;
		texture->loadFromFile(nameTexture);

		body.setSize(Vector2f(50.0f, 50.0f));
		body.setOrigin(body.getSize() / 2.0f);
		body.setPosition({ 206.0f, 206.0f });
		body.setPosition(50.0f, 500.0f);
		body.setTexture(texture);

		animation = new Animation(texture, Vector2u(3, 2), 0.3f);

		this->health = health;
}

Player::~Player()
{

}
void Player::Update(float deltaTime)
{   //Velocity tiene que ver con la gravedad
	velocity.x = 0.0f;

	if(controls == "letters"){

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			velocity.x -= speed;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			velocity.x += speed;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canJump)
		{
			canJump = false;

			velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
		}

	}
	else if(controls == "arrows"){

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			velocity.x -= speed;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			velocity.x += speed;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && canJump)
		{
			canJump = false;
			velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
		}

	}


	velocity.y += 981.0f * deltaTime;

	if (velocity.x == 0.0f)
	{
		row = 0;

	}
	else
	{
		row = 1;

		if (velocity.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}
	animation->Update(row, deltaTime, faceRight);
	body.setTextureRect(animation->uvRect);
	body.move(velocity * deltaTime);
}

void Player::Draw(RenderWindow& window) 
{
	window.draw(body);

}

void Player::OnCollision(Vector2f direction)
{
	if (direction.x < 0.0f)
	{   
		//Colision on the left
		velocity.x = 0.0f;

	}
	else if (direction.x > 0.0f)
	{
		//Colision on the right 
		velocity.x = 0.0f;
	}
	if (direction.y < 0.0f)
	{
		//Colision on the bottom(creo que es abajo)
		velocity.y = 0.0f;
		canJump = true;
	}
	else if (direction.y > 0.0f)
	{
		//Colision con arriba
		velocity.y = 0.0f;
	}
}

void Player::SetPosition(sf::Vector2f position) {
	body.setPosition(position);	
	this->initialPosition = position;
}

void Player::die() {
	health--;
	body.setPosition(initialPosition);
}