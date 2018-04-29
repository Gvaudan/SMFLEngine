//
// Created by David on 22/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_SCENENODE_HH
#define INC_2DGAMEFRAMEWORK_SCENENODE_HH

#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include <vector>
#include <memory>

class C_SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable {
public:
  typedef std::unique_ptr<C_SceneNode> Ptr;
public:
  C_SceneNode();

  virtual void attachChild(Ptr child);

  virtual Ptr detachChild(const C_SceneNode &node);

  virtual void update(sf::Time dt);

  sf::Vector2f getWorldPosition() const;

  sf::Transform getWorldTransform() const;


private:
  virtual void updateCurrent(sf::Time dt);

  void updateChildren(sf::Time dt);

  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

  virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;

  void drawChildren(sf::RenderTarget &target, sf::RenderStates states) const;


private:
  std::vector<Ptr> mChildren;
  C_SceneNode *mParent;
};


#endif //INC_2DGAMEFRAMEWORK_SCENENODE_HH
