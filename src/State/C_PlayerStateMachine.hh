//
// Created by dyoubi on 26/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_C_PLAYERSTATEMACHINE_HH
#define INC_2DGAMEFRAMEWORK_C_PLAYERSTATEMACHINE_HH

#include "../Tools/TemplateSingleton.hh"
#include "C_BaseStateMachine.hh"


class C_PlayerStateMachine :
        public TemplateSingleton<C_PlayerStateMachine>,
        public C_BaseStateMachine {

};


#endif //INC_2DGAMEFRAMEWORK_C_PLAYERSTATEMACHINE_HH
