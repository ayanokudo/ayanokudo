//=============================================================================
//
// �L�[�{�[�h�̓��͏��� [inputkeyboard.cpp]
// Author : AYANO KUDO
//
//=============================================================================
#include "inputkeyboard.h"
#include "input.h"

//=============================================================================
// [CInputKeyboard] �R���X�g���N�^
//=============================================================================
CInputKeyboard::CInputKeyboard()
{
    // �L�[�̏��N���A
    memset(m_aKeyState, 0, sizeof(m_aKeyState));
    memset(m_aKeyStateTrigger, 0, sizeof(m_aKeyStateTrigger));
    memset(m_aKeyRelease, 0, sizeof(m_aKeyRelease));
}

//=============================================================================
// [~CInputKeyboard] �f�X�g���N�^
//=============================================================================
CInputKeyboard::~CInputKeyboard()
{

}

//=============================================================================
// [Init] ����������
//=============================================================================
HRESULT CInputKeyboard::Init(HINSTANCE hInstance, HWND hWnd)
{
    CInput::Init(hInstance,hWnd);

    //���̓f�o�C�X(�L�[�{�[�h)�̍쐬
    if (FAILED(m_pInputDevice->CreateDevice(GUID_SysKeyboard, &m_pKeyDevice, NULL)))
    {
        return E_FAIL;
    }

    //�f�[�^�t�H�[�}�b�g�̎w��
    if (FAILED(m_pKeyDevice->SetDataFormat(&c_dfDIKeyboard)))
    {
        return E_FAIL;
    }

    //�������[�h�ݒ�(�t�H�A�O���E���h����r�����[�h)
    if (FAILED(m_pKeyDevice->SetCooperativeLevel(hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE))))
    {
        return E_FAIL;
    }

    //�L�[�{�[�h�ւ̃A�N�Z�X�����l��(���͐���J�n)
    m_pKeyDevice->Acquire();

    return S_OK;
}

//=============================================================================
// [Uninit] �I������
//=============================================================================
void CInputKeyboard::Uninit(void)
{
    CInput::Uninit();
}

//=============================================================================
// [Update] �X�V����
//=============================================================================
void CInputKeyboard::Update(void)
{
    BYTE aKeyState[NUM_KEY_MAX];// ���݂̃L�[
    int nCntKey;

    //�f�o�C�X����f�[�^���擾
    if (SUCCEEDED(m_pKeyDevice->GetDeviceState(sizeof(aKeyState), aKeyState)))
    {
        for (nCntKey = 0; nCntKey < NUM_KEY_MAX; nCntKey++)
        {
            //�L�[�g���K�[����ۑ�
            m_aKeyStateTrigger[nCntKey] = (m_aKeyState[nCntKey] ^ aKeyState[nCntKey]) & aKeyState[nCntKey];

            //�L�[�����[�X����ۑ�
            m_aKeyRelease[nCntKey] = (m_aKeyState[nCntKey] ^ aKeyState[nCntKey]) &~aKeyState[nCntKey];

            //�L�[�v���X����ۑ�
            m_aKeyState[nCntKey] = aKeyState[nCntKey];

        }
    }
    else
    {
        //�L�[�{�[�h�̃A�N�Z�X�����擾
        m_pKeyDevice->Acquire();
    }
}
