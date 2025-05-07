/**
 * @file Target.cpp
 * @brief Implements the Target class for managing target sprites (moles and bombs).
 *
 * @authors 
 *   Tolu, Keith
 */

#include "Target.h"
#include <cstdlib>

Target::Target() : bombFlag(false) {
    // Define base grid positions with offsets applied.
    float offsetX = -35.f; ///< Horizontal offset.
    float offsetY = -60.f; ///< Vertical offset.
    positions = {
        {130.f + offsetX, 55.f + offsetY}, {360.f + offsetX, 55.f + offsetY}, {585.f + offsetX, 55.f + offsetY},
        {130.f + offsetX, 270.f + offsetY}, {360.f + offsetX, 270.f + offsetY}, {585.f + offsetX, 270.f + offsetY},
        {130.f + offsetX, 490.f + offsetY}, {360.f + offsetX, 490.f + offsetY}, {585.f + offsetX, 490.f + offsetY}
    };
}

void Target::init() {
    // Load textures.
    if (!moleTexture.loadFromFile("mole.png")) {
        // Handle error appropriately.
    }
    if (!bombTexture.loadFromFile("bomb.png")) {
        // Handle error appropriately.
    }
    // Create the sprite using the mole texture.
    sprite = std::make_unique<sf::Sprite>(moleTexture);
    // Do not set a default scale here; it will be adjusted in setNewTarget().
    setNewTarget();
}

void Target::setNewTarget() {
    // Choose a random position for the target.
    int index = std::rand() % positions.size();
    sprite->setPosition(positions[index]);

    // Decide whether to show a mole (50%) or a bomb (50%).
    int randomValue = std::rand() % 100;
    if (randomValue < 50) {
        sprite->setTexture(moleTexture);
        bombFlag = false;
        // Set scale for mole.
        sprite->setScale(sf::Vector2f(0.03f, 0.03f));
    } else {
        sprite->setTexture(bombTexture);
        bombFlag = true;
        // Set scale for bomb.
        sprite->setScale(sf::Vector2f(0.06f, 0.06f));
        // Shift bomb 10 pixels to the right relative to its current position.
        sprite->move(10.f, 0.f);
    }
}

const sf::Sprite & Target::getSprite() const {
    return *sprite;
}

bool Target::isBomb() const {
    return bombFlag;
}
