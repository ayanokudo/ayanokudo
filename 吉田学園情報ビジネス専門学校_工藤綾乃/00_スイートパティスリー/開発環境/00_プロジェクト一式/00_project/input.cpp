//=============================================================================
//
// ���͏��� [input.cpp]
// Author : AYANO KUDO
//
//=============================================================================
#include "input.h"

//*****************************************************************************
// �ÓI�����o�ϐ�������
//*****************************************************************************
LPDIRECTINPUT8  CInput::m_pInputDevice = NULL;
LPDIRECTINPUTDEVICE8 CInput::m_pConDevice = NULL;

//=============================================================================
// [CInput] �R���X�g���N�^
//=============================================================================
CInput::CInput()
{
    m_pKeyDevice = NULL;
}

//=============================================================================
// [~CInput] �f�X�g���N�^
//=============================================================================
CInput::~CInput()
{

}

//=============================================================================
// [CInput] ����������
//=============================================================================
HRESULT CInput::Init(HINSTANCE hInstance, HWND hWnd)
{
    //Direct�I�u�W�F�N�g�̍쐬
    if (FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_pInputDevice, NULL)))
    {
        return E_FAIL;
    }
    return S_OK;
}

//=============================================================================
// [Uninit] �I������
//=============================================================================
void CInput::Uninit(void)
{
    //DirectInput�I�u�W�F�N�g�̉��
    if (m_pInputDevice)
    {
        m_pInputDevice->Release();
        m_pInputDevice = NULL;
    }

    //���̓f�o�C�X�i�L�[�{�[�h�j�̊J��
    if (m_pKeyDevice != NULL)
    {
        //�L�[�{�[�h�̃A�N�Z�X�����J��
        m_pKeyDevice->Unacquire();// �f�o�C�X����̒�~����
        m_pKeyDevice->Release();
        m_pKeyDevice = NULL;
    }
    if (m_pConDevice!=NULL)
    {
        //�R���g���[���̃A�N�Z�X�����J��
        m_pConDevice->Unacquire();
        m_pConDevice->Release();
        m_pConDevice = NULL;
    }
}
