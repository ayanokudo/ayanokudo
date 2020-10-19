//=============================================================================
//
// �^�C�g������ [title.cpp]
// Author : AYANO KUDO
//
//=============================================================================
#include "title.h"
#include "manager.h"
#include "renderer.h"
#include "input.h"
#include "inputkeyboard.h"
#include "inputcontroller.h"
#include "polygon.h"
#include "sound.h"
#include "scene2d.h"
#include "fade.h"
#include "star.h"

//******************************************************************************
// �}�N����`
//******************************************************************************
#define TITLE_LATENCY   (60)      // �^�C�g����ʑҋ@����
#define ALPHA_VARIATION (5.0f)    // �A���t�@�l�̕ω���
#define ALPHA_DISPLACE  (0.5f)    // �A���t�@�l�̂��炷��

//******************************************************************************
// �ÓI�����o�ϐ���`
//******************************************************************************
TEXTURE_DATA CTitle::m_aTextureDate[CTitle::TITLE_MAX] // �^�C�g���̃e�N�X�`���̃f�[�^
{
    { D3DXVECTOR3(SCREEN_WIDTH / 2.0f,SCREEN_HEIGHT / 2.0f,0.0f),D3DXVECTOR3(SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f), "data/TEXTURE/title000.png" },     // �w�i
    { D3DXVECTOR3(SCREEN_WIDTH / 1.5f ,150.0f,0.0f),D3DXVECTOR3(464.0f,248.0f,0.0f),"data/TEXTURE/title_logo.png " },                               // �^�C�g�����S
    { D3DXVECTOR3(SCREEN_WIDTH / 2.0f ,SCREEN_HEIGHT - 200,0.0f),D3DXVECTOR3(600.0f,200.0f,0.0f),"data/TEXTURE/press_key.png "}
}; 
LPDIRECT3DTEXTURE9 CTitle::m_pTexture[CTitle::TITLE_MAX];

CStar* CTitle::m_pStar[MAX_STAR_TITLE] = {};

//=============================================================================
// [CTitle] �R���X�g���N�^
//=============================================================================
CTitle::CTitle()
{
    // �e�����o�ϐ�������
    memset(m_apPolygon, NULL, sizeof(m_apPolygon));
    m_nCountWait = 0;
    m_color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
    m_fAlpha = 0.0f;
}

//=============================================================================
// [~CTitle] �f�X�g���N�^
//=============================================================================
CTitle::~CTitle()
{

}

//=============================================================================
// [Create] �I�u�W�F�N�g�̐���
//=============================================================================
CTitle * CTitle::Create(void)
{
    CTitle *pTitle = NULL;
    if (!pTitle)
    {
        pTitle = new CTitle;
        pTitle->Init();
    }
    return pTitle;
}

//=============================================================================
// [Load] �e�N�X�`���̓ǂݍ���
//=============================================================================
HRESULT CTitle::Load(void)
{
    // �f�o�C�X�̎擾�@
    LPDIRECT3DDEVICE9 pDevice;
    pDevice = CManager::GetRenderer()->GetDevice();

    for (int nCount = 0; nCount < TITLE_MAX; nCount++)
    {
    // �e�N�X�`���̐���
    D3DXCreateTextureFromFile(pDevice, m_aTextureDate[nCount].textureName, &m_pTexture[nCount]);
    }
    return S_OK;
}

//=============================================================================
// [Unload] �e�N�X�`���̔j��
//=============================================================================
void CTitle::Unload(void)
{
    // �e�N�X�`���̊J��
    for (int nCount = 0; nCount < TITLE_MAX; nCount++)
    {
    if (m_pTexture[nCount]!= NULL)
    {
        m_pTexture[nCount]->Release();
        m_pTexture[nCount] = NULL;
    }
    }
}

//=============================================================================
// [Init] ����������
//=============================================================================
HRESULT CTitle::Init(void)
{
    m_nCountWait = 0;
    // �T�E���h�̍Đ�
    CSound *pSound = CManager::GetSound();
    pSound->Play(CSound::SOUND_LABEL_BGM000);

    CTitle::Load();

    for (int nCount = 0; nCount < TITLE_MAX; nCount++)
    {
        m_apPolygon[nCount] = CScene2D::Create(m_aTextureDate[nCount].pos, m_aTextureDate[nCount].size);
        m_apPolygon[nCount]->SetObjtype(CScene::OBJTYPE_BG);
        m_apPolygon[nCount]->BindTexture(m_pTexture[nCount]);
    }
    return S_OK;
}
 
//=============================================================================
// [Uninit] �I������
//=============================================================================
void CTitle::Uninit(void)
{
    // �T�E���h�̒�~
    CSound *pSound = CManager::GetSound();
    pSound->Stop(CSound::SOUND_LABEL_BGM000);

    // �������̊J��
    for (int nCount = 0; nCount < TITLE_MAX; nCount++)
    {
        if (m_apPolygon[nCount] != NULL)
        {
            m_apPolygon[nCount]->Uninit();
        }
    }

    CScene::ReleaseAll();

    CTitle::Unload();
}

//=============================================================================
// [Update] �X�V����
//=============================================================================
void CTitle::Update(void)
{
    // �ϐ��錾
    CInputKeyboard   *pInputKeyboard = CManager::GetInputKeyboard();
    CInputController *pInputController = CManager::GetInputController();
    m_nCountWait++;

    // //�����_���Ő����~�点��

    if (rand() % 30 == 0)
    {
        CStar::Create(D3DXVECTOR3(rand() % 1000, -50.0f, 0.0f), D3DXVECTOR3(rand() % 3 + 1, rand() % 3 + 1, 0.0f));
        CStar::Create(D3DXVECTOR3(rand() % 1000, -50.0f, 0.0f), D3DXVECTOR3(-rand() % 3 + 1, -rand() % 3 + 1, 0.0f));
    }

    UpdatePolygon();
    if (m_nCountWait >= TITLE_LATENCY)
    {// �^�C�g����ʍŏ���1�b�͑ҋ@
        // �X�y�[�X�L�[���������Ƃ��Q�[����ʂ�
        if (pInputKeyboard->GetKeyTrigger(DIK_SPACE) ||
            pInputKeyboard->GetKeyTrigger(DIK_RETURN) ||
            pInputController->GetConTrigger(CInputController::BUTTON_10))
        {
            // �T�E���h�炷
            CSound *pSound = CManager::GetSound();
            pSound->Play(CSound::SOUND_LABEL_SE_006);
            // �Q�[����ʂ֑J��
            CFade::SetFade(CManager::MODE_TUTORIAL);
        }
    }

}

//=============================================================================
// [Draw] �`�揈��
//=============================================================================
void CTitle::Draw(void)
{

}

//=============================================================================
// [UpdatePolygon] �|���S�����Ƃ̏���
//=============================================================================
void CTitle::UpdatePolygon(void)
{
    for (int nCountPolygon = 0; nCountPolygon < TITLE_MAX; nCountPolygon++)
    {
        switch (nCountPolygon)
        {
            // UI�̏ꍇ�_�ł�����
            // sinf �� m_fAlpha �̒l���� -1.0f�`1.0f �͈̔͂�Ԃ��̂�
            // ALPHA_DISPLACE�ŃA���t�@�l��
        case TITLE_PRESS_BUTTON:
            m_fAlpha += ALPHA_VARIATION;
            m_color.a = sinf(D3DXToRadian(m_fAlpha)) + ALPHA_DISPLACE;
            m_apPolygon[nCountPolygon]->SetColor(m_color);
            break;
        }
    m_apPolygon[nCountPolygon]->Update();
    }
}
