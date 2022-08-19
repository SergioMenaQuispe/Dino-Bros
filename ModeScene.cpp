#include "ModeScene.h"
#include "SceneManager.h"

ModeScene::ModeScene(sf::RenderWindow* window) {
    event = new sf::Event;
    SceneManager::clean();
    this->window = window;


    /* set background */
    txr_background.loadFromFile("Images/game-mode.jpeg");
    background.setTexture(&txr_background);
    background.setSize({ 800,600 });

    /* set pointer */
    txr_pointer.loadFromFile("./Images/pointer.png");
    pointer.setTexture(txr_pointer);
    pointer_position = { 120,90 };
    pointer.setPosition(pointer_position);

    /*
    * Opc:
    * 0 -> easy
    * 1 -> mediunm
    * 3 -> hard
    */
    opc = 0;
}


void ModeScene::draw() {
    window->clear();
    events();
    window->draw(background);
    window->draw(pointer);
}

void ModeScene::events() {
    while (window->pollEvent(*event))
    {
        switch (event->type)
        {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::KeyPressed:
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                pointer_position.y -= 55;
                opc--;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                pointer_position.y += 55;
                opc++;
            }

            if (pointer_position.y < 90) {
                pointer_position.y = 200;
                opc = 2;
            }

            if (pointer_position.y > 200) {
                pointer_position.y = 90;
                opc = 0;
            }

            pointer.setPosition(pointer_position);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                switch (opc)
                {
                case 0:
                    SceneManager::setDifficult(1);
                    break;
                case 1:
                    SceneManager::setDifficult(2);
                    break;
                case 2:
                    SceneManager::setDifficult(3);
                    break;
                }

                SceneManager::pop();
            }
        }
    }
}