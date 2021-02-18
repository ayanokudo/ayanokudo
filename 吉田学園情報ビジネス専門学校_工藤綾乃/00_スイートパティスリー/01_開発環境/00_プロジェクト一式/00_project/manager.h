//=============================================================================
//
// �}�l�[�W���[ [manager.h]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef _MANAGER_H_
#define _MANAGER_H_
#include "main.h"

//*****************************************************************************
// �O���錾
//*****************************************************************************
class CInput;
class CInputKeyboard;
class CInputController;
class CRenderer;
class CSound;
class CGame;
class CRanking;
class CTitle;
class CTutorial;
class CResult;
class CFade;

//*****************************************************************************
// �N���X��`
//*****************************************************************************
class CManager
{
public:
    // ���[�h�̎��
    typedef enum
    {
        MODE_NONE = 0,      // ���[�h����
        MODE_TITLE,         // �^�C�g��
        MODE_TUTORIAL,      // �`���[�g���A��
        MODE_GAME,          // �Q�[��
        MODE_RESULT,        // ���U���g
        MODE_RANKING,       // �����L���O
        MODE_MAX            // ���[�h�̍ő吔
    }MODE;

    CManager();
    ~CManager();

    HRESULT Init(HINSTANCE hInstance, HWND hWnd, bool bWindow);
    void Uninit(void);
    void Update(void);
    void Draw(void);

    static CSound* GetSound(void) { return m_pSound; }
    static CRenderer* GetRenderer(void) { return m_pRenderer; }
    static CInputKeyboard* GetInputKeyboard(void) { return (CInputKeyboard*)m_pInputKeyboard; }
    static CInputController* GetInputController(void) { return (CInputController*)m_InputController; }

    // ���[�h�̃Z�b�^/�Q�b�^
    static void SetMode(MODE mode);
    static MODE GetMode(void) { return m_mode; }

    // �Q�[���N���A��Ԃ̃Z�b�^/�Q�b�^
    static void SetClearedGame(bool IsClearedGame) { bIsClearedGame = IsClearedGame; }
    static bool GetClearedGame(void) { return bIsClearedGame; }

private:
    // �����o�ϐ�
    static MODE                m_mode;                // ���݂̃��[�h
    static CRenderer           *m_pRenderer;          // �����_�����O�����̃|�C���^
    static  CInputKeyboard     *m_pInputKeyboard;
    static CInputController    *m_InputController;
    static CSound              *m_pSound;
    static CTitle              *m_pTitle;              // �^�C�g����ʂ̃|�C���^
    static CTutorial           *m_pTutorial;           // �`���[�g���A����ʂ̃|�C���^
    static CGame               *m_pGame;
    static CResult             *m_pResult;
    static CRanking            *m_pRanking;

    static bool bIsClearedGame;                   // �Q�[���N���A�������ǂ���
};
#endif