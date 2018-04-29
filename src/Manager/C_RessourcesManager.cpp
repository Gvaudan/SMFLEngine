//
// Created by David on 22/04/2018.
//

#include "C_RessourcesManager.hh"

bool C_RessourcesManager::load_spritesheet(std::string p_id, std::string p_path) {
  m_holder_texture.acquire(p_id, thor::Resources::fromFile<sf::Texture>(p_path));
}

bool C_RessourcesManager::loead_texture(std::string p_id, std::string p_path) {
  return false;
}

bool C_RessourcesManager::load_sound(std::string p_id, std::string p_path) {
  return false;
}

std::shared_ptr<sf::Font> C_RessourcesManager::load_font(std::string p_id, std::string p_path) {
  m_font_map[p_id] = m_holder_font.acquire(p_id, thor::Resources::fromFile<sf::Font>(p_path), thor::Resources::Reuse);
  return m_font_map[p_id];
}

const sf::Font C_RessourcesManager::get_fond(std::string p_id) {

  if (!m_font_map.empty()) {
    auto font = m_font_map[p_id];
    return *font;
  }
  return *m_font_map[p_id];
}
