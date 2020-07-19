#include "String.h"

String::String(const char* string) {
    m_Size = strlen(string);
    m_Data = new char[m_Size + 1];
    memcpy(m_Data, string, m_Size);
    m_Data[m_Size] = 0;
}

String::String(const String& other) : m_Size(other.m_Size) {
    m_Data = new char[m_Size];
    memcpy(m_Data, other.m_Data, m_Size + 1);
}

String::~String() {
    delete[] m_Data;
}

char& String::operator[](unsigned int idx) {
    return m_Data[idx];
}

std::ostream& operator<<(std::ostream& stream, const String& string) {
    stream << string.m_Data;
    return stream;
}