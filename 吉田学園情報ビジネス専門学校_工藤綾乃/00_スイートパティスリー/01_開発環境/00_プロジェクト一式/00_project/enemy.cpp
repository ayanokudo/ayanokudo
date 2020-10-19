//=============================================================================
//
// �G�̏��� [enemy.cpp]
// Author : AYANO KUDO
//
//=============================================================================
#include "enemy.h"
#include "manager.h"
#include "renderer.h"
#include "Item.h"
#include "sound.h"
#include "score.h"
#include "game.h"
#include "explosion.h"
#include "player.h"
#include "bullet.h"
#include "particle_effect.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define ENEMY_SIZE_X    (60.0f)

#define ENEMY_DAMAGE_INTARVAL   (30)     // �_���[�W��Ԃɂ��鎞��
#define ENEMY_FLASHING_INTERVAL (6)      // �_���[�W��Ԃ̎��ɓ_�ł�����Ԋu

#define ENEMY_EFFECT_POS                 GetPosition()      // �O�ՃG�t�F�N�g�̏o���ʒu�̐ݒ�
#define ENEMY_EFFECT_MOVE                D3DXVECTOR3( 5.0f, 5.0f, 0.0f )    // �O�ՃG�t�F�N�g�̈ړ��ʂ̐ݒ�
#define ENEMY_EFFECT_FREDUCTION_MOVE     D3DXVECTOR3( rand()%1 / 10.0f, -rand() % 1 / 10.0f, 0.0f )  // �O�ՃG�t�F�N�g�̈ړ������ʂ̐ݒ�
#define ENEMY_EFFECT_COLOR               D3DXCOLOR( 1.0f, 1.0f, 1.0f, 1.0 )                          // �O�ՃG�t�F�N�g�̐F�̐ݒ�
#define ENEMY_EFFECT_SIZE                (30.0f)                                                     // �O�ՃG�t�F�N�g�̃T�C�Y�̐ݒ�
#define ENEMY_EFFECT_FREDUCTION_SIZE    (1.5f)                                                        // �O�ՃG�t�F�N�g�̃T�C�Y�̌�����
#define ENEMY_EFFECT_FREDUCTION_ALPHA    (0.0f)                                                      // �O�ՃG�t�F�N�g�̃A���t�@�l�����ʂ̐ݒ�
#define ENEMY_EFFECT_TYPE                CParticle_Effect::PARTICLE_TYPE_COOKIE                      // �O�ՃG�t�F�N�g�̃^�C�v

//*****************************************************************************
// �ÓI�����o�ϐ�������
//*****************************************************************************
LPDIRECT3DTEXTURE9 CEnemy::m_pTexture = {};
char* CEnemy::m_apTextureName = {
    "data/TEXTURE/enemy000.png"
};

//=============================================================================
// [CEnemy] �R���X�g���N�^
//=============================================================================
CEnemy::CEnemy()
{
    SetObjtype(OBJTYPE_ENEMY);
    SetSize(D3DXVECTOR3(ENEMY_SIZE_X, ENEMY_SIZE_Y,0.0f));
    m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
    m_nLife=1;
    m_State = STATE_NORMAL;
    m_nCntLaserInterval = 0;
    m_bIsBoss = false;
}

//=============================================================================
// [~CEnemy] �f�X�g���N�^
//=============================================================================
CEnemy::~CEnemy()
{

}

//=============================================================================
// [Create] �I�u�W�F�N�g�̐���
//=============================================================================
CEnemy * CEnemy::Create(void)
{
    // �ϐ��錾
    CEnemy *pEnemy = NULL;
    if (pEnemy == NULL)
    {
        // �������̊m��
        pEnemy = new CEnemy();
        pEnemy->Init();
    }
    return pEnemy;
}

//=============================================================================
// [Load] �e�N�X�`���̓ǂݍ���
//=============================================================================
HRESULT CEnemy::Load(void)
{
    // �f�o�C�X�̎擾
    LPDIRECT3DDEVICE9 pDevice;
    pDevice = CManager::GetRenderer()->GetDevice();

    D3DXCreateTextureFromFile(pDevice, m_apTextureName, &m_pTexture);
    return S_OK;
}

//=============================================================================
// [UnLoad] �e�N�X�`���̔j��
//=============================================================================
void CEnemy::Unload(void)
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
HRESULT CEnemy::Init(void)
{
    // �e�����o�ϐ�������

    CScene2D::Init();

    // �e�N�X�`���̊��蓖��
    BindTexture(m_pTexture);

    return S_OK;
}

//=============================================================================
// [Uninit] �I������
//=============================================================================
void CEnemy::Uninit(void)
{
    CScene2D::Uninit();
}

