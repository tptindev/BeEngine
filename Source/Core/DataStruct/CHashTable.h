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
    CDoublyLinkedList<T*> m_table;

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
        for (int i = 0; i < static_cast<int>(m_max_capacity); i++)
        {
            m_table.push_back(nullptr);
        }
    }

    friend std::ostream& operator<<(std::ostream& out,  CHashTable& obj)
    {
        int i = 0;
        auto it = obj.m_table.begin();
        while (it != obj.m_table.end())
        {
            if(*it != nullptr)
            {
                out << "[" << (*it) << "][" << i << "][" << ((*it) == nullptr? -1: *(*it)) << "]" << std::endl;
            }
            ++it;
            ++i;
        }
        return out;
    }

    unsigned int operator()(const char* key)
    {
        return hash(key);
    }

    unsigned int operator()(int key)
    {
        return hash(key);
    }

    void insert(Key key, T* ptr)
    {
        if(ptr == nullptr) return;
        else
        {
            int index = hash(key);
            if(index < m_table.count())  m_table[index] = ptr;
            else return;
        }
    }

    void remove(Key key)
    {
        int index = hash(key);
        auto it = m_table.begin();
        for (; it != m_table.end(); ++it)
        {
            if ((*it) == m_table[index])
            {
                m_table.erase(it);
                return;
            }
        }
    }
};

#endif // CHASHTABLE_H
