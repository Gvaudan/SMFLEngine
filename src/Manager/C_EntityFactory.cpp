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
  m_creators[p_type_id] = p_creator;
  return true;
}

C_Entity *C_EntityFactory::Create(std::string p_type_id) {
  auto it = m_creators.find(p_type_id);
  if (it == m_creators.end()) {
    BOOST_LOG_TRIVIAL(error) << __PRETTY_FUNCTION__ << "could not find m_model: " << p_type_id << "\n";
    return nullptr;
  }
  C_BaseEntityCreator *pCreator = (*it).second;
  return pCreator->C_CreateEntity();
}
