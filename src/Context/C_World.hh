//
// Created by David on 22/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_C_WORLD_HH
#define INC_2DGAMEFRAMEWORK_C_WORLD_HH

#include "../Graphic/C_TextureHolder.hh"
#include "../Graphic/C_SceneNode.hh"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <d3d10.h>

// Forward declaration
namespace sf { class RenderWindow; }

class C_World : private sf::NonCopyable {
public:
  explicit C_World(sf::RenderWindow &window);

  void update(sf::Time dt);

  void draw();

private:
  void loadTextures();

  void buildScene();

private:
  enum Layer {
    Backgroundv,
    Air,
    LayerCount
  };

private:
  sf::RenderWindow &mWindow;
  sf::View mWorldView;
  T_TEXTURE_HOLDER *m_textures;

  C_SceneNode mSceneGraph;
  std::array<C_SceneNode *, LayerCount> mSceneLayers;

  sf::FloatRect mWorldBounds;
  sf::Vector2f mSpawnPosition;
  float mScrollSpeed;
};

#endif //INC_2DGAMEFRAMEWORK_C_WORLD_HH
