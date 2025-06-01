#include "..\include\Board.h"

Board::Board(size_t row = 0, size_t col = 0) {
    m_row = row;
    m_col = col;
    m_data.resize(m_row, vector<char>(m_col));
    if (col!=0&&row!=0) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if ((i==0&&j==0)||(i==0&&j==col-1)||(i==row-1&&j==0)||(i==row-1&&j==col-1))
                    m_data[i][j] = '+';
                else if (i==0||i==row-1)
                    m_data[i][j] = '-';
                else if (j==0||j==col-1)
                    m_data[i][j] = '|';
                else
                    m_data[i][j] = ' ';
            }
        }
    }
}

// Board::Board(Board& board) {
//     // delete the old board
//     for (int i = 0; i < m_row; i++)
//         if (m_data[i]!=nullptr)
//             delete[] m_data[i];
//     if (m_data!=nullptr)
//         delete[] m_data;
//
//     if (board.m_data==nullptr) {
//         m_data = nullptr;
//         return;
//     }
//
//     m_row = board.m_row;
//     m_col = board.m_col;
//     m_data = new char*[m_row];
//     for (int i = 0; i < m_row; i++) {
//         m_data = new char*[m_col];
//         for (int j = 0; j < m_col; j++) {
//             m_data[i][j] = board[i][j];
//         }
//     }
// }

Board::~Board() {}

size_t Board::getRow() {return m_row;}
size_t Board::getCol() {return m_col;}

void Board::setRow(size_t row) {m_row = row;}
void Board::setCol(size_t col) {m_col = col;}

vector<char> &Board::operator[](int index) {
    return m_data[index];
}


bool Board::isFull(int x, int y) const {
    if (x<=0||x>=m_col-1||y<=0||y>=m_row-1||m_data[y][x]!=' ')
        return true;
    return false;
}

void Board::draw() {
    for (int i = 0; i < m_row; i++) {
        for (int j = 0; j < m_col; j++) {
            cout << m_data[i][j];
        }
        cout << endl;
    }
}