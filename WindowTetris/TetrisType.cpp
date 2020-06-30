#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include "myhead.h"
#include <conio.h>
#include "const.h"

using namespace std;

//方块绘制
//L型方块
bool CTetris::DrawTetris_L_A(int nMove) {
    char ch = '0';

    nFlagDown = false;

    int nTemp = nMove + 1;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (szAryTetris_L_A[i][j] == 1) {
                funcDrawSquare(j + 1 + m_GlobalX, nMove + i);
            }         
        }
    }

    bool nFlag = false;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (szAryTetris_L_A[i][j] == 1) { //1
                int nX = i + nTemp;
                int nY = j + 1 + m_GlobalX;
                char szFlag = m_pszMap[nX * m_nMaxWidth + nY];

                if (szFlag == 1 || szFlag == 2 || szFlag == 3 || 
                    szFlag == 4 || szFlag == 5) { //~1
                    nFlag = true;
                    break;
                }
            }
        }
    }

    switch (m_nColorType) {
    case 1:
        if (nFlag == true) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (szAryTetris_L_A[i][j] == 1) { //1
                        int nX = i + nMove;
                        int nY = j + 1 + m_GlobalX;
                        m_pszMap[nX * m_nMaxWidth + nY] = COLOR_GREEN;
                    }
                }
            }
            nFlagDown = true;
            return true;
        }
        break;
    case 2:
        if (nFlag == true) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (szAryTetris_L_A[i][j] == 1) { //1
                        int nX = i + nMove;
                        int nY = j + 1 + m_GlobalX;
                        m_pszMap[nX * m_nMaxWidth + nY] = COLOR_PURPLE;
                    }
                }
            }
            nFlagDown = true;
            return true;
        }
        break;
    case 3:
        if (nFlag == true) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (szAryTetris_L_A[i][j] == 1) { //1
                        int nX = i + nMove;
                        int nY = j + 1 + m_GlobalX;
                        m_pszMap[nX * m_nMaxWidth + nY] = COLOR_RED;
                    }
                }
            }
            nFlagDown = true;
            return true;
        }
        break;
    case 4:
        if (nFlag == true) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (szAryTetris_L_A[i][j] == 1) { //1
                        int nX = i + nMove;
                        int nY = j + 1 + m_GlobalX;
                        m_pszMap[nX * m_nMaxWidth + nY] = COLOR_YELLOW;
                    }
                }
            }
            nFlagDown = true;
            return true;
        }
        break;
    }

    return false;
}

bool CTetris::DrawTetris_L_B(int nMove) {
    char ch = '0';

    nFlagDown = false;

    int nTemp = nMove + 1;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (szAryTetris_L_B[i][j] == 1) {
                funcDrawSquare(j + 1 + m_GlobalX, nMove + i);
            }          
        }
    }

    bool nFlag = false;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (szAryTetris_L_B[i][j] == 1) { //1
                int nX = i + nTemp;
                int nY = j + 1 + m_GlobalX;
                char szFlag = m_pszMap[nX * m_nMaxWidth + nY];

                if (szFlag == 1 || szFlag == 2 || szFlag == 3 ||
                    szFlag == 4 || szFlag == 5) { //~1
                    nFlag = true;
                    break;
                }
            }
        }
    }

    switch (m_nColorType) {
    case 1:
        if (nFlag == true) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (szAryTetris_L_B[i][j] == 1) { //1
                        int nX = i + nMove;
                        int nY = j + 1 + m_GlobalX;
                        m_pszMap[nX * m_nMaxWidth + nY] = COLOR_GREEN;
                    }
                }
            }
            nFlagDown = true;
            return true;
        }
        break;
    case 2:
        if (nFlag == true) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (szAryTetris_L_B[i][j] == 1) { //1
                        int nX = i + nMove;
                        int nY = j + 1 + m_GlobalX;
                        m_pszMap[nX * m_nMaxWidth + nY] = COLOR_PURPLE;
                    }
                }
            }
            nFlagDown = true;
            return true;
        }
        break;
    case 3:
        if (nFlag == true) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (szAryTetris_L_B[i][j] == 1) { //1
                        int nX = i + nMove;
                        int nY = j + 1 + m_GlobalX;
                        m_pszMap[nX * m_nMaxWidth + nY] = COLOR_RED;
                    }
                }
            }
            nFlagDown = true;
            return true;
        }
        break;
    case 4:
        if (nFlag == true) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (szAryTetris_L_B[i][j] == 1) { //1
                        int nX = i + nMove;
                        int nY = j + 1 + m_GlobalX;
                        m_pszMap[nX * m_nMaxWidth + nY] = COLOR_YELLOW;
                    }
                }
            }
            nFlagDown = true;
            return true;
        }
        break;
    }

    return false;
}

//T型方块
bool CTetris::DrawTetris_T(int nMove) {
    char ch = '0';

    nFlagDown = false;

    int nTemp = nMove + 1;

    //控制下落
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (szAryTetris_T[i][j] == 1) {
                funcDrawSquare(j + 1 + m_GlobalX, nMove + i);
            }          
        }
    }

    bool nFlag = false;

    //判断是否有障碍
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (szAryTetris_T[i][j] == 1) { //1
                int nX = i + nTemp;
                int nY = j + 1 + m_GlobalX;
                char szFlag = m_pszMap[nX * m_nMaxWidth + nY];

                if (szFlag == 1 || szFlag == 2 || szFlag == 3 ||
                    szFlag == 4 || szFlag == 5) { //~1
                    nFlag = true;
                    break;
                }
            }
        }
    }

    switch (m_nColorType) {
    case 1:
        if (nFlag == true) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (szAryTetris_T[i][j] == 1) { //1
                        int nX = i + nMove;
                        int nY = j + 1 + m_GlobalX;
                        m_pszMap[nX * m_nMaxWidth + nY] = COLOR_GREEN;
                    }
                }
            }
            nFlagDown = true;
            return true;
        }
        break;
    case 2:
        if (nFlag == true) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (szAryTetris_T[i][j] == 1) { //1
                        int nX = i + nMove;
                        int nY = j + 1 + m_GlobalX;
                        m_pszMap[nX * m_nMaxWidth + nY] = COLOR_PURPLE;
                    }
                }
            }
            nFlagDown = true;
            return true;
        }
        break;
    case 3:
        if (nFlag == true) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (szAryTetris_T[i][j] == 1) { //1
                        int nX = i + nMove;
                        int nY = j + 1 + m_GlobalX;
                        m_pszMap[nX * m_nMaxWidth + nY] = COLOR_RED;
                    }
                }
            }
            nFlagDown = true;
            return true;
        }
        break;
    case 4:
        if (nFlag == true) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (szAryTetris_T[i][j] == 1) { //1
                        int nX = i + nMove;
                        int nY = j + 1 + m_GlobalX;
                        m_pszMap[nX * m_nMaxWidth + nY] = COLOR_YELLOW;
                    }
                }
            }
            nFlagDown = true;
            return true;
        }
        break;
    }

    return false;
}

//Z型方块
bool CTetris::DrawTetris_Z_A(int nMove) {
    char ch = '0';

    nFlagDown = false;

    int nTemp = nMove + 1;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (szAryTetris_Z_A[i][j] == 1) {
                funcDrawSquare(j + 1 + m_GlobalX, nMove + i);
            }        
        }
    }

    bool nFlag = false;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (szAryTetris_Z_A[i][j] == 1) { //1
                int nX = i + nTemp;
                int nY = j + 1 + m_GlobalX;
                char szFlag = m_pszMap[nX * m_nMaxWidth + nY];

                if (szFlag == 1 || szFlag == 2 || szFlag == 3 ||
                    szFlag == 4 || szFlag == 5) { //~1
                    nFlag = true;
                    break;
                }
            }
        }
    }

    switch (m_nColorType) {
    case 1:
        if (nFlag == true) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (szAryTetris_Z_A[i][j] == 1) { //1
                        int nX = i + nMove;
                        int nY = j + 1 + m_GlobalX;
                        m_pszMap[nX * m_nMaxWidth + nY] = COLOR_GREEN;
                    }
                }
            }
            nFlagDown = true;
            return true;
        }
        break;
    case 2:
        if (nFlag == true) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (szAryTetris_Z_A[i][j] == 1) { //1
                        int nX = i + nMove;
                        int nY = j + 1 + m_GlobalX;
                        m_pszMap[nX * m_nMaxWidth + nY] = COLOR_PURPLE;
                    }
                }
            }
            nFlagDown = true;
            return true;
        }
        break;
    case 3:
        if (nFlag == true) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (szAryTetris_Z_A[i][j] == 1) { //1
                        int nX = i + nMove;
                        int nY = j + 1 + m_GlobalX;
                        m_pszMap[nX * m_nMaxWidth + nY] = COLOR_RED;
                    }
                }
            }
            nFlagDown = true;
            return true;
        }
        break;
    case 4:
        if (nFlag == true) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (szAryTetris_Z_A[i][j] == 1) { //1
                        int nX = i + nMove;
                        int nY = j + 1 + m_GlobalX;
                        m_pszMap[nX * m_nMaxWidth + nY] = COLOR_YELLOW;
                    }
                }
            }
            nFlagDown = true;
            return true;
        }
        break;
    }

    return false;
}

bool CTetris::DrawTetris_Z_B(int nMove) {
    char ch = '0';

    nFlagDown = false;

    int nTemp = nMove + 1;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (szAryTetris_Z_B[i][j] == 1) {
                funcDrawSquare(j + 1 + m_GlobalX, nMove + i);
            }         
        }
    }

    bool nFlag = false;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (szAryTetris_Z_B[i][j] == 1) { //1
                int nX = i + nTemp;
                int nY = j + 1 + m_GlobalX;
                char szFlag = m_pszMap[nX * m_nMaxWidth + nY];

                if (szFlag == 1 || szFlag == 2 || szFlag == 3 ||
                    szFlag == 4 || szFlag == 5) { //~1
                    nFlag = true;
                    break;
                }
            }
        }
    }

    switch (m_nColorType) {
    case 1:
        if (nFlag == true) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (szAryTetris_Z_B[i][j] == 1) { //1
                        int nX = i + nMove;
                        int nY = j + 1 + m_GlobalX;
                        m_pszMap[nX * m_nMaxWidth + nY] = COLOR_GREEN;
                    }
                }
            }
            nFlagDown = true;
            return true;
        }
        break;
    case 2:
        if (nFlag == true) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (szAryTetris_Z_B[i][j] == 1) { //1
                        int nX = i + nMove;
                        int nY = j + 1 + m_GlobalX;
                        m_pszMap[nX * m_nMaxWidth + nY] = COLOR_PURPLE;
                    }
                }
            }
            nFlagDown = true;
            return true;
        }
        break;
    case 3:
        if (nFlag == true) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (szAryTetris_Z_B[i][j] == 1) { //1
                        int nX = i + nMove;
                        int nY = j + 1 + m_GlobalX;
                        m_pszMap[nX * m_nMaxWidth + nY] = COLOR_RED;
                    }
                }
            }
            nFlagDown = true;
            return true;
        }
        break;
    case 4:
        if (nFlag == true) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (szAryTetris_Z_B[i][j] == 1) { //1
                        int nX = i + nMove;
                        int nY = j + 1 + m_GlobalX;
                        m_pszMap[nX * m_nMaxWidth + nY] = COLOR_YELLOW;
                    }
                }
            }
            nFlagDown = true;
            return true;
        }
        break;
    }

    return false;
}

//田型方块
bool CTetris::DrawTetris_Square(int nMove) {
    char ch = '0';

    nFlagDown = false;

    int nTemp = nMove + 1;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (szAryTetris_Square[i][j] == 1) {
                funcDrawSquare(j + 1 + m_GlobalX, nMove + i);
            }          
        }
    }

    bool nFlag = false;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (szAryTetris_Square[i][j] == 1) { //1
                int nX = i + nTemp;
                int nY = j + 1 + m_GlobalX;
                char szFlag = m_pszMap[nX * m_nMaxWidth + nY];

                if (szFlag == 1 || szFlag == 2 || szFlag == 3 ||
                    szFlag == 4 || szFlag == 5) { //~1
                    nFlag = true;
                    break;
                }
            }
        }
    }

    switch (m_nColorType) {
    case 1:
        if (nFlag == true) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (szAryTetris_Square[i][j] == 1) { //1
                        int nX = i + nMove;
                        int nY = j + 1 + m_GlobalX;
                        m_pszMap[nX * m_nMaxWidth + nY] = COLOR_GREEN;
                    }
                }
            }
            nFlagDown = true;
            return true;
        }
        break;
    case 2:
        if (nFlag == true) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (szAryTetris_Square[i][j] == 1) { //1
                        int nX = i + nMove;
                        int nY = j + 1 + m_GlobalX;
                        m_pszMap[nX * m_nMaxWidth + nY] = COLOR_PURPLE;
                    }
                }
            }
            nFlagDown = true;
            return true;
        }
        break;
    case 3:
        if (nFlag == true) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (szAryTetris_Square[i][j] == 1) { //1
                        int nX = i + nMove;
                        int nY = j + 1 + m_GlobalX;
                        m_pszMap[nX * m_nMaxWidth + nY] = COLOR_RED;
                    }
                }
            }
            nFlagDown = true;
            return true;
        }
        break;
    case 4:
        if (nFlag == true) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (szAryTetris_Square[i][j] == 1) { //1
                        int nX = i + nMove;
                        int nY = j + 1 + m_GlobalX;
                        m_pszMap[nX * m_nMaxWidth + nY] = COLOR_YELLOW;
                    }
                }
            }
            nFlagDown = true;
            return true;
        }
        break;
    }

    return false;
}

//长条方块
bool CTetris::DrawTetris_I(int nMove) {
    char ch = '0';

    nFlagDown = false;

    int nTemp = nMove + 1;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (szAryTetris_I[i][j] == 1) {
                funcDrawSquare(j + 1 + m_GlobalX, nMove + i);
            }          
        }
    }

    bool nFlag = false;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (szAryTetris_I[i][j] == 1) { //1
                int nX = i + nTemp;
                int nY = j + 1 + m_GlobalX;
                char szFlag = m_pszMap[nX * m_nMaxWidth + nY];

                if (szFlag == 1 || szFlag == 2 || szFlag == 3 || 
                    szFlag == 4 || szFlag == 5) { //~1
                    nFlag = true;
                    break;
                }
            }
        }
    }

    switch (m_nColorType) {
    case 1:
        if (nFlag == true) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (szAryTetris_I[i][j] == 1) { //1
                        int nX = i + nMove;
                        int nY = j + 1 + m_GlobalX;
                        m_pszMap[nX * m_nMaxWidth + nY] = COLOR_GREEN;
                    }
                }
            }
            nFlagDown = true;
            return true;
        }
        break;
    case 2:
        if (nFlag == true) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (szAryTetris_I[i][j] == 1) { //1
                        int nX = i + nMove;
                        int nY = j + 1 + m_GlobalX;
                        m_pszMap[nX * m_nMaxWidth + nY] = COLOR_PURPLE;
                    }
                }
            }
            nFlagDown = true;
            return true;
        }
        break;
    case 3:
        if (nFlag == true) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (szAryTetris_I[i][j] == 1) { //1
                        int nX = i + nMove;
                        int nY = j + 1 + m_GlobalX;
                        m_pszMap[nX * m_nMaxWidth + nY] = COLOR_RED;
                    }
                }
            }
            nFlagDown = true;
            return true;
        }
        break;
    case 4:
        if (nFlag == true) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (szAryTetris_I[i][j] == 1) { //1
                        int nX = i + nMove;
                        int nY = j + 1 + m_GlobalX;
                        m_pszMap[nX * m_nMaxWidth + nY] = COLOR_YELLOW;
                    }
                }
            }
            nFlagDown = true;
            return true;
        }
        break;
    }

    return false;
}