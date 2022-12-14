#include "MenuScene.h"
#include "SceneManager.h"

MenuScene::MenuScene(sf::RenderWindow* window) {
    event = new sf::Event;
    SceneManager::clean();
    this->window = window;


    /* set background */
    txr_background.loadFromFile("Images/other-menu.jpeg");
    background.setTexture(&txr_background);
    background.setSize({ 800,600 });

    /* set pointer */
    txr_pointer.loadFromFile("./Images/pointer.png");
    pointer.setTexture(txr_pointer);
    pointer_position = { 120,80 };
    pointer.setPosition(pointer_position);

    /*
    * Opc:
    * 0 -> 1 player
    * 1 -> 2 player
    * 3 -> Game mode
    * 4 -> exit
    */
    opc = 0;
    label = "Menu Scene";
}


void MenuScene::draw() {
    window->clear();
    events();
    window->draw(background);
    window->draw(pointer);
}

void MenuScene::events() {
    while (window->pollEvent(*event))
    {
        switch (event->type)
        {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::KeyPressed:
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                pointer_position.y -= 65;
                opc--;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                pointer_position.y += 65;
                opc++;
            }

            if (pointer_position.y < 80) {
                pointer_position.y = 275;
                opc = 3;
            }

            if (pointer_position.y > 275) {
                pointer_position.y = 80;
                opc = 0;
            }

            pointer.setPosition(pointer_position);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                switch (opc)
                {
                case 0:
                    SceneManager::push(SceneManager::createGameScene(window, 1, SceneManager::getDifficult()));
                    break;

                case 1:
                    SceneManager::push(SceneManager::createGameScene(window, 2, SceneManager::getDifficult()));
                    break;

                case 2:
                    SceneManager::push(SceneManager::createModeScene(window));
                    break;

                case 3: 
                    exit(1);
                    break;
                }
            }
        }
    }
}
