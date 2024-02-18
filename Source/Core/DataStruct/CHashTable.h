#ifndef CHASHTABLE_H
#define CHASHTABLE_H

#include <string.h>
#include <stdio.h>
#include <iostream>
#include <functional>
#include "CDoublyLinkedList.h"

template<typename Key, typename T, size_t TableSize>
class CHashTable
{
private:
    size_t m_capacity;
    CDoublyLinkedList<T*> *m_table;

private:
    unsigned int hash(const char* key)
    {
        int length = static_cast<int>(strnlen(key, 256));
        unsigned int hash_value = 0;
        for (int i = 0; i < length; i++)
        {
            hash_value += key[i];
            hash_value = (hash_value + key[i]) % m_capacity;
        }

        return hash_value;
    }

    unsigned int hash(Key key)
    {
        return (key % static_cast<int>(m_capacity));
    }

public:
    CHashTable()
        : m_capacity(TableSize)
    {
        m_table = new CDoublyLinkedList<T*>[m_capacity];
    }

    friend std::ostream& operator<<(std::ostream& out,  CHashTable& obj)
    {
        out << "\nSTART ----------\n";
        for (int j = 0; j < static_cast<int>(obj.m_capacity); j++)
        {
            auto it = obj.m_table[j].begin();
            while (it != obj.m_table[j].end())
            {
                if(*it != nullptr)
                {
                    out << "[" << j << "][" << (*it) << "][" << ((*it) == nullptr? -1: *(*it)) << "]\n";
                }
                ++it;
            }
        }
        out << "END -----------\n";
        return out;
    }

    CDoublyLinkedList<T*>& operator[](const char* key)
    {
        unsigned int index = hash(key);
        if (index < 0 || index >= m_capacity) {
            throw std::out_of_range("Index out of range");
        }
        return m_table[index];
    }

    void insert(Key key, T* ptr)
    {
        if(ptr == nullptr) return;
        else
        {
            int index = hash(key);
            if(index < static_cast<int>(m_capacity) && index >= 0)  m_table[index].push_back(ptr);
            else return;
        }
    }

    void remove(Key key)
    {
        int index = hash(key);
        auto it = m_table[index].begin();
        for (; it != m_table[index].end(); ++it)
        {
            m_table[index].erase(it);
        }
    }
};

#endif // CHASHTABLE_H
