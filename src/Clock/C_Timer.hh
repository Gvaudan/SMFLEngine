//
// Created by David on 22/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_C_TIMER_HH
#define INC_2DGAMEFRAMEWORK_C_TIMER_HH

#include <SFML/System/Clock.hpp>
#include <TemplateSingleton.hh>

class C_Timer  : public TemplateSingleton<C_Timer>{
public:
  void start();
  void pause();
  void unpause();
  sf::Time restart();
  void stop();
  bool is_started();
  bool is_paused();
  sf::Time get_time();
private:
  sf::Clock m_clock;
  sf::Time m_start_ticks;
  sf::Time m_pause_ticks;
  //The m_timer status
  bool m_is_paused;
  bool m_is_started;
};


#endif //INC_2DGAMEFRAMEWORK_C_TIMER_HH
