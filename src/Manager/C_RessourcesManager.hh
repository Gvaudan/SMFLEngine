//
// Created by David on 22/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_C_RESSOURCESMANAGER_HH
#define INC_2DGAMEFRAMEWORK_C_RESSOURCESMANAGER_HH

#include "../headers/settings.h"

#include <Thor/Resources.hpp>
#include <SFML/Graphics/Font.hpp>

namespace pt = boost::property_tree;

class C_RessourcesManager : public TemplateSingleton<C_RessourcesManager> {

public:
  bool init_loader();

  bool load_spritesheet(std::string p_id, std::string p_path);

  bool loead_texture(std::string p_id, std::string p_path);

  bool load_sound(std::string p_id, std::string p_path);

  std::shared_ptr<sf::Font> load_font(std::string p_id, std::string p_path);

  const sf::Font get_fond(std::string p_id);

  const pt::ptree get_setting(std::string p_id);

  bool load_settins_file();

  C_RessourcesManager();

private:
  thor::ResourceLoader<pt::ptree> load_json_file(std::string p_path);

  pt::ptree load_animation_set();

  pt::ptree load_entities_set(std::string p_entitie_type);

  pt::ptree load_ressources_set();

  pt::ptree load_game_set();

  pt::ptree load_controllers_set();

  std::map<std::string, std::shared_ptr<sf::Font>> m_font_map;
  thor::ResourceHolder<sf::Texture, std::string, thor::Resources::RefCounted> m_holder_texture;
  thor::ResourceHolder<sf::Font, std::string, thor::Resources::RefCounted> m_holder_font;

  std::map<std::string, pt::ptree> m_map_settings;

  thor::ResourceHolder<pt::ptree, std::string> m_holder_settings;

};

#endif //INC_2DGAMEFRAMEWORK_C_RESSOURCESMANAGER_HH
