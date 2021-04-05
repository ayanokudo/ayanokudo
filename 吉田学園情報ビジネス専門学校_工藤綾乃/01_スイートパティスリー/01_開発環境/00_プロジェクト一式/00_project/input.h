//=============================================================================
//
// ���͏��� [input.h]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef _INPUT_H_
#define _INPUT_H_
#include "main.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define NUM_KEY_MAX (256)// �L�[�̍ő吔

//******************************************************************************
// �N���X�̒�`
//******************************************************************************
class CInput
{
public:
    CInput();
    virtual ~CInput();// �h���N���X�̃f�X�g���N�^���Ăяo�����߂ɉ��z�֐��ɂ���

    virtual HRESULT Init(HINSTANCE hInstance, HWND hWnd);
    virtual void Uninit(void);
    virtual void Update(void) = 0;

protected:
    LPDIRECTINPUTDEVICE8   m_pKeyDevice;         //���̓f�o�C�X(�L�[�{�[�h)
    static LPDIRECTINPUTDEVICE8 m_pConDevice;     // �R���g���[���[�f�o�C�X
    static LPDIRECTINPUT8  m_pInputDevice;    // DirectInput�̃f�o�C�X
};
#endif