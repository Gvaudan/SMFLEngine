//
// Created by David on 22/04/2018.
//

#include "C_Game.hh"
#include "../Clock/C_Timer.hh"
#include <iostream>

using namespace std;

C_Game::C_Game()
    : m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, WINDOW_STYLE),
      m_world(m_window), mFont(), mStatisticsText(), mStatisticsUpdateTime(), mStatisticsNumFrames(0) {

}

void C_Game::run() {
  cout << __PRETTY_FUNCTION__ << endl;
  C_Timer::get_instance()->start();
  sf::Time timeSinceLastUpdate = sf::Time::Zero;

  while (m_window.isOpen()) {

    sf::Time elapsedTime = C_Timer::get_instance()->restart();
    timeSinceLastUpdate += elapsedTime;
    while (timeSinceLastUpdate > m_fps) {
      timeSinceLastUpdate -= m_fps;
      handleEvent();
      update();
    }
    update_static(elapsedTime);
    render();
  }
  C_Timer::get_instance()->stop();
}

bool C_Game::init() {
  BOOST_LOG_TRIVIAL(info) << __PRETTY_FUNCTION__;
  //TextureManager::get_instance()->load("","");

  C_EntityFactory::get_instance()->RegisterType("test-sprite", new C_TestEntityCreator());
  m_test_entitie = (C_TestEntitie *) C_EntityFactory::get_instance()->Create("test-sprite");
  return false;
}

void C_Game::update() {
}

void C_Game::render() {
  m_window.clear();

  m_window.setView(m_window.getDefaultView());
  m_test_entitie->draw(m_window, sf::RenderStates::Default);
  //m_window->draw(mStatisticsText);
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
    std:
    string str = "FPS = " + std::to_string(mStatisticsNumFrames) + " - " +
                 "TimeUpdate = " + std::to_string(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "us";
    mStatisticsText.setString(str);
    mStatisticsUpdateTime -= sf::seconds(1.0f);
    mStatisticsNumFrames = 0;
  }
}