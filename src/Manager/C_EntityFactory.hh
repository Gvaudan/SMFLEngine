//
// Created by David on 22/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_C_ENTITYFACTORY_HH
#define INC_2DGAMEFRAMEWORK_C_ENTITYFACTORY_HH

#include <TemplateSingleton.hh>
#include "../Graphic/C_Entity.hh"
#include <string>
#include <map>

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
};

#endif //INC_2DGAMEFRAMEWORK_C_ENTITYFACTORY_HH
