//
// Created by David on 22/04/2018.
//

#include <boost/log/trivial.hpp>
#include "C_EntityFactory.hh"
bool C_EntityFactory::RegisterType(std::string p_type_id, C_BaseEntityCreator *p_creator) {
  auto it = m_creators.find(p_type_id);
  // if the m_model is already registered, do nothing
  if (it != m_creators.end()) {
	delete p_creator;
	return false;
  }
  C_RessourcesManager::get_instance()->load_entities_set(p_type_id);
  // TODO : Charger les textures de l'entite
  m_creators[p_type_id] = p_creator;
  return true;
}

C_Entity *C_EntityFactory::Create(std::string p_type_id) {
  auto it = m_creators.find(p_type_id);
  if (it == m_creators.end()) {
	BOOST_LOG_TRIVIAL(fatal) << __PRETTY_FUNCTION__ << "could not find m_model: " << p_type_id << "\n";
	return nullptr;
  }
  // TODO : Charger les textures de l'entite si elle ne sont pas presentes

  // TODO : Charger les keys frames de l'entitie
  std::map<std::string, std::set<thor::FrameAnimation>> entitie_animations;

  C_BaseEntityCreator *pCreator = (*it).second;
  return pCreator->C_CreateEntity();
}
