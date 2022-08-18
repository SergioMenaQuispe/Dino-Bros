#include "LoseScene.h"
#include"SceneManager.h"
#include"GameScene.h"
#include"Level.h"
#include"Level1.h"
#include"Level2.h"
#include"Level3.h"


LoseScene::LoseScene(sf::RenderWindow * window, GameScene* game) {
    event = new sf::Event;
    SceneManager::clean();
    this->window = window;
    label = "Lose Scene";
    this->game = game;
}


void LoseScene::draw() {
    events();
    window->clear(sf::Color::Red);
}

void LoseScene::events() {
    while (window->pollEvent(*event))
    {
        switch (event->type)
        {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::KeyPressed:
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
                SceneManager::pop();
            }
        }

    }
}