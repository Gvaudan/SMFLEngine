//
// Created by David on 22/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_BASESTATE_HH
#define INC_2DGAMEFRAMEWORK_BASESTATE_HH

#include <Thor/Input.hpp>
#include <string>

class C_BaseState {
public:
    virtual void handleInput() = 0;

    virtual void update() = 0;

    virtual void render() = 0;

    virtual void on_start() = 0;

    virtual void on_exit() = 0;

    virtual const std::string &get_state_id() const;

    void push_action(std::string p_name, thor::Action p_action);

protected:
    bool m_is_cancelable = false;
    std::string m_state_id;
    thor::ActionMap<std::string> m_action_map;
public:
    const thor::ActionMap<std::string> &get_action_map() const;
};


#endif //INC_2DGAMEFRAMEWORK_BASESTATE_HH
