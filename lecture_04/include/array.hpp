#ifndef ARRAY_HPP
#define ARRAY_HPP


class Array
{
public:
    Array();
    Array(size_t, size_t);
    Array(const Array&);
    ~Array();

    void print() const;
    size_t getRowCount() const { return m_nRow; }
    size_t getColCount() const { return m_nCol; }
    int** getBegin() const { return m_pArray; }

    bool isAt(size_t, size_t) const;
    bool setAt(size_t, size_t, int);
    bool getAt(size_t, size_t, int&) const;

    bool isEqualSize(const Array&) const;

    bool isEqual(const Array&) const;
    bool add(const Array&);
    bool subtract(const Array&);
    Array transpose() const;


private:
    static size_t genSize();
    static int** fillData(size_t, size_t);
    static int** createEmptyArray(size_t, size_t);
    int at(size_t, size_t) const;


private:
    const size_t    m_nRow;
    const size_t    m_nCol;
    int**           m_pArray;
};

#endif // ARRAY_HPP
