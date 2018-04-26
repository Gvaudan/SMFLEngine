//
// Created by David on 22/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_C_RESSOURCESMANAGER_HH
#define INC_2DGAMEFRAMEWORK_C_RESSOURCESMANAGER_HH

#include <Thor/Resources.hpp>
#include <SFML/Graphics/Font.hpp>
#include <TemplateSingleton.hh>


class C_RessourcesManager : public TemplateSingleton<C_RessourcesManager> {

public:
    bool load_spritesheet(std::string p_id, std::string p_path);

    bool loead_texture(std::string p_id, std::string p_path);

    bool load_sound(std::string p_id, std::string p_path);

    std::shared_ptr<sf::Font> load_font(std::string p_id, std::string p_path);

private:
    thor::ResourceHolder<sf::Texture, std::string> m_holder_texture;
    thor::ResourceHolder<sf::Font, std::string, thor::Resources::RefCounted> m_holder_font;
};

#endif //INC_2DGAMEFRAMEWORK_C_RESSOURCESMANAGER_HH
