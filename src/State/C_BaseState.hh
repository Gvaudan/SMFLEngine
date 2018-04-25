//
// Created by David on 22/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_BASESTATE_HH
#define INC_2DGAMEFRAMEWORK_BASESTATE_HH

#include <string>

class C_BaseState {
public:
  virtual void handleInput() = 0;

  virtual void update() = 0;

  virtual void render() = 0;

  virtual void on_start() = 0;

  virtual void on_exit() = 0;

  virtual const std::string &get_state_id() const;

protected:
  bool m_is_cancelable = false;
  std::string m_state_id;
};


#endif //INC_2DGAMEFRAMEWORK_BASESTATE_HH
