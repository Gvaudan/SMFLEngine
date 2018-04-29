//
// Created by David on 29/04/2018.
//

#include "C_DrawableString.hh"
#include "../Manager/C_RessourcesManager.hh"

C_DrawableString::C_DrawableString() {

  m_font = C_RessourcesManager::get_instance()->get_fond("FPS");
  m_text.setString("");
  m_text.setFont(m_font);
  m_text.setFillColor(sf::Color::Yellow);
  m_text.setCharacterSize(20);
}

void C_DrawableString::update(sf::Time dt) {
  C_SceneNode::update(dt);
}

void C_DrawableString::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(m_text);
}