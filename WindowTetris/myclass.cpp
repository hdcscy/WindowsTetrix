#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "myhead.h"
#include <conio.h>
#include "const.h"
#include "resource.h"

#pragma warning( disable : 4996)

#define ICON_SIZE 32
#define BODER_DISTANCE 0
#define STR_SCORE 32

HICON g_tetrisSquareIcon = nullptr;
HICON g_blankIcon = nullptr;

HICON g_redIcon = nullptr;
HICON g_greenIcon = nullptr;
HICON g_purpleIcon = nullptr;
HICON g_yellowIcon = nullptr;

using namespace std;

//自定义构造函数
CTetris::CTetris()
{   
    srand((unsigned int)time(NULL));
    nFlagDown = false;
    bColorFlag = true;
    m_nRandNext = rand() % 7 + 1;
    m_nRandProc = m_nRandNext;
    m_GlobalX = 4;
    bNext = true;
    nCnt = 0;
    DrawUI();
}

//拷贝构造函数
CTetris::CTetris(const CTetris& dup) {

}

//析构函数
CTetris::~CTetris() {
    //释放资源
    delete(m_pszMap);
    ReleaseDC(hWnd, hDC);
    cout << "Game models will close." << endl;
}

//随机调用
void CTetris::funcSrandCall() {
    DelLine(m_pszMap);

    if (bNext) {
        m_nRandNext = rand() % 7 + 1;
        funcDrawNextSquare();
        bNext = false;
    }

    if (funcFix()) {
        m_nRandProc = m_nRandNext;
    }

    bFlag = false;

    PrintUI();

    if (SrandTetris(nCnt, m_nRandProc)) {
        return;
    }

    nCnt++;
}

//左右显示
void CTetris::funcPrintLeftAndRight() {
    PrintUI();
    SrandTetris(nCnt, m_nRandProc);
}

//判断是否固定
bool CTetris::funcFix() {
    if (nFlagDown) {
        nCnt = 0;
        m_GlobalX = 3;
        bColorFlag = true;
        bNext = true;
        return true;
    }
    return false;
}

//绘制界面
void CTetris::DrawUI() {
    //绘制围墙，0和1标记
    m_pszMap = new char[m_nMaxWidth * m_nMaxHeight];

    for (int i = 0; i < m_nMaxHeight; i++) {
        for (int j = 0; j < m_nMaxWidth; j++) {
            if (j == 0 || j == m_nMaxWidth - 1 || i == m_nMaxHeight - 1) {
                m_pszMap[i * m_nMaxWidth + j] = 1;
            }
            else {
                m_pszMap[i * m_nMaxWidth + j] = 0;
            }
        }
    }
}

//SDK图标加载
void CTetris::funcLoadIcon() {
    //加载图标文件
    g_tetrisSquareIcon = LoadIcon(lpCs->hInstance,
        MAKEINTRESOURCE(IDI_TETRIS));

    g_blankIcon = LoadIcon(lpCs->hInstance,
        MAKEINTRESOURCE(IDI_BLANK));

    g_greenIcon = LoadIcon(lpCs->hInstance,
        MAKEINTRESOURCE(IDI_GREEN));

    g_purpleIcon = LoadIcon(lpCs->hInstance,
        MAKEINTRESOURCE(IDI_PURPLE));

    g_redIcon = LoadIcon(lpCs->hInstance,
        MAKEINTRESOURCE(IDI_RED));

    g_yellowIcon = LoadIcon(lpCs->hInstance,
        MAKEINTRESOURCE(IDI_YELLOW));

    bSdkloadIconFlag = true;
}

//SDK绘制方块
void CTetris::funcDrawSquare(int x, int y) {

    if (hDC == nullptr) {
        return;
    }

    if (bColorFlag) {
        m_nColorType = rand() % 4 + 1;
    }
  
    switch (m_nColorType) {
    case 1:
        DrawIconEx(hDC, x * ICON_SIZE + BODER_DISTANCE, y * ICON_SIZE, g_greenIcon, ICON_SIZE, ICON_SIZE, 0, NULL, DI_NORMAL);
        break;
    case 2:
        DrawIconEx(hDC, x * ICON_SIZE + BODER_DISTANCE, y * ICON_SIZE, g_purpleIcon, ICON_SIZE, ICON_SIZE, 0, NULL, DI_NORMAL);
        break;
    case 3:
        DrawIconEx(hDC, x * ICON_SIZE + BODER_DISTANCE, y * ICON_SIZE, g_redIcon, ICON_SIZE, ICON_SIZE, 0, NULL, DI_NORMAL);
        break;
    case 4:
        DrawIconEx(hDC, x * ICON_SIZE + BODER_DISTANCE, y * ICON_SIZE, g_yellowIcon, ICON_SIZE, ICON_SIZE, 0, NULL, DI_NORMAL);
        break;
    }

    bColorFlag = false;

    return;
}

void CTetris::funcDrawBlank(int x, int y) {

    if (hDC == nullptr) {
        return;
    }

    DrawIconEx(hDC, x * ICON_SIZE + BODER_DISTANCE, y * ICON_SIZE, g_blankIcon, ICON_SIZE, ICON_SIZE, 0, NULL, DI_NORMAL);

    return;
}

void CTetris::funcDrawWall(int x, int y) {
    if (hDC == nullptr) {
        return;
    }

    DrawIconEx(hDC, x * ICON_SIZE + BODER_DISTANCE, y * ICON_SIZE, g_tetrisSquareIcon, ICON_SIZE, ICON_SIZE, 0, NULL, DI_NORMAL);

    return;
}

void CTetris::funcDrawGreen(int x, int y) {
    if (hDC == nullptr) {
        return;
    }
    DrawIconEx(hDC, x * ICON_SIZE + BODER_DISTANCE, y * ICON_SIZE, g_greenIcon, ICON_SIZE, ICON_SIZE, 0, NULL, DI_NORMAL);
    return;
}

void CTetris::funcDrawPurple(int x, int y) {
    if (hDC == nullptr) {
        return;
    }
    DrawIconEx(hDC, x * ICON_SIZE + BODER_DISTANCE, y * ICON_SIZE, g_purpleIcon, ICON_SIZE, ICON_SIZE, 0, NULL, DI_NORMAL);
    return;
}

void CTetris::funcDrawRed(int x, int y) {
    if (hDC == nullptr) {
        return;
    }
    DrawIconEx(hDC, x * ICON_SIZE + BODER_DISTANCE, y * ICON_SIZE, g_redIcon, ICON_SIZE, ICON_SIZE, 0, NULL, DI_NORMAL);
    return;
}

void CTetris::funcDrawYellow(int x, int y) {
    if (hDC == nullptr) {
        return;
    }
    DrawIconEx(hDC, x * ICON_SIZE + BODER_DISTANCE, y * ICON_SIZE, g_yellowIcon, ICON_SIZE, ICON_SIZE, 0, NULL, DI_NORMAL);
    return;
}

void CTetris::funcDrawScore() {
    if (hDC == nullptr) {
        return;
    }

    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 5; j++) {
            if (j == 0 || j == 5 - 1 || i == 0 || i == 3 || i == 11 - 1 || i == 17 - 1) {
                funcDrawWall(j + 13, i + 2);
            }
        }
    }

    RECT rect = { 50, 50, 200, 200 };

    char* szTemp = new char[STR_SCORE];
    char* szTemp2 = new char[STR_SCORE];
    char* szTemp3 = new char[STR_SCORE];
    char* szTemp4 = new char[STR_SCORE];
    char* szTemp5 = new char[STR_SCORE];
    char* szTemp6 = new char[STR_SCORE];
    char* szTemp7 = new char[STR_SCORE];
    char* szTemp8 = new char[STR_SCORE];
    char* szTemp9 = new char[STR_SCORE];

    memset(szTemp, 0, STR_SCORE);
    memset(szTemp2, 0, STR_SCORE);
    memset(szTemp3, 0, STR_SCORE);
    memset(szTemp4, 0, STR_SCORE);
    memset(szTemp5, 0, STR_SCORE);
    memset(szTemp6, 0, STR_SCORE);
    memset(szTemp7, 0, STR_SCORE);
    memset(szTemp8, 0, STR_SCORE);
    memset(szTemp9, 0, STR_SCORE);

    itoa(m_nScore, szTemp, 10);
    strcpy(szTemp2, "SCORE");
    strcpy(szTemp3, "NEXT TETRIS");
    //strcpy(szTemp4, "Original type");
    strcpy(szTemp4, "ORIGINAL");
    strcpy(szTemp5, "INSTRUCT");
    strcpy(szTemp6, "SHAPE:   ↑");
    strcpy(szTemp7, "DROP:    ↓");
    strcpy(szTemp8, "LEFT:     ←");
    strcpy(szTemp9, "RIGHT:   →");


    //strcat(szTemp2, szTemp);

    SetTextColor(hDC, RGB(80, 183, 0));
    SetBkColor(hDC, RGB(0, 0, 0));


    TextOut(hDC, 474, 108, szTemp2, strlen(szTemp2));
    TextOut(hDC, 474, 126, szTemp, strlen(szTemp));
    TextOut(hDC, 453, 204, szTemp3, strlen(szTemp3));
    TextOut(hDC, 462, 224, szTemp4, strlen(szTemp4));
    TextOut(hDC, 462, 433, szTemp5, strlen(szTemp5));
    TextOut(hDC, 462, 470, szTemp6, strlen(szTemp6));
    TextOut(hDC, 462, 490, szTemp7, strlen(szTemp7));
    TextOut(hDC, 462, 510, szTemp8, strlen(szTemp8));
    TextOut(hDC, 462, 530, szTemp9, strlen(szTemp9));

    if (szTemp != nullptr) {
        delete[] szTemp;
        szTemp = nullptr;
    }

    if (szTemp2 != nullptr) {
        delete[] szTemp2;
        szTemp2 = nullptr;
    }

    if (szTemp3 != nullptr) {
        delete[] szTemp3;
        szTemp3 = nullptr;
    }

    if (szTemp4 != nullptr) {
        delete[] szTemp4;
        szTemp4 = nullptr;
    }

    if (szTemp5 != nullptr) {
        delete[] szTemp5;
        szTemp5 = nullptr;
    }

    if (szTemp6 != nullptr) {
        delete[] szTemp6;
        szTemp6 = nullptr;
    }

    if (szTemp7 != nullptr) {
        delete[] szTemp7;
        szTemp7 = nullptr;
    }

    if (szTemp8 != nullptr) {
        delete[] szTemp8;
        szTemp8 = nullptr;
    }

    if (szTemp9 != nullptr) {
        delete[] szTemp9;
        szTemp9 = nullptr;
    }
}

//显示下一个方块
void CTetris::funcDrawNextSquare() {
    char *mapsNest = new char[4 * 4] { 0 };
    memcpy(mapsNest, arys2[m_nRandNext - 1], 4 * 4);
    //memcpy(mapsNest, arys2[6], 4 * 4);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            DrawIconEx(hDC, (j + 23.2) * 20, (i + 13) * 20, g_blankIcon, 20, 20, 0, NULL, DI_NORMAL);
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            switch (m_nRandNext) {
            //switch (7) {
                //szAryTetris_L_A
            case 1:
                if (mapsNest[i * 4 + j] == 1) {
                    DrawIconEx(hDC, (j + 23.2) * 20, (i + 13) * 20, g_tetrisSquareIcon, 20, 20, 0, NULL, DI_NORMAL);
                }
                break;
                
                //szAryTetris_L_B
            case 2:
                if (mapsNest[i * 4 + j] == 1) {
                    DrawIconEx(hDC, (j + 23.2) * 20, (i + 13) * 20, g_tetrisSquareIcon, 20, 20, 0, NULL, DI_NORMAL);
                }
                break;

                //szAryTetris_Z_A
            case 3:
                if (mapsNest[i * 4 + j] == 1) {
                    DrawIconEx(hDC, (j + 23.2) * 20, (i + 13) * 20, g_tetrisSquareIcon, 20, 20, 0, NULL, DI_NORMAL);
                }
                break;

                //szAryTetris_Z_B
            case 4:
                if (mapsNest[i * 4 + j] == 1) {
                    DrawIconEx(hDC, (j + 23.2) * 20, (i + 13) * 20, g_tetrisSquareIcon, 20, 20, 0, NULL, DI_NORMAL);
                }
                break;

                //szAryTetris_T
            case 5:
                if (mapsNest[i * 4 + j] == 1) {
                    DrawIconEx(hDC, (j + 23.2) * 20, (i + 13) * 20, g_tetrisSquareIcon, 20, 20, 0, NULL, DI_NORMAL);
                }
                break;

                //szAryTetris_I
            case 6:
                if (mapsNest[i * 4 + j] == 1) {
                    DrawIconEx(hDC, (j + 23.2) * 20, (i + 13) * 20, g_tetrisSquareIcon, 20, 20, 0, NULL, DI_NORMAL);
                }
                break;

                //szAryTetris_Square
            case 7:
                if (mapsNest[i * 4 + j] == 1) {
                    DrawIconEx(hDC, (j + 23.77) * 20, (i + 13) * 20, g_tetrisSquareIcon, 20, 20, 0, NULL, DI_NORMAL);
                }
                break;
            }
        }
    }

    if (mapsNest != nullptr) {
        delete[] mapsNest;
        mapsNest = nullptr;
    }
}

//显示函数
void CTetris::PrintUI() {
    //围墙和方块显示
    for (int i = 0; i < m_nMaxHeight; i++) {
        for (int j = 0; j < m_nMaxWidth; j++) {
            if (m_pszMap[i * m_nMaxWidth + j] == 0) {
                funcDrawBlank(j, i);
            } 
            else if (m_pszMap[i * m_nMaxWidth + j] == COLOR_GREEN) {
                funcDrawGreen(j, i);
            }
            else if (m_pszMap[i * m_nMaxWidth + j] == COLOR_PURPLE) {
                funcDrawPurple(j, i);
            }
            else if (m_pszMap[i * m_nMaxWidth + j] == COLOR_RED) {
                funcDrawRed(j, i);
            }
            else if (m_pszMap[i * m_nMaxWidth + j] == COLOR_YELLOW) {
                funcDrawYellow(j, i);
            }
        }
    }
}

//随机函数
bool CTetris::SrandTetris(int nMove, int m_type) {
    bool bFlag = false;
    switch (m_type) {
    case 1:
        bFlag = DrawTetris_L_A(nMove);
        break;
    case 2:
        bFlag = DrawTetris_L_B(nMove);
        break;
    case 3:
        bFlag = DrawTetris_Z_A(nMove);
        break;
    case 4:
        bFlag = DrawTetris_Z_B(nMove);
        break;
    case 5:
        bFlag = DrawTetris_T(nMove);
        break;
    case 6:
        bFlag = DrawTetris_I(nMove);
        break;
    case 7:
        bFlag = DrawTetris_Square(nMove);
        break;
    }

    return bFlag;
}

//图形旋转
void CTetris::RotateTetris(char *block, int nMove) {
    //地图大小
    int nMapSize = 4;
    char szAryTemp[4][4] = { 0 };

    //临时空间
    char *ary = (char *) new char[16]{ 0 };

    if (ary == NULL) {
        goto EXIT_PROC;
    }

    //左旋转
    for (int i = 0; i < nMapSize; i++) {
        for (int j = 0; j < nMapSize; j++) {
            //顺时针旋转,列跟着行变化
            ary[i * nMapSize + j] = block[j * nMapSize + (nMapSize - 1 - i)];
        }
    }

    //先存放至二维数组
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            szAryTemp[i][j] = ary[i * 4 + j];
        }
    }

    //判断旁边是否可以旋转
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (szAryTemp[i][j] == 1) { //1
                int nX = i + nMove;
                int nY = j + 1 + m_GlobalX;
                char szFlag = m_pszMap[nX * m_nMaxWidth + nY];
                if (szFlag == 1 || szFlag == 2 || szFlag == 3 ||
                    szFlag == 4 || szFlag == 5) {
                    return;
                }
            }
        }
    }
    //赋值给block
    ::memcpy(block, ary, nMapSize * nMapSize);

EXIT_PROC:
    if (ary != NULL)
    {
        delete ary;
    }
    return;
}

//SDK左移动
bool CTetris::funcLeftMove(char* TetrisTp, int nMove) {
    if (funcFix()) {
        return false;
    }

    char szAryTemp[4][4] = { 0 };
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            szAryTemp[i][j] = TetrisTp[i * 4 + j];
        }
    }

    m_GlobalX = m_GlobalX - 1;

    //判断是否碰墙或者方块
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (szAryTemp[i][j] == 1) { //1
                int nX = i + nMove;
                int nY = j + 1 + m_GlobalX;
                char szFlag = m_pszMap[nX * m_nMaxWidth + nY];
                if (szFlag == 1 || szFlag == 2 || szFlag == 3 ||
                    szFlag == 4 || szFlag == 5) {
                    m_GlobalX = m_GlobalX + 1;
                    return false;
                }
            }
        }
    }

    return true;
}

//SDK右移动
bool CTetris::funcRightMove(char* TetrisTp, int nMove) {
    if (funcFix()) {
        return false;
    }

    char szAryTemp[4][4] = { 0 };
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            szAryTemp[i][j] = TetrisTp[i * 4 + j];
        }
    }

    m_GlobalX = m_GlobalX + 1;

    //判断是否碰墙或者方块
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (szAryTemp[i][j] == 1) { //1
                int nX = i + nMove;
                int nY = j + 1 + m_GlobalX;
                char szFlag = m_pszMap[nX * m_nMaxWidth + nY];
                if (szFlag == 1 || szFlag == 2 || szFlag == 3 ||
                    szFlag == 4 || szFlag == 5) {
                    m_GlobalX = m_GlobalX - 1;
                    return false;
                }
            }
        }
    }

    return true;
}

//游戏结束判定
bool CTetris::GameOver() {
    //如果检测到下落计数小于等于0
    if (nCnt == 0) {
        for (int i = 0; i < m_nMaxHeight; i++) {
            for (int j = 0; j < m_nMaxWidth; j++) {
                funcDrawWall(j, i);
            }
        }
        return true;
    }

    return false;
}

//消行
void CTetris::DelLine(char* Map) {
    int nCnt2 = 0;
    char szAryTemp[21][12] = { 0 };
    char szStr[13] = "\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1\x1";
    char szTemp[13] = "";

    //将地图数据从一维数组转换成二维数组
    for (int i = 0; i < m_nMaxHeight; i++) {
        for (int j = 0; j < m_nMaxWidth; j++) {
            szAryTemp[i][j] = Map[i * m_nMaxWidth + j];
        }
    }

    for (int i = 0; i < m_nMaxHeight - 1; i++) {
        for (int j = 0; j < m_nMaxWidth; j++) {
            if (szAryTemp[i][j] >= 1) {
                nCnt2++;
            }
            else {
                nCnt2--;
            }
        }
        if (nCnt2 == 12) {
            for (int k = i; k > 0; k--) {
                ::memcpy((char *)szAryTemp[k], (char *)szAryTemp[k - 1], m_nMaxWidth);
            }
            //消行计数
            m_nScore += 10;
            m_nRandSound = rand() % 8 + 1;
            if (m_nRandSound <= 4) {
                mciOpen.lpstrElementName = TEXT("sounds\\deline1.wav");
                if (mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT, (DWORD)&mciOpen) == 0) {
                    dev[0] = mciOpen.wDeviceID;
                }
                else {
                    mciOpen.wDeviceID = dev[0];
                }
                mciPlay.dwFrom = 0;
                mciSendCommand(mciOpen.wDeviceID, MCI_PLAY, MCI_NOTIFY | MCI_FROM, (DWORD)&mciPlay);
            }
            else {
                mciOpen.lpstrElementName = TEXT("sounds\\deline2.wav");
                if (mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT, (DWORD)&mciOpen) == 0) {
                    dev[1] = mciOpen.wDeviceID;
                }
                else {
                    mciOpen.wDeviceID = dev[1];
                }
                mciPlay.dwFrom = 0;
                mciSendCommand(mciOpen.wDeviceID, MCI_PLAY, MCI_NOTIFY | MCI_FROM, (DWORD)&mciPlay);
            }
            funcDrawScore();
            funcDrawNextSquare();
        }
        nCnt2 = 0;
    }

    ::memcpy(Map, (char *)szAryTemp, m_nMaxHeight * m_nMaxWidth);
}