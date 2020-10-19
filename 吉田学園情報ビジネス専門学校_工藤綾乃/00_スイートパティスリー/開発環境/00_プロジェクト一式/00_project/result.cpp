//=============================================================================
//
// ���U���g�̏��� [result.cpp]
// Author : AYANO KUDO
//
//=============================================================================
#include "result.h"
#include "manager.h"
#include "renderer.h"
#include "input.h"
#include "inputkeyboard.h"
#include "inputcontroller.h"
#include "polygon.h"
#include "sound.h"
#include "scene2d.h"
#include "fade.h"

//******************************************************************************
// �ÓI�����o�ϐ���`
//******************************************************************************
char *CResult::m_apTextureName[RESURT_TEXTURE_MAX] = {
    "data/TEXTURE/RankingBg.png" ,
    "data/TEXTURE/gameover_logo.png",
    "data/TEXTURE/gameclear_logo.png"
};

LPDIRECT3DTEXTURE9 CResult::m_pTexture[RESURT_TEXTURE_MAX-1] = {};// �e�N�X�`���ւ̃|�C���^

D3DXVECTOR3 CResult::m_pos[RESURT_TEXTURE_MAX - 1] = 
{
    { SCREEN_WIDTH / 2.0f,SCREEN_HEIGHT / 2.0f,0.0f },
    { SCREEN_WIDTH / 2.0f ,SCREEN_HEIGHT / 2.0f,0.0f }
};// �\������|���S���̈ʒu

D3DXVECTOR3 CResult::m_size[RESURT_TEXTURE_MAX - 1] = 
{
    { SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f },
    { 788,80.0f,0.0f }
};// �\������|���S���̃T�C�Y

bool CResult::m_IsClearedGame;                               // �Q�[�����N���A�������ǂ���

//=============================================================================
// [CResult] �R���X�g���N�^
//=============================================================================
CResult::CResult()
{
    for (int nCount = 0; nCount < MAX_RESULT; nCount++)
    {
        m_apPolygon[nCount] = NULL;
    }
    m_IsClearedGame = false;
}

//=============================================================================
// [~CResult] �f�X�g���N�^
//=============================================================================
CResult::~CResult()
{

}

//=============================================================================
// [Create] �I�u�W�F�N�g�̐���
//=============================================================================
CResult *CResult::Create(bool IsClearedGame)
{
    CResult *pResult = NULL;
    if (!pResult)
    {
        pResult = new CResult;
        pResult->Init(IsClearedGame);
    }

    return pResult;
}

//=============================================================================
// [Load] �e�N�X�`���̓ǂݍ���
//=============================================================================
HRESULT CResult::Load(void)
{
    // �f�o�C�X�̎擾�@
    LPDIRECT3DDEVICE9 pDevice;
    pDevice = CManager::GetRenderer()->GetDevice();

        // �e�N�X�`���̐���
        D3DXCreateTextureFromFile(pDevice, m_apTextureName[0], &m_pTexture[0]);
        D3DXCreateTextureFromFile(pDevice, m_apTextureName[1 + m_IsClearedGame], &m_pTexture[1]);

    return S_OK;
}

//=============================================================================
// [UnLoad] �e�N�X�`���̔j��
//=============================================================================
void CResult::Unload(void)
{
    // �e�N�X�`���̊J��
    for (int nCount = 0; nCount < MAX_RESULT; nCount++)
    {
        if (m_pTexture[nCount] != NULL)
        {
            m_pTexture[nCount]->Release();
            m_pTexture[nCount] = NULL;
        }
    }
}

//=============================================================================
// [Init] ����������
//=============================================================================
HRESULT CResult::Init(bool IsClearedGame)
{
    m_IsClearedGame = IsClearedGame;// �Q�[���N���A��Ԃ�ۑ�
    Load();// �e�N�X�`���̓ǂݍ���

    // �T�E���h�̍Đ�
    CSound *pSound = CManager::GetSound();
    pSound->Play(CSound::SOUND_LABEL_BGM002);

    for (int nCount = 0; nCount < MAX_RESULT; nCount++)
    {
        m_apPolygon[nCount] = CScene2D::Create(m_pos[nCount], m_size[nCount]);
        m_apPolygon[nCount]->SetObjtype(CScene::OBJTYPE_BG);
        m_apPolygon[nCount]->BindTexture(m_pTexture[nCount]);
    }


    return S_OK;
}

//=============================================================================
// [Uninit] �I������
//=============================================================================
void CResult::Uninit(void)
{
    // �T�E���h�̒�~
    CSound *pSound = CManager::GetSound();
    pSound->Stop(CSound::SOUND_LABEL_BGM002);

    // �������̊J��
    for (int nCount = 0; nCount < MAX_RESULT; nCount++)
    {
        if (m_apPolygon[nCount] != NULL)
        {
            m_apPolygon[nCount]->Uninit();
        }
    }

    CResult::Unload();
}

//=============================================================================
// [Update] �X�V����
//=============================================================================
void CResult::Update(void)
{
    // �ϐ��錾
    CInputKeyboard*pInputKeyboard = CManager::GetInputKeyboard();
    CInputController *pInputController = CManager::GetInputController();

    for (int nCount = 0; nCount < MAX_RESULT; nCount++)
    {
        m_apPolygon[nCount]->Update();
    }
    if (pInputKeyboard->GetKeyTrigger(DIK_SPACE) ||
        pInputController->GetConTrigger(CInputController::BUTTON_10))
    {
        CFade::SetFade(CManager::MODE_TITLE);
    }
}

//=============================================================================
// [Draw] �`�揈��
//=============================================================================
void CResult::Draw(void)
{
    for (int nCount = 0; nCount < MAX_RESULT; nCount++)
    {
        m_apPolygon[nCount]->Draw();
    }
}
