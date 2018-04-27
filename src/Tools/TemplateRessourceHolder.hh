//
// Created by David on 22/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_TEMPLATERESSOURCEHOLDER_HH
#define INC_2DGAMEFRAMEWORK_TEMPLATERESSOURCEHOLDER_HH

#include "TemplateSingleton.hh"
#include <string>
#include <memory>
#include <map>
#include <cassert>

template<typename T_Resource, typename T_Identifier>
class TemplateRessourceHolder : public TemplateSingleton<TemplateRessourceHolder<T_Resource, T_Identifier>> {
public:
  void load(T_Identifier id, const std::string &filename);

  T_Resource &get(T_Identifier id);

  const T_Resource &get(T_Identifier id) const;

private:
  void insertResource(T_Identifier id, std::unique_ptr<T_Resource> resource);

private:
  std::map<T_Identifier, std::unique_ptr<T_Resource>> m_resource_map;
};
#include "TemplateRessourceHolder.inl"

#endif //INC_2DGAMEFRAMEWORK_TEMPLATERESSOURCEHOLDER_HH
