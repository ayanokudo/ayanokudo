//=============================================================================
//
// �V�[���h�̏��� [Shield.cpp]
// Author : AYANO KUDO
//
//=============================================================================
#include "shield.h"
#include "manager.h"
#include "renderer.h"
#include "game.h"
#include "player.h"
#include "enemy.h"

//*****************************************************************************
// �ÓI�����o�ϐ�������
//*****************************************************************************
LPDIRECT3DTEXTURE9 CShield::m_pTexture = NULL;
char *CShield::m_pTextureName = "data/TEXTURE/effect002.png";

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define  MAX_DURABLEVALUE (3)       // �ϋv�l�̍ő�l
#define SHIELD_SIZE_X (80.0f)       // �V�[���h�̃T�C�Y
#define SHIELD_SIZE_Y (80.0f)       // �V�[���h�̃T�C�Y

//=============================================================================
// [CShield] �R���X�g���N�^
//=============================================================================
CShield::CShield()
{
    m_nDurableValue=MAX_DURABLEVALUE;
    SetObjtype(OBJTYPE_SHIELD);
}


//=============================================================================
// [~CShield] �f�X�g���N�^
//=============================================================================
CShield::~CShield()
{
}

//=============================================================================
// [Create] �I�u�W�F�N�g�̐���
//=============================================================================
CShield * CShield::Create(D3DXVECTOR3 pos, CPlayer* pPlayer)
{
    CShield *pShield = NULL;
    if (!pShield)
    {
        pShield = new CShield;
        pShield->Init(pos, pPlayer);
    }
    return pShield;
}

//=============================================================================
// [Load] �e�N�X�`���̓ǂݍ���
//=============================================================================
HRESULT CShield::Load(void)
{
    // �f�o�C�X�̎擾
    LPDIRECT3DDEVICE9 pDevice;
    pDevice = CManager::GetRenderer()->GetDevice();

    // �e�N�X�`���̐���
    D3DXCreateTextureFromFile(pDevice, m_pTextureName, &m_pTexture);
    return S_OK;
}

//=============================================================================
// [Unload] �e�N�X�`���̔j��
//=============================================================================
void CShield::Unload(void)
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
HRESULT CShield::Init(D3DXVECTOR3 pos, CPlayer* pPlayer)
{
    // �e�����o�ϐ�������
    CScene2D::Init();
    SetPosition(pos);
    SetSize(D3DXVECTOR3(SHIELD_SIZE_X, SHIELD_SIZE_Y,0.0f));
    SetColor(D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));
    m_pPlayer = pPlayer;
    // �e�N�X�`���̊��蓖��
    BindTexture(m_pTexture);

    return S_OK;
}

//=============================================================================
// [Uninit] �I������
//=============================================================================
void CShield::Uninit(void)
{
    CScene2D::Uninit();
}

//=============================================================================
// [Update] �X�V����
//=============================================================================
void CShield::Update(void)
{
    // �v���C���[�̈ʒu�ɒǏ]������
    CScene2D::Update();
    D3DXVECTOR3 pos = GetPosition();
    CPlayer *pPlayer = CGame::GetPlayer();

    pos = pPlayer->GetPosition();
    SetPosition(pos);
    // �G�Ƃ̓����蔻��
    CScene* pScene = JudgeFittingRectangle(CScene::OBJTYPE_ENEMY);
    if (pScene!=NULL)
    {
        ((CEnemy*)pScene)->Damage();
        pScene = NULL;
        Damage();
        pPlayer->SetShield(false);
    }
    // �n�`�Ƃ̓����蔻��
    pScene = JudgeFittingRectangle(CScene::OBJTYPE_TERRAIN);
    if (pScene)
    {
        Damage();
        // �v���C���[����莞�Ԗ��G��Ԃɂ���
        pPlayer->SetShield(false);
    }

}

//=============================================================================
// [Draw] �`�揈��
//=============================================================================
void CShield::Draw(void)
{
    // �|���S���̕`��
    CScene2D::Draw();
}

//=============================================================================
// [Damage] �_���[�W
//=============================================================================
void CShield::Damage(void)
{
    m_nDurableValue--;


    if (m_nDurableValue <= MAX_DURABLEVALUE / 2.0f)
    {
        SetColor(D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f));
    }
    // �V�[���h�̑ϋv�l��0�ȉ��ɂȂ�����
    if (m_nDurableValue <= 0)
    {
        m_pPlayer->SetShieldObjct(NULL);
        Uninit();
    }
}


