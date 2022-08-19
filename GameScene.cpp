#include "GameScene.h"
#include "SceneManager.h"
#include"Heart.h"
#include"Level1.h"
#include"Level2.h"
#include"Level3.h"

/* Sera el contexto de los niveles, (patron de diseño strategy)*/
GameScene::GameScene(sf::RenderWindow* window, int difficult) {
    event = new sf::Event;
    SceneManager::clean();
    this->window = window;

    wins = 0;
    
    VIEW_HEIGHT = 400.0f;
    view = new sf::View(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));

    this->difficult = difficult;
    background.setSize({ 3500,1500 });
    background.setScale(2, 1);

    this->label = "Game Scene";
    
    hearts.push_back(Heart({ 50.0f,500.0f }));
}

void GameScene::draw() {

    events();
    
    /* Set window and view */
    window->clear();
    window->draw(background);

    view->setCenter(players.at(0).GetPosition());
    window->setView(*view);//seguir camara de jugador

    deltaTime = clock.restart().asSeconds();
    // jugadores
    for (Player& player : players) {
        player.Draw(*window);
        player.Update(deltaTime);
        if (player.isWinner()) {
            Win();
            std::cout << "win" << wins << std::endl;
        }
    }

    // plataformas
    for (Platform& platform : platforms) {
        platform.Draw(*window);
    }

    // spikes
    for (Spike& spike : spikes) {
        spike.Draw(*window);
    }

    // doors
    for (Door& door : doors) {
        door.Draw(*window);
    }
    
    CheckCollisions(doors);
    CheckCollisions(platforms);
    CheckCollisions(spikes);

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
    this->level = level;
}

void GameScene::changeLevel() {

    // niveles
    switch (wins)
    {
    case 0:
        // nivel 1
        if (!level) {
            level = new Level1;
            setLevel(level);
            level->setObjects(platforms, spikes, doors);
            level->setPlayersPosition(players);

            /* set background */

            level->setBackground(background);
        }

        break;
    case 1:
        // nivel 2
        if (level && level->GetLabel() == "level 1") {
            delete level;

            level = new Level2;
            setLevel(level);
            level->setPlayersPosition(players);
            level->setObjects(platforms, spikes, doors);
            level->setBackground(background);
        }

        break;
    case 2: break;
        // nivel 3
        if (level && level->GetLabel() == "level 2") {
            delete level;
            level = new Level3;
            setLevel(level);
            level->setPlayersPosition(players);
            level->setObjects(platforms, spikes, doors);
            level->setBackground(background);
        }


    }
}


template<typename structure>
void GameScene::CheckCollisions(std::vector<structure> collection) {
    sf::Vector2f direction;
   
    for (structure& element : collection) {
        for (Player& player : players)
            element.OnCollision(player,direction,100.0f);
    }
}


void GameScene::Win() {
    
    if (wins < 3) {
        for (Player& p : players) {
            p.setWin(false);
        }
        wins++;
    }
    
    else {
        SceneManager::push(SceneManager::createWinScene(window));
    }
}