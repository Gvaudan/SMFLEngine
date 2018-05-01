//
// Created by David on 22/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_SETTINGS_H
#define INC_2DGAMEFRAMEWORK_SETTINGS_H

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define WINDOW_TITLE "2DGameFrameWork"
#define WINDOW_STYLE sf::Style::Default

#define RESSOURCES_ROOT "ressources/"
#define FONTS_LEVEL_PATH "ressources/fonts/"
#define FONTS_SPRITES_PATH "ressources/sprites/"
#define GAME_SETTINGS_FILE "ressources/GameSettings.json"

#include <Thor/Input.hpp>
#include <SFML/Window/Joystick.hpp>
#include <TemplateSingleton.hh>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

struct s_settings {
};

namespace GameState {
  namespace Player {
    typedef enum {
      NEUTRAL,
      ON_MOVE,
      ON_JUMP,
      ON_CROUSH,
      ON_HIT,
      ON_ATTACK
    } State;
    typedef enum {
      JUMP,
      MOVE,
      ATTACK
    } Action;
    typedef enum {
      LOW,
      HIGHT,
      SUPER
    } Attack;
  }
}

typedef sf::Joystick sfJoy;
namespace ControllerBind {

  typedef enum s_gamepad_model {
    XBOXONE = 0,
    XBOX360 = 1,
    PS4 = 2
  } t_gamepad_model;
  typedef enum s_gamepad_commands {
    LStick = '1',
    RStick = '2',
    LTrigger = '3',
    RTrigger = '4',
    DPad = '5',
    A = '1',
    B = '2',
    X = '3',
    Y = '4',
    START = '5',
    SELECT = '6',
    LB = '7',
    RB = '8'
  } t_gamepad_commands;

  typedef struct s_gamepad_stick {
    sfJoy::Joystick::Axis m_axis_x;
    sfJoy::Joystick::Axis m_axis_y;

    thor::JoystickAxis *m_up = nullptr;
    thor::JoystickAxis *m_down = nullptr;
    thor::JoystickAxis *m_left = nullptr;
    thor::JoystickAxis *m_right = nullptr;

    float m_treshold;

    float current_x;
    float current_y;

  } t_gamepad_stick;

  typedef struct s_gamepad {
    struct s_gamepad_stick;
  } t_game_pad;

};

#endif //INC_2DGAMEFRAMEWORK_SETTINGS_H
