//
// Created by David on 22/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_GAME_HH
#define INC_2DGAMEFRAMEWORK_GAME_HH

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
//#include "ToString.h"
#include "TemplateSingleton.hh"
#include "settings.h"
#include "../Event/C_EventHandler.hh"
#include "../Graphic/C_TextureHolder.hh"
#include "../Entities/C_TestEntitie.hh"

#include "C_World.hh"
#include <boost/log/trivial.hpp>

class C_Game : public TemplateSingleton<C_Game> {
public:
  C_Game();
  bool init();

  void run();

private:
  void update();

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
  C_TestEntitie *m_test_entitie;
};


#endif //INC_2DGAMEFRAMEWORK_GAME_HH
