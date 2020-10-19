//=============================================================================
//
// �e�̏��� [bullet.cpp]
// Author : AYANO KUDO
//
//=============================================================================
#include "bullet.h"
#include "manager.h"
#include "renderer.h"
#include "score.h"
#include "game.h"
#include "enemy.h"
#include "player.h"
#include "option.h"
#include "particle_effect.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define BULLET_SIZE_X (15.0f)                           // �e�̉��̑傫��
#define BULLET_SIZE_Y (15.0f)                           // �e�̏c�̑傫��
#define RIMIT_PLAYER_BULLET (2)                         // �v���C���[�̓����ɏo����e�̐�
#define BULLET_MOVE D3DXVECTOR3(20.0f,0.0f,0.0f)        // �e�̈ړ���

#define BULLET_EFFECT_POS               D3DXVECTOR3(pos.x,pos.y,0.0f)                            // �O�ՃG�t�F�N�g�̏o���ʒu�̐ݒ�
#define BULLET_EFFECT_MOVE              D3DXVECTOR3(4.0f, 0.0f, 0.0f)                            // �O�ՃG�t�F�N�g�̈ړ��ʂ̐ݒ�
#define BULLET_EFFECT_FREDUCTION_MOVE   D3DXVECTOR3(1.0f, 0.0f, 0.0f)                            // �O�ՃG�t�F�N�g�̈ړ������ʂ̐ݒ�
#define BULLET_EFFECT_COLOR             D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5)                         // �O�ՃG�t�F�N�g�̐F�̐ݒ�
#define BULLET_EFFECT_SIZE              (35.0f)                                                  // �O�ՃG�t�F�N�g�̃T�C�Y�̐ݒ�
#define BULLET_EFFECT_FREDUCTION_SIZE   (1.0f)                                                   // �O�ՃG�t�F�N�g�̃T�C�Y�̌�����
#define BULLET_EFFECT_FREDUCTION_ALPHA  (0.05f)                                                  // �O�ՃG�t�F�N�g�̃A���t�@�l�����ʂ̐ݒ�
#define BULLET_EFFECT_TYPE              CParticle_Effect::PARTICLE_TYPE_CIRCLE

//*****************************************************************************
// �ÓI�����o�ϐ�������
//*****************************************************************************
LPDIRECT3DTEXTURE9 CBullet::m_apTexture[TYPE_MAX] = {};
char *CBullet::m_apTextureName[TYPE_MAX] = {
    "data/TEXTURE/bullet001.png",
    "data/TEXTURE/enemy000.png"
};
//=============================================================================
// [CBullet] �R���X�g���N�^
//=============================================================================
CBullet::CBullet()
{
    m_nLife = 50;
    SetObjtype(OBJTYPE_BULLET);
    SetPosition(D3DXVECTOR3(100.0f, 100.0f, 100.0f));
    SetSize(D3DXVECTOR3(BULLET_SIZE_X, BULLET_SIZE_Y,0.0f));
}

//=============================================================================
// [~CBullet] �f�X�g���N�^
//=============================================================================
CBullet::~CBullet()
{

}

//=============================================================================
// [Create] �I�u�W�F�N�g�̐���
//=============================================================================
CBullet *CBullet::Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, TYPE type, CScene* pScene)
{
    // �ϐ��錾
    CBullet *pBullet;

    // �������̊m��
    pBullet = new CBullet;

    // ����������
    pBullet->Init(pos, move,type, pScene);


    return pBullet;
}

//=============================================================================
// [Load] �e�N�X�`���̓ǂݍ���
//=============================================================================
HRESULT CBullet::Load(void)
{
    // �f�o�C�X�̎擾
    LPDIRECT3DDEVICE9 pDevice;
    pDevice = CManager::GetRenderer()->GetDevice();

    for (int nCount = 0; nCount < TYPE_MAX; nCount++)
    {
        // �e�N�X�`���̐���
        D3DXCreateTextureFromFile(pDevice, m_apTextureName[nCount], &m_apTexture[nCount]);
    }
    return S_OK;
}

//=============================================================================
// [Unload] �e�N�X�`���̔j��
//=============================================================================
void CBullet::Unload(void)
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
HRESULT CBullet::Init(D3DXVECTOR3 pos, D3DXVECTOR3 move, TYPE type, CScene* pScene)
{
    // �e�����o�ϐ�������
    SetPosition(pos);
    m_move = move;
    m_type = type;
    m_pScene = pScene;
    CScene2D::Init();
    // �e�N�X�`���̊��蓖��
    BindTexture(m_apTexture[type]);

    return S_OK;
}

//=============================================================================
// [Uninit] �I������
//=============================================================================
void CBullet::Uninit(void)
{
    // �v���C���[���̒e�����Ă�悤�ɂ���
    if (m_pScene != NULL)
    {
        if (m_pScene->GetObjectType() == CScene::OBJTYPE_PLAYER)
        {
            int nCntBullet = ((CPlayer*)m_pScene)->GetCountBullet();
                nCntBullet--;
            ((CPlayer*)m_pScene)->SetCountBullet(nCntBullet);
        }

        if (m_pScene->GetObjectType() == CScene::OBJTYPE_OPTION)
        {
            int nCntBullet = ((COption*)m_pScene)->GetCountBullet();
            nCntBullet--;
            ((COption*)m_pScene)->SetCountBullet(nCntBullet);
        }
        m_pScene = NULL;
    }

    CScene2D::Uninit();
}

//=============================================================================
// [Update] �X�V����
//=============================================================================
void CBullet::Update(void)
{
    // �e�̈ړ�
    D3DXVECTOR3 pos = GetPosition();
    pos += m_move;
    SetPosition(pos);

    CScene2D::Update();

    // ��ʊO�ɏo����폜
    if (pos.x < 0.0f + BULLET_SIZE_X / 2 ||
        pos.x > SCREEN_WIDTH - BULLET_SIZE_X / 2 ||
        pos.y < 0.0f + BULLET_SIZE_Y / 2 ||
        pos.y > SCREEN_HEIGHT - BULLET_SIZE_Y / 2
        )
    {
        Uninit();
        return;
    }

    // �O�ՃG�t�F�N�g
    CParticle_Effect::SetTrajectory(BULLET_EFFECT_POS,BULLET_EFFECT_MOVE, BULLET_EFFECT_FREDUCTION_MOVE, BULLET_EFFECT_COLOR, BULLET_EFFECT_SIZE, BULLET_EFFECT_FREDUCTION_SIZE, BULLET_EFFECT_FREDUCTION_ALPHA, BULLET_EFFECT_TYPE);

    //�n�`�Ƃ̓����蔻��
    CScene *pScene = JudgeFittingRectangle(CScene::OBJTYPE_TERRAIN);
    if (pScene)
    {
        Uninit();
        pScene = NULL;
        return;
    }

}

//=============================================================================
// [Draw] �`�揈��
//=============================================================================
void CBullet::Draw(void)
{
    // �|���S���̕`��
    CScene2D::Draw();
}