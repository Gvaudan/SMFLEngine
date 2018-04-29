//
// Created by David on 29/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_C_DEBUGSCREEN_HH
#define INC_2DGAMEFRAMEWORK_C_DEBUGSCREEN_HH

#include "../Graphic/C_TextureHolder.hh"
#include "../Graphic/C_SceneNode.hh"
#include "C_DrawableString.hh"

#include <Thor/Resources.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class C_DebugScreen : public C_SceneNode {
public:
  C_DebugScreen();

  void updateCurrent(sf::Time dt) override;

  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
  bool m_toggle_FPS;
  std::shared_ptr<sf::Font> m_font;
  std::vector<C_DrawableString*> m_text_list;
  sf::Text m_fps;
  sf::Text m_frame_time;
};


#endif //INC_2DGAMEFRAMEWORK_C_DEBUGSCREEN_HH
