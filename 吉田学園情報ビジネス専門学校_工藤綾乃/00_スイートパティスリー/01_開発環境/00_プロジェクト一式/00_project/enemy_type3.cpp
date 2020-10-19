//=============================================================================
//
// �{�X�̎���̓G�̏��� [enemy_type3.cpp]
// Author : AYANO KUDO
//
//=============================================================================
#include "enemy_type3.h"
#include "renderer.h"
#include "manager.h"
#include "bullet.h"
#include "game.h"
#include "player.h"

//*****************************************************************************
// �ÓI�����o�ϐ�������
//*****************************************************************************
#define ENEMY_BALLET_INTARVAL (180)    // �G���e���o���Ԋu
#define ENEMY_BALLET_SPEED    (7.0f)   // �G���o���e�̑��x

//*****************************************************************************
// �ÓI�����o�ϐ�������
//*****************************************************************************
LPDIRECT3DTEXTURE9 CEnemy_Type3::m_pTexture     = NULL;                           // �e�N�X�`���ւ̃|�C���^
char*              CEnemy_Type3::m_pTextureName = "data/TEXTURE/enemy002.png";    // �e�N�X�`���̃t�@�C����

//=============================================================================
// [CEnemy_Type3] �R���X�g���N�^
//=============================================================================
CEnemy_Type3::CEnemy_Type3()
{
    // �e�ϐ��̏�����
    m_fAngle = 0.0f;
    SetLife(-1);// type3�͕s���g ���炩���ߑ̗͂�0�ȉ��ɂ���Ǝ��ȂȂ�
}

//=============================================================================
// [~CEnemy_Type3] �f�X�g���N�^
//=============================================================================
CEnemy_Type3::~CEnemy_Type3()
{
}

//=============================================================================
// [Create] �I�u�W�F�N�g�̐���
// �Ԃ�l : �m�ۂ����������ւ̃|�C���^��Ԃ�
//=============================================================================
CEnemy_Type3 * CEnemy_Type3::Create(D3DXVECTOR3 pos, float fAngle)
{
    CEnemy_Type3* pEnemyType3 = NULL;
    if (pEnemyType3 == NULL)
    {
        pEnemyType3 = new CEnemy_Type3;
        pEnemyType3->Init(pos, fAngle);
    }
    return pEnemyType3;
}

//=============================================================================
// [Load] �e�N�X�`���̓ǂݍ���
//=============================================================================
HRESULT CEnemy_Type3::Load(void)
{
    // �f�o�C�X�̎擾
    LPDIRECT3DDEVICE9 pDevice;
    pDevice = CManager::GetRenderer()->GetDevice();
    D3DXCreateTextureFromFile(pDevice, m_pTextureName, &m_pTexture);
    return S_OK;
}

//=============================================================================
// [UnLoad] �e�N�X�`���̔j��
//=============================================================================
void CEnemy_Type3::Unload(void)
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
// ����
// pos    : �ʒu
// fAngle : �p�x
//=============================================================================
HRESULT CEnemy_Type3::Init(D3DXVECTOR3 pos,float fAngle)
{
    SetPosition(pos);
    m_fAngle = fAngle;
    CEnemy::Init();

    // �e�N�X�`���̊��蓖��
    BindTexture(m_pTexture);
    return S_OK;
}

//=============================================================================
// [Uninit] �I������
//=============================================================================
void CEnemy_Type3::Uninit(void)
{
    CEnemy::Uninit();
}

//=============================================================================
// [Update] �X�V����
//=============================================================================
void CEnemy_Type3::Update(void)
{
    CEnemy::Update();

    // ���̃^�C�~���O�Ńv���C���[�̕����ɒe�𔭎�
    if (rand() % ENEMY_BALLET_INTARVAL == 0)
    {
        ShootBullet();
    }

}

//=============================================================================
// [Draw] �`�揈��
//=============================================================================
void CEnemy_Type3::Draw(void)
{
    CEnemy::Draw();
}


//=============================================================================
// [ShootBullet] �e�̔���
//=============================================================================
void CEnemy_Type3::ShootBullet(void)
{
    // �ϐ��錾
    D3DXVECTOR3 pos       = GetPosition();                        // �ʒu
    D3DXVECTOR3 PlayerPos = CGame::GetPlayer()->GetPosition();    // �v���C���[�̈ʒu(�ڕW���W)
    D3DXVECTOR3 move;                                             // �ړ���

    // �e�̔��ˊp�x���v�Z
    float fRadian;      // �p�x

    // �ڕW�܂ł̊p�x�����߂�
    fRadian = atan2f(PlayerPos.y - pos.y, PlayerPos.x - pos.x);

    move = D3DXVECTOR3(cosf(fRadian) * ENEMY_BALLET_SPEED,sinf(fRadian) * ENEMY_BALLET_SPEED,0.0f);
    // �v���C���[�̈ʒu�Ɍ������Ēe�𔭎�
    CBullet::Create(GetPosition(), move, CBullet::TYPE_ENEMY, this);
}

//=============================================================================
// ��ʒu�𒆐S�ɉ�]
// pos : ��]�̒��S�ʒu
// fLength : ���S�ʒu����̒���
// fRot : ��]������p�x
//=============================================================================
void CEnemy_Type3::Rotation(D3DXVECTOR3 pos, float fLength, float fRot)
{
    D3DXVECTOR3 enemyPos = GetPosition();
    // �p�x�̍X�V
    m_fAngle += fRot;
    // ��]������
    enemyPos.x = pos.x + fLength * cosf(m_fAngle);
    enemyPos.y = pos.y + fLength * sinf(m_fAngle);
    enemyPos.z = 0.0f;

    SetPosition(enemyPos);
}