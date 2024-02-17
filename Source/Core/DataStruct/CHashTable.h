#ifndef CHASHTABLE_H
#define CHASHTABLE_H

#include <string.h>
#include <stdio.h>
#include <iostream>
#include "CDoublyLinkedList.h"

template<typename Key, typename T>
class CHashTable
{
private:
    size_t m_max_capacity;
    CDoublyLinkedList<T*> *m_table;

private:
    unsigned int hash(const char* key)
    {
        int length = static_cast<int>(strnlen(key, 256));
        unsigned int hash_value = 0;
        for (int i = 0; i < length; i++)
        {
            hash_value += key[i];
            hash_value = (hash_value + key[i]) % m_max_capacity;
        }
        return hash_value;
    }

    unsigned int hash(int key)
    {
        return (key % static_cast<int>(m_max_capacity));
    }

public:
    CHashTable(size_t capacity)
        : m_max_capacity(capacity)
    {
        m_table = new CDoublyLinkedList<T*>[m_max_capacity];
    }

    friend std::ostream& operator<<(std::ostream& out,  CHashTable& obj)
    {
        out << "\nSTART ----------\n";
        for (int j = 0; j < static_cast<int>(obj.m_max_capacity); j++)
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

    CDoublyLinkedList<T*>& operator[](const char* key) const
    {
        unsigned int index = hash(key);
        return m_table[index];
    }

    void insert(Key key, T* ptr)
    {
        if(ptr == nullptr) return;
        else
        {
            int index = hash(key);
            if(index < static_cast<int>(m_max_capacity) && index >= 0)  m_table[index].push_back(ptr);
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
