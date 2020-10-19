//=============================================================================
//
// �}�l�[�W���[ [manager.cpp]
// Author : AYANO KUDO
//
//=============================================================================
#include "manager.h"
#include "renderer.h"
#include "inputkeyboard.h"
#include "inputcontroller.h"
#include "sound.h"
#include "title.h"
#include "tutorial.h"
#include "game.h"
#include "ranking.h"
#include "result.h"
#include "fade.h"

//*****************************************************************************
// �ÓI�����o�ϐ��̏�����
//*****************************************************************************
CManager::MODE    CManager::m_mode            = MODE_NONE;
CRenderer        *CManager::m_pRenderer       = NULL;
CInputKeyboard   *CManager::m_pInputKeyboard  = NULL;
CInputController *CManager::m_InputController = NULL;
CSound           *CManager::m_pSound          = NULL;
CTitle           *CManager::m_pTitle          = NULL;       // �^�C�g����ʂ̃|�C���^
CTutorial        *CManager::m_pTutorial       = NULL;       // �`���[�g���A����ʂ̃|�C���^
CGame            *CManager::m_pGame           = NULL;
CRanking         *CManager::m_pRanking        = NULL;
CResult          *CManager::m_pResult         = NULL;
bool              CManager::bIsClearedGame;                 // �Q�[���N���A�������ǂ���

//=============================================================================
// [CManager] �R���X�g���N�^
//=============================================================================
CManager::CManager()
{
    m_mode = MODE_NONE;
    bIsClearedGame = false;
}

//=============================================================================
// [~CManager] �f�X�g���N�^
//=============================================================================
CManager::~CManager()
{

}

//=============================================================================
// [Init] ����������
// hInstance : �L�[�{�[�h�̓��͂ɕK�p
//=============================================================================
HRESULT CManager::Init(HINSTANCE hInstance, HWND hWnd, bool bWindow)
{
    if (m_pInputKeyboard == NULL)
    {
        // �������̊m��
        m_pInputKeyboard = new CInputKeyboard;

        if (m_pInputKeyboard != NULL)
        {
            m_pInputKeyboard->Init(hInstance, hWnd);
        }
    }
    if (m_InputController == NULL)
    {
        // �������̊m��
        m_InputController = new CInputController;

        if (m_InputController != NULL)
        {
            m_InputController->Init(hInstance, hWnd);
        }
    }

    // �������̊m��
    m_pRenderer = new CRenderer;
    // ����������
    m_pRenderer->Init(hWnd, bWindow);

    if (m_pSound == NULL)
    {
        m_pSound = new CSound;
    // �T�E���h�̏�����
    m_pSound->Init(hWnd);
    }

    return S_OK;
}

//=============================================================================
// [Uninit] �I������
//=============================================================================
void CManager::Uninit(void)
{
    // �R���g���[���̏I������
    if (m_InputController)
    {
        m_InputController->Uninit();
        delete m_InputController;
        m_InputController = NULL;
    }

    // �L�[�{�[�h�̏I������
    if (m_pInputKeyboard)
    {
        m_pInputKeyboard->Uninit();
        delete m_pInputKeyboard;
        m_pInputKeyboard = NULL;
    }

    // �e���[�h�̏I������
    switch (m_mode)
    {

    case MODE_TITLE:
        if (m_pTitle)
        {
            m_pTitle->Uninit();
            delete m_pTitle;
            m_pTitle = NULL;
        }
        break;

    case MODE_TUTORIAL: // �`���[�g���A��
        m_pTutorial->Uninit();
        delete m_pTutorial;
        m_pTutorial = NULL;
        break;

    case MODE_GAME:
        if (m_pGame)
        {
            m_pGame->Uninit();
            delete m_pGame;
            m_pGame = NULL;
        }
        break;

    case MODE_RESULT:
        if (m_pResult)
        {
            m_pResult->Uninit();
            delete m_pResult;
            m_pResult = NULL;
        }
        break;

    case MODE_RANKING:
        if (m_pRanking)
        {
        m_pRanking->Uninit();
        delete m_pRanking;
            m_pRanking = NULL;
        }
        break;
    }

    if (m_pRenderer)
    {
        // �I������
        m_pRenderer->Uninit();

        // ��������J�����ă|�C���^�̒��g��NULL�ɂ���
        delete m_pRenderer;
        m_pRenderer = NULL;
    }

    //�T�E���h�̏I������
    if (m_pSound)
    {
        m_pSound->Uninit();
        // ��������J�����ă|�C���^�̒��g��NULL�ɂ���
        delete m_pSound;
        m_pSound = NULL;
    }
}

//=============================================================================
// [Updete] �X�V����
//=============================================================================
void CManager::Update(void)
{
    if (CGame::GetPause() == false)
    {
        if (m_pRenderer != NULL)
        {
            // �X�V����
            m_pRenderer->Update();
        }
    }

    // ���݂̃��[�h�̍X�V�������s��
    switch (m_mode)
    {

    case MODE_TITLE:    // �^�C�g��
        m_pTitle->Update();
        break;

    case MODE_TUTORIAL: // �`���[�g���A��
        m_pTutorial->Update();
        break;

    case MODE_GAME:     // �Q�[��
        m_pGame->Update();
        break;

    case MODE_RESULT:   // ���U���g
        m_pResult->Update();
        break;

    case MODE_RANKING:  // �����L���O
        m_pRanking->Update();
        break;
    }

    m_pInputKeyboard->Update();
    m_InputController->Update();
}

//=============================================================================
// [Draw] �`�揈��
//=============================================================================
void CManager::Draw(void)
{

    if (m_pRenderer != NULL)
    {
        // �I�u�W�F�N�g�̕`�揈��
        m_pRenderer->Draw();
    }


}

//=============================================================================
// [SetMode] ���[�h�̐ݒ�
//=============================================================================
void CManager::SetMode(MODE mode)
{
    // ���݂̃��[�h���I��
    switch (m_mode)
    {
    case MODE_TITLE:       // �^�C�g��
        if (m_pTitle)
        {
            m_pTitle->Uninit();
            delete m_pTitle;
            m_pTitle = NULL;
        }
        break;

    case MODE_TUTORIAL: // �`���[�g���A��
        m_pTutorial->Uninit();
        delete m_pTutorial;
        m_pTutorial = NULL;
        break;

    case MODE_GAME:     // �Q�[��
        if (m_pGame != NULL)
        {
            m_pGame->Uninit();
            delete m_pGame;
            m_pGame = NULL;
        }
        break;

    case MODE_RESULT:   // ���U���g
        if (m_pResult)
        {
            m_pResult->Uninit();
            delete m_pResult;
            m_pResult = NULL;
        }
        break;

    case MODE_RANKING:  // �����L���O
        if (m_pRanking != NULL)
        {
            m_pRanking->Uninit();
            delete m_pRanking;
            m_pRanking = NULL;
        }
        break;
    }

    m_mode = mode;

    // ���̃��[�h��������
    switch (m_mode)
    {
    case MODE_TITLE:    // �^�C�g��
        m_pTitle = CTitle::Create();
        break;

    case MODE_TUTORIAL: // �`���[�g���A��
        m_pTutorial = CTutorial::Create();
        break;

    case MODE_GAME:     // �Q�[��
        m_pGame = CGame::Create();
        break;

    case MODE_RESULT:   // ���U���g
        m_pResult = CResult::Create(bIsClearedGame);
        break;

    case MODE_RANKING:  // �����L���O
        m_pRanking = CRanking::Create();
        break;
    }
}