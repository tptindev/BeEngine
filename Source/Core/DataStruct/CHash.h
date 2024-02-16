#ifndef CHASH_H
#define CHASH_H

#include <string.h>
#include <stdio.h>
#include "CDoublyLinkedList.h"

template<typename Key, typename Value>
class CHash
{
private:
    size_t m_max_capacity = sizeof(Key);
    CDoublyLinkedList<Value> m_table;

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
        return (key % m_max_capacity);
    }

public:
    CHash()
    {
        for (int i = 0; i < static_cast<int>(m_max_capacity); i++)
        {
            m_table.push_back(nullptr);
        }
    }

    unsigned int operator()(const char* key)
    {
        return hash(key);
    }

    unsigned int operator()(int key)
    {
        return hash(key);
    }
};

#endif // CHASH_H
