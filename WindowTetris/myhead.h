#include <iostream>
#include <string.h>
#include "const.h"

using namespace std;

class CTetris {
public:
    /*-----1.��ʼ����������-----*/
    //���캯��
    CTetris();

    //�������캯��
    CTetris(const CTetris& dup);

    //��������
    ~CTetris();

    //���ƽ���
    void DrawUI();

    //��ӡ����
    void PrintUI();

    //�������
    bool DrawTetris_L_A(int nMove);
    bool DrawTetris_L_B(int nMove);
    bool DrawTetris_Z_A(int nMove);
    bool DrawTetris_Z_B(int nMove);
    bool DrawTetris_T(int nMove);
    bool DrawTetris_I(int nMove);
    bool DrawTetris_Square(int nMove);

    /*-----2.���ܲ���-----*/

    //������ַ���
    bool SrandTetris(int nMove, int m_type);

    //��ת����
    void RotateTetris(char *block, int nMove);

    //�ж���Ϸ�Ƿ����
    bool GameOver();

    //����
    void DelLine(char* Map);


    //==========================
    //==========SDK����==========
    //==========================

    //����ͼ��
    void funcLoadIcon();

    //��ʾ����
    void funcDrawSquare(int x, int y);

    void funcDrawBlank(int x, int y);

    void funcDrawWall(int x, int y);

    void funcDrawGreen(int x, int y);
    void funcDrawPurple(int x, int y);
    void funcDrawRed(int x, int y);
    void funcDrawYellow(int x, int y);

    void funcDrawScore();

    void funcDrawNextSquare();

    //�������
    void funcSrandCall();

    //�ж��Ƿ�̶�
    bool funcFix();

    //���ƶ�
    bool funcLeftMove(char* TetrisTp, int nMove);

    //���ƶ�
    bool funcRightMove(char* TetrisTp, int nMove);

    //�����ƶ���ʾ
    void funcPrintLeftAndRight();

public:
    char* m_pszStart;
    int m_nMaxWidth = 12;    //Χǽ�����
    int m_nMaxHeight = 21;   //Χǽ��󳤶�
    char* m_pszMap;     //���Ƶ�ͼ��
    int m_type;         //��������
    int m_GlobalX = 0;  //ȫ��Xƫ����
    int m_nScore = 0;   //����
    int m_nRandProc;    //�����
    int m_nRandNext;    //�����һ�������

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