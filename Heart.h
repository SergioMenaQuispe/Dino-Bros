#pragma once
#include<SFML/Graphics.hpp>

class Heart {
private:
	sf::Texture texture;
	sf::RectangleShape body;
public:
	Heart(sf::Vector2f position) {
		texture.loadFromFile("Images/corazon_of.png");
		body.setTexture(&texture);
		body.setPosition(position);
		body.setScale({ 50,60 });
	}

	sf::RectangleShape getBody() {
		return body;
	}
};