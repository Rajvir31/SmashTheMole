/**
 * @file Game.cpp
 * @brief Implements the Game class which handles the game loop, event processing, state updates, and rendering.
 *
 * @authors 
 *   Eseosa
 */

#include "Game.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

Game::Game() 
    : window(sf::VideoMode(800, 600, 32), "Smash The Mole"),
      gameState(GameState::MENU),
      score(0),
      gameDuration(60),
      targetInterval(sf::seconds(0.65f))
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Load the menu background image.
    if (!menuBackgroundTexture.loadFromFile("menu_background.jpg")) {
        std::cerr << "Error loading menu_background.jpg" << std::endl;
    } else {
        menuBackgroundSprite.setTexture(menuBackgroundTexture);
        // Scale to cover the entire window.
        sf::Vector2u texSize = menuBackgroundTexture.getSize();
        sf::Vector2u winSize = window.getSize();
        float scaleX = static_cast<float>(winSize.x) / texSize.x;
        float scaleY = static_cast<float>(winSize.y) / texSize.y;
        menuBackgroundSprite.setScale(scaleX, scaleY);
    }

    // Load the gameplay background image.
    if (!backgroundTexture.loadFromFile("background.jpeg")) {
        std::cerr << "Error loading background.jpeg" << std::endl;
    } else {
        backgroundSprite.setTexture(backgroundTexture);
        // Scale to cover the entire window.
        sf::Vector2u texSize = backgroundTexture.getSize();
        sf::Vector2u winSize = window.getSize();
        float scaleX = static_cast<float>(winSize.x) / texSize.x;
        float scaleY = static_cast<float>(winSize.y) / texSize.y;
        backgroundSprite.setScale(scaleX, scaleY);
    }

    // Load the font.
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font (arial.ttf)" << std::endl;
    }
    
    // Create the score and timer texts.
    scoreText = std::make_unique<sf::Text>(sf::String("Score: 0"), font, 28);
    scoreText->setFillColor(sf::Color::White);
    scoreText->setPosition(sf::Vector2f(10.f, 10.f));

    timerText = std::make_unique<sf::Text>(sf::String("Time: 60"), font, 28);
    timerText->setFillColor(sf::Color::White);
    timerText->setPosition(sf::Vector2f(690.f, 10.f));

    // Load the custom cursor (whacker) image.
    if (!cursorTexture.loadFromFile("whacker.png")) {
        std::cerr << "Error loading whacker.png" << std::endl;
    } else {
        cursorSprite.setTexture(cursorTexture);
        // Set origin so that the cursor is centered.
        cursorSprite.setOrigin(cursorTexture.getSize().x / 2.f, cursorTexture.getSize().y / 2.f);
        // Scale down the whacker.
        cursorSprite.setScale(0.15f, 0.15f);
    }
    // Hide the system mouse cursor.
    window.setMouseCursorVisible(false);

    // Initialize the menu and target modules.
    menu.init(font);
    target.init();
}

void Game::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        sf::Time dt = clock.restart();
        processEvents();
        update(dt);
        render();
    }
}

void Game::processEvents() {
    sf::Event event;  // SFML 2 uses a plain sf::Event.
    while (window.pollEvent(event)) {
        // Close event.
        if (event.type == sf::Event::Closed)
            window.close();

        if (gameState == GameState::MENU) {
            // In the menu, press Return to start.
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return) {
                gameState = GameState::PLAYING;
                resetGame();
            }
        }
        else if (gameState == GameState::PLAYING) {
            // Process mouse button events.
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePos(static_cast<float>(event.mouseButton.x), 
                                      static_cast<float>(event.mouseButton.y));
                if (target.getSprite().getGlobalBounds().contains(mousePos)) {
                    if (target.isBomb()) {
                        gameState = GameState::GAME_OVER;
                    } else {
                        score += 100;
                        target.setNewTarget();
                        targetClock.restart();
                    }
                }
            }
        }
        else if (gameState == GameState::GAME_OVER) {
            // In the game-over screen, press R to restart or Escape to exit.
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::R) {
                    gameState = GameState::PLAYING;
                    resetGame();
                }
                else if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }
        }
    }
}

void Game::update(sf::Time /*dt*/) {
    if (gameState == GameState::PLAYING) {
        int elapsedTime = gameClock.getElapsedTime().asSeconds();
        int remainingTime = gameDuration - elapsedTime;
        if (remainingTime <= 0) {
            gameState = GameState::GAME_OVER;
        }

        std::stringstream ss;
        ss << "Score: " << score;
        scoreText->setString(ss.str());

        std::stringstream ts;
        ts << "Time: " << remainingTime;
        timerText->setString(ts.str());

        if (targetClock.getElapsedTime() >= targetInterval) {
            target.setNewTarget();
            targetClock.restart();
        }
    }
}

void Game::render() {
    window.clear(sf::Color::White);
    // Draw the background based on the game state.
    if (gameState == GameState::MENU) {
        window.draw(menuBackgroundSprite);
        menu.drawMenu(window);
    } else {
        window.draw(backgroundSprite);
        if (gameState == GameState::PLAYING) {
            window.draw(*scoreText);
            window.draw(*timerText);
            window.draw(target.getSprite());
        } else if (gameState == GameState::GAME_OVER) {
            menu.drawGameOver(window, score);
        }
    }
    // Update and draw the custom cursor to follow the mouse.
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    cursorSprite.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    window.draw(cursorSprite);
    
    window.display();
}

void Game::resetGame() {
    score = 0;
    gameClock.restart();
    targetClock.restart();
    target.setNewTarget();
}
