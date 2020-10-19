//=============================================================================
//
// �����L���O���� [ranking.h]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef _RANKING_H_
#define _RANKING_H_
#include "main.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define MAX_RANKING_SCORE   (5)       // �����L���O�̉�ʂŕ\������X�R�A�̐�

//*****************************************************************************
// �O���錾
//*****************************************************************************
class CScene2D;
class CScore;
class CRanking_UI;

//*****************************************************************************
// �N���X�̒�`
//*****************************************************************************
// �����L���O�N���X
class CRanking
{
public:
    // �T�[�o�[�ɃR�}���h��v��
    typedef enum
    {
        COMMAND_TYPE_NONE = 0,
        COMMAND_TYPE_GET_RANKING,		// �����L���O�ꗗ���擾
        COMMAND_TYPE_SET_RANKING		// �����L���O��ݒ�
    } COMMAND_TYPE;
    CRanking();
    ~CRanking();

    static void Load(void);
    static void Unload(void);
    static CRanking *Create(void);

    void Init(void);
    void Uninit(void);
    void Update(void);
    void Draw(void);

   static int SetRanking(int nScore);
   static void GetRanking(void);

private:
    static CScore       *m_pScore[MAX_RANKING_SCORE];   // �X�R�A�I�u�W�F�N�g�ւ̃|�C���^
    static CRanking_UI  *m_pRankingUI;                  // �����L���OUI�I�u�W�F�N�g�ւ̃|�C���^
    
};
#endif // !_RANKING_H_
