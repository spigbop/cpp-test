#pragma once
#ifndef OBJECT_H
#define OBJECT_H

#include <unordered_map>

class Object {
public:
	using RefId = unsigned int;

protected:
	static std::unordered_map<RefId, Object*> s_registry;
	static RefId s_next;

	RefId m_id;

public:
	Object();
	virtual ~Object();

	RefId id() const;

	static Object* fromId(RefId id);
};

#endif