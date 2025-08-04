#include "./string.h"

#include <cstdio>

String::String() : m_data(nullptr), m_length(0) {}

String::String(const char* s) {
	if (s) {
		m_length = std::strlen(s);
		m_data = new char[m_length+1];
		std::strcpy(m_data, s);
	} else {
		m_data = nullptr;
		m_length = 0;
	}
}

String::String(const String& copied_from) {
	m_length = copied_from.m_length;
	if (m_length > 0) {
		m_data = new char[m_length+1];
		std::strcpy(m_data, copied_from.m_data);
	} else {
		m_data = nullptr;
	}
}

String::String(String&& moved_from) noexcept : 
	m_data(moved_from.m_data),
	m_length(moved_from.m_length) {
	
	moved_from.m_data = nullptr;
	moved_from.m_length = 0;
}

String::String(int i) {
	char buffer[32];
    std::snprintf(buffer, sizeof(buffer), "%d", i);
    m_length = std::strlen(buffer);
    m_data = new char[m_length + 1];
    std::strcpy(m_data, buffer);
}

String::String(unsigned int u) {
    char buffer[32];
    std::snprintf(buffer, sizeof(buffer), "%u", u);
    m_length = std::strlen(buffer);
    m_data = new char[m_length+1];
    std::strcpy(m_data, buffer);
}

String::String(float f) {
    char buffer[32];
    std::snprintf(buffer, sizeof(buffer), "%.6g", f);
    m_length = std::strlen(buffer);
    m_data = new char[m_length+1];
    std::strcpy(m_data, buffer);
}

String::~String() {
	delete[] m_data;
}

const char* String::str() const {
	return m_data ? m_data : "";
}

size_t String::size() const {
	return m_length;
}

String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] m_data;

        m_length = other.m_length;
        m_data = new char[m_length+1];
        std::strcpy(m_data, other.m_data);
    }
    return *this;
}

String operator+(const String& lhs, const String& rhs) {
	size_t new_len = lhs.m_length + rhs.m_length;
	char* data_buffer = new char[new_len+1];

	std::strcpy(data_buffer, lhs.str());
	std::strcat(data_buffer, rhs.str());

	String result(data_buffer);
	delete[] data_buffer;

	return result;
}
