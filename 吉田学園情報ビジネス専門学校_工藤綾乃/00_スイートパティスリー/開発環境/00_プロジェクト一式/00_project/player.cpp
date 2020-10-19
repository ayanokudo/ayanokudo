//=============================================================================
//
// �v���C���[�̏��� [player.cpp]
// Author : AYANO KUDO
//
//=============================================================================
#include "player.h"
#include "game.h"
#include "manager.h"
#include "input.h"
#include "inputkeyboard.h"
#include "inputcontroller.h"
#include "bullet.h"
#include "laser.h"
#include "missile.h"
#include "shield.h"
#include "renderer.h"
#include "bg.h"
#include "sound.h"
#include "explosion.h"
#include "life.h"
#include "triangle_effect.h"
#include "particle_effect.h"
#include "triangle.h"
#include "option.h"
#include "energy_ui.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define TEXTURE_PLAYER "data/TEXTURE/player000.png"     // �v���C���[�̃e�N�X�`����
#define PLAYER_MOVE        (4.0f)                            // �v���C���[�̈ړ���
#define SCROLL_MOVE        (0.0005f)                          // �v���C���[�̓����ɍ��킹�ē����X�N���[���̑��x
#define SCROLL_MOVE_LEFT   (0.0001f)                     // ���ɓ��͂������̃v���C���[�̓����ɍ��킹�ē����X�N���[���̑��x

#define PLAYER_SIZE_X      (60.0f)                           // �v���C���[�̉��̑傫��
#define PLAYER_SIZE_Y      (45.0f)                           // �v���C���[�̏c�̑傫��

#define PLAYER_LIMIT_POS_UP    (150.0f)                                   // �v���C���[�̈ړ��͈�(�����)
#define PLAYER_LIMIT_POS_DOWN  (630.0f)                                    // �v���C���[�̈ړ��͈�(������)
#define PLAYER_LIMIT_POS_RIGHT (SCREEN_WIDTH - PLAYER_SIZE_Y / 2.0f)      // �v���C���[�̈ړ��͈�(������)
#define PLAYER_LIMIT_POS_LEFT  (PLAYER_SIZE_Y / 2.0f)                     // �v���C���[�̈ړ��͈�(�E����)

#define PLAYER_FLASHING_INTERVAL (6)                    // ���G���Ԓ��̓_�ł̊Ԋu
#define LIMIT_SPEED   (5)         // �X�s�[�h�̃p���[�A�b�v���E�l
#define SPEED_MOVE    (2.0f)      // �X�s�[�h�A�b�v�����Ƃ��ɏオ�鑬�x
#define LIMIT_MISSILE (1)         // �~�T�C���̃p���[�A�b�v���E�l

// �G�t�F�N�g�̐ݒ�
#define PLAYER_EFFECT_POS              D3DXVECTOR3(pos.x - PLAYER_SIZE_X / 2,pos.y,0.0f)         // �O�ՃG�t�F�N�g�̏o���ʒu�̐ݒ�
#define PLAYER_EFFECT_MOVE             D3DXVECTOR3(-rand() %  10 + 1, (rand() % 1 + 1), 0.0f)    // �O�ՃG�t�F�N�g�̈ړ��ʂ̐ݒ�
#define PLAYER_EFFECT_FREDUCTION_MOVE  D3DXVECTOR3(-rand()%5 / 10.0f, rand() % 5 / 10.0f, 0.0f)  // �O�ՃG�t�F�N�g�̈ړ������ʂ̐ݒ�
#define PLAYER_EFFECT_COLOR            D3DXCOLOR(1.0f, 0.3f, 0.1f, 1.0)                          // �O�ՃG�t�F�N�g�̐F�̐ݒ�
#define PLAYER_EFFECT_SIZE             ((float)m_nEnergy/70.0f)                                  // �O�ՃG�t�F�N�g�̃T�C�Y�̐ݒ�
#define PLAYER_EFFECT_FREDUCTION_SIZE    (0.00f)                                                 // �O�ՃG�t�F�N�g�̃T�C�Y�̌�����
#define PLAYER_EFFECT_FREDUCTION_ALPHA (0.1f)                                                    // �O�ՃG�t�F�N�g�̃A���t�@�l�����ʂ̐ݒ�
#define PLAYER_EFFECT_TYPE             CParticle_Effect::PARTICLE_TYPE_CIRCLE                    // �O�ՃG�t�F�N�g�̃^�C�v

