//
// Created by David on 22/04/2018.
//

#include "C_Game.hh"
#include "../Clock/C_Timer.hh"
#include "../State/C_GameStateMachine.h"
#include "../Manager/C_RessourcesManager.hh"
#include "../Entities/C_TestStateMachine.hh"
#include <iostream>

using namespace std;

C_Game::C_Game()
    : m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, WINDOW_STYLE),
      m_world(m_window), mFont(), mStatisticsText(), mStatisticsUpdateTime(), mStatisticsNumFrames(0) {
  //m_window.setFramerateLimit(60);
}

void C_Game::run() {
  cout << __PRETTY_FUNCTION__ << endl;
  C_Timer::get_instance()->start();

  sf::Time timeSinceLastUpdate = sf::Time::Zero;
  sf::Time accumulator = sf::Time::Zero;
  sf::Time currentTime = C_Timer::get_instance()->get_time();
  sf::Time frameTime = sf::Time::Zero;
  sf::Time time = sf::Time::Zero;

  const sf::Time dt = sf::seconds(0.01f);

  while (m_window.isOpen()) {

    timeSinceLastUpdate = C_Timer::get_instance()->restart();
    frameTime = timeSinceLastUpdate - currentTime;

    currentTime = timeSinceLastUpdate;

    accumulator += frameTime;
    while (accumulator >= dt) {
      accumulator -= dt;
      time += dt;
    }

    update(timeSinceLastUpdate);
    handleEvent();
    render();
  }
  C_Timer::get_instance()->stop();
}

bool C_Game::init() {
  C_RessourcesManager::get_instance()->init_loader();

  m_font = C_RessourcesManager::get_instance()->load_font("FPS", "ressources/fonts/8-Bit Madness.ttf");
  mFont = *m_font.get();
  mStatisticsText.setFont(mFont);
  mStatisticsText.setCharacterSize(24); // in pixels, not points!
  mStatisticsText.setFillColor(sf::Color::Red);

  m_debug = new C_DebugScreen();


  sf::Joystick::update();
  bool connected = sf::Joystick::isConnected(0);
  if (connected) {
    unsigned int buttons = sf::Joystick::getButtonCount(0);
    auto id = sf::Joystick::getIdentification(0);

    BOOST_LOG_TRIVIAL(info) << __PRETTY_FUNCTION__ << " : Joystick is connected";
    BOOST_LOG_TRIVIAL(info) << __PRETTY_FUNCTION__ << " : " << to_string(buttons) << " buttons";
    BOOST_LOG_TRIVIAL(info) << __PRETTY_FUNCTION__ << " : product name : " << id.name.toAnsiString();
    BOOST_LOG_TRIVIAL(info) << __PRETTY_FUNCTION__ << " : product id : " << to_string(id.productId);
    BOOST_LOG_TRIVIAL(info) << __PRETTY_FUNCTION__ << " : vendor vendor id : " << to_string(id.vendorId);
  } else {
    BOOST_LOG_TRIVIAL(warning) << __PRETTY_FUNCTION__ << " : No joystick connected";
  }

  C_EntityFactory::get_instance()->RegisterType("test-sprite", new C_TestEntityCreator());
  m_test_entitie = (C_TestEntitie *) C_EntityFactory::get_instance()->Create("test-sprite");

  C_GameStateMachine::get_instance()->push_state(new C_InGameState());

  return false;
}

void C_Game::update() {
}

void C_Game::update(sf::Time p_elapsed_time) {
  C_GameStateMachine::get_instance()->update(p_elapsed_time);

  m_player.update(p_elapsed_time);
  update_static(p_elapsed_time);
  m_debug->update(p_elapsed_time);
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

void C_Game::render() {
  m_window.clear();

  m_window.setView(m_window.getDefaultView());
  //m_test_entitie->draw(m_window, sf::RenderStates::Default);
  m_player.draw(m_window, sf::RenderStates::Default);
  //m_window.draw(mStatisticsText);
  m_debug->draw(m_window, sf::RenderStates::Default);
  m_window.display();
}

void C_Game::handleEvent() {
  sf::Event event;
  C_EventHandler::get_instance()->process_event(event, &m_window, m_player);
}

void C_Game::exit() {

}

void C_Game::clean() {

}