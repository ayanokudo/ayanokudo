//=============================================================================
//
// ���[�U�[���� [laser.cpp]
// Author : AYANO KUDO
//
//=============================================================================
#include "laser.h"
#include "manager.h"
#include "renderer.h"
#include "sound.h"
#include "scene.h"
#include "enemy.h"
#include "explosion.h"
#include "game.h"
#include "score.h"
#include "player.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define LASER_SIZE_X (20.0f)     // ���[�U�[�̃T�C�Y(x��)
#define LASER_SIZE_Y (20.0f)      // ���[�U�[�̃T�C�Y(y��)
#define LASER_MOVE   D3DXVECTOR3(20.0f,0.0f,0.0f)
#define LIMIT_LASER_LENGTH (16)     // ���[�U�[�̒����̌��E�l
#define LASER_DAMAGE_INTERVAL (20)  // ���[�U�[���_���[�W��^����Ԋu

//*****************************************************************************
// �ÓI�����o�ϐ�������
//*****************************************************************************
LPDIRECT3DTEXTURE9 CLaser::m_pTexture = NULL;
char *CLaser::m_apTextureName = "data/TEXTURE/cream000.png";

//=============================================================================
// [CLaser] �R���X�g���N�^
//=============================================================================
CLaser::CLaser()
{
    m_nLaserLength = 1;
    SetObjtype(OBJTYPE_BULLET);
    SetPosition(D3DXVECTOR3(100.0f, 100.0f, 100.0f));
    SetSize(D3DXVECTOR3(LASER_SIZE_X, LASER_SIZE_Y,0.0f));

}

//=============================================================================
// [~CLaser] �f�X�g���N�^
//=============================================================================
CLaser::~CLaser()
{
}

//=============================================================================
// [Create] �I�u�W�F�N�g�̐���
//=============================================================================
CLaser *CLaser::Create(D3DXVECTOR3 pos, CScene2D* pScene2D)
{
    CLaser *pLaser = NULL;

    if (!pLaser)
    {
        pLaser = new CLaser;
        pLaser->Init(pos, pScene2D);
    }
    return pLaser;
}

//=============================================================================
// [Load] �e�N�X�`���̓ǂݍ���
//=============================================================================
HRESULT CLaser::Load(void)
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
void CLaser::Unload(void)
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
HRESULT CLaser::Init(D3DXVECTOR3 pos, CScene2D* pScene2D)
{
    // �e�����o�ϐ�������
    SetPosition(pos);
    CScene2D::Init();
    m_pScene2D = pScene2D;
    // �e�N�X�`���̊��蓖��
    BindTexture(m_pTexture);

    return S_OK;
}

//=============================================================================
// [Uninit] �I������
//=============================================================================
void CLaser::Uninit(void)
{
    CScene2D::Uninit();
}

//=============================================================================
// [Update] �X�V����
//=============================================================================
void CLaser::Update(void)
{
    D3DXVECTOR3 pos = GetPosition();
    D3DXVECTOR3 size = GetSize();

    // ���[�U�[�̒������Z���Ƃ�
    if (m_nLaserLength < LIMIT_LASER_LENGTH)
    {
        // ���[�U�[�̒������ő�ɂȂ�܂ŒǏ]
        D3DXVECTOR3 pObjpos = m_pScene2D->GetPosition();
        pos = D3DXVECTOR3(pObjpos.x+ size.x / 2, pObjpos.y, 0.0f);
        SetPosition(pos);

        // ���[�U�[�����ɐL�΂�
        size += LASER_MOVE;
        SetSize(size);

        // ���[�U�[��L�΂����̂�UV���W�̒���
        m_nLaserLength++;
        SetTexture(D3DXVECTOR2((float)m_nLaserLength, 1.0f));
    }
    else
    {
        // ���[�U�[�̈ړ�
        pos += LASER_MOVE;
        SetPosition(pos);
    }

    CScene2D::Update();

    //�G�Ƃ̓����蔻��
    CScene *pScene = JudgeFittingRectangle(CScene::OBJTYPE_ENEMY);
    if (pScene)
    {
        if (((CEnemy*)pScene)->GetnCntLaserInterval() <= 0)
        {
            ((CEnemy*)pScene)->Damage();
            ((CEnemy*)pScene)->SetCntLaserInterval(LASER_DAMAGE_INTERVAL);
        }

    }

    // ��ʊO�ɏo����폜
    if (pos.x < 0.0f - size.x / 2 ||
        pos.x > SCREEN_WIDTH + size.x / 2 ||
        pos.y < 0.0f - size.y / 2 ||
        pos.y > SCREEN_HEIGHT + size.y / 2
        )
    {
        Uninit();
        return;
    }
}

//=============================================================================
// [Draw] �`�揈��
//=============================================================================
void CLaser::Draw(void)
{
    // �|���S���̕`��
    CScene2D::Draw();
}