//*****************************************************************************
// �ÓI�����o�ϐ�������
//*****************************************************************************
LPDIRECT3DTEXTURE9 CPlayer::m_pTexture = NULL;

//=============================================================================
// [CPlayer] �R���X�g���N�^
//=============================================================================
CPlayer::CPlayer()
{
    // �e�l�̏�����
    SetObjtype(CScene::OBJTYPE_PLAYER);
    SetPosition(D3DXVECTOR3(200.0f, 360.0f, 0.0f));
    SetSize(D3DXVECTOR3(PLAYER_SIZE_X, PLAYER_SIZE_Y,0.0f));
    m_pLife = NULL;
    m_powerUp = POWERUP_NONE;
    m_bIsDisplayed = true;
    m_State = PLAYER_STATE_NORMAL;
    m_nEnergy = MAX_ENERGY;
    m_pEnergyUI = NULL;

    // �p���[�A�b�v���e������
    m_shotType = SHOTTYPE_BULLET;
    m_nInterval = BULLET_INTERVAL;
    m_nShotInterval = 0;
    m_nCntBullet = 0;
    m_nIntervalMissile = 0;
    m_nSppedLv = 0;
    m_bHasMissile = false;
    m_nCntMissile = 0;
    m_nOptionLv = 0;
    for (int nCountOption = 0; nCountOption < LIMIT_OPTION; nCountOption++)
    {
        m_pOption[nCountOption] = NULL;
    }
    m_bUsingShield = false;
    m_pShield = NULL;
}

//=============================================================================
// [~CPlayer] �f�X�g���N�^
//=============================================================================
CPlayer::~CPlayer()
{

}

//=============================================================================
// [Create] �I�u�W�F�N�g�̐���
//=============================================================================
CPlayer *CPlayer::Create(void)
{
    // �ϐ��錾
    CPlayer *pPlayer=NULL;
    if (!pPlayer)
    {
    // �������̊m��
    pPlayer = new CPlayer;

    // ����������
    pPlayer->Init();

    }
    return pPlayer;
}

//=============================================================================
// [Load] �e�N�X�`���̓ǂݍ���
//=============================================================================
HRESULT CPlayer::Load(void)
{
    // �f�o�C�X�̎擾�@
    LPDIRECT3DDEVICE9 pDevice;
    pDevice = CManager::GetRenderer()->GetDevice();

    // �e�N�X�`���̐���
    D3DXCreateTextureFromFile(pDevice, TEXTURE_PLAYER, &m_pTexture);
    return S_OK;
}

//=============================================================================
// [Unload] �e�N�X�`���̔j��
//=============================================================================
void CPlayer::Unload(void)
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
HRESULT CPlayer::Init(void)
{
     // �e�����o�ϐ�������
    CScene2D::Init();
    m_nShotInterval = 0;
    m_nLife = MAX_LIFE;
    m_pLife = CLife::Create(m_nLife);
    m_pEnergyUI = CEnergy_UI::Create();
    SetTexture(D3DXVECTOR2(0.0f, 1.0), D3DXVECTOR2(1.0f, 3.0));
    // �e�N�X�`���̊��蓖��
    BindTexture(m_pTexture);
    return S_OK;
}

//=============================================================================
// [Uninit] �I������
//=============================================================================
void CPlayer::Uninit(void)
{
    CScene2D::Uninit();
    if (m_pLife != NULL)
    {
        m_pLife = NULL;
    }
    if (m_pEnergyUI != NULL)
    {
        m_pEnergyUI = NULL;
    }

}

