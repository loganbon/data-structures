#ifndef DATA_STRUCTURES_STRING_H
#define DATA_STRUCTURES_STRING_H

#include <iostream>

class String {

private:
    char* m_Data;
    unsigned int m_Size;

public:
    String(const char* string);
    String(const String& other);
    ~String();

    friend std::ostream& operator<<(std::ostream& stream, const String& string);
    char& operator[](unsigned int idx);

};


#endif //DATA_STRUCTURES_STRING_H
