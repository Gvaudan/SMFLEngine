//
// Created by David on 22/04/2018.
//

#include <boost/log/trivial.hpp>
#include "C_RessourcesManager.hh"
//===================================================================

C_RessourcesManager::C_RessourcesManager() {
  BOOST_LOG_TRIVIAL(info) << __PRETTY_FUNCTION__;
}


bool C_RessourcesManager::load_spritesheet(std::string p_id, std::string p_path) {
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

bool C_RessourcesManager::load_settins_file() {

}

thor::ResourceLoader<pt::ptree> C_RessourcesManager::load_json_file(std::string p_path) {
  return thor::ResourceLoader<pt::ptree>(
      [=]() {
        pt::ptree *json = new pt::ptree();
        pt::read_json(p_path, *json);
        return std::unique_ptr<pt::ptree>(json);
      }, p_path);
}

bool C_RessourcesManager::init_loader() {

  auto item = m_holder_settings.acquire("SETTINGS", load_json_file(GAME_SETTINGS_FILE));
  m_map_settings["SETTINGS"] = item;
  return true;
}

const pt::ptree C_RessourcesManager::get_setting(std::string p_id) {
  if (!m_map_settings.empty()) {
    auto setting = m_map_settings[p_id];
    return setting;
  }
  return m_map_settings[p_id];
}
