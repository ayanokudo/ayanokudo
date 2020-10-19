//=============================================================================
//
// �A�C�e���̏��� [game.h]
// Author : AYANO KUDO
//
//=============================================================================
#include "Item.h"
#include "manager.h"
#include "renderer.h"
#include "player.h"
#include "score.h"
#include "game.h"
#include "sound.h"
#include "particle_effect.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define ITEM_000_FILE_NAME "data/TEXTURE/item000.png"       // �p���[�A�b�v�A�C�e���̃t�@�C����
#define ITEM_000_SIZE_X    (60.0f)                           // �p���[�A�b�v�A�C�e���̑傫��(x��)
#define ITEM_000_SIZE_Y    (60.0f)                           // �p���[�A�b�v�A�C�e���̑傫��(y��)

#define ITEM_001_FILE_NAME "data/TEXTURE/item001.png"        // �G�l���M�[�񕜃A�C�e���̃t�@�C����
#define ITEM_001_SIZE_X    (16.0f)                           // �G�l���M�[�񕜃A�C�e���A�C�e���̑傫��(x��)
#define ITEM_001_SIZE_Y    (64.0f)                           // �G�l���M�[�񕜃A�C�e���A�C�e���̑傫��(y��)
#define LIFEUP (MAX_ENERGY / 10)                             // �̗͂̉񕜗�

// �G�t�F�N�g�̐ݒ�
#define ITEM_001_EFFECT_POS              D3DXVECTOR3( pos.x , pos.y -ITEM_001_SIZE_Y / 2,0.0f )         // �O�ՃG�t�F�N�g�̏o���ʒu�̐ݒ�
#define ITEM_001_EFFECT_FLIP_POS         D3DXVECTOR3( pos.x , pos.y +ITEM_001_SIZE_Y / 2,0.0f )    // �O�ՃG�t�F�N�g�̏o���ʒu�̐ݒ�(���]��)

#define ITEM_001_EFFECT_MOVE             D3DXVECTOR3( rand() %  1 + 1, -(rand() % 10 + 1), 0.0f )    // �O�ՃG�t�F�N�g�̈ړ��ʂ̐ݒ�
#define ITEM_001_EFFECT_FLIP_MOVE        D3DXVECTOR3( rand() %  1 + 1, (rand() % 10 + 1), 0.0f )    // �O�ՃG�t�F�N�g�̈ړ��ʂ̐ݒ�

#define ITEM_001_EFFECT_FREDUCTION_MOVE  D3DXVECTOR3( rand()%1 / 10.0f, -rand() % 5 / 10.0f, 0.0f )  // �O�ՃG�t�F�N�g�̈ړ������ʂ̐ݒ�
#define ITEM_001_EFFECT_COLOR            D3DXCOLOR( 1.0f, 0.3f, 0.1f, 1.0 )                          // �O�ՃG�t�F�N�g�̐F�̐ݒ�
#define ITEM_001_EFFECT_SIZE             (30.0f)                                                     // �O�ՃG�t�F�N�g�̃T�C�Y�̐ݒ�
#define ITEM_001_UI_EFFECT_FREDUCTION_SIZE    (0.00f)                                                // �O�ՃG�t�F�N�g�̃T�C�Y�̌�����
#define ITEM_001_EFFECT_FREDUCTION_ALPHA (0.2f)                                                      // �O�ՃG�t�F�N�g�̃A���t�@�l�����ʂ̐ݒ�
#define ITEM_001_EFFECT_TYPE             CParticle_Effect::PARTICLE_TYPE_CIRCLE                      // �O�ՃG�t�F�N�g�̃^�C�v

//*****************************************************************************
// �ÓI�����o�ϐ�
//*****************************************************************************
LPDIRECT3DTEXTURE9 CItem::m_apTexture[TYPE_MAX] = {};

// �A�C�e���̏��
CItem::ITEM_DATA CItem::m_aItemData[TYPE_MAX] = {
    { ITEM_000_FILE_NAME , D3DXVECTOR3(ITEM_000_SIZE_X,ITEM_000_SIZE_Y,0.0f) },
    { ITEM_001_FILE_NAME , D3DXVECTOR3(ITEM_001_SIZE_X,ITEM_001_SIZE_Y,0.0f) }
};

//=============================================================================
// [CItem] �R���X�g���N�^
//=============================================================================
CItem::CItem()
{
    SetObjtype(OBJTYPE_ITEM);
    m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}

//=============================================================================
// [~CItem] �f�X�g���N�^
//=============================================================================
CItem::~CItem()
{
}

//=============================================================================
// [Create] �I�u�W�F�N�g�̐���
//=============================================================================
CItem * CItem::Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, TYPE type, bool bIsFlip)
{
    CItem *pItem = NULL;
    if (!pItem)
    {
        pItem = new CItem;
        pItem->Init(pos, move, type, bIsFlip);
    }

    return pItem;
}

//=============================================================================
// [Load] �e�N�X�`���̓ǂݍ���
//=============================================================================
HRESULT CItem::Load(void)
{
    // �f�o�C�X�̎擾�@
    LPDIRECT3DDEVICE9 pDevice;
    pDevice = CManager::GetRenderer()->GetDevice();
    for (int nCount = 0; nCount < TYPE_MAX; nCount++)
    {
        // �e�N�X�`���̐���
        D3DXCreateTextureFromFile(pDevice, m_aItemData[nCount].pTextureName, &m_apTexture[nCount]);
    }
    return S_OK;
}

//=============================================================================
// [UnLoad] �e�N�X�`���̔j��
//=============================================================================
void CItem::Unload(void)
{
    for (int nCount = 0; nCount < TYPE_MAX; nCount++)
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
// [Init] ����������
//=============================================================================
HRESULT CItem::Init(D3DXVECTOR3 pos, D3DXVECTOR3 move, TYPE type, bool bIsFlip)
{
    // �e�����o�ϐ�������
    SetPosition(pos);
    m_move = move;
     m_type = type;    // �^�C�v�̐ݒ�
     m_bIsFlip = bIsFlip;
    SetSize(D3DXVECTOR3(m_aItemData[m_type].size.x, m_aItemData[m_type].size.y, 0.0f));
    CScene2D::Init();

    // �e�N�X�`���̊��蓖��
    BindTexture(m_apTexture[m_type]);

    return S_OK;
}

//=============================================================================
// [Uninit] �I������
//=============================================================================
void CItem::Uninit(void)
{
    CScene2D::Uninit();
}

//=============================================================================
// [Update] �X�V����
//=============================================================================
void CItem::Update(void)
{
    // �ʒu�̍X�V
    D3DXVECTOR3 pos = GetPosition();
    pos += m_move;
    SetPosition(pos);

    CScene2D::Update();

    //���@�Ƃ̓����蔻��

    switch (m_type)
    {
        // �p���[�A�b�v�̏���
    case TYPE_000:
        PowerUp();
        break;
    case TYPE_001:
        // ���E�\�N�̏���
        RecoverEnergy();
        break;
    }
}

//=============================================================================
// [Draw] �`�揈��
//=============================================================================
void CItem::Draw(void)
{
     CScene2D::Draw();
}

//=============================================================================
// [PowerUp] �p���[�A�b�v����
//=============================================================================
void CItem::PowerUp(void)
{
    CScene *pScene = JudgeFittingRectangle(CScene::OBJTYPE_PLAYER);
    if (pScene)
    {
        // �X�R�A�ǉ�
        CScore *pScore = CGame::GetScore();
        pScore->SetScore(100);

        // SE��炷
        CSound *pSound = CManager::GetSound();
        pSound->Play(CSound::SOUND_LABEL_SE_007);

        // �p���[�A�b�v���e�����炷
        int nPowUp = ((CPlayer*)pScene)->GetPowerUp() + 1;
        ((CPlayer*)pScene)->SetPowerUp((CPlayer::POWERUP)nPowUp);
        Uninit();
    }
}

//=============================================================================
// [EnergyHealing] �G�l���M�[�̉񕜏���
//=============================================================================
void CItem::RecoverEnergy(void)
{
    D3DXVECTOR3 pos = GetPosition();
    pos += m_move;
    // �O�ՃG�t�F�N�g
    if (m_bIsFlip)
    {// �㉺���]���|���S���̉��ɃG�t�F�N�g�\��
         CParticle_Effect::SetTrajectory(ITEM_001_EFFECT_FLIP_POS, ITEM_001_EFFECT_FLIP_MOVE, ITEM_001_EFFECT_FREDUCTION_MOVE, ITEM_001_EFFECT_COLOR, ITEM_001_EFFECT_SIZE, ITEM_001_UI_EFFECT_FREDUCTION_SIZE, ITEM_001_EFFECT_FREDUCTION_ALPHA, ITEM_001_EFFECT_TYPE);

    }
    else
    {
        CParticle_Effect::SetTrajectory(ITEM_001_EFFECT_POS, ITEM_001_EFFECT_MOVE, ITEM_001_EFFECT_FREDUCTION_MOVE, ITEM_001_EFFECT_COLOR, ITEM_001_EFFECT_SIZE, ITEM_001_UI_EFFECT_FREDUCTION_SIZE, ITEM_001_EFFECT_FREDUCTION_ALPHA, ITEM_001_EFFECT_TYPE);
    }

    // �v���C���[�Ɠ���������v���C���[�̃G�l���M�[����
    CPlayer *pPlayer = CGame::GetPlayer();
    CScene *pScene = JudgeFittingRectangle(CScene::OBJTYPE_PLAYER);
    if (pScene)
    {
        int nEnergy = pPlayer->GetEnergy();
        nEnergy += LIFEUP;

        pPlayer->SetEnergy(nEnergy);

        Uninit();

        // SE��炷
        CSound *pSound = CManager::GetSound();
        pSound->Play(CSound::SOUND_LABEL_SE_007);
    }
}
