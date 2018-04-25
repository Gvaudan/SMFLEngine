template<typename T_Resource, typename T_Identifier>
void TemplateRessourceHolder<T_Resource, T_Identifier>::load(T_Identifier id, const std::string &filename) {
  // Create and load resource
  std::unique_ptr <T_Resource> resource(new T_Resource());
  if (!resource->loadFromFile(filename))
    throw std::runtime_error("TemplateRessourceHolder::load - Failed to load " + filename);

  // If loading successful, insert resource to map
  insertResource(id, std::move(resource));
}

template<typename T_Resource, typename T_Identifier>
T_Resource &TemplateRessourceHolder<T_Resource, T_Identifier>::get(T_Identifier id) {
  auto found = m_resource_map.find(id);
  assert(found != m_resource_map.end());

  return *found->second;
}

template<typename T_Resource, typename T_Identifier>
const T_Resource &TemplateRessourceHolder<T_Resource, T_Identifier>::get(T_Identifier id) const {
  auto found = m_resource_map.find(id);
  assert(found != m_resource_map.end());

  return *found->second;
}

template<typename T_Resource, typename T_Identifier>
void TemplateRessourceHolder<T_Resource, T_Identifier>::insertResource(T_Identifier id, std::unique_ptr <T_Resource> resource) {
  // Insert and check success
  auto inserted = m_resource_map.insert(std::make_pair(id, std::move(resource)));
  assert(inserted.second);
}