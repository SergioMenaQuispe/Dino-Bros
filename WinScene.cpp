#include "WinScene.h"
#include"SceneManager.h"

WinScene::WinScene(sf::RenderWindow* window) {
    event = new sf::Event;
    SceneManager::clean();
    this->window = window;
    label = "Win Scene";

    /* set background */
    txr_background.loadFromFile("Images/win.jpeg");
    background.setTexture(&txr_background);
    background.setSize({ 800,600 });
}


void WinScene::draw() {
    window->clear();
    events();
    window->draw(background);
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
            exit(1);
        }

    }
}