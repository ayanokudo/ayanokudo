//=============================================================================
//
// �I�v�V�����̏���[option.cpp]
// Author : AYANO KUDO
//
//=============================================================================
#include "option.h"
#include "manager.h"
#include "renderer.h"
#include "game.h"
#include "input.h"
#include "inputkeyboard.h"
#include "inputcontroller.h"
#include "enemy.h"
#include "player.h"
#include "scene2d.h"
#include "sound.h"
#include "bullet.h"
#include "laser.h"
#include "missile.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define OPTION_SIZE_X (35.0f)
#define OPTION_SIZE_Y (50.0f)

#define LIMIT_SPEED   (4)         // �X�s�[�h�̃p���[�A�b�v���E�l
#define LIMIT_MISSILE (1)         // �~�T�C���̃p���[�A�b�v���E�l

//*****************************************************************************
// �ÓI�����o�ϐ�������
//*****************************************************************************
LPDIRECT3DTEXTURE9 COption::m_pTexture = NULL;
char * COption::m_pTextureName = "data/TEXTURE/option.png";

//=============================================================================
// [COption] �R���X�g���N�^
//=============================================================================
COption::COption()
{
    SetObjtype(CScene::OBJTYPE_OPTION);
    SetPosition(D3DXVECTOR3(200.0f, 360.0f, 0.0f));
    m_nIndex = 0;
    m_nShotInterval = 0;
    m_nCntBullet = 0;
    m_nIntervalMissile = 0; // �~�T�C���̔��ˊԊu
    m_nCntMissile = 0;
    SetSize(D3DXVECTOR3(OPTION_SIZE_X, OPTION_SIZE_Y,0.0f));
    m_nOptNum = CGame::GetPlayer()->GetOptionLv();
}

//=============================================================================
// [~COption] �f�X�g���N�^
//=============================================================================
COption::~COption()
{

}


//=============================================================================
// [Create] �v���C���[�̐���
//=============================================================================
COption * COption::Create(D3DXVECTOR3 pos)
{
    COption *pOption = NULL;
    if (pOption==NULL)
    {
        pOption = new COption;
        pOption->Init(pos);
    }
    return pOption;
}


//=============================================================================
// [Load] �e�N�X�`���̓ǂݍ���
//=============================================================================
HRESULT COption::Load(void)
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
void COption::Unload(void)
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
HRESULT COption::Init(D3DXVECTOR3 pos)
{
    CPlayer* pPlayer = CGame::GetPlayer();
    COption** pOption = pPlayer->GetOption();
    // �e�����o�ϐ�������
    for (int nCount = 0; nCount < OPTION_LENGTH; nCount++)
    {
        if (m_nOptNum == 0)
        {// �ŏ��̃I�v�V�����̏ꍇ�v���C���[��Ǐ]
            m_aOrbit[nCount] = pPlayer->GetPosition();
        }
        else
        {// ����ȊO�͑O�̃I�v�V������Ǐ]
            m_aOrbit[nCount] = pOption[m_nOptNum - 1]->GetPosition();
        };
    }
    SetPosition(m_aOrbit[m_nIndex]);

    CScene2D::Init();
    // �e�N�X�`���̊��蓖��
    BindTexture(m_pTexture);
    return S_OK;
}

//=============================================================================
// [Uninit] �I������
//=============================================================================
void COption::Uninit(void)
{
    CScene2D::Uninit();
}

//=============================================================================
// [Update] �X�V����
//=============================================================================
void COption::Update(void)
{
    CScene2D::Update();
    CSound *pSound = CManager::GetSound();
    D3DXVECTOR3 pos = GetPosition();
    CInputKeyboard*pInputKeyboard = CManager::GetInputKeyboard();
    CInputController *pInputController = CManager::GetInputController();

    // �G�ɓ����������G�Ƀ_���[�W��^����
    CScene *pScene = JudgeFittingRectangle(CScene::OBJTYPE_ENEMY);
    if (pScene)
    {
        ((CEnemy*)pScene)->Damage();
        pScene = NULL;
    }

    // �X�y�[�X�L�[or2�{�^���Œe�𔭎�
    if (pInputKeyboard->GetKeyPress(DIK_SPACE) ||
        pInputController->GetConPress(CInputController::BUTTON_2))
    {
        CPlayer::SHOTTYPE shotType = CGame::GetPlayer()->GetShotType();
        const int nInterval = CGame::GetPlayer()->GetInterval();

        m_nShotInterval++;
        m_nIntervalMissile++;

        //�e�̔���
        if (m_nShotInterval % nInterval == 0)
        {
            m_nShotInterval = 0;
            // �V���b�g�̎�ނɂ���Č���������
            switch (shotType)
            {
            case CPlayer::SHOTTYPE_BULLET:
                if (m_nCntBullet < LIMIT_PLAYER_BULLET)
                {// �e�̌��Ă��Ԃ̂Ƃ�
                    CBullet::Create(pos, D3DXVECTOR3(20.0f, 0.0f, 0.0f), CBullet::TYPE_PLAYER, this);
                    pSound->Play(CSound::SOUND_LABEL_SE_002);
                    m_nCntBullet++;
                }
                break;
            case CPlayer::SHOTTYPE_DOBLE:
                if (m_nCntBullet < LIMIT_PLAYER_BULLET)
                {// �e�̌��Ă��Ԃ̂Ƃ�
                    CBullet::Create(pos, D3DXVECTOR3(20.0f, 0.0f, 0.0f), CBullet::TYPE_PLAYER, this);
                    CBullet::Create(pos, D3DXVECTOR3(cos(D3DX_PI / 4)*20.0f, (-cos(D3DX_PI / 4))*20.0f, 0.0f), CBullet::TYPE_PLAYER, this);
                    m_nCntBullet += 2;
                }
                break;
            case CPlayer::SHOTTYPE_LASER:
                // ���[�U�[�̔���
                CLaser::Create(pos,this);
                break;
            }
        }

        if (m_nIntervalMissile % MISSILE_INTERVAL == 0)
        {
            //�~�T�C���̔���
            int nMissileLv = CGame::GetPlayer()->GetCountMissile();
            if (nMissileLv > 0)
            {
                m_nIntervalMissile = 0;
                if (m_nCntMissile < 2)
                {
                    m_nCntMissile++;
                    CMissile::Create(pos, this);
                }
            }
        }
    }
}

//=============================================================================
// [Draw] �`�揈��
//=============================================================================
void COption::Draw(void)
{
    // �|���S���̕`��
    CScene2D::Draw();
}

//=============================================================================
// [Move] �ړ�����
//=============================================================================
void COption::Move(void)
{
    SetPosition(m_aOrbit[m_nIndex]);
    CPlayer* pPlayer = CGame::GetPlayer();
    COption** pOption = pPlayer->GetOption();

    if (m_nOptNum == 0)
    {// �ŏ��̃I�v�V�����̏ꍇ�v���C���[��Ǐ]
        m_aOrbit[m_nIndex] = pPlayer->GetPosition();
    }
    else
    {// ����ȊO�͑O�̃I�v�V������Ǐ]
        m_aOrbit[m_nIndex]= pOption[m_nOptNum -1]->GetPosition();
    }
    m_nIndex = (m_nIndex + 1) % OPTION_LENGTH;
}
