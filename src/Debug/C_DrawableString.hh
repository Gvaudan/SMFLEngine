//
// Created by David on 29/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_C_DRAWABLESTRING_HH
#define INC_2DGAMEFRAMEWORK_C_DRAWABLESTRING_HH

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../Graphic/C_SceneNode.hh"

class C_DrawableString : public C_SceneNode {
public:
  C_DrawableString();

  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

  void update(sf::Time dt) override;

protected:
  sf::Font m_font;
  sf::Text m_text;
};


#endif //INC_2DGAMEFRAMEWORK_C_DRAWABLESTRING_HH
