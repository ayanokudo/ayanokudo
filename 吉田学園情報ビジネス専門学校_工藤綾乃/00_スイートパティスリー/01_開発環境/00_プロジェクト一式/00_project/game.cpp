//=============================================================================
//
// �Q�[���̏��� [game.h]
// Author : AYANO KUDO
//
//=============================================================================
#include "game.h"
#include "scene2d.h"
#include "input.h"
#include "input.h"
#include "inputkeyboard.h"
#include "inputcontroller.h"
#include "pause.h"
#include "player.h"
#include "life.h"
#include "energy_ui.h"
#include "stage.h"
#include "bullet.h"
#include "laser.h"
#include "missile.h"
#include "enemy.h"
#include "enemy_type3.h"
#include "boss.h"
#include "explosion.h"
#include "bg.h"
#include "score.h"
#include "triangle.h"
#include "Item.h"
#include "powerui.h"
#include "sound.h"
#include "fade.h"
#include "terrain.h"
#include "number.h"
#include "shield.h"
#include "option.h"
#include "particle_effect.h"
#include "ranking.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define END_LATENCY (10)        // �Q�[���I�����̑ҋ@����

//*****************************************************************************
// �ÓI�����o�ϐ��̏�����
//*****************************************************************************
TEXTURE_DATA CGame::m_StatsData[MAX_STATS_BAR] = 
{
    { D3DXVECTOR3(SCREEN_WIDTH / 2.0f,55.0f,0.0f),D3DXVECTOR3(SCREEN_WIDTH,150,0.0f),"" },
    { D3DXVECTOR3(SCREEN_WIDTH / 2.0f,710.0f,0.0f),D3DXVECTOR3(SCREEN_WIDTH,100,0.0f),""}
};

CPlayer         *CGame::m_pPlayer    = NULL;
CBg             *CGame::m_pBg        = NULL;
CStage          *CGame::m_pStage     = NULL;
CScore          *CGame::m_pScore     = NULL;
CStar           *CGame::m_pStar      = NULL;
CTriangle       *CGame::m_pTriangle  = NULL;
CPowerUI        *CGame::m_pPowerUI   = NULL;
CPause          *CGame::m_pPause     = NULL;
CScene2D        *CGame::m_CScene2d[MAX_STATS_BAR] = {};
CGame::STATE     CGame::m_Gamestate  = STATE_NONE;
bool             CGame::m_bIsPause     = false;

//=============================================================================
// [CGame] �R���X�g���N�^
//=============================================================================
CGame::CGame()
{
    // �e�����o�ϐ��̏�����
    m_pStage = NULL;
    m_nCountGameState = 0;
    m_bIsPause=false;
}

//=============================================================================
// [~CGame] �f�X�g���N�^
//=============================================================================
CGame::~CGame()
{

}

//=============================================================================
// [Create] �I�u�W�F�N�g�̐���
//=============================================================================
CGame *CGame::Create(void)
{
    CGame *pGame = NULL;
    if (!pGame)
    {

        pGame = new CGame;
        pGame->Init();
    }
        return pGame;
}

//=============================================================================
// [Load] �e�N�X�`���̓ǂݍ���
//=============================================================================
void CGame::Load(void)
{
    CPlayer::Load();
    CLife::Load();
    CEnergy_UI::Load();
    CBullet::Load();
    CLaser::Load();
    CEnemy::Load();
    CEnemy_Type3::Load();
    CBoss::Load();
    CExplosion::Load();
    CParticle_Effect::Load();
    CBg::Load();
    CItem::Load();
    CPowerUI::Load();
    CMissile::Load();
    CTerrain::Load();
    CNumber::Load();
    CShield::Load();
    COption::Load();
    CPause::Load();
}

//=============================================================================
// [Unload] �e�N�X�`���̔j��
//=============================================================================
void CGame::Unload(void)
{
    CPlayer::Unload();
    CLife::Unload();
    CEnergy_UI::Unload();
    CEnemy::Unload();
    CEnemy_Type3::Unload();
    CBoss::Unload();
    CBullet::Unload();
    CMissile::Unload();
    CLaser::Unload();
    CBg::Unload();
    CItem::Unload();
    CExplosion::Unload();
    CParticle_Effect::Unload();
    CPowerUI::Unload();
    CNumber::Unload();
    CShield::Unload();
    COption::Unload();
    CPause::Unload();
}

//=============================================================================
// [Init] ����������
//=============================================================================
void CGame::Init(void)
{
    m_nCountGameState = 0;

    // �e�N�X�`���̓ǂݍ���
    Load();

    m_Gamestate = STATE_NORMAL;
    CSound *pSound = CManager::GetSound();
    pSound->Play(CSound::SOUND_LABEL_BGM001);

    // �e��I�u�W�F�N�g�̐���
    m_pBg = CBg::Create();

    for (int nCntStatsBar = 0; nCntStatsBar < MAX_STATS_BAR; nCntStatsBar++)
    {
         m_CScene2d[nCntStatsBar] = CScene2D::Create(m_StatsData[nCntStatsBar].pos, m_StatsData[nCntStatsBar].size);
         m_CScene2d[nCntStatsBar]->SetObjtype(CScene::OBJTYPE_BG);
         m_CScene2d[nCntStatsBar]->SetColor(D3DXCOLOR(0.3f, 0.16f, 0.1f, 1.0f));
    }

    m_pScore = CScore::Create(D3DXVECTOR3(400, 10.0f, 0.0f));
    m_pPlayer = CPlayer::Create();
    m_pPowerUI = CPowerUI::Create();
    m_pPause = CPause::Create();

    if (m_pStage == NULL)
    {
        m_pStage = new CStage;
        m_pStage->Init();
    }
}

//=============================================================================
// [Uninit] �I������
//=============================================================================
void CGame::Uninit(void)
{
    // �T�E���h�̒�~
    CSound *pSound = CManager::GetSound();
    pSound->Stop();

        // 2D�|���S���̃������̊J��
        CScene2D::ReleaseAll();

        if (m_pStage)
        {
            delete m_pStage;
            m_pStage = NULL;
        }
        if (m_pPause!=NULL)
        {
            m_pPause = NULL;
        }
        // �e�N�X�`���̔j��
        Unload();
}

//=============================================================================
// [Update] �X�V����
//=============================================================================
void CGame::Update(void)
{
    // �ϐ��錾
    CInputKeyboard *pInputKeyboard = CManager::GetInputKeyboard();
    CInputController *pInputController = CManager::GetInputController();
    CSound *pSound = CManager::GetSound();

    // �|�[�Y���ł͂Ȃ���
    if (m_bIsPause == false)
    {
        m_pStage->Update();

        // �Q�[����Ԃ̊m�F
        switch (m_Gamestate)
        {
        case STATE_NORMAL:
            break;
        case STATE_END:
            m_nCountGameState++;
            if (m_nCountGameState >= END_LATENCY)
            {
                // ���݂̃X�R�A�𑗐M���A���U���g��ʂ� �J��
                SetState(STATE_NONE);
                //CRanking::SetRanking(m_pScore->GetScore());�@// �T�[�o�[�͂̒ʐM�͉ƂŃf�o�b�N�ł��Ȃ��̂ŃR�����g�A�E�g
                CFade::SetFade(CManager::MODE_RESULT);
            }
            break;
        }
    }

    // P�L�[�Ń|�[�Y��Ԃ�ύX
    if (pInputKeyboard->GetKeyTrigger(DIK_P) ||
        pInputController->GetConTrigger(CInputController::BUTTON_10))
    {
        // SE��炷
        pSound->Play(CSound::SOUND_LABEL_SE_008);
        m_pPause->Update();
        m_bIsPause = m_bIsPause ^ true;
    }
}