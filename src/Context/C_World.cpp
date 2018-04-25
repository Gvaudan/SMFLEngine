//
// Created by David on 22/04/2018.
//

#include "C_World.hh"
#include "../Graphic/C_SpriteNode.hh"
#include <SFML/Graphics/RenderWindow.hpp>
#include <boost/log/trivial.hpp>

C_World::C_World(sf::RenderWindow &window)
    : mWindow(window),
      m_textures(T_TEXTURE_HOLDER::get_instance()),
      mWorldView(window.getDefaultView()),
      mSceneGraph(),
      mSceneLayers(),
      mWorldBounds(0.f, 0.f, mWorldView.getSize().x, 2000.f),
      mSpawnPosition(mWorldView.getSize().x / 2.f, mWorldBounds.height - mWorldView.getSize().y / 2.f),
      mScrollSpeed(-50.f) {
  BOOST_LOG_TRIVIAL(debug) << __PRETTY_FUNCTION__;
  loadTextures();
  buildScene();
}

void C_World::update(sf::Time dt) {
  BOOST_LOG_TRIVIAL(info) << __PRETTY_FUNCTION__;

  // Scroll the world
  mWorldView.move(0.f, mScrollSpeed * dt.asSeconds());

  // Move the player sidewards (plane scouts follow the main aircraft)
  //sf::Vector2f position = mPlayerAircraft->getPosition();
  //sf::Vector2f velocity = mPlayerAircraft->getVelocity();

  // If player touches borders, flip its X velocity
  //if (position.x <= mWorldBounds.left + 150.f
  //    || position.x >= mWorldBounds.left + mWorldBounds.width - 150.f)
  //{
  //  velocity.x = -velocity.x;
  //  mPlayerAircraft->setVelocity(velocity);
  //}

  // Apply movements
  mSceneGraph.update(dt);
}

void C_World::draw() {
  mWindow.setView(mWorldView);
  mWindow.draw(mSceneGraph);
}

void C_World::loadTextures() {

}

void C_World::buildScene() {
  BOOST_LOG_TRIVIAL(trace) << __PRETTY_FUNCTION__;
// Initialize the different layers
  for (std::size_t i = 0; i < LayerCount; ++i) {
    C_SceneNode::Ptr layer(new C_SceneNode());
    mSceneLayers[i] = layer.get();

    mSceneGraph.attachChild(std::move(layer));
  }
}
