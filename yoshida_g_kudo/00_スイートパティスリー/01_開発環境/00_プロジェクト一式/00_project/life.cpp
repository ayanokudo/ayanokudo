//=============================================================================
//
// �c�@UI���� [life.cpp]
// Author : AYANO KUDO
//
//=============================================================================
#include "life.h"
#include "polygon.h"
#include "manager.h"
#include "renderer.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define LIFE_SIZE (40)      // �@�c�@�\���̑傫��

//*****************************************************************************
// �ÓI�����o�ϐ��錾
//*****************************************************************************
char* CLife::m_pTextureName = { "data/TEXTURE/player000.png" };
LPDIRECT3DTEXTURE9 CLife::m_pTexture = NULL;

//=============================================================================
// [CLife] �R���X�g���N�^
//=============================================================================
CLife::CLife()
{
    m_nLife = 0;
    //SetObjtype(OBJTYPE_UI);
    for (int nCountLife = 0; nCountLife < MAX_LIFE; nCountLife++)
    {
        m_apPolygon[nCountLife] = NULL;
    }
}

//=============================================================================
// [CLife] �R���X�g���N�^
//=============================================================================
CLife::CLife(int nLife)
{
    m_nLife = nLife;
    for (int nCountLife = 0; nCountLife < MAX_LIFE; nCountLife++)
    {
        m_apPolygon[nCountLife] = NULL;
    }
}

//=============================================================================
// [~CLife] �f�X�g���N�^
//=============================================================================
CLife::~CLife()
{
}

//=============================================================================
// [Create] �c�@�I�u�W�F�N�g�̐���
//=============================================================================
CLife * CLife::Create(int nLife)
{
    CLife *pLife = NULL;
    if (!pLife)
    {
        pLife = new CLife(nLife);
        pLife->Init();
    }
    return pLife;
}

//=============================================================================
// [Load] �e�N�X�`���̓ǂݍ���
//=============================================================================
HRESULT CLife::Load(void)
{
    LPDIRECT3DDEVICE9 pDevice;
    pDevice = CManager::GetRenderer()->GetDevice();

    D3DXCreateTextureFromFile(pDevice, m_pTextureName, &m_pTexture);
    return S_OK;
}

//=============================================================================
// [UnLoad] �e�N�X�`���̔j��
//=============================================================================
void CLife::Unload(void)
{
    // �e�N�X�`���̔j��
        if (m_pTexture != NULL)
        {
            m_pTexture->Release();
            m_pTexture = NULL;
        }
}


//=============================================================================
// [Init] ����������
//=============================================================================
HRESULT CLife::Init(void)
{
    for (int nCount = 0; nCount < m_nLife; nCount++)
    {
        m_apPolygon[nCount] = CPolygon::Create(D3DXVECTOR3(200.0f + (LIFE_SIZE*nCount), 100.0f, 0.0f), D3DXVECTOR3(LIFE_SIZE, LIFE_SIZE, 0.0f));
        m_apPolygon[nCount]->SetTexture(D3DXVECTOR2(0.0f, 1.0f), D3DXVECTOR2(1.0f, 3.0f));
        m_apPolygon[nCount]->BindTexture(m_pTexture);
    }
    return S_OK;
}

//=============================================================================
// [Uninit] �I������
//=============================================================================
void CLife::Uninit(void)
{
    for (int nCount = 0; nCount < MAX_LIFE; nCount++)
    {
        if (m_apPolygon[nCount])
        {
            m_apPolygon[nCount]->Uninit();
            m_apPolygon[nCount] = NULL;
        }
    }
    Release();
}

//=============================================================================
// [Update] �X�V����
//=============================================================================
void CLife::Update(void)
{

}

//=============================================================================
// [Draw] �`�揈��
//=============================================================================
void CLife::Draw(void)
{
    for (int nCount = 0; nCount < m_nLife; nCount++)
    {
        m_apPolygon[nCount]->Draw();
    }
}

