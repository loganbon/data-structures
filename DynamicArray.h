#ifndef DATA_STRUCTURES_DYNAMICARRAY_H
#define DATA_STRUCTURES_DYNAMICARRAY_H
#include <cstdio>

template<typename T>
class DynamicArray {

private:
    T* m_Data;
    size_t m_Size = 0;
    size_t m_Capacity = 0;

    void reallocate(size_t newCapacity) {
        T* newData = (T*)::operator new(newCapacity * sizeof(T));

        if (newCapacity < m_Size)
            m_Size = newCapacity;

        for (size_t i = 0; i < m_Size; i++)
            newData[i] = std::move(m_Data[i]);

        for (size_t i = 0; i < m_Size; i++)
            m_Data[i].~T();

        ::operator delete(m_Data, m_Capacity * sizeof(T));
        m_Data = newData;
        m_Capacity = newCapacity;
    }

public:
    DynamicArray() {
        reallocate(2);
    }

    ~DynamicArray() {
        clear();
        ::operator delete(m_Data, m_Capacity * sizeof(T));
    }

    size_t const size() {
        return m_Size;
    }

    const T& operator[](size_t pos) const {
        return m_Data[pos];
    }

    T& operator[](size_t pos) {
        return m_Data[pos];
    }

    void pushBack(T&& elem) {

        if (m_Size >= m_Capacity)
            reallocate(m_Capacity + m_Capacity / 2);

        m_Data[m_Size] = std::move(elem);
        m_Size++;
    }

    void popBack() {
        if (m_Size > 0) {
            m_Size--;
            m_Data[m_Size].~T();
        }
    }

    void clear() {
        for (size_t i = 0; i < m_Size; i++)
            m_Data[i].~T();
        m_Size = 0;
    }

    template<typename... Args>
    T& emplaceBack(Args&&... args) {
        if (m_Size >= m_Capacity)
            reallocate(m_Capacity + m_Capacity / 2);

        new(&m_Data[m_Size]) T(std::forward<Args>(args)...);
        return m_Data[m_Size++];
    }


};

#endif //DATA_STRUCTURES_DYNAMICARRAY_H