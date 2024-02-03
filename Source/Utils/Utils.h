#ifndef UTILS_H_
#define UTILS_H_

#include <string>
#include <algorithm>
#include <iostream>
#include <typeinfo>
#include <string>
#include <stdint.h>
#include <sstream>

template <class T>
inline void safeRelease(T *ptr)
{
    if (ptr == nullptr)
        return;
    delete ptr;
    ptr = nullptr;
}

// function to convert decimal to hexadecimal
template <typename T>
inline std::string decToHex(T n)
{
    // ans string to store hexadecimal number
    std::string ans = "";

    while (n != 0)
    {
        // remainder variable to store remainder
        int rem = 0;

        // ch variable to store each character
        char ch;
        // storing remainder in rem variable.
        rem = n % 16;

        // check if temp < 10
        if (rem < 10)
        {
            ch = rem + 48;
        }
        else
        {
            ch = rem + 55;
        }

        // updating the ans string with the character variable
        ans += ch;
        n = n / 16;
    }

    // reversing the ans string to get the final result
    int i = 0, j = ans.size() - 1;
    while (i <= j)
    {
        std::swap(ans[i], ans[j]);
        i++;
        j--;
    }
    return ans;
}

inline std::string hexToASCII(std::string hex)
{
    // initialize the ASCII code string as empty.
    std::string ascii = "";
    for (size_t i = 0; i < hex.length(); i += 2)
    {
        // extract two characters from hex string
        std::string part = hex.substr(i, 2);

        // change it into base 16 and
        // typecast as the character
        char ch = stoul(part, nullptr, 16);

        // add this char to final ASCII string
        ascii += ch;
    }
    return ascii;
}

inline std::string dec64ToASCII(uint64_t dec)
{
    std::string hex = decToHex<uint64_t>(dec);
    std::string str = hexToASCII(hex);
    return str;
}

/// @brief
/// @param str
/// @return
inline const char *strToChars(std::string &str)
{
    return str.c_str();
}

template <typename T>
std::string classNameOf()
{
    std::string name = typeid(T).name();
    size_t spacePosition = name.find_first_of(" ");
    if (spacePosition != std::string::npos)
    {
        return name.substr(spacePosition + 1, name.length());
    }
    return name; // mostly primitive types
}

template <class T>
inline void swap(T &a, T &b)
{
    T c(a);
    a = b;
    b = c;
}

#endif // UTILS_H_
