#include "GameScene.h"
#include "SceneManager.h"
#include"Level1.h"
#include"Level2.h"
#include"Level3.h"

/* Sera el contexto de los niveles, (patron de diseño strategy)*/
GameScene::GameScene(sf::RenderWindow* window) {
    event = new sf::Event;
    SceneManager::clean();
    this->window = window;

    wins = 2;
    
    VIEW_HEIGHT = 400.0f;
    view = new sf::View(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));

}

void GameScene::draw() {
    deltaTime = clock.restart().asSeconds();

    events();

    for (Player& player : players) {
        player.Update(deltaTime);
    }


    Vector2f direction;

    for (Platform& platform : platforms) {
        for (Player& player : players)
            if (platform.GetCollider().CheckCollider(player.GetCollider(), direction, 1.0f))
            {
                player.OnCollision(direction);
            }
    }


    view->setCenter(players.at(0).GetPosition());

    window->clear(Color(100, 100, 100));
    window->draw(background);

    window->setView(*view);//seguir camara de jugador

    // jugadores
    for (Player& player : players) {
        player.Draw(*window);
    }

    // plataformas
    for (Platform& platform : platforms)
        platform.Draw(*window);
    

    changeLevel();
}
    


void GameScene::events() {
    while (window->pollEvent(*event))
    {
        switch (event->type)
        {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::Resized:
            ResizeView();
            break;

        }
    }
}

void GameScene::addPlayers(Player& p) {
    players.push_back(p);
}


void GameScene::ResizeView()
{
    float aspectRatio = float(window->getSize().x) / float(window->getSize().y);
    view->setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

void GameScene::setLevel(Level* level) 
{
    platforms = level->GetPlatforms();
}

void GameScene::changeLevel() {

    // niveles
    switch (wins)
    {
    case 0:
        // nivel 1
        if (!level) {
            level = new Level1(players);
            setLevel(level);
        }

        break;
    case 1:
        // nivel 2
        if (level && level->GetLabel() == "level 1") {
            delete level;
        }

        if (!level) {
            level = new Level2(players);
            setLevel(level);
        }
        break;
    case 2: break;
        // nivel 3
        if (level && level->GetLabel() == "level 2") {
            delete level;
        }

        if (!level) {
            level = new Level3(players);
            setLevel(level);
        }

    }
}