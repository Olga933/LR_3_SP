// LR_3_SP.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "LR_3_SP.h"

#define MAX_LOADSTRING 100

#define IDI_Button1    1001
#define IDI_Button2    1002
#define IDI_Button3    1003
#define IDI_Button4    1004
#define IDI_Button5    1005
#define IDI_Button6    1006
#define IDI_Button7    1007
#define IDI_Button8    1008
#define IDI_Button9    1009
#define IDI_Button10   1010
#define IDI_Button11   1011

#define IDI_Static1    1012
#define IDI_Static2    1013
#define IDI_Static3    1014

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

HWND hStatic1;
HWND hStatic2;
HWND hStatic3;

HWND hBut1;
HWND hBut2;
HWND hBut3;
HWND hBut4;
HWND hBut5;
HWND hBut6;
HWND hBut7;
HWND hBut8;
HWND hBut9;
HWND hBut10;
HWND hBut11;

HWND LR_2;
HWND Borland;
HWND C_PI;

int child;
int parent;

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

BOOL CALLBACK change_childs_name(HWND hWnd, LPARAM lParam)
{
    SendMessage(hWnd, WM_SETTEXT, 0, lParam);
    return TRUE;
}

BOOL CALLBACK renumber_child(HWND hWnd, LPARAM lParam)
{
    TCHAR buf[MAX_LOADSTRING] = L"Дочернее";
    TCHAR num[MAX_LOADSTRING];
    _itot_s(child, num, 10);
    _tcscat_s(buf, num);
    SendMessage(hWnd, WM_SETTEXT, NULL, LPARAM(buf));
    child++;
    return TRUE;
}


BOOL CALLBACK renumber(HWND hWnd, LPARAM lParam)
{
    child = 0;
    EnumChildWindows(hWnd, &renumber_child, lParam);
    TCHAR buf[MAX_LOADSTRING] = L"Окно";
    TCHAR num[MAX_LOADSTRING];
    _itot_s(parent, num, 10);
    _tcscat_s(buf, num);
    SendMessage(hWnd, WM_SETTEXT, NULL, LPARAM(buf));
    parent++;
    return TRUE;
}


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LR3SP, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LR3SP));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LR3SP));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LR3SP);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   hStatic1 = CreateWindow(TEXT("STATIC"), TEXT("        LR_2"), WS_VISIBLE | WS_CHILD,
       50, 50, 100, 40, hWnd, (HMENU)IDI_Static1, hInstance, nullptr);
   hStatic2 = CreateWindow(TEXT("STATIC"), TEXT("      Borland"), WS_VISIBLE | WS_CHILD,
       50, 120, 100, 40, hWnd, (HMENU)IDI_Static2, hInstance, nullptr);
   hStatic3 = CreateWindow(TEXT("STATIC"), TEXT("          C#"), WS_VISIBLE | WS_CHILD,
       50, 190, 100, 40, hWnd, (HMENU)IDI_Static3, hInstance, nullptr);

   hBut1 = CreateWindow(TEXT("BUTTON"), TEXT("Спрятать LR_2"), WS_VISIBLE | WS_CHILD,
       170, 50, 130, 40, hWnd, (HMENU)IDI_Button1, hInstance, nullptr);
   hBut2 = CreateWindow(TEXT("BUTTON"), TEXT("Спрятать Borland"), WS_VISIBLE | WS_CHILD,
       170, 120, 130, 40, hWnd, (HMENU)IDI_Button2, hInstance, nullptr);
   hBut3 = CreateWindow(TEXT("BUTTON"), TEXT("Спрятать C#"), WS_VISIBLE | WS_CHILD,
       170, 190, 130, 40, hWnd, (HMENU)IDI_Button3, hInstance, nullptr);
   hBut4 = CreateWindow(TEXT("BUTTON"), TEXT("Активное/неактивное"), WS_VISIBLE | WS_CHILD,
       320, 50, 155, 40, hWnd, (HMENU)IDI_Button4, hInstance, nullptr);
   hBut5 = CreateWindow(TEXT("BUTTON"), TEXT("Активное/неактивное"), WS_VISIBLE | WS_CHILD,
       320, 120, 155, 40, hWnd, (HMENU)IDI_Button5, hInstance, nullptr);
   hBut6 = CreateWindow(TEXT("BUTTON"), TEXT("Активное/неактивное"), WS_VISIBLE | WS_CHILD,
       320, 190, 155, 40, hWnd, (HMENU)IDI_Button6, hInstance, nullptr);
   hBut7 = CreateWindow(TEXT("BUTTON"), TEXT("Закрыть"), WS_VISIBLE | WS_CHILD,
       495, 190, 80, 40, hWnd, (HMENU)IDI_Button7, hInstance, nullptr);
   hBut8 = CreateWindow(TEXT("BUTTON"), TEXT("Нажать кнопку"), WS_VISIBLE | WS_CHILD,
       495, 50, 110, 40, hWnd, (HMENU)IDI_Button8, hInstance, nullptr);
   hBut9 = CreateWindow(TEXT("BUTTON"), TEXT("Меню"), WS_VISIBLE | WS_CHILD,
       625, 50, 75, 40, hWnd, (HMENU)IDI_Button9, hInstance, nullptr);
   hBut10 = CreateWindow(TEXT("BUTTON"), TEXT("Нумерация дочерних окон"), WS_VISIBLE | WS_CHILD,
       720, 50, 190, 40, hWnd, (HMENU)IDI_Button10, hInstance, nullptr);
   hBut11 = CreateWindow(TEXT("BUTTON"), TEXT("Нумерация всех окон"), WS_VISIBLE | WS_CHILD,
       50, 270, 180, 40, hWnd, (HMENU)IDI_Button11, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;

            case IDI_Button1:
            {
                LR_2 = FindWindow(NULL, L"LR_2_SP_1");
                if (IsWindowVisible(LR_2))
                    ShowWindow(LR_2, SW_HIDE);
            }
            break;

            case IDI_Button2:
            {
                Borland = FindWindow(NULL, L"Form1");
                if (IsWindowVisible(Borland))
                    ShowWindow(Borland, SW_HIDE);
            }
            break;

            case IDI_Button3:
            {
                C_PI = FindWindow(NULL, L"Form_PI");
                if (IsWindowVisible(C_PI))
                    ShowWindow(C_PI, SW_HIDE);
            }
            break;

            case IDI_Button4:
            {
                LR_2 = FindWindow(NULL, L"LR_2_SP_1");
                if (IsWindowEnabled(LR_2))
                    EnableWindow(LR_2, false);
                else
                    EnableWindow(LR_2, true);
            }
            break;

            case IDI_Button5:
            {
                Borland = FindWindow(NULL, L"Form1");
                if (IsWindowEnabled(Borland))
                    EnableWindow(Borland, false);
                else
                    EnableWindow(Borland, true);
            }
            break;

            case IDI_Button6:
            {
                C_PI = FindWindow(NULL, L"Form_PI");
                if (IsWindowEnabled(C_PI))
                    EnableWindow(C_PI, false);
                else
                    EnableWindow(C_PI, true);
            }
            break;

            case IDI_Button7:
            {
                C_PI = FindWindow(NULL, L"Form_PI");
                if (C_PI)
                    if (IsWindowEnabled(C_PI))
                        PostMessage(C_PI, WM_QUIT, NULL, NULL);
                    
            }
            break;

            case IDI_Button8:
            {
                LR_2 = FindWindow(NULL, L"LR_2_SP_1");
                HWND hBut = FindWindowEx(LR_2, NULL, L"BUTTON", L"Кнопка 1");
                SendMessage(hBut, WM_LBUTTONDOWN, MK_LBUTTON, MAKELONG(5, 5));
                SendMessage(hBut, WM_LBUTTONUP, MK_LBUTTON, MAKELONG(5, 5));
            }
            break;

            case IDI_Button9:
            {
                LR_2 = FindWindow(NULL, L"LR_2_SP_1");
                if (LR_2)
                    SendMessage(LR_2, WM_COMMAND, IDM_ABOUT, NULL);
            }
            break;

            case IDI_Button10:
            {
                LR_2 = FindWindow(NULL, L"LR_2_SP_1");
                if (LR_2)
                    EnumChildWindows(LR_2, &change_childs_name, LPARAM(L"name was changed"));
            }
            break;

            case IDI_Button11:
            {
                parent = 0;
                EnumWindows(&renumber, NULL);
            }
            break;

            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }


        }
        break;

        case WM_RBUTTONDOWN:
        {
            LR_2 = FindWindow(NULL, L"LR_2_SP_1");
            if (IsWindowVisible(LR_2))
            {
                SendMessage(LR_2, WM_RBUTTONDOWN, MK_RBUTTON, lParam);
                SendMessage(LR_2, WM_RBUTTONUP, MK_RBUTTON, lParam);
            }
        }
        break;

        case WM_LBUTTONDOWN:
        {
            LR_2 = FindWindow(NULL, L"LR_2_SP_1");
            if (LR_2)
            {
                SendMessage(LR_2, WM_LBUTTONDOWN, MK_LBUTTON, lParam);
            }
            
        }
        break;

        case WM_LBUTTONUP:
        {   
            LR_2 = FindWindow(NULL, L"LR_2_SP_1");
            if (LR_2)
            {
                SendMessage(LR_2, WM_LBUTTONUP, MK_LBUTTON, lParam);
            }
        }
        break;

        case WM_MOUSEMOVE:
        {
            LR_2 = FindWindow(NULL, L"LR_2_SP_1");
            if (LR_2)
            {
                WORD x = LOWORD(lParam), y = HIWORD(lParam);
                SendMessage(LR_2, WM_MOUSEMOVE, wParam, MAKELONG(x, y));
            }
          
            /*
            LR_2 = FindWindow(NULL, L"LR_2_SP_1");
            if (LR_2)
            {
                POINT coords;
                coords.x = LOWORD(lParam);
                coords.y = HIWORD(lParam);
                ClientToScreen(hWnd, &coords);
                ScreenToClient(LR_2, &coords);
                SendMessage(LR_2, WM_MOUSEMOVE, wParam, MAKELONG(coords.x, coords.y));
            }*/

        }
        break;


    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
