//=============================================================================
//
// �G�l���M�[�\���̏��� [energy_ui.cpp]
// Author : AYANO KUDO
//
//=============================================================================
#include "energy_ui.h"
#include "polygon.h"
#include "game.h"
#include "player.h"
#include "particle_effect.h"
#include "manager.h"
#include "renderer.h"

//*****************************************************************************
// �ÓI�����o�ϐ�
//*****************************************************************************
LPDIRECT3DTEXTURE9  CEnergy_UI::m_pTexture = NULL;       // �e�N�X�`���ւ̃|�C���^
char               *CEnergy_UI::m_pTextureName = "data/TEXTURE/energy_ui.png";  // �e�N�X�`����

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define ENERGY_UI_SIZE_X (300.0f)       // �G�l���M�[�\��UI�̑傫��(x��)
#define ENERGY_UI_SIZE_Y (60.0f)       // �G�l���M�[�\��UI�̑傫��(y��)

// �G�t�F�N�g�̐ݒ�
#define ENERGY_UI_EFFECT_POS              D3DXVECTOR3(m_pos.x - m_size.x / 2,m_pos.y,0.0f)         // �O�ՃG�t�F�N�g�̏o���ʒu�̐ݒ�
#define ENERGY_UI_EFFECT_MOVE             D3DXVECTOR3(-rand() %  10 + 1, (rand() % 1 + 1), 0.0f)    // �O�ՃG�t�F�N�g�̈ړ��ʂ̐ݒ�
#define ENERGY_UI_EFFECT_FREDUCTION_MOVE  D3DXVECTOR3(-rand()%5 / 10.0f, rand() % 5 / 10.0f, 0.0f)  // �O�ՃG�t�F�N�g�̈ړ������ʂ̐ݒ�
#define ENERGY_UI_EFFECT_COLOR            D3DXCOLOR(1.0f, 0.3f, 0.1f, 1.0)                          // �O�ՃG�t�F�N�g�̐F�̐ݒ�
#define ENERGY_UI_EFFECT_SIZE             (30.0f)                                                   // �O�ՃG�t�F�N�g�̃T�C�Y�̐ݒ�
#define ENERGY_UI_EFFECT_FREDUCTION_SIZE    (0.00f)                                                     // �O�ՃG�t�F�N�g�̃T�C�Y�̌�����
#define ENERGY_UI_EFFECT_FREDUCTION_ALPHA (0.1f)                                                    // �O�ՃG�t�F�N�g�̃A���t�@�l�����ʂ̐ݒ�
#define ENERGY_UI_EFFECT_TYPE             CParticle_Effect::PARTICLE_TYPE_CIRCLE                    // �O�ՃG�t�F�N�g�̃^�C�v

//=============================================================================
// [CEnergy_UI] �R���X�g���N�^
//=============================================================================
CEnergy_UI::CEnergy_UI()
{
    m_size = m_size = D3DXVECTOR3(ENERGY_UI_SIZE_X, ENERGY_UI_SIZE_Y, 0.0f);;
    m_pos = D3DXVECTOR3(SCREEN_WIDTH - ENERGY_UI_SIZE_X / 2, SCREEN_HEIGHT - ENERGY_UI_SIZE_Y / 2, 0.0f);
}

//=============================================================================
// [~CEnergy_UI] �f�X�g���N�^
//=============================================================================
CEnergy_UI::~CEnergy_UI()
{
}

//=============================================================================
// [Create] �I�u�W�F�N�g�̐���
//=============================================================================
CEnergy_UI * CEnergy_UI::Create(void)
{
    CEnergy_UI* pEnergyUI = NULL;
    if (pEnergyUI==NULL)
    {
        pEnergyUI = new CEnergy_UI;
        pEnergyUI->Init();

    }
    return pEnergyUI;
}

//=============================================================================
// [Load] �e�N�X�`���̓ǂݍ���
//=============================================================================
HRESULT CEnergy_UI::Load(void)
{
    // �f�o�C�X�̎擾�@
    LPDIRECT3DDEVICE9 pDevice;
    pDevice = CManager::GetRenderer()->GetDevice();

    // �e�N�X�`���̐���
    D3DXCreateTextureFromFile(pDevice, m_pTextureName, &m_pTexture);
    return S_OK;
}

//=============================================================================
// [Unload] �e�N�X�`���̔j��
//=============================================================================
void CEnergy_UI::Unload(void)
{
    // �e�N�X�`���̊J��
    if (m_pTexture != NULL)
    {
        m_pTexture->Release();
        m_pTexture = NULL;
    }
}


//=============================================================================
// [Init] ����������
//=============================================================================
HRESULT CEnergy_UI::Init(void)
{
        m_pPolygon = CPolygon::Create(m_pos, m_size);
        m_pPolygon->BindTexture(m_pTexture);
    return S_OK;
}

//=============================================================================
// [Uninit] �I������
//=============================================================================
void CEnergy_UI::Uninit(void)
{
        if (m_pPolygon != NULL)
        {
            m_pPolygon->Uninit();
            delete m_pPolygon;
            m_pPolygon= NULL;
        }
    Release();
}

//=============================================================================
// [Update] �X�V����
//=============================================================================
void CEnergy_UI::Update(void)
{
    CPlayer *pPlayer = CGame::GetPlayer();
    int nEnergy = pPlayer->GetEnergy();

    // �v���C���[�̃G�l���M�[�c�ʂ��m�F���Ē�����ς���
    float nPercentage = (float)nEnergy / (float)MAX_ENERGY;

    // �T�C�Y�̍X�V
    m_size = D3DXVECTOR3(ENERGY_UI_SIZE_X * nPercentage, ENERGY_UI_SIZE_Y, 0.0f);
    m_pPolygon->SetSize(m_size);

    // �ʒu�̍X�V
    m_pos = D3DXVECTOR3(SCREEN_WIDTH - m_size.x / 2, SCREEN_HEIGHT - ENERGY_UI_SIZE_Y / 2, 0.0f);
    m_pPolygon->SetPosition(m_pos);

    m_pPolygon->CPolygon::Update();

    // �O�ՃG�t�F�N�g�̐���
    CParticle_Effect::SetTrajectory(ENERGY_UI_EFFECT_POS, ENERGY_UI_EFFECT_MOVE, ENERGY_UI_EFFECT_FREDUCTION_MOVE, ENERGY_UI_EFFECT_COLOR, ENERGY_UI_EFFECT_SIZE, ENERGY_UI_EFFECT_FREDUCTION_SIZE, ENERGY_UI_EFFECT_FREDUCTION_ALPHA, ENERGY_UI_EFFECT_TYPE);
}

//=============================================================================
// [Draw] �`�揈��
//=============================================================================
void CEnergy_UI::Draw(void)
{
    m_pPolygon->Draw();
}
