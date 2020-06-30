#include <iostream>
#include <string.h>
#include "const.h"

using namespace std;

class CTetris {
public:
    /*-----1.初始化和清理部分-----*/
    //构造函数
    CTetris();

    //拷贝构造函数
    CTetris(const CTetris& dup);

    //析构函数
    ~CTetris();

    //绘制界面
    void DrawUI();

    //打印界面
    void PrintUI();

    //方块绘制
    bool DrawTetris_L_A(int nMove);
    bool DrawTetris_L_B(int nMove);
    bool DrawTetris_Z_A(int nMove);
    bool DrawTetris_Z_B(int nMove);
    bool DrawTetris_T(int nMove);
    bool DrawTetris_I(int nMove);
    bool DrawTetris_Square(int nMove);

    /*-----2.功能部分-----*/

    //随机出现方块
    bool SrandTetris(int nMove, int m_type);

    //旋转方块
    void RotateTetris(char *block, int nMove);

    //判定游戏是否结束
    bool GameOver();

    //消行
    void DelLine(char* Map);


    //==========================
    //==========SDK部分==========
    //==========================

    //加载图标
    void funcLoadIcon();

    //显示方块
    void funcDrawSquare(int x, int y);

    void funcDrawBlank(int x, int y);

    void funcDrawWall(int x, int y);

    void funcDrawGreen(int x, int y);
    void funcDrawPurple(int x, int y);
    void funcDrawRed(int x, int y);
    void funcDrawYellow(int x, int y);

    void funcDrawScore();

    void funcDrawNextSquare();

    //随机调用
    void funcSrandCall();

    //判断是否固定
    bool funcFix();

    //左移动
    bool funcLeftMove(char* TetrisTp, int nMove);

    //右移动
    bool funcRightMove(char* TetrisTp, int nMove);

    //左右移动显示
    void funcPrintLeftAndRight();

public:
    char* m_pszStart;
    int m_nMaxWidth = 12;    //围墙最大宽度
    int m_nMaxHeight = 21;   //围墙最大长度
    char* m_pszMap;     //绘制的图形
    int m_type;         //方块类型
    int m_GlobalX = 0;  //全局X偏移量
    int m_nScore = 0;   //计数
    int m_nRandProc;    //随机数
    int m_nRandNext;    //存放下一个随机数

    bool bFlag;
    char *mapsNest = new char[4 * 4] { 0 };

    bool bSdkloadIconFlag;

public:
    HWND hWnd;
    UINT uMsg;
    WPARAM wParam;
    LPARAM lParam;
    LPCREATESTRUCT lpCs;
    HDC hDC;

    MCIDEVICEID dev[20];
    MCI_OPEN_PARMS mciOpen;
    MCI_PLAY_PARMS mciPlay;

    int nCnt;
    bool nFlagDown;
    int m_nRandSound;
    int m_nColorType;
    bool bColorFlag;
    bool bNext;

    enum emColor {
        COLOR_GREEN = 2,
        COLOR_PURPLE,
        COLOR_RED,
        COLOR_YELLOW
    };
};