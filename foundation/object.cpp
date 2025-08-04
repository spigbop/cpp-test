#include "./object.h"

#include <iostream>

std::unordered_map<Object::RefId, Object*> Object::s_registry;
Object::RefId Object::s_next = 1;

Object::Object() {
	m_id = s_next ++;
	s_registry[m_id] = this;
	std::cout << "Object created with reference ID: " << m_id << std::endl;
}

Object::~Object() {
	s_registry.erase(m_id);
}

Object::RefId Object::id() const {
    return m_id;
}

Object* Object::fromId(Object::RefId id) {
    auto it = s_registry.find(id);
    return (it != s_registry.end()) ? it->second : nullptr;
}
