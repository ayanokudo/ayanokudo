//=============================================================================
//
// �~�T�C���̏��� [missile.cpp]
// Author : AYANO KUDO
//
//=============================================================================
#include "missile.h"
#include "manager.h"
#include "renderer.h"
#include "sound.h"
#include "scene.h"
#include "explosion.h"
#include "game.h"
#include "score.h"
#include "player.h"
#include "option.h"
#include "enemy.h"
#include "terrain.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define MISSILE_SIZE_X (50.0f)     // �~�T�C���̃T�C�Y(x��)
#define MISSILE_SIZE_Y (40.0f)      // �~�T�C���̃T�C�Y(y��)
#define MISSILE_MOVE   D3DXVECTOR3(5.0f,20.0f,0.0f)

//*****************************************************************************
// �ÓI�����o�ϐ�������
//*****************************************************************************
LPDIRECT3DTEXTURE9 CMissile::m_pTexture = NULL;
char *CMissile::m_apTextureName = "data/TEXTURE/missile.png";

//=============================================================================
// [CMissile] �R���X�g���N�^
//=============================================================================
CMissile::CMissile()
{
    SetObjtype(OBJTYPE_BULLET);
    SetPosition(D3DXVECTOR3(100.0f, 100.0f, 100.0f));
    m_pScene = NULL;
    SetSize(D3DXVECTOR3(MISSILE_SIZE_X, MISSILE_SIZE_Y,0.0f));
}

//=============================================================================
// [~CMissile] �f�X�g���N�^
//=============================================================================
CMissile::~CMissile()
{
}

//=============================================================================
// [Create] �I�u�W�F�N�g�̐���
//=============================================================================
CMissile *CMissile::Create(D3DXVECTOR3 pos, CScene* pScene)
{
    CMissile *pMissile = NULL;

    if (pMissile==NULL)
    {
        pMissile = new CMissile;
        pMissile->Init(pos, pScene);
    }
    return pMissile;
}

//=============================================================================
// [Load] �e�N�X�`���̓ǂݍ���
//=============================================================================
HRESULT CMissile::Load(void)
{
    // �f�o�C�X�̎擾
    LPDIRECT3DDEVICE9 pDevice;
    pDevice = CManager::GetRenderer()->GetDevice();

    // �e�N�X�`���̐���
    D3DXCreateTextureFromFile(pDevice, m_apTextureName, &m_pTexture);
    return S_OK;
}

//=============================================================================
// [Unload] �e�N�X�`���̔j��
//=============================================================================
void CMissile::Unload(void)
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
HRESULT CMissile::Init(D3DXVECTOR3 pos, CScene* pScene)
{
    // �e�����o�ϐ�������
    SetPosition(pos);
    CScene2D::Init();
    m_pScene = pScene;
    // �e�N�X�`���̊��蓖��
    BindTexture(m_pTexture);

    return S_OK;
}

//=============================================================================
// [Uninit] �I������
//=============================================================================
void CMissile::Uninit(void)
{
    // �~�T�C���̃J�E���g�����炷
    if (m_pScene->GetObjectType() == CScene::OBJTYPE_PLAYER)
    {
        int nCntMissile = ((CPlayer*)m_pScene)->GetCountMissile();
        nCntMissile--;
        ((CPlayer*)m_pScene)->SetCountMissile(nCntMissile);
    }

    if (m_pScene->GetObjectType() == CScene::OBJTYPE_OPTION)
    {
        int nCntMissile = ((COption*)m_pScene)->GetCountMissile();
        nCntMissile--;
        ((COption*)m_pScene)->SetCountMissile(nCntMissile);
    }
    CScene2D::Uninit();
}

//=============================================================================
// [Update] �X�V����
//=============================================================================
void CMissile::Update(void)
{
    // �e�̈ړ�
    D3DXVECTOR3 pos = GetPosition();
    pos += MISSILE_MOVE;


    // ��ʊO�ɏo����폜
    if (pos.x < 0.0f + MISSILE_SIZE_X / 2 ||
        pos.x > SCREEN_WIDTH - MISSILE_SIZE_X / 2 ||
        pos.y < 0.0f + MISSILE_SIZE_Y / 2 ||
        pos.y > SCREEN_HEIGHT - MISSILE_SIZE_Y / 2
        )
    {
        Uninit();
        return;
    }

    //�G�Ƃ̓����蔻��
    CScene *pScene = JudgeFittingRectangle(CScene::OBJTYPE_ENEMY);
    if (pScene)
    {
        ((CEnemy*)pScene)->Damage();
        pScene = NULL;
        Uninit();
        return;
    }
    // �n�`�ɓ����������͒n�`�ɉ����Ĉړ�
    pScene = NULL;
     pScene = JudgeFittingRectangle(CScene::OBJTYPE_TERRAIN);
    if (pScene)
    {   
        pos.x += 10.0f;
        pos.y = ((CScene2D*)pScene)->GetPosition().y - TERRAIN_SIZE_Y / 2;
    }
    SetPosition(pos);
    CScene2D::Update();
}

//=============================================================================
// [Draw] �`�揈��
//=============================================================================
void CMissile::Draw(void)
{
    // �|���S���̕`��
    CScene2D::Draw();
}
