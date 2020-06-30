#include <windows.h>
#include <tchar.h>
#include <string>
#include <time.h>
#include <cstdlib>
#include "resource.h"
#include "myhead.h"

#pragma comment(lib, "WINMM.LIB")
#pragma warning( disable : 4996)

CTetris CTest;
unsigned long int ulDownCnt = 0;
bool g_bFlag = false;

LRESULT CALLBACK funcMyWindowProc(HWND   hWnd,
                                  UINT   uMsg,
                                  WPARAM wParam,
                                  LPARAM lParam) {

    int nRet = 1;
    int nKey = 0;

    switch (uMsg) {
        //WM_CREATE内主要做一些初始化的事情
        case WM_CREATE: {
            /*窗口初始化*/
            HDC hDC = GetDC(hWnd);
            LPCREATESTRUCT lpCs = (LPCREATESTRUCT)lParam;
            CTest.hWnd = hWnd;
            CTest.uMsg = uMsg;
            CTest.wParam = wParam;
            CTest.lParam = lParam;
            CTest.lpCs = lpCs;
            CTest.hDC = hDC;

            CTest.funcLoadIcon();

            SetTimer(hWnd, 1, 500, nullptr);
        }
        break;
    
        case WM_TIMER: {
            //OutputDebugString("WM_TIMER\r\n");
            //InvalidateRect(hWnd, NULL, false);
            //CTest.PrintUI();

            /*if (CTest.SrandTetris(CTest.nCnt, CTest.m_nRandNext)) {
                return 1;
            }*/

            CTest.funcSrandCall();

            //if (ulDownCnt == 10)

            if (CTest.GameOver()) {
                SetTimer(hWnd, 1, 99999999, nullptr);
                MessageBox(NULL, "游戏结束！", "提示", MB_OK);
                exit(0);
            }
            
            //ulDownCnt++;
            //CTest.nCnt++;
            //ValidateRect(hWnd, NULL);
            //UpdateWindow(hWnd);
        }
        break;

        case WM_DESTROY: {
            PostMessage(hWnd, WM_QUIT, 0, 0);
        }
        break;

        case WM_KEYDOWN: {
            nKey = wParam;
            if (nKey == VK_UP) {
                switch (CTest.m_nRandProc) {
                case 1:
                    CTest.RotateTetris((char*)szAryTetris_L_A, CTest.nCnt);
                    break;
                case 2:
                    CTest.RotateTetris((char*)szAryTetris_L_B, CTest.nCnt);
                    break;
                case 3:
                    CTest.RotateTetris((char*)szAryTetris_Z_A, CTest.nCnt);
                    break;
                case 4:
                    CTest.RotateTetris((char*)szAryTetris_Z_B, CTest.nCnt);
                    break;
                case 5:
                    CTest.RotateTetris((char*)szAryTetris_T, CTest.nCnt);
                    break;
                case 6:
                    CTest.RotateTetris((char*)szAryTetris_I, CTest.nCnt);
                    break;
                case 7:
                    break;
                }
                CTest.funcPrintLeftAndRight();
            }
            else if (nKey == VK_DOWN) {
                CTest.funcSrandCall();
            }
            else if (nKey == VK_LEFT) {
                bool bRetf = true;
                switch (CTest.m_nRandProc) {
                case 1:
                    bRetf = CTest.funcLeftMove((char*)szAryTetris_L_A, CTest.nCnt);
                    break;
                case 2:
                    bRetf = CTest.funcLeftMove((char*)szAryTetris_L_B, CTest.nCnt);
                    break;
                case 3:
                    bRetf = CTest.funcLeftMove((char*)szAryTetris_Z_A, CTest.nCnt);
                    break;
                case 4:
                    bRetf = CTest.funcLeftMove((char*)szAryTetris_Z_B, CTest.nCnt);
                    break;
                case 5:
                    bRetf = CTest.funcLeftMove((char*)szAryTetris_T, CTest.nCnt);
                    break;
                case 6:
                    bRetf = CTest.funcLeftMove((char*)szAryTetris_I, CTest.nCnt);
                    break;
                case 7:
                    bRetf = CTest.funcLeftMove((char*)szAryTetris_Square, CTest.nCnt);
                    break;
                }

                if (bRetf) {
                    CTest.funcPrintLeftAndRight();
                }
            }
            else if (nKey == VK_RIGHT) {
                bool bRetf = true;
                switch (CTest.m_nRandProc) {
                case 1:
                    bRetf = CTest.funcRightMove((char*)szAryTetris_L_A, CTest.nCnt);
                    break;
                case 2:
                    bRetf = CTest.funcRightMove((char*)szAryTetris_L_B, CTest.nCnt);
                    break;
                case 3:
                    bRetf = CTest.funcRightMove((char*)szAryTetris_Z_A, CTest.nCnt);
                    break;
                case 4:
                    bRetf = CTest.funcRightMove((char*)szAryTetris_Z_B, CTest.nCnt);
                    break;
                case 5:
                    bRetf = CTest.funcRightMove((char*)szAryTetris_T, CTest.nCnt);
                    break;
                case 6:
                    bRetf = CTest.funcRightMove((char*)szAryTetris_I, CTest.nCnt);
                    break;
                case 7:
                    bRetf = CTest.funcRightMove((char*)szAryTetris_Square, CTest.nCnt);
                    break;
                }

                if (bRetf) {
                    CTest.funcPrintLeftAndRight();
                }
            }
            else if (nKey == VK_SPACE) {
                ShowWindow(hWnd, SW_MINIMIZE);
                Sleep(300);
                ShowWindow(hWnd, SW_SHOWNORMAL);
            }
        }

        break;

        case WM_CLOSE: {
            int nFlag = MessageBox(hWnd, "是否退出？", "提示", MB_OKCANCEL);
            if (nFlag == IDOK) {
                DestroyWindow(hWnd);
            }
        }
        break;

        case WM_PAINT: {
            /*if (funcDrawSquare(hWnd) == false) {
                return 0;
            }*/

            for (int i = 0; i < CTest.m_nMaxHeight; i++) {
                for (int j = 0; j < CTest.m_nMaxWidth; j++) {
                    if (CTest.m_pszMap[i * CTest.m_nMaxWidth + j] == 1) {
                        CTest.funcDrawWall(j, i);
                    }
                }
            }

            CTest.funcDrawNextSquare();
            CTest.funcDrawScore();
        }

        default:
            nRet = DefWindowProc(hWnd, uMsg, wParam, lParam);
        break;
    }
    
    return nRet;
}

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR     lpCmdLine,
                   int       nCmdShow) {

    MessageBox(NULL, "游戏即将开始！", "提示", MB_OK);
    
    PlaySound(TEXT("sounds\\tetris_bgm.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    WNDCLASSEX win_tagTest = { 0 };
    win_tagTest.cbSize = sizeof(WNDCLASSEX);
    win_tagTest.lpszClassName = "TetrisWin32";
    win_tagTest.lpfnWndProc = funcMyWindowProc;
    win_tagTest.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);

    ATOM atom = RegisterClassEx(&win_tagTest);

    if (atom == 0) {
        return 0;
    }

    HWND hWnd = CreateWindow(
                    "TetrisWin32",
                    "Tetris（作者：新化思源实验学校 1802班 陈为）",
                    WS_OVERLAPPED | WS_SYSMENU | WS_MINIMIZEBOX,
                    800,
                    100,
                    620,
                    720,
                    NULL,
                    NULL,
                    hInstance,
                    NULL);

    if (hWnd == 0) {
        return 0;
    }

    //ShowWindow(hWnd, SW_SHOWNORMAL);
    ShowWindow(hWnd, SW_MINIMIZE);
    ShowWindow(hWnd, SW_SHOWNORMAL);
    UpdateWindow(hWnd);

    MSG msg = { 0 };


    while (1) {
        BOOL bRet = GetMessage(&msg, NULL, 0, 0);
        if (!bRet) {
            break;
        }

        //翻译消息，处理虚拟键信息
        TranslateMessage(&msg);

        //派发消息
        DispatchMessage(&msg);

    }

    return 0;
}