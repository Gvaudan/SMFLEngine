//
// Created by David on 29/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_C_GAMEPAD_HH
#define INC_2DGAMEFRAMEWORK_C_GAMEPAD_HH

#include "settings.h"

#include <Thor/Input.hpp>
#include <SFML/Window/Joystick.hpp>

namespace pt = boost::property_tree;

namespace ControllerBind {

  class C_GamePad {
  public:
    C_GamePad();

    C_GamePad(unsigned int p_id);

    virtual ~C_GamePad();

    void bind_inputs(pt::ptree &p_ptree);

    void update_inputs();

    const t_gamepad_stick &get_LStick() const;

    const t_gamepad_stick &get_RStick() const;

    const t_gamepad_stick &get_DPad() const;

    const std::string &get_owner_id() const;

    const std::string &get_name() const;

    unsigned int get_id() const;

    bool get_is_connected() const;

    t_gamepad_model get_model() const;

    float get_dead_zone() const;

    const thor::ActionMap<std::string> &get_action_map() const;

    unsigned int get_A() const;

    unsigned int get_B() const;

    unsigned int get_X() const;

    unsigned int get_Y() const;

    unsigned int get_start() const;

    unsigned int get_select() const;

    unsigned int get_LB() const;

    unsigned int get_RB() const;


    void on_connect();

    void on_disconnect();

  private:
    bool init();

    bool init(pt::ptree &p_ptree);

    std::string owner_id;
    std::string m_name;
    unsigned int m_id;
    bool m_is_connected;

    t_gamepad_model m_model;

    t_gamepad_stick m_LStick;
    t_gamepad_stick m_RStick;
    t_gamepad_stick m_DPad;

    float m_dead_zone;

    thor::ActionMap<std::string> m_action_map;

    unsigned int m_A;
    unsigned int m_B;
    unsigned int m_X;
    unsigned int m_Y;
    unsigned int m_start;
    unsigned int m_select;
    unsigned int m_LB;
    unsigned int m_RB;
  };

}
#endif //INC_2DGAMEFRAMEWORK_C_GAMEPAD_HH
