//=============================================================================
//
// �n�`���� [terrain.cpp]
// Author : AYANO KUDO
//
//=============================================================================
#include "terrain.h"
#include "manager.h"
#include "renderer.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define SCROLLING_SPEED (-4.0f)

//*****************************************************************************
// �ÓI�����o�ϐ�������
//*****************************************************************************
LPDIRECT3DTEXTURE9 CTerrain::m_pTexture[CTerrain::TYPE_MAX] = {};
char* CTerrain::m_apTextureName[CTerrain::TYPE_MAX] = {
    "data/TEXTURE/terrain000.png"
};
D3DXVECTOR3 CTerrain::m_move = D3DXVECTOR3(SCROLLING_SPEED, 0.0f, 0.0f);

//=============================================================================
// [CTerrain] �R���X�g���N�^
//=============================================================================
CTerrain::CTerrain()
{
    SetObjtype(OBJTYPE_TERRAIN);
    SetSize(D3DXVECTOR3(TERRAIN_SIZE_X, TERRAIN_SIZE_Y,0.0f));

    m_move = D3DXVECTOR3(SCROLLING_SPEED,0.0f,0.0f);
}

//=============================================================================
// [~CTerrain] �f�X�g���N�^
//=============================================================================
CTerrain::~CTerrain()
{
}

//=============================================================================
// [Create] �I�u�W�F�N�g�̐���
//=============================================================================
CTerrain *CTerrain::Create(D3DXVECTOR3 pos)
{
    CTerrain *pTerrain = NULL;

    if (!pTerrain)
    {
        pTerrain = new CTerrain();
        pTerrain->Init(pos);
    }
    return pTerrain;
}

//=============================================================================
// [Load] �e�N�X�`���̓ǂݍ���
//=============================================================================
HRESULT CTerrain::Load(void)
{
    // �f�o�C�X�̎擾
    LPDIRECT3DDEVICE9 pDevice;
    pDevice = CManager::GetRenderer()->GetDevice();
    for (int nCntEnemy = 0; nCntEnemy < TYPE_MAX; nCntEnemy++)
    {
        D3DXCreateTextureFromFile(pDevice, m_apTextureName[nCntEnemy], &m_pTexture[nCntEnemy]);
    }
    // �e�N�X�`���̐���
    return S_OK;;
}

//=============================================================================
// [UnLoad] �e�N�X�`���̔j��
//=============================================================================
void CTerrain::Unload(void)
{
    // �e�N�X�`���̔j��
    for (int nCntEnemy = 0; nCntEnemy < TYPE_MAX; nCntEnemy++)
    {
        if (m_pTexture[nCntEnemy] != NULL)
        {
            m_pTexture[nCntEnemy]->Release();
            m_pTexture[nCntEnemy] = NULL;
        }
    }
}

//=============================================================================
// [Init] ����������
//=============================================================================
void CTerrain::Init(D3DXVECTOR3 pos)
{
    SetPosition(pos);
    CScene2D::Init();
    // �e�N�X�`���̊��蓖��
    BindTexture(m_pTexture[0]);
}

//=============================================================================
// [Uninit] �I������
//=============================================================================
void CTerrain::Uninit(void)
{
    CScene2D::Uninit();
}

//=============================================================================
// [Upeate] �X�V����
//=============================================================================
void CTerrain::Update(void)
{
    D3DXVECTOR3 pos = GetPosition();
    CScene2D::Update();

    pos += m_move;
    SetPosition(pos);

}


//=============================================================================
// [Draw] �`�揈��
//=============================================================================
void CTerrain::Draw(void)
{
    // �|���S���̕`��
    CScene2D::Draw();
}
