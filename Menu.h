/**
 * @file Menu.h
 * @brief Declares the Menu class used for the game start and game over screens.
 *
 * @authors 
 *   Rajvir, Tolu
 */

#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <memory>

/**
 * @brief The Menu class handles the display of the start menu and game-over screens.
 */
class Menu {
public:
    /**
     * @brief Constructs a new Menu object.
     */
    Menu();

    /**
     * @brief Initializes the menu texts using the provided font.
     * @param font The font to be used for text rendering.
     */
    void init(const sf::Font &font);

    /**
     * @brief Draws the start menu on the given window.
     * @param window The render window.
     */
    void drawMenu(sf::RenderWindow &window);

    /**
     * @brief Draws the game-over screen with the final score.
     * @param window The render window.
     * @param score The final score.
     */
    void drawGameOver(sf::RenderWindow &window, int score);

private:
    std::unique_ptr<sf::Text> titleText;        ///< Title text displayed on the menu.
    std::unique_ptr<sf::Text> instructionText;  ///< Instruction text displayed on the menu.
    std::unique_ptr<sf::Text> gameOverText;       ///< "Game Over" text.
    std::unique_ptr<sf::Text> finalScoreText;     ///< Final score display text.
    std::unique_ptr<sf::Text> restartText;        ///< Restart instructions.
};

#endif // MENU_H
