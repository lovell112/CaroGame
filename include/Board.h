#pragma once
#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

class Board {
    size_t m_row;
    size_t m_col;
    vector<vector<char>> m_data;
public:
    Board(size_t, size_t);
    ~Board();

    size_t getRow();
    size_t getCol();
    void setRow(size_t);
    void setCol(size_t);

    vector<char>& operator[](int);
    Board operator=(const Board&);

    bool isFull(int, int) const;
    void draw();
};