//=============================================================================
// [Update] �X�V����
//=============================================================================
void CEnemy::Update(void)
{
    D3DXVECTOR3 pos = GetPosition();
    CScene2D::Update();

    pos += m_move;
    SetPosition(pos);

    m_nCntLaserInterval--;

    // �v���C���[�Ƃ̓����蔻��
    CScene *pScene = JudgeFittingRectangle(CScene::OBJTYPE_PLAYER);
        if (pScene)
        {
            // �v���C���[�Ƀ_���[�W��^����
            ((CPlayer*)pScene)->Damage();
            pScene = NULL;
        }
    if (m_State==STATE_NORMAL)
    {
        // �e�Ƃ̓����蔻��
        pScene = JudgeFittingRectangle(CScene::OBJTYPE_BULLET);
        if (pScene)
        {   //�v���C���[�̒e��������
            if (((CBullet*)pScene)->GetType()==CBullet::TYPE_PLAYER)
            {
            Damage();
            pScene->Uninit();
            pScene = NULL;
            }
        }

    }

    // ��ʊO�ɏo����폜
    if (pos.x <= -1000.0f - ENEMY_SIZE_X / 2 ||
        pos.x >= 3000 ||
        pos.y <= 0.0f - ENEMY_SIZE_Y / 2 ||
        pos.y >= SCREEN_HEIGHT + ENEMY_SIZE_Y / 2
        )
    {
        Uninit();
    }


}

//=============================================================================
// [Draw] �`�揈��
//=============================================================================
void CEnemy::Draw(void)
{
    // �|���S���̕`��
    CScene2D::Draw();
}

//=============================================================================
// [Damage] �_���[�W����
//=============================================================================
void CEnemy::Damage(void)
{
    m_nLife -= 1;

    // ���ʉ���炷
    CSound *pSound = CManager::GetSound();
    pSound->Play(CSound::SOUND_LABEL_SE_004);

    m_State = STATE_DAMAGE; // �_���[�W��Ԃɂ���
    m_nStateCount = ENEMY_DAMAGE_INTARVAL;

    // �G��|������
    if (m_nLife == 0)
    {
        // �ґ��̐����`�F�b�N
        CheckSurvival();

        // �G�t�F�N�g�̐���
        CExplosion::Create(GetPosition());
        CParticle_Effect::SetBom(ENEMY_EFFECT_POS, ENEMY_EFFECT_MOVE, ENEMY_EFFECT_FREDUCTION_MOVE, ENEMY_EFFECT_COLOR, ENEMY_EFFECT_SIZE, ENEMY_EFFECT_FREDUCTION_SIZE, ENEMY_EFFECT_FREDUCTION_ALPHA, ENEMY_EFFECT_TYPE);

        // �X�R�A�̉��Z
        CScore *pScore = CGame::GetScore();
        pScore->SetScore(100);

        if (m_bIsBoss)
        {// �|�ꂽ�G���{�X�̏ꍇ�Q�[���N���A��Ԃɂ���
         // �Q�[���N���A��Ԃɂ���
            CManager::SetClearedGame(true);
        }

        // �G���폜
        Uninit();
    }
}

//=============================================================================
// [CheckSurvival] �ґ��̐����`�F�b�N
//=============================================================================
void CEnemy::CheckSurvival(void)
{
    // ����ԍ���0�ȏ�̂Ƃ�
    if (m_nFormaitionNum>=0)
    {

        int nCntSurvival = 0;   // �ґ��̓G������
        D3DXVECTOR3 pos = GetPosition();
        // �ґ��ԍ��`�F�b�N
        for (int nCount = 0; nCount < MAX_POLYGON; nCount++)
        {
            CScene *pEnemy = GetSceneObject(nCount);
            if (pEnemy != NULL)
            {

                if (pEnemy->GetObjectType() == CScene::OBJTYPE_ENEMY)
                {
                    if (m_nFormaitionNum == ((CEnemy*)pEnemy)->GetFormaitionNum())
                    {// �������ǉ�
                        nCntSurvival++;
                    }
                }
            }
        }

        // ���������G���Ō�̕ґ��̏ꍇ
        if (nCntSurvival == 1)
        {
            // �p���[�A�b�v�A�C�e������
            CItem::Create(pos, D3DXVECTOR3(-2.0f, 0.0f, 0.0f), CItem::TYPE_000 ,false);
        }
    }
}

//=============================================================================
// [CheckState] ���݂̏�Ԃ��m�F
//=============================================================================
void CEnemy::CheckState(void)
{
    // ��Ԃ��m�F
    switch (m_State)
    {
    case STATE_ANGER:    // �{����
            // �J�E���g�����炷
        m_nStateCount--;

        // ��莞�ԂŒʏ��Ԃɖ߂�
        if (m_nStateCount<=0)
        {
            SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
            m_State = STATE_NORMAL;
        }
        break;

    case STATE_DAMAGE:
        // �_���[�W��� : �Ԃ��_��(���̏�Ԃ̂Ƃ��͍U�����󂯂Ȃ�)
        // ��莞�ԂŒʏ��Ԃɖ߂�
        m_nStateCount--;

        if (m_nStateCount% ENEMY_FLASHING_INTERVAL * 2 <= ENEMY_FLASHING_INTERVAL)
        {
            SetColor(D3DXCOLOR(1.0f, 0.5f, 0.5f, 0.3f));
        }
        else
        {
            SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f));
        }
        if (m_nStateCount<=0)
        {
            SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
            m_State = STATE_NORMAL;
        }
        break;

    }
}