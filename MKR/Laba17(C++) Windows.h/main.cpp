#include <iostream>
#include <windows.h> // Бібліотека для WinApi


const char g_szClassName[] = "MyWindowsClass"; // Рядкова змінна вікна

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) // Функція обробки повідомлень
{
    switch(msg)
    {
        case WM_CREATE:{
            CreateWindow(TEXT("button"),TEXT("Button"),
                         WS_VISIBLE | WS_CHILD,
                         300,380,120,35,
                         hWnd,(HMENU)1,NULL,NULL
            );
            break;
        }
        case WM_CLOSE:
            DestroyWindow(hWnd);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            return DefWindowProc(hWnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{   // Точка входу у програму
    WNDCLASSEX wc;
    HWND hwnd; // вказівник на вікно програми
    HWND hwndButton; // вказівник на кнопку
    MSG msg; // вказівник на обробку повідомлень отриманих від користувача

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm = LoadIcon(NULL,IDI_APPLICATION);

    if (!RegisterClassEx(&wc)) {
        MessageBox(NULL,"Class not registered", "Error", MB_ICONINFORMATION | MB_OK);
        return 0;
    }

    hwnd = CreateWindowEx(
            WS_EX_CLIENTEDGE,
            g_szClassName,
            "Laba #17",
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            720,480,
            NULL,
            NULL,
            hInstance,
            NULL
            );



    if (hwnd==NULL) {
        MessageBox(NULL,"Window Creation Failed!", "Error.", MB_ICONINFORMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd,SW_SHOWNORMAL);
    UpdateWindow(hwnd);

    while (GetMessage(&msg, NULL,0 ,0)) { // Функція, яка постійно оновлює потік повідомлень
        TranslateMessage(&msg);          // отриманих від користувача у робочому полі вікна
        DispatchMessage(&msg);
    }
    return msg.wParam;
}