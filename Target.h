/**
 * @file Target.h
 * @brief Declares the Target class for managing moles and bombs.
 *
 * @author 
 *   Rajvir
 */

#ifndef TARGET_H
#define TARGET_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

/**
 * @brief The Target class manages the target sprite (mole or bomb) and its positions.
 */
class Target {
public:
    /**
     * @brief Constructs a new Target object.
     */
    Target();

    /**
     * @brief Initializes the target by loading textures and setting initial properties.
     */
    void init();

    /**
     * @brief Sets a new target at a random position and configures its properties.
     */
    void setNewTarget();

    /**
     * @brief Gets the current target sprite.
     * @return const sf::Sprite& The target sprite.
     */
    const sf::Sprite & getSprite() const;

    /**
     * @brief Checks if the current target is a bomb.
     * @return true if it is a bomb, false otherwise.
     */
    bool isBomb() const;

private:
    std::unique_ptr<sf::Sprite> sprite; ///< The target sprite.
    sf::Texture moleTexture;            ///< Texture for the mole.
    sf::Texture bombTexture;            ///< Texture for the bomb.
    bool bombFlag;                      ///< Flag indicating if the current target is a bomb.
    std::vector<sf::Vector2f> positions;  ///< Predefined positions for targets.
};

#endif // TARGET_H
