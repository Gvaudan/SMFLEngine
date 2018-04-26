//
// Created by dyoubi on 26/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_C_TESTENTITIESTATE_HH
#define INC_2DGAMEFRAMEWORK_C_TESTENTITIESTATE_HH


#include "C_TestEntitie.hh"
#include "../State/C_BaseState.hh"

class C_TestEntitieState : public C_BaseState {
public:
    C_TestEntitieState();

    C_TestEntitieState(C_TestEntitie *p_entitie);

    void handleInput() override;

    void update() override;

    void render() override;

    void on_start() override;

    void on_exit() override;

private:
    void init_actions() override;

    C_TestEntitie *m_entitie;
};


#endif //INC_2DGAMEFRAMEWORK_C_TESTENTITIESTATE_HH
