#include "WinScene.h"
#include"SceneManager.h"

WinScene::WinScene(sf::RenderWindow* window) {
    event = new sf::Event;
    SceneManager::clean();
    this->window = window;
}


void WinScene::draw() {
    window->clear(sf::Color::Blue);
}

void WinScene::events() {
    while (window->pollEvent(*event))
    {
        switch (event->type)
        {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::KeyPressed:
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
                SceneManager::pop();
            }
        }

    }
}