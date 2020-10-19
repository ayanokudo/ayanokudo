//=============================================================================
//
// �Q�[���̏��� [game.h]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef _GAME_H_
#define _GAME_H_
#include "main.h"

//*****************************************************************************
// �O���錾
//*****************************************************************************
class CPlayer;
class CBg;
class CStage;
class CScore;
class CStar;
class CTriangle;
class CPowerUI;
class CPause;
class CScene2D;

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define MAX_STATS_BAR (2)       // �X�e�[�^�X�o�[�̐�(�㉺��2��)

//******************************************************************************
// �N���X�̒�`
//******************************************************************************
class CGame
{
public:
    // �Q�[���̏��
    typedef enum
    {
        STATE_NONE=0,
        STATE_NORMAL,
        STATE_END,
    }STATE;

    CGame();
    ~CGame();
    static CGame *Create(void);

    static void Load(void);
    static void Unload(void);
    void Init(void);
    void Uninit(void);
    void Update(void);

    static CScore *GetScore(void) { return m_pScore; }

    // �Q�[���̏�ԃZ�b�^/�Q�b�^
    static void SetState(STATE gameState) { m_Gamestate = gameState; }
    static STATE GetState(void) { return m_Gamestate; }

    // �v���C���[�̃Q�b�^
    static CPlayer* GetPlayer(void) { return m_pPlayer; }
    
    // �w�i�̃Q�b�^
    static CBg* GetBg(void) { return m_pBg; }

    // �|�[�Y��Ԃ̃Z�b�^/�Q�b�^
    static void SetPause(bool IsPause) { m_bIsPause = IsPause;}
    static bool GetPause(void)         { return m_bIsPause; }

private:
    static TEXTURE_DATA m_StatsData[MAX_STATS_BAR];

    static CPlayer     *m_pPlayer;
    static CBg         *m_pBg;
    static CStage      *m_pStage;
    static CScore      *m_pScore;
    static CStar       *m_pStar;
    static CTriangle   *m_pTriangle;
    static CPowerUI    *m_pPowerUI;
    static CPause      *m_pPause;
    static CScene2D    *m_CScene2d[MAX_STATS_BAR];        // �X�e�[�^�X�o�[�̏��
    static STATE        m_Gamestate;              // �Q�[���̏��
    int                 m_nCountGameState;                 // �Q�[���I�����̑ҋ@����

    static bool         m_bIsPause;                  // �|�[�Y�����ǂ���

};
#endif // !_GAME_H_
