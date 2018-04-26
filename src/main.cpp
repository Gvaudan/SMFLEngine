#include <iostream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Context/C_Game.hh"

using namespace std;
int main() {

  C_Game::get_instance()->init();
  C_Game::get_instance()->run();
  return EXIT_SUCCESS;
}