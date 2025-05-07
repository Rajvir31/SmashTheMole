/**
 * @file Game.h
 * @brief Declares the Game class which encapsulates the main game logic, state management, and rendering.
 *
 * @authors 
 *   Keith, Rajvir
 */

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Target.h"
#include <memory>

/**
 * @brief Enumeration for the various game states.
 */
enum class GameState { MENU, PLAYING, GAME_OVER };

/**
 * @brief The Game class manages the game loop, event processing, state updates, and rendering.
 */
class Game {
public:
    /**
     * @brief Constructs a new Game object.
     */
    Game();

    /**
     * @brief Runs the main game loop.
     */
    void run();

private:
    /**
     * @brief Processes system and user input events.
     */
    void processEvents();

    /**
     * @brief Updates the game state based on elapsed time.
     * @param dt Time elapsed since last update.
     */
    void update(sf::Time dt);

    /**
     * @brief Renders the current game state to the window.
     */
    void render();

    /**
     * @brief Resets game variables for a new game.
     */
    void resetGame();

    sf::RenderWindow window;             ///< Main game window.
    GameState gameState;                 ///< Current game state.
    Menu menu;                           ///< Menu module.
    Target target;                       ///< Target (mole/bomb) module.
    sf::Font font;                       ///< Font for text rendering.
    std::unique_ptr<sf::Text> scoreText; ///< Displays the player's score.
    std::unique_ptr<sf::Text> timerText; ///< Displays the countdown timer.
    int score;                           ///< Player's current score.
    const int gameDuration;              ///< Duration of the game in seconds.
    sf::Clock gameClock;                 ///< Clock for overall game time.
    sf::Clock targetClock;               ///< Clock for target repositioning.
    sf::Time targetInterval;             ///< Interval between target moves.

    // Background images:
    sf::Texture menuBackgroundTexture;   ///< Texture for the menu background.
    sf::Sprite menuBackgroundSprite;     ///< Sprite for the menu background.
    sf::Texture backgroundTexture;       ///< Texture for the gameplay background.
    sf::Sprite backgroundSprite;         ///< Sprite for the gameplay background.

    // Custom cursor (whacker) variables:
    sf::Texture cursorTexture;           ///< Texture for the custom cursor.
    sf::Sprite cursorSprite;             ///< Sprite for the custom cursor.
};

#endif // GAME_H
