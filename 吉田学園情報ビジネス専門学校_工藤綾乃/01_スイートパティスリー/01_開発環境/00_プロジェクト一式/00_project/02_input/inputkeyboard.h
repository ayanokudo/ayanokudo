//=============================================================================
//
// �L�[�{�[�h�̓��͏��� [inputkeyboard.h]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef _INPUTKEYBOARD_H_
#define _INPUTKEYBOARD_H_
#include "input.h"

//******************************************************************************
// �N���X�̒�`
//******************************************************************************
// �L�[�{�[�h���̓N���X
class CInputKeyboard : public CInput
{
public:
    CInputKeyboard();
    ~CInputKeyboard();

    HRESULT Init(HINSTANCE hInstance, HWND hWnd);
    void Uninit(void);
    void Update(void);

    bool GetKeyPress(int nKey) { return (m_aKeyState[nKey] & 0x80) ? true : false; }
    bool GetKeyTrigger(int nKey) {return  (m_aKeyStateTrigger[nKey] & 0x80) ? true : false;}
private:
    BYTE m_aKeyState[NUM_KEY_MAX];                  //�L�[�{�[�h�̃v���X���
    BYTE m_aKeyStateTrigger[NUM_KEY_MAX];           //�L�[�{�[�h�̃g���K�[���
    BYTE m_aKeyRelease[NUM_KEY_MAX];                //�L�[�{�[�h�̃����[�X���
};
#endif