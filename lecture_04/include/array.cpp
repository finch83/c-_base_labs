#include <iostream>
#include <random>
#include <algorithm>

#include "array.hpp"


Array::Array() :
    m_nRow(genSize()),
    m_nCol(genSize()),
    m_pArray(fillData(m_nRow, m_nCol)) {}



Array::Array(size_t nRow, size_t nCol) :
    m_nRow(nRow),
    m_nCol(nCol),
    m_pArray(createEmptyArray(m_nRow, m_nCol)) {}



Array::Array(const Array& dstArr) :
    m_nCol(dstArr.getColCount()),
    m_nRow(dstArr.getRowCount()),
    m_pArray(createEmptyArray(m_nRow, m_nCol))
{
    for(size_t row = 0; row < m_nRow; ++row) {
        for (size_t col = 0; col < m_nCol; ++col) {
            m_pArray[row][col] = dstArr.at(row, col);
        }
    }
}



Array::~Array()
{
    for(int row = 0; row < m_nRow; ++row) {
        delete [] m_pArray[row];
    }
    delete [] m_pArray;
}



void Array::print() const
{
    std::cout << "nRow: " << m_nRow << std::endl;
    std::cout << "nCol: " << m_nCol << std::endl;

    for (size_t row = 0; row < m_nRow; ++row) {
        for (size_t col = 0; col < m_nCol; ++col) {
            std::cout << " " << m_pArray[row][col];
        }
        std::cout << std::endl;
    }
}



int Array::at(size_t nRowPos, size_t nColPos) const
{
    return m_pArray[nRowPos][nColPos];
}



bool Array::getAt(size_t nRowPos, size_t nColPos, int& elem) const
{
    bool res = false;

    if (isAt(nRowPos, nColPos)) {
        elem = at(nRowPos, nColPos);
        res = true;
    }

    return res;
}



bool Array::isAt(size_t nRowPos, size_t nColPos) const
{
    return ( (nRowPos >= m_nRow) ? false :
    (nColPos >= m_nCol ? false : true));
}



bool Array::setAt(size_t row, size_t col, int val)
{
    if (!isAt(row, col)) {
        std::cout << "Out of range for: ["
                  << row << "][" << col << "]\n";
        return false;
    }

    m_pArray[row][col] = val;

    return true;
}



bool Array::isEqualSize(const Array& dstArr) const
{
    if ( (dstArr.getColCount() != getColCount()) ||
         (dstArr.getColCount() != getColCount()) )
        return false;

    return true;
}



size_t Array::genSize()
{
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution<size_t> distrib(2, 10);

    return distrib(generator);
}



int** Array::fillData(const size_t nRow, const size_t nCol)
{
    int** pArray = createEmptyArray(nRow, nCol);

    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution<int> distrib(0, 9);
    for (size_t row = 0; row < nRow; ++row) {
        for (size_t col = 0; col < nCol; ++col) {
            pArray[row][col] = distrib(generator);
        }
    }

    return pArray;
}



int** Array::createEmptyArray(size_t nRow, size_t nCol)
{
    int** pArray = new int* [nRow];
    for (size_t row = 0; row < nRow; ++row) {
        pArray[row] = new int [nCol];
    }

    return pArray;
}



bool Array::isEqual(const Array &dstArr) const
{
    if (!isEqualSize(dstArr))
        return false;

    for(size_t row = 0; row < m_nRow; ++row) {
        for (size_t col = 0; col < m_nCol; ++col) {
            if ( at(row, col) != dstArr.at(row, col) ) {
                return false;
            }
        }
    }

return true;
}



bool Array::add(const Array& dstArr)
{
    if (!isEqualSize(dstArr))
        return false;

    for(size_t row = 0; row < m_nRow; ++row) {
        for (size_t col = 0; col < m_nCol; ++col) {
            m_pArray[row][col] += dstArr.at(row, col);
        }
    }

    return true;
}



bool Array::subtract(const Array& dstArr)
{
    if (!isEqualSize(dstArr))
        return false;

    for(size_t row = 0; row < m_nRow; ++row) {
        for (size_t col = 0; col < m_nCol; ++col) {
            m_pArray[row][col] -= dstArr.at(row, col);
        }
    }

    return true;
}



Array Array::transpose() const
{
    Array newArray(m_nCol, m_nRow);

    for (size_t row = 0; row < m_nRow; ++row) {
        for (size_t col = 0; col < m_nCol; ++col) {
            newArray.setAt(col, row, m_pArray[row][col]);
        }
    }

    return newArray;
}
