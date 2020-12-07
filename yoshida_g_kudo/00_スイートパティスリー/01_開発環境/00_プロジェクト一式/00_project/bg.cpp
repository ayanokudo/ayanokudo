//=============================================================================
//
// �w�i�̏��� [bg.h]
// Author : AYANO KUDO
//
//=============================================================================
#include "bg.h"
#include "manager.h"
#include "renderer.h"
#include "scene2d.h"

//*****************************************************************************
// �ÓI�����o�ϐ�
//*****************************************************************************
LPDIRECT3DTEXTURE9 CBg::m_apTexture[MAX_BG] = {};
char* CBg::m_pTextureName[MAX_BG] = {
    "data/TEXTURE/bg102.png",
    "data/TEXTURE/bg101.png",
    "data/TEXTURE/bg100.png"
};

//=============================================================================
// [CBg] �R���X�g���N�^
//=============================================================================
CBg::CBg()
{
    m_pos = D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f);
    SetObjtype(CScene::OBJTYPE_BG);
    for (int nCountBg = 0; nCountBg < MAX_BG; nCountBg++)
    {
        m_apScene2D[nCountBg] = NULL;
    }
    m_Scroll = D3DXVECTOR2( 0.0f,0.0f);
    m_playerScroll = D3DXVECTOR2(0.0f, 0.0f);

}

//=============================================================================
// [~CBg] �f�X�g���N�^
//=============================================================================
CBg::~CBg()
{

}

//=============================================================================
// [Load] �e�N�X�`���̓ǂݍ���
//=============================================================================
HRESULT CBg::Load(void)
{
    // �f�o�C�X�̎擾�@
    LPDIRECT3DDEVICE9 pDevice;
    pDevice = CManager::GetRenderer()->GetDevice();
    for (int nCount = 0; nCount < MAX_BG; nCount++)
    {
        // �e�N�X�`���̐���
        D3DXCreateTextureFromFile(pDevice, m_pTextureName[nCount], &m_apTexture[nCount]);
    }
    return S_OK;
}

//=============================================================================
// [Unload] �e�N�X�`���̔j��
//=============================================================================
void CBg::Unload(void)
{
    for (int nCount = 0; nCount < MAX_BG; nCount++)
    {
        // �e�N�X�`���̔j��
        if (m_apTexture[nCount] != NULL)
        {
            m_apTexture[nCount]->Release();
            m_apTexture[nCount] = NULL;
        }
    }
}

//=============================================================================
// [Create] �w�i�̐���
//=============================================================================
CBg * CBg::Create(void)
{
    CBg *pBg=NULL;
    if (!pBg)
    {
        pBg = new CBg;
        pBg->Init();
    }
    return pBg;
}

//=============================================================================
// [Init] ����������
//=============================================================================
HRESULT CBg::Init(void)
{
    // �w�i�̐���
    for (int nCount = 0; nCount < MAX_BG; nCount++)
    {
        m_apScene2D[nCount] = CScene2D::Create(m_pos, D3DXVECTOR3(SCREEN_WIDTH, SCREEN_HEIGHT,0.0f));
        m_apScene2D[nCount]->Init();
        m_apScene2D[nCount]->SetObjtype(CScene::OBJTYPE_BG);
        m_apScene2D[nCount]->BindTexture(m_apTexture[nCount]);
    }
    return S_OK;
}

//=============================================================================
// [Uninit] �I������
//=============================================================================
void CBg::Uninit(void)
{
    for (int nCount = 0; nCount < MAX_BG; nCount++)
    {
        if (m_apScene2D[nCount])
        {
            m_apScene2D[nCount]->Uninit();
            m_apScene2D[nCount] = NULL;
        }
    }
    Release();
}

//=============================================================================
// [Update] �X�V����
//=============================================================================
void CBg::Update(void)
{
    m_Scroll += D3DXVECTOR2(SCROLL_SPEED + m_playerScroll.x, m_playerScroll.y);

    // �|���S���̕`��
    for (int nCount = 0; nCount < MAX_BG; nCount++)
    {
        m_apScene2D[nCount]->SetTexture(D3DXVECTOR2(m_Scroll.x*(nCount+1), m_Scroll.y*(nCount + 1)), D3DXVECTOR2(1.0f,1.0f));
        m_apScene2D[nCount]->SetColor(D3DXCOLOR (1.0f,1.0f,1.0f,0.5f));
    }
}

//=============================================================================
// [Draw] �`�揈��
//=============================================================================
void CBg::Draw(void)
{

}

