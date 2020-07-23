#ifndef DATA_STRUCTURES_ARRAY_H
#define DATA_STRUCTURES_ARRAY_H

template<typename T, size_t N>
class Array {
private:
    T m_Data[N];

public:
    Array() {};
    constexpr size_t size() { return N; };
    T& operator[](int idx) { return m_Data[idx]; };
    const T& operator[](int idx) const { return m_Data[idx]; };

};


#endif //DATA_STRUCTURES_ARRAY_H
