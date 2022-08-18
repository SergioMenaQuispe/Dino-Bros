#include "LoseScene.h"
#include"SceneManager.h"

LoseScene::LoseScene(sf::RenderWindow * window) {
    event = new sf::Event;
    SceneManager::clean();
    this->window = window;
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