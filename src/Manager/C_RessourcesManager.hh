//
// Created by David on 22/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_C_RESSOURCESMANAGER_HH
#define INC_2DGAMEFRAMEWORK_C_RESSOURCESMANAGER_HH

#include "../Graphic/C_TextureHolder.hh"

#include <Thor/Resources.hpp>

class C_RessourcesManager : public TemplateSingleton<C_RessourcesManager> {
private:
  C_RessourcesManager();
  T_TEXTURE_HOLDER *m_textures_holder;
};

#endif //INC_2DGAMEFRAMEWORK_C_RESSOURCESMANAGER_HH
