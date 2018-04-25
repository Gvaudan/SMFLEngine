//
// Created by David on 22/04/2018.
//

#include "C_SpriteNode.hh"
#include <SFML/Graphics/RenderTarget.hpp>

C_SpriteNode::C_SpriteNode(const sf::Texture &texture) : mSprite(texture) {}

C_SpriteNode::C_SpriteNode(const sf::Texture &texture, const sf::IntRect &textureRect) :
    mSprite(texture,
            textureRect) {

}

void C_SpriteNode::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(mSprite, states);
}
