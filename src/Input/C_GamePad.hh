//
// Created by David on 29/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_C_GAMEPAD_HH
#define INC_2DGAMEFRAMEWORK_C_GAMEPAD_HH

#include <TemplateSingleton.hh>
#include <Thor/Input.hpp>
#include <SFML/Window/Joystick.hpp>

namespace ControllerBind {

  typedef enum s_stick_type {
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
  } t_stick_type;

  typedef struct s_gamepad_stick {
    sf::Joystick::Axis m_axis_x;
    sf::Joystick::Axis m_axis_y;
    s_stick_type type;
  } t_gamepad_stick;

  typedef struct s_gamepad {
    struct s_gamepad_stick;
  } t_game_pad;

  class C_GamePad {
  public:
    C_GamePad();

    void bind_inputs();

    void update_inputs();

    const t_gamepad_stick &get_LStick() const;

    const t_gamepad_stick &get_RStick() const;

    const t_gamepad_stick &get_DPad() const;

  private:
    std::string m_name;
    unsigned int m_id;
    bool m_is_connected;

    t_gamepad_stick m_LStick;
    t_gamepad_stick m_RStick;
    t_gamepad_stick m_DPad;

    unsigned int m_A;
    unsigned int m_B;
    unsigned int m_X;
    unsigned int m_Y;
    unsigned int m_start;
    unsigned int m_select;
    unsigned int m_LB;
    unsigned int m_RB;
    float m_dead_zone;

  };

}
#endif //INC_2DGAMEFRAMEWORK_C_GAMEPAD_HH
