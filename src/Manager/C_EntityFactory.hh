//
// Created by David on 22/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_C_ENTITYFACTORY_HH
#define INC_2DGAMEFRAMEWORK_C_ENTITYFACTORY_HH

#include "settings.h"
#include <TemplateSingleton.hh>
#include "../Graphic/C_Entity.hh"
#include "C_RessourcesManager.hh"

#include <thor/Animations.hpp>
#include <string>
#include <map>

namespace pt = boost::property_tree;
class C_BaseEntityCreator {
public:
  virtual C_Entity *C_CreateEntity() const = 0;
  virtual ~C_BaseEntityCreator() {}
};

class C_EntityFactory : public TemplateSingleton<C_EntityFactory> {
public:
  bool RegisterType(std::string p_type_id, C_BaseEntityCreator *p_creator);

  C_Entity *Create(std::string p_type_id);

private:
  std::map<std::string, C_BaseEntityCreator *> m_creators;
  std::map<std::string, pt::ptree> m_entities_settings;
};

#endif //INC_2DGAMEFRAMEWORK_C_ENTITYFACTORY_HH
