//
// Created by David on 22/04/2018.
//

#include <boost/assert.hpp>
#include <boost/foreach.hpp>
#include "ForEach.hh"
#include "C_SceneNode.hh"

C_SceneNode::C_SceneNode() : mChildren(), mParent(nullptr) {}

void C_SceneNode::attachChild(C_SceneNode::Ptr child) {
  child->mParent = this;
  mChildren.push_back(std::move(child));
}

C_SceneNode::Ptr C_SceneNode::detachChild(const C_SceneNode &node) {
  auto found = std::find_if(mChildren.begin(), mChildren.end(), [&](Ptr &p) { return p.get() == &node; });
  assert(found != mChildren.end());

  Ptr result = std::move(*found);
  result->mParent = nullptr;
  mChildren.erase(found);
  return result;
}

void C_SceneNode::update(sf::Time dt) {

  updateCurrent(dt);
  updateChildren(dt);
}

sf::Vector2f C_SceneNode::getWorldPosition() const {
  return getWorldTransform() * sf::Vector2f();
}

sf::Transform C_SceneNode::getWorldTransform() const {
  sf::Transform transform = sf::Transform::Identity;

  for (const C_SceneNode *node = this; node != nullptr; node = node->mParent)
    transform = node->getTransform() * transform;

  return transform;
}

void C_SceneNode::updateCurrent(sf::Time dt) {

}

void C_SceneNode::updateChildren(sf::Time dt) {

  FOREACH(Ptr &child, mChildren) {
          child->update(dt);
        }
}

void C_SceneNode::draw(sf::RenderTarget &target, sf::RenderStates states) const {

}

void C_SceneNode::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {

}

void C_SceneNode::drawChildren(sf::RenderTarget &target, sf::RenderStates states) const {

}

const std::string &C_SceneNode::get_id() const {
  return m_id;
}
