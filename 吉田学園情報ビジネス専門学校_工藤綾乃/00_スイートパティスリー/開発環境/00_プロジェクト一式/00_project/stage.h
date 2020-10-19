//=============================================================================
//
// �X�e�[�W�̏��� [stage.h]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef _STAGE_H_
#define _STAGE_H_
#include "main.h"
#include "scene.h"

//******************************************************************************
// �\���̒�`
//******************************************************************************
typedef struct
{
    D3DXVECTOR3 pos;
    int nFlame;              // �o���^�C�~���O
    CScene::OBJTYPE type;    // ���
    int nFlip;              // ���E�\�N�̌���
    int Formaition;          // �ґ��̐�
    D3DXVECTOR3 orbit[10];   // �ڕW�̈ʒu
    
}STAGEDATA;

//******************************************************************************
// �N���X�̒�`
//******************************************************************************
//�X�e�[�W�N���X
class CStage
{
public:
    CStage();
    ~CStage();
    // �X�e�[�W�t�@�C���̓ǂݍ���
    void ReadFile(void);
    void Init(void);
    void Update(void);

private:
    static int m_nFreme;  // �J�E���^
    int m_nIndex;         // �o��������I�u�W�F�N�g�̃C���f�b�N�X
    static STAGEDATA m_pStageData[MAX_POLYGON];// �X�e�[�W�̏��
    int m_nNumber;        // ��

    int m_nFormaition;    // �G�̑���ԍ�
};

#endif // !_STAGE_H_
