#include "LoseScene.h"
#include"SceneManager.h"

LoseScene::LoseScene(sf::RenderWindow * window) {
    event = new sf::Event;
    SceneManager::clean();
    this->window = window;
    this->label = "Lose Scene";

    /* set background */
    txr_background.loadFromFile("Images/game-over.jpeg");
    background.setTexture(&txr_background);
    background.setSize({ 800,600 });

}


void LoseScene::draw() {
    window->clear();
    window->setView(sf::View(sf::Vector2f(400, 300), sf::Vector2f(800, 600)));
    events();
    window->draw(background);

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
                SceneManager::push(SceneManager::createMenuScene(window));
            }

            else {
                exit(1);
            }
        }

    }
}