//=============================================================================
//
// �G�̏��� [boss.cpp]
// Author : AYANO KUDO
//
//=============================================================================
#include "boss.h"
#include "manager.h"
#include "renderer.h"
#include "game.h"
#include "enemy_type3.h"
#include "terrain.h"
#include "sound.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define BOSS_LIFE   (40)            // �{�X�̗̑�
#define BOSS_SIZE_X (170)           // �{�X�̑傫��
#define BOSS_SIZE_Y (250)           // �{�X�̑傫��

#define BOSS_ENEMY_LENGTH (150.0f)  // �{�X�̎���̓G�̒���
#define BOSS_ENEMY_ROT    (0.05f)   // �{�X�̎���̓G�̉�]���x

//*****************************************************************************
// �ÓI�����o�ϐ�������
//*****************************************************************************
LPDIRECT3DTEXTURE9 CBoss::m_pTexture = NULL;
char* CBoss::m_pTextureName = "data/TEXTURE/boss000.png";
CEnemy_Type3 *CBoss::m_pEnemy[MAX_BOSS_ENEMY] = {};

//=============================================================================
// [CBoss] �R���X�g���N�^
//=============================================================================
CBoss::CBoss()
{
    SetIsBoss(true);
    SetLife(BOSS_LIFE);
    SetSize(D3DXVECTOR3(BOSS_SIZE_X, BOSS_SIZE_Y, 0.0f));
    SetMove(D3DXVECTOR3(-4.0f, 0.0f, 0.0f));

    for (int nCountEnemy = 0; nCountEnemy < MAX_BOSS_ENEMY; nCountEnemy++)
    {
        m_pEnemy[nCountEnemy] = NULL;
    }

}

//=============================================================================
// [~CBoss] �f�X�g���N�^
//=============================================================================
CBoss::~CBoss()
{
}

//=============================================================================
// [Create] �I�u�W�F�N�g�̐���
//=============================================================================
CBoss * CBoss::Create(D3DXVECTOR3 pos)
{
    // �ϐ��錾
    CBoss *pBoss = NULL;
    if (pBoss == NULL)
    {
        // �������̊m��
        pBoss = new CBoss();
        pBoss->Init( pos);
    }
    return pBoss;
}

//=============================================================================
// [Load] �e�N�X�`���̓ǂݍ���
//=============================================================================
HRESULT CBoss::Load(void)
{
    // �f�o�C�X�̎擾
    LPDIRECT3DDEVICE9 pDevice;
    pDevice = CManager::GetRenderer()->GetDevice();

    D3DXCreateTextureFromFile(pDevice, m_pTextureName, &m_pTexture);

    // �e�N�X�`���̐���
    return S_OK;
}

//=============================================================================
// [UnLoad] �e�N�X�`���̔j��
//=============================================================================
void CBoss::Unload(void)
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
HRESULT CBoss::Init(D3DXVECTOR3 pos)
{
    // �ϐ��錾
    CSound *pSound = CManager::GetSound();
    SetPosition(pos);
    CEnemy::Init();
    // �e�N�X�`���̊��蓖��
    BindTexture(m_pTexture);

    CTerrain::SetMove(D3DXVECTOR3(0.0f, 0.0f, 0.0f));// �n�`�̃X�N���[�����~
    pSound->Stop();
    pSound->Play(CSound::SOUND_LABEL_BGM003);

    return S_OK;
}

//=============================================================================
// [Uninit] �I������
//=============================================================================
void CBoss::Uninit(void)
{
    // �ϐ��錾
    // �{�X���|�ꂽ�烊�U���g��ʂ֑J�ڂ���
    CGame::SetState(CGame::STATE_END);// �Q�[���I��
    for (int nCountEnemy = 0; nCountEnemy < MAX_BOSS_ENEMY; nCountEnemy++)
    {
        if (m_pEnemy[nCountEnemy]!=NULL)
        {
            m_pEnemy[nCountEnemy]->Uninit();
            m_pEnemy[nCountEnemy] = NULL;

        }
    }

    CEnemy::Uninit();
}

//=============================================================================
// [Update] �X�V����
//=============================================================================
void CBoss::Update(void)
{
    D3DXVECTOR3 pos = GetPosition();
    CEnemy::CheckState();
    if (pos.x < 800)
    {
        SetMove(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
    }

    CEnemy::Update();
    for (int nCountEnemy = 0; nCountEnemy < MAX_BOSS_ENEMY; nCountEnemy++)
    {
        if (m_pEnemy[nCountEnemy]==NULL)
        {
            m_pEnemy[nCountEnemy] = CEnemy_Type3::Create(pos,(float)nCountEnemy);
        }
        else
        {
            m_pEnemy[nCountEnemy]->Rotation(pos, BOSS_ENEMY_LENGTH, BOSS_ENEMY_ROT);
        }
    }
}

//=============================================================================
// [Draw] �`�揈��
//=============================================================================
void CBoss::Draw(void)
{
    CEnemy::Draw();
}