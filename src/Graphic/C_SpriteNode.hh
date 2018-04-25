//
// Created by David on 22/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_C_SPRITENODE_HH
#define INC_2DGAMEFRAMEWORK_C_SPRITENODE_HH


#include "C_SceneNode.hh"
#include <SFML/Graphics/Sprite.hpp>

class C_SpriteNode : public C_SceneNode {
public:
  explicit C_SpriteNode (const sf::Texture &texture);
  C_SpriteNode (const sf::Texture &texture, const sf::IntRect &textureRect);

private:
  virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;

private:
  sf::Sprite mSprite;
};


#endif //INC_2DGAMEFRAMEWORK_C_SPRITENODE_HH