//=============================================================================
// [Update] �X�V����
//=============================================================================
void CPlayer::Update(void)
{
    // �ϐ��錾
    D3DXVECTOR3 pos = GetPosition();
    CInputKeyboard *pInputKeyboard = CManager::GetInputKeyboard();
    CInputController *pInputController = CManager::GetInputController();

    CheckState();// �v���C���[��Ԃ̊m�F

    CScene2D::Update();

    //�v���C���[����ʂɕ\������Ă��鎞
    if (m_bIsDisplayed)
    {
        // �v���C���[�̈ړ�����
        Move();

        // �O�ՃG�t�F�N�g�̐���
        CParticle_Effect::SetTrajectory(PLAYER_EFFECT_POS, PLAYER_EFFECT_MOVE, PLAYER_EFFECT_FREDUCTION_MOVE, PLAYER_EFFECT_COLOR, PLAYER_EFFECT_SIZE, PLAYER_EFFECT_FREDUCTION_SIZE, PLAYER_EFFECT_FREDUCTION_ALPHA, PLAYER_EFFECT_TYPE);

        // �X�y�[�X�L�[or2�{�^���Œe�𔭎�
        if (pInputKeyboard->GetKeyPress(DIK_SPACE) ||
            pInputController->GetConPress(CInputController::BUTTON_2))
        {
            m_nShotInterval++;
            m_nIntervalMissile++;

            //�e�̔���
            if (m_nShotInterval % m_nInterval == 0)
            {
                m_nShotInterval = 0;
                // �V���b�g�̎�ނɂ���Č���������
                switch (m_shotType)
                {
                    // �e(�p���[�A�b�v����)���
                case SHOTTYPE_BULLET:
                    ShootBullet();
                    break;

                    // �e(�_�u��)���
                case SHOTTYPE_DOBLE:
                    ShootDouble();
                    break;
                    // ���[�U�[���
                case SHOTTYPE_LASER:
                    ShootLaser();
                    break;
                }
            }

            //�~�T�C���̔���
            if (m_bHasMissile == true)
            {
                ShootMissile();
            }
        }

        // X�L�[or1�{�^���Ńp���[�A�b�v
        if (pInputKeyboard->GetKeyTrigger(DIK_X) ||
            pInputKeyboard->GetKeyTrigger(DIK_N) ||
            pInputController->GetConTrigger(CInputController::BUTTON_1))
        {
            PowerUp();
        }
        if (m_State == PLAYER_STATE_NORMAL)
        {
            // �G�l���M�[�̌���
            EnergyDown();
            // �G�l���M�[�\��UI�̍X�V
            m_pEnergyUI->Update();

            // �n�`�Ƃ̓����蔻��
            CScene *pScene = JudgeFittingRectangle(CScene::OBJTYPE_TERRAIN);
            if (pScene)
            {
                Damage();
                pScene = NULL;
                return;
            }

            // �e�Ƃ̓����蔻��
            pScene = JudgeFittingRectangle(CScene::OBJTYPE_BULLET);
            if (pScene)
            {   //�v���C���[�̒e��������
                if (((CBullet*)pScene)->GetType() == CBullet::TYPE_ENEMY)
                {
                    Damage();
                    pScene->Uninit();
                    pScene = NULL;
                    return;
                }
            }
        }
    }

    // �f�o�b�O�R�}���h
#if _DEBUG
    DebugCommand();
#endif // _DEBUG

}

//=============================================================================
// [Draw] �`�揈��
//=============================================================================
void CPlayer::Draw(void)
{
    // �|���S���̕`��
    m_pLife->Draw();
    m_pEnergyUI->Draw();
    CScene2D::Draw();
}

//=============================================================================
// [Move] �ړ��̏���
//=============================================================================
void CPlayer::Move(void)
{
    // �ϐ��錾
    D3DXVECTOR3 pos = GetPosition();
    CInputKeyboard*pInputKeyboard = CManager::GetInputKeyboard();
    CInputController *pInputController = CManager::GetInputController();
    D3DXVECTOR2 BgScroll = D3DXVECTOR2(0.0f, 0.0f);
    SetTexture(D3DXVECTOR2(0.0f, 1.0), D3DXVECTOR2(1.0f, 3.0));

    bool bIsMove = false;           // �ړ����Ă��邩�ǂ���

    // ���Ɉړ�����
    if (pInputKeyboard->GetKeyPress(DIK_LEFT) || pInputKeyboard->GetKeyPress(DIK_A) || pInputController->GetConPress(CROSSKEY_LEFT))
    {
        if (pInputKeyboard->GetKeyPress(DIK_UP) ||
            pInputKeyboard->GetKeyPress(DIK_W) ||
            pInputController->GetConPress(CROSSKEY_UP_MAX))
        {// ���Ə�𓯎��ɉ������Ƃ�
            pos.x -= sinf(D3DX_PI / 4) * (PLAYER_MOVE + (m_nSppedLv * SPEED_MOVE));
            pos.y -= cosf(D3DX_PI / 4) * (PLAYER_MOVE + (m_nSppedLv * SPEED_MOVE));
            BgScroll = D3DXVECTOR2(-sinf(D3DX_PI / 4) * SCROLL_MOVE_LEFT, -cosf(D3DX_PI / 4) * SCROLL_MOVE);
            SetTexture(D3DXVECTOR2(0.0f, 0.0), D3DXVECTOR2(1.0f, 3.0));
        }
        else if (pInputKeyboard->GetKeyPress(DIK_DOWN) ||
            pInputKeyboard->GetKeyPress(DIK_S) ||
            pInputController->GetConPress(CROSSKEY_DOWN))
        {//���Ɖ��𓯎��ɉ�������
            pos.x -= sinf(D3DX_PI / 4) * (PLAYER_MOVE + (m_nSppedLv * SPEED_MOVE));
            pos.y += cosf(D3DX_PI / 4) * (PLAYER_MOVE + (m_nSppedLv * SPEED_MOVE));
            BgScroll = D3DXVECTOR2(-sinf(D3DX_PI / 4) * SCROLL_MOVE_LEFT, cosf(D3DX_PI / 4) * SCROLL_MOVE);
            SetTexture(D3DXVECTOR2(0.0f, 2.0f), D3DXVECTOR2(1.0f, 3.0f));
        }
        else
        {	//��������������
            pos.x -= (PLAYER_MOVE + (m_nSppedLv * SPEED_MOVE));//���Ɉړ�
            BgScroll = D3DXVECTOR2(-SCROLL_MOVE_LEFT, 0.0f);
        }
        bIsMove = true;
    }

    // �E�Ɉړ�����
    else if (pInputKeyboard->GetKeyPress(DIK_RIGHT) ||
        pInputKeyboard->GetKeyPress(DIK_D) ||
        pInputController->GetConPress(CROSSKEY_RIGHT))
    {
        if (pInputKeyboard->GetKeyPress(DIK_UP) ||
            pInputKeyboard->GetKeyPress(DIK_W) ||
            pInputController->GetConPress(CROSSKEY_UP_MIN) ||
            pInputController->GetConPress(CROSSKEY_UP_MAX))
        {// �E�Ə�𓯎��ɉ������Ƃ�
            pos.x += sinf(D3DX_PI / 4) * (PLAYER_MOVE + (m_nSppedLv * SPEED_MOVE));
            pos.y -= cosf(D3DX_PI / 4) * (PLAYER_MOVE + (m_nSppedLv * SPEED_MOVE));
            BgScroll = D3DXVECTOR2(sinf(D3DX_PI / 4) * SCROLL_MOVE, -cosf(D3DX_PI / 4) * SCROLL_MOVE);
            SetTexture(D3DXVECTOR2(0.0f, 0.0f), D3DXVECTOR2(1.0f, 3.0));
        }
        else if (pInputKeyboard->GetKeyPress(DIK_DOWN) ||
            pInputKeyboard->GetKeyPress(DIK_S) ||
            pInputController->GetConPress(CROSSKEY_DOWN))
        {// �E�Ɖ��𓯎��ɉ������Ƃ�
            pos.x += (D3DX_PI / 4) * (PLAYER_MOVE + (m_nSppedLv * SPEED_MOVE));
            pos.y += (D3DX_PI / 4) * (PLAYER_MOVE + (m_nSppedLv * SPEED_MOVE));
            BgScroll = D3DXVECTOR2(sinf(D3DX_PI / 4) * SCROLL_MOVE, cosf(D3DX_PI / 4) * SCROLL_MOVE);
            SetTexture(D3DXVECTOR2(0.0f, 2.0f), D3DXVECTOR2(1.0f, 3.0));
        }
        else
        {	// �E�����������Ƃ�
            pos.x += (PLAYER_MOVE + (m_nSppedLv * SPEED_MOVE));//�E�Ɉړ�
            BgScroll = D3DXVECTOR2(SCROLL_MOVE, 0.0f);
        }
        bIsMove = true;
    }

    //�@�ゾ���������Ƃ�
    else if (pInputKeyboard->GetKeyPress(DIK_UP) ||
        pInputKeyboard->GetKeyPress(DIK_W) ||
        pInputController->GetConPress(CROSSKEY_UP_MIN))
    {
        pos.y -= (PLAYER_MOVE + (m_nSppedLv * SPEED_MOVE));
        BgScroll = D3DXVECTOR2(0.0f, -SCROLL_MOVE);
        SetTexture(D3DXVECTOR2(0.0f, 0.0f), D3DXVECTOR2(1.0f, 3.0));
        bIsMove = true;
    }

    // �������������Ƃ�
    else if (pInputKeyboard->GetKeyPress(DIK_DOWN) ||
        pInputKeyboard->GetKeyPress(DIK_S) ||
        pInputController->GetConPress(CROSSKEY_DOWN))
    {
        pos.y += (PLAYER_MOVE + (m_nSppedLv * SPEED_MOVE));
        BgScroll = D3DXVECTOR2(0.0f, SCROLL_MOVE);
        SetTexture(D3DXVECTOR2(0.0f, 2.0f), D3DXVECTOR2(1.0f, 3.0));
        bIsMove = true;
    }

    // ��ʊO�ɂ͂ݏo���Ȃ��悤�ɂ���
    if (pos.y <= PLAYER_LIMIT_POS_UP)
    {// ��
        pos.y = PLAYER_LIMIT_POS_UP;
    }
    if (pos.y >= PLAYER_LIMIT_POS_DOWN)
    {//��
        pos.y = PLAYER_LIMIT_POS_DOWN;
    }
    if (pos.x <= PLAYER_LIMIT_POS_LEFT)
    {// ��
        pos.x = PLAYER_LIMIT_POS_LEFT;
    }
    if (pos.x >= PLAYER_LIMIT_POS_RIGHT)
    {// �E
        pos.x = PLAYER_LIMIT_POS_RIGHT;
    }

    // �ʒu�̍X�V
    SetPosition(pos);

    // �v���C���[�̓����ɍ��킹�Ĕw�i���X�N���[��������
    CGame::GetBg()->SetPlayerScroll(BgScroll);

    // �I�v�V����������ꍇ�I�v�V�����̈ړ�
    if (m_nOptionLv > 0 && bIsMove == true)
    {
        for (int nCount = 0; nCount < m_nOptionLv; nCount++)
        {

            if (m_pOption[nCount] != NULL)
            {
                m_pOption[nCount]->Move();
            }
        }
    }
}

//=============================================================================
// [ShootBullet] �e(�p���[�A�b�v����)�̔���
//=============================================================================
void CPlayer::ShootBullet(void)
{
    // �ϐ��錾
    D3DXVECTOR3 pos = GetPosition();
    CSound *pSound = CManager::GetSound();

    if (m_nCntBullet < LIMIT_PLAYER_BULLET)
    {// �e�̌��Ă��Ԃ̂Ƃ�
        CBullet::Create(pos, D3DXVECTOR3(20.0f, 0.0f, 0.0f), CBullet::TYPE_PLAYER, this);
        pSound->Play(CSound::SOUND_LABEL_SE_002);
        m_nCntBullet++;
    }
}

//=============================================================================
// [ShootDouble] �e(�_�u�����)�̔���
//=============================================================================
void CPlayer::ShootDouble(void)
{
    // �ϐ��錾
    D3DXVECTOR3 pos = GetPosition();
    CSound *pSound = CManager::GetSound();

    if (m_nCntBullet < LIMIT_PLAYER_BULLET)
    {// �e�̌��Ă��Ԃ̂Ƃ�
        CBullet::Create(pos, D3DXVECTOR3(20.0f, 0.0f, 0.0f), CBullet::TYPE_PLAYER, this);
        CBullet::Create(pos, D3DXVECTOR3(cos(D3DX_PI / 4)*20.0f, (-cos(D3DX_PI / 4))*20.0f, 0.0f), CBullet::TYPE_PLAYER, this);
        pSound->Play(CSound::SOUND_LABEL_SE_002);
        m_nCntBullet += 2;
    }
}

//=============================================================================
// [ShootLaser] ���[�U�[�̔���
//=============================================================================
void CPlayer::ShootLaser(void)
{
    // �ϐ��錾
    D3DXVECTOR3 pos = GetPosition();
    CSound *pSound = CManager::GetSound();

    CLaser::Create(pos, this);
    pSound->Play(CSound::SOUND_LABEL_SE_002);
}

//=============================================================================
// [ShootMissile] �~�T�C���̔���
//=============================================================================
void CPlayer::ShootMissile(void)
{
    // �ϐ��錾
    D3DXVECTOR3 pos = GetPosition();

    if (m_nIntervalMissile % MISSILE_INTERVAL == 0)
    {
        m_nIntervalMissile = 0;
        if (m_nCntMissile < 1)
        {
            m_nCntMissile++;
            CMissile::Create(pos, this);
        }
    }
}

//=============================================================================
// [EnergyDown] �G�l���M�[�̌���
//=============================================================================
void CPlayer::EnergyDown(void)
{
    m_nEnergy--;
    if (m_nEnergy <= 0)
    {
        Damage();
    }
}

//=============================================================================
// [Damage] �_���[�W���󂯂����̏���
//=============================================================================
void CPlayer::Damage(void)
{
    // �ϐ��錾
    D3DXVECTOR3 pos = GetPosition();
    CSound *pSound = CManager::GetSound();

    // �c�@�̐ݒ�
    m_nLife--;
    m_pLife->SetLife(m_nLife);

    // �v���C���[����U��\���ɂ���
    SetPosition(D3DXVECTOR3(-100.0f, -100.0f, 0.0f));
    pSound->Play(CSound::SOUND_LABEL_SE_005);
    m_bIsDisplayed = false;
    CTriangle_Effect::Create(pos, 300);// �G�t�F�N�g�̐���

    // �G�l���M�[�̃��Z�b�g
    m_nEnergy = MAX_ENERGY;

    // �p���[�A�b�v���e�̃��Z�b�g
    m_nInterval = BULLET_INTERVAL;
    m_shotType = SHOTTYPE_BULLET;
    m_nSppedLv = 0;
    m_bHasMissile = false;
    m_nOptionLv = 0;

    for (int nCount = 0; nCount < LIMIT_OPTION; nCount++)
    {// �I�v�V�����̃I�u�W�F�N�g��j��
        if (m_pOption[nCount] != NULL)
        {
            m_pOption[nCount]->Uninit();
            m_pOption[nCount] = NULL;
        }
    }
    m_bUsingShield = false;
    if (m_pShield != NULL)
    {
        m_pShield->Uninit();
        m_pShield = NULL;
    }
    // �p���[�A�b�v�Q�[�W�_�����̓X�s�[�h�A�b�v�ɂ���
    if (m_powerUp != POWERUP_NONE)
    {
        m_powerUp = POWERUP_SPPED;
    }
    // �c�@���Ȃ��Ȃ�����
    if (m_nLife <= 0)
    {
        Uninit();
        CGame::SetState(CGame::STATE_END);// �Q�[���I��
    }
}

//=============================================================================
// [SetPowerUp] �p���[�A�b�v�̐ݒ�
//=============================================================================
void CPlayer::SetPowerUp(POWERUP powerUp)
{ 
    m_powerUp = powerUp;
}

//=============================================================================
// [PowerUp] �p���[�A�b�v
//=============================================================================
void CPlayer::PowerUp(void)
{
    CSound *pSound = CManager::GetSound();

    // ���݂̃J�[�\���ɂ��������e����������
    if (m_powerUp != POWERUP_NONE)
    {
        switch (m_powerUp)
        {
            // �X�s�[�h�A�b�v
        case POWERUP_SPPED:
            // ���E�܂Ńp���[�A�b�v����ƃp���[�A�b�v�ł��Ȃ��Ȃ�
            if (m_nSppedLv <= LIMIT_SPEED)
            {
                m_nSppedLv++;
                // SE��炷
                pSound->Play(CSound::SOUND_LABEL_SE_008);
                m_powerUp = POWERUP_NONE;
            }
            break;

            // �~�T�C���ǉ�
        case POWERUP_MISSILE:
            if (m_bHasMissile == false)
            {
                m_bHasMissile = true;
                m_powerUp = POWERUP_NONE;
                // SE��炷
                pSound->Play(CSound::SOUND_LABEL_SE_008);
            }
            break;

            // �_�u���ǉ�
        case POWERUP_DOUBLE:
            if (m_shotType != SHOTTYPE_DOBLE)
            {
                m_shotType = SHOTTYPE_DOBLE;    // �V���b�g�̎�ނ��_�u���ɕύX
                m_nInterval = BULLET_INTERVAL;
                // SE��炷
                pSound->Play(CSound::SOUND_LABEL_SE_008);
                m_powerUp = POWERUP_NONE;
            }
            break;

            // ���[�U�[�ǉ�
        case POWERUP_LASER:
            if (m_shotType != SHOTTYPE_LASER)
            {
                m_shotType = SHOTTYPE_LASER;    // �V���b�g�̎�ނ����[�U�[�ɕύX
                m_nInterval = LASER_INTERVAL;
                // SE��炷
                pSound->Play(CSound::SOUND_LABEL_SE_008);
                m_powerUp = POWERUP_NONE;
            }
            break;

            // �I�v�V�����ǉ�
        case POWERUP_OPTION:
            if (m_nOptionLv < LIMIT_OPTION)
            {// ���łɃI�v�V����������ꍇ�O�̃I�v�V�����̈ʒu���g�p
                m_pOption[m_nOptionLv] = m_nOptionLv > 0 ? COption::Create(m_pOption[m_nOptionLv - 1]->CScene2D::GetPosition()) : COption::Create(GetPosition());
                m_nOptionLv++;
                // SE��炷
                pSound->Play(CSound::SOUND_LABEL_SE_008);
                m_powerUp = POWERUP_NONE;
            }
            break;
            // �V�[���h�ǉ�
        case POWERUP_SHIELD:
            if (m_pShield == NULL)
            {
                m_bUsingShield = true;
                CShield::Create(GetPosition(),this);
                // SE��炷
                pSound->Play(CSound::SOUND_LABEL_SE_008);
                m_powerUp = POWERUP_NONE;
            }
            break;
        }

    }
}

//=============================================================================
// [CheckState] �v���C���[�̏�Ԃ��m�F
//=============================================================================
void CPlayer::CheckState(void)
{
    // �_���[�W��Ԃ̎��_�ł�����
    switch (m_State)
    {

    case PLAYER_STATE_INVINCIBLE:     // ���G���
        m_nInvincibleCount--;
        if (m_nInvincibleCount% PLAYER_FLASHING_INTERVAL * 2 <= PLAYER_FLASHING_INTERVAL)
        {
           SetColor(D3DXCOLOR(1.0f, 0.5f, 0.5f, 0.3f));
        }
        else
        {
            SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f));
        }

        // ���G���Ԃ̃J�E���g���Ȃ��Ȃ�����ʏ��Ԃɖ߂�
        if (m_nInvincibleCount <= 0)
        {
            SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
            m_State = PLAYER_STATE_NORMAL;
        }
        break;
    }
}

#if _DEBUG
//=============================================================================
// [DebugCommand] �f�o�b�O�R�}���h
//=============================================================================
void CPlayer::DebugCommand(void)
{
    CInputKeyboard*pInputKeyboard = CManager::GetInputKeyboard();

    // 1�L�[���� : �X�s�[�h�A�b�v
    if (pInputKeyboard->GetKeyTrigger(DIK_1))
    {
        if (m_nSppedLv <= LIMIT_SPEED)
        {
            m_nSppedLv++;
        }
    }
    // 2�L�[���� : �~�T�C���擾
    if (pInputKeyboard->GetKeyTrigger(DIK_2))
    {
        if (m_bHasMissile == false)
        {
            m_bHasMissile = true;
        }
    }
    // 3�L�[���� : �V���b�g���_�u���ɕύX
    if (pInputKeyboard->GetKeyTrigger(DIK_3))
    {
        if (m_shotType != SHOTTYPE_DOBLE)
        {
            m_shotType = SHOTTYPE_DOBLE;
            m_nInterval = BULLET_INTERVAL;
        }
    }
    // 4�L�[���� : �V���b�g�����[�U�[�ɕύX
    if (pInputKeyboard->GetKeyTrigger(DIK_4))
    {
        if (m_shotType != SHOTTYPE_LASER)
        {
            m_shotType = SHOTTYPE_LASER;
            m_nInterval = LASER_INTERVAL;
        }
    }
    // 5�L�[���� : �I�v�V�����ǉ�
    if (pInputKeyboard->GetKeyTrigger(DIK_5))
    {
        if (m_nOptionLv < LIMIT_OPTION)
        {// ���łɃI�v�V����������ꍇ�O�̃I�v�V�����̈ʒu���g�p
            m_pOption[m_nOptionLv] = m_nOptionLv > 0 ? COption::Create(m_pOption[m_nOptionLv - 1]->CScene2D::GetPosition()) : COption::Create(GetPosition());
            m_nOptionLv++;
        }
    }
    // 6�L�[���� : �V�[���h�擾
    if (pInputKeyboard->GetKeyTrigger(DIK_6))
    {
        if (m_pShield == NULL)
        {
            m_bUsingShield = true;
            m_pShield = CShield::Create(GetPosition(),this);
        }
    }

}
#endif // _DEBUG