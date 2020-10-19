//=============================================================================
//
// �|�[�Y���� [pause.cpp]
// Author : AYANO KUDO
//
//=============================================================================
#include "pause.h"
#include "polygon.h"
#include "manager.h"
#include "renderer.h"
#include "game.h"

//*****************************************************************************
// �ÓI�����o�ϐ��錾
//*****************************************************************************
char* CPause::m_pTextureName = { "data/TEXTURE/pause_000.png" };
LPDIRECT3DTEXTURE9 CPause::m_pTexture = NULL;

//=============================================================================
// [CGame] �R���X�g���N�^
//=============================================================================
CPause::CPause()
{
    SetObjtype(OBJTYPW_PAUSE);
    memset(m_apPolygon, NULL, sizeof(m_apPolygon));
}

//=============================================================================
// [~CGame] �f�X�g���N�^
//=============================================================================
CPause::~CPause()
{
}

//=============================================================================
// [Create] �I�u�W�F�N�g�̐���
//=============================================================================
CPause * CPause::Create(void)
{
    // �ϐ��錾
    CPause *pPause = NULL;
    if (pPause == NULL)
    {
        // �������̊m��
        pPause = new CPause();
        pPause->Init();
    }
    return pPause;
}

//=============================================================================
// [Load] �e�N�X�`���̓ǂݍ���
//=============================================================================
HRESULT CPause::Load(void)
{
    LPDIRECT3DDEVICE9 pDevice;
    pDevice = CManager::GetRenderer()->GetDevice();

    D3DXCreateTextureFromFile(pDevice, m_pTextureName, &m_pTexture);
    return S_OK;
}

//=============================================================================
// [UnLoad] �e�N�X�`���̔j��
//=============================================================================
void CPause::Unload(void)
{
    // �e�N�X�`���̔j��
    if (m_pTexture != NULL)
    {
        m_pTexture->Release();
        m_pTexture = NULL;
    }
}

// [Init] ����������
//=============================================================================
HRESULT CPause::Init(void)
{
    for (int nCount = 0; nCount < PAUSE_MAX; nCount++)
    {
        m_apPolygon[nCount] = CPolygon::Create(D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f), D3DXVECTOR3(200.0f, 80.0f, 0.0f));
        m_apPolygon[nCount]->BindTexture(m_pTexture);
    }
    return S_OK;
}

//=============================================================================
// [Uninit] �I������
//=============================================================================
void CPause::Uninit(void)
{
    for (int nCount = 0; nCount < PAUSE_MAX; nCount++)
    {
        if (m_apPolygon[nCount])
        {
            m_apPolygon[nCount]->Uninit();
            m_apPolygon[nCount] = NULL;
        }
    }
}

//=============================================================================
// [Update] �X�V����
//=============================================================================
void CPause::Update(void)
{
    
}

//=============================================================================
// [Draw] �`�揈��
//=============================================================================
void CPause::Draw(void)
{
    // �ϐ��錾
    bool bPause=CGame::GetPause();
    if (bPause)
    {
        for (int nCount = 0; nCount < PAUSE_MAX; nCount++)
        {
            m_apPolygon[nCount]->Draw();
        }
    }
}
