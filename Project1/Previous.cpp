#include "Previous.h"
#include <iostream>

using namespace std;

Previous::Previous (int nRows, int nCols)
{
    m_rows = nRows;
    m_cols = nCols;
    // Through assumption, we can go straight into iterations.
    for (int i=0; i < m_rows; i++){
        for (int j=0; j < m_cols; j++){
            m_arena[i][j] = 'A' - 1;
        }
    }
}

bool Previous::dropACrumb(int r, int c)
{
    r--;c--;
    bool out = false;
    if (r <= m_rows && r >= 0 && c <= m_cols && c >= 0){
        if (m_arena[r][c] != 'R'){
            m_arena[r][c]++;
        }
        out = true;
    }
    return out;
}

void Previous::showPreviousMoves() const
{
    clearScreen(); //Clears Screen
    for (int i=0; i < m_rows; i++){
        for (int j=0; j < m_cols; j++){
            if (m_arena[i][j] == 'A' - 1){
                cout << ".";
            }else{
                cout << m_arena[i][j];
            }
        }
        cout << endl;
    }
    cout << endl;
}
