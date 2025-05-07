/**
 * @file Menu.cpp
 * @brief Implements the Menu class for the start and game-over screens.
 *
 * @authors 
 *   Keith, Eseosa
 */

#include "Menu.h"
#include <sstream>

Menu::Menu() {
    // Smart pointers are initially null.
}

void Menu::init(const sf::Font &font) {
    titleText = std::make_unique<sf::Text>(sf::String("Smash The Mole"), font, 60);
    titleText->setFillColor(sf::Color::White);
    titleText->setPosition(sf::Vector2f(190.f, 150.f));

    instructionText = std::make_unique<sf::Text>(sf::String("Press Enter to Start"), font, 24);
    instructionText->setFillColor(sf::Color::Black);
    instructionText->setPosition(sf::Vector2f(300.f, 300.f));

    gameOverText = std::make_unique<sf::Text>(sf::String("Game Over!"), font, 48);
    gameOverText->setFillColor(sf::Color::Red);
    gameOverText->setPosition(sf::Vector2f(280.f, 200.f));

    finalScoreText = std::make_unique<sf::Text>(sf::String("Final Score: 0"), font, 32);
    finalScoreText->setFillColor(sf::Color::Black);
    finalScoreText->setPosition(sf::Vector2f(315.f, 350.f));

    restartText = std::make_unique<sf::Text>(sf::String("Press R to Restart or Esc to Exit"), font, 24);
    restartText->setFillColor(sf::Color::Black);
    restartText->setPosition(sf::Vector2f(260.f, 400.f));
}

void Menu::drawMenu(sf::RenderWindow &window) {
    window.draw(*titleText);
    window.draw(*instructionText);
}

void Menu::drawGameOver(sf::RenderWindow &window, int score) {
    window.draw(*gameOverText);
    std::stringstream ss;
    ss << "Final Score: " << score;
    finalScoreText->setString(ss.str());
    window.draw(*finalScoreText);
    window.draw(*restartText);
}
