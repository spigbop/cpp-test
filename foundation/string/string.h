#ifndef STRING_H
#define STRING_H

#include <cstring>

class String {
private:
	char* m_data;
	size_t m_length;

public:
	String();
	String(const String& copied_from);
	String(String&& moved_from) noexcept;
	String(const char* s);

	String(int i);
	String(unsigned int u);
	String(float f);

	~String();

	const char* str() const;
	size_t size() const;

	String& operator=(const String& other);
	String& operator=(String& other) noexcept;

	friend String operator+(const String& lhs, const String& rhs);
};

#endif