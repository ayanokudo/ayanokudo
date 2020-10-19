//=============================================================================
//
// ���C������ [main.cpp]
// Author : AYANO KUDO
//
//=============================================================================
#include "main.h"
#include "renderer.h"
#include "scene.h"
#include "scene2d.h"
#include "manager.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define CLASS_NAME      "AppClass"                // �E�C���h�E�̃N���X��
#define WINDOW_NAME     "�X�C�[�g�p�e�B�X���["    // �E�C���h�E�̃L���v�V������
#define WINDOWMODE FALSE                           // �E�B���h�E���[�h�̐ݒ�(FALSE�ɂ���ƃt���X�N���[��)

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
#ifdef _DEBUG
int    g_nCountFPS;         // FPS�J�E���^
#endif

//=============================================================================
// [WinMain] ���C���֐�
//=============================================================================
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX wcex =
    {
        sizeof(WNDCLASSEX),
        CS_CLASSDC,
        WndProc,
        0,
        0,
        hInstance,
        NULL,
        LoadCursor(NULL, IDC_ARROW),
        (HBRUSH)(COLOR_WINDOW + 1),
        NULL,
        CLASS_NAME,
        NULL
    };
    RECT rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
    HWND hWnd;
    MSG msg;
    DWORD dwCurrentTime;
    DWORD dwFrameCount;
    DWORD dwExecLastTime;
    DWORD dwFPSLastTime;

    // �E�B���h�E�N���X�̓o�^
    RegisterClassEx(&wcex);

    // �w�肵���N���C�A���g�̈���m�ۂ��邽�߂ɕK�v�ȃE�B���h�E���W���v�Z
    AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

    // �E�B���h�E�̍쐬
    hWnd = CreateWindow(CLASS_NAME,
        WINDOW_NAME,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        (rect.right - rect.left),
        (rect.bottom - rect.top),
        NULL,
        NULL,
        hInstance,
        NULL);

    WSADATA WsaData;

    // Winsock�̏�����(��������ƂO��z��)
    int nErr = WSAStartup(WINSOCK_VERSION, &WsaData);
    if (nErr)
    {// �������Ɏ��s����
        return 1;
    }

    // �}�l�[�W���[�̏�����
    CManager *pManager;
    pManager = new CManager;

    // ��O������FALSE�ɂ���ƃt���X�N���[��
    pManager->Init(hInstance,hWnd, WINDOWMODE);

    // ����\��ݒ�
    timeBeginPeriod(1);

    // �t���[���J�E���g������
    dwCurrentTime =
        dwFrameCount = 0;
    dwExecLastTime =
        dwFPSLastTime = timeGetTime();

    // �E�C���h�E�̕\��
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    // ���b�Z�[�W���[�v
    while (1)
    {
            if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
            {// PostQuitMessage()���Ă΂ꂽ�烋�[�v�I��
                break;
            }
            else
            {
                // ���b�Z�[�W�̖|��ƃf�B�X�p�b�`
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            dwCurrentTime = timeGetTime();	// ���݂̎��Ԃ��擾
            if ((dwCurrentTime - dwFPSLastTime) >= 500)
            {// 0.5�b���ƂɎ��s
#ifdef _DEBUG
             // FPS���Z�o
                g_nCountFPS = dwFrameCount * 1000 / (dwCurrentTime - dwFPSLastTime);
#endif
                dwFPSLastTime = dwCurrentTime;	// ���݂̎��Ԃ�ۑ�
                dwFrameCount = 0;
            }

            if ((dwCurrentTime - dwExecLastTime) >= (1000 / 60))
            {// 1/60�b�o��
                dwExecLastTime = dwCurrentTime;	// ���݂̎��Ԃ�ۑ�

               // �X�V����
                pManager->Update();

                // �`�揈��
                pManager->Draw();

                dwFrameCount++;
            }
        }
    }

    // �I������
    pManager->Uninit();

    if (pManager!=NULL)
    {
        delete pManager;
        pManager = NULL;
    }
    // �E�B���h�E�N���X�̓o�^������
    UnregisterClass(CLASS_NAME, wcex.hInstance);

    // ����\��߂�
    timeEndPeriod(1);

    return (int)msg.wParam;
}

//=============================================================================
// [WndProc] �E�C���h�E�v���V�[�W��
//=============================================================================
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CREATE:
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_ESCAPE:             // [ESC]�L�[�������ꂽ
            DestroyWindow(hWnd);    // �E�B���h�E��j������悤�w������
            break;
        }
        break;
    default:
        break;
    }

    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

#ifdef _DEBUG
//=============================================================================
// [GetFPS] FPS�̑��M
//=============================================================================
int GetFPS(void)
{
    return g_nCountFPS; 
}
#endif