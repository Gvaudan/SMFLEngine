//
// Created by David on 22/04/2018.
//

#include "C_Game.hh"
#include "../Clock/C_Timer.hh"
#include "../State/C_GameStateMachine.h"
#include "../Manager/C_RessourcesManager.hh"
#include "../State/C_TestStateMachine.hh"
#include <iostream>

using namespace std;

C_Game::C_Game()
    : m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, WINDOW_STYLE),
      m_world(m_window), mFont(), mStatisticsText(), mStatisticsUpdateTime(), mStatisticsNumFrames(0) {
  m_window.setFramerateLimit(60);
}

void C_Game::run() {
  cout << __PRETTY_FUNCTION__ << endl;
  C_Timer::get_instance()->start();

  sf::Time timeSinceLastUpdate = sf::Time::Zero;
  sf::Time accumulator = sf::Time::Zero;
  sf::Time currentTime = C_Timer::get_instance()->get_time();
  sf::Time frameTime = sf::Time::Zero;
  sf::Time time = sf::Time::Zero;

  const sf::Time dt = sf::seconds(0.1f);

  while (m_window.isOpen()) {

    timeSinceLastUpdate = C_Timer::get_instance()->restart();
    frameTime = timeSinceLastUpdate - currentTime;
    currentTime = timeSinceLastUpdate;
    accumulator += frameTime;

    while (accumulator >= dt) {
      accumulator -= dt;
      time += dt;
    }

    update();
    update_static(timeSinceLastUpdate);
    handleEvent();
    render();
  }
  C_Timer::get_instance()->stop();
}

bool C_Game::init() {
  BOOST_LOG_TRIVIAL(info) << __PRETTY_FUNCTION__;

  m_font = C_RessourcesManager::get_instance()->load_font("FPS", "ressources/fonts/8-Bit Madness.ttf");
  mFont = *m_font.get();
  mStatisticsText.setFont(mFont);
  mStatisticsText.setCharacterSize(24); // in pixels, not points!
  mStatisticsText.setFillColor(sf::Color::Red);

  C_EntityFactory::get_instance()->RegisterType("test-sprite", new C_TestEntityCreator());
  m_test_entitie = (C_TestEntitie *) C_EntityFactory::get_instance()->Create("test-sprite");
  m_test_entitie->set_current_state(new C_TestEntitieState(m_test_entitie));

  C_TestStateMachine::get_instance()->set_entitie(m_test_entitie);
  C_TestStateMachine::get_instance()->push_state(m_test_entitie->get_current_state());

  C_GameStateMachine::get_instance()->push_state(new C_InGameState());

  BOOST_LOG_TRIVIAL(trace) << __PRETTY_FUNCTION__ << " : FPS : " << m_fps.asMicroseconds();

  return false;
}

void C_Game::update() {
  m_test_entitie->update(C_Timer::get_instance()->get_time());
  C_GameStateMachine::get_instance()->update();
}

void C_Game::render() {
  m_window.clear();

  m_window.setView(m_window.getDefaultView());
  m_test_entitie->draw(m_window, sf::RenderStates::Default);
  m_window.draw(mStatisticsText);
  m_window.display();
}

void C_Game::handleEvent() {
  sf::Event event;
  C_EventHandler::get_instance()->process_event(event, &m_window);
}

void C_Game::exit() {

}

void C_Game::clean() {

}

void C_Game::update_static(sf::Time p_elapsed_time) {
  mStatisticsUpdateTime += p_elapsed_time;
  mStatisticsNumFrames += 1;

  if (mStatisticsUpdateTime >= sf::seconds(1.0f)) {
    std::string str = "FPS = " + std::to_string(mStatisticsNumFrames) + "\n" +
                      "TimeUpdate = " +
                      std::to_string(mStatisticsUpdateTime.asMilliseconds() / mStatisticsNumFrames) +
                      "ms";
    mStatisticsText.setString(str);
    mStatisticsUpdateTime -= sf::seconds(1.0f);
    mStatisticsNumFrames = 0;
  }
}