//
// Created by David on 22/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_GAME_HH
#define INC_2DGAMEFRAMEWORK_GAME_HH

#include "settings.h"
#include "TemplateSingleton.hh"

#include "../Event/C_EventHandler.hh"
#include "../Graphic/C_TextureHolder.hh"
#include "../Entities/C_TestEntitie.hh"

#include "C_World.hh"
#include "../Entities/Player/C_Player.hh"
#include "../Debug/C_DebugScreen.hh"

#include <boost/log/trivial.hpp>
#include <Thor/Resources.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


class C_Game : public TemplateSingleton<C_Game> {
public:
  C_Game();

  bool init();

  void run();

private:
  void update();

  void update(sf::Time p_elapsed_time);

  void update_static(sf::Time p_elapsed_time);

  void render();

  void handleEvent();

  void exit();

  void clean();

  sf::Font mFont;
  sf::Text mStatisticsText;

  sf::RenderWindow m_window;
  const sf::Time m_fps = sf::seconds(1.f / 60.f);
  sf::Time mStatisticsUpdateTime;
  std::size_t mStatisticsNumFrames;

  C_World m_world;
  C_Player m_player;
  C_TestEntitie *m_test_entitie;

  bool m_toggle_FPS;
  C_DebugScreen* m_debug;
  std::shared_ptr<sf::Font> m_font;

};


#endif //INC_2DGAMEFRAMEWORK_GAME_HH
