#ifndef MATRIX2D_H
#define MATRIX2D_H

#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <assert.h>

template<typename T>
class CMatrix2D
{
private:
    int m_rows, m_columns;
    T *m_data = nullptr;

public:
    explicit CMatrix2D(): m_rows(10), m_columns(10)
    {
        this->m_data = new T[m_rows  *m_columns];
    }
    explicit CMatrix2D(int rows, int columns) : m_rows(rows),m_columns(columns)
    {
        assert((rows  * columns > 0) && "Matrix size invalid");
        this->m_data = new T[rows  *columns];
    }

    virtual ~CMatrix2D()
    {
        if(this->m_data != nullptr)
        {
            delete []this->m_data;
            this->m_data = nullptr;
        }
    }

    // copy constructor
    CMatrix2D(const CMatrix2D<T> &copy)
    {
        this->m_columns = copy.m_columns;
        this->m_rows = copy.m_rows;

        if(this->m_data != nullptr)
        {
            delete []this->m_data;
        }

        this->m_data = new T[m_rows * m_columns];
        std::copy(copy.m_data, copy.m_data + (m_rows * m_columns), this->m_data);
    }

    // move constructor
    CMatrix2D(CMatrix2D<T> &&copy) noexcept
    {
        swap(*this, copy);
        copy.m_data = nullptr;
    }

    // Copy assignment operator
    CMatrix2D<T> &operator=(const CMatrix2D<T> &copy)
    {
        if (this != &copy)
        {
            CMatrix2D<T> tmp(copy);
            swap(*this, tmp);
        }
        return *this;
    }

    // Move assignment operator
    CMatrix2D<T>& operator=(CMatrix2D<T>&& other) noexcept
    {
        swap(*this, other);
        return *this;
    }

    T &at(int y, int x)
    {
        assert((x < m_columns && y < m_rows) && "Index invalid");
        return this->m_data[(y  * m_columns) + x];
    }

    T &at(int pos)
    {
        assert((pos < (m_rows * m_columns)) && "Index invalid");
        return this->m_data[pos];
    }

    void resize(int rows, int columns)
    {
        if(m_data != nullptr)
        {
            delete []m_data;
        }
        m_data = new T[rows  *columns];
        m_rows = rows;
        m_columns = columns;
    }

    int rows() const
    {
        return m_rows;
    }
    int columns() const
    {
        return m_columns;
    }

    void print()
    {
        for (int row = 0; row < m_rows; row++)
        {
            // read line
            for (int col = 0; col < m_columns; col++)
            {
                std::cout << at(row, col) << " ";
            }
            std::cout << "\n";
        }
    }
    static CMatrix2D<T> fromString(const char *cstr, int rows, int columns)
    {
        std::string str(cstr);
        std::istringstream ss(str);
        CMatrix2D<T> data(rows, columns);

        // read rows
        for (int row = 0; row < rows; row++)
        {
            // read lines
            std::string line;
            for (int col = 0; col < columns; col++)
            {
                std::getline(ss, line, ',');
                data.at(row, col) = std::stoi(line);
            }
        }
        return data;
    }

    friend void swap(CMatrix2D<T>& first, CMatrix2D<T>& second) noexcept {
        using std::swap;

        swap(first.m_rows, second.m_rows);
        swap(first.m_columns, second.m_columns);
        swap(first.m_data, second.m_data);
    }
};

using Matrix2DI = CMatrix2D<int>;
using Matrix2U = CMatrix2D<unsigned int>;
using Matrix2F = CMatrix2D<float>;
using Matrix2LF = CMatrix2D<double>;

#endif // MATRIX2D_H
