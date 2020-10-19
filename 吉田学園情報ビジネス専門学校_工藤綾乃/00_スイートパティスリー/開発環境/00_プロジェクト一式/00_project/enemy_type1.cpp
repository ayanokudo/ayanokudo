//=============================================================================
//
// �G�̏��� [enemytype1.cpp]
// Author : AYANO KUDO
//
//=============================================================================
#include "enemy_type1.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define ENEMY_SPPED_TYPE1     (6.0f)

//=============================================================================
// [CEnemyType1] �R���X�g���N�^
//=============================================================================
CEnemyType1::CEnemyType1()
{
    m_OrbitIndex = 0;
    for (int nCntOrbit = 0; nCntOrbit < MAX_ORBIT; nCntOrbit++)
    {
        m_Orbit[nCntOrbit] = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
    }
}

//=============================================================================
// [~CEnemy] �f�X�g���N�^
//=============================================================================
CEnemyType1::~CEnemyType1()
{

}

//=============================================================================
// [Create] �I�u�W�F�N�g�̐���
// �Ԃ�l : �m�ۂ����������ւ̃|�C���^��Ԃ�
//=============================================================================
CEnemyType1 * CEnemyType1::Create(D3DXVECTOR3 pos, int Formaition, int nNum)
{
    CEnemyType1* pEnemyType1 = NULL;
    if (pEnemyType1 == NULL)
    {
        pEnemyType1 = new CEnemyType1;
        pEnemyType1->Init(pos, Formaition, nNum);
    }
    return pEnemyType1;
}

//=============================================================================
// [Init] ����������
//=============================================================================
HRESULT CEnemyType1::Init(D3DXVECTOR3 pos, int Formaition, int nNum)
{
    SetFormaitionNum(Formaition);
    SetPosition(D3DXVECTOR3(pos.x + (ENEMY_SIZE_X * nNum), pos.y, 0.0f));
    CEnemy::Init();
    return S_OK;
}

//=============================================================================
// [Uninit] �I������
//=============================================================================
void CEnemyType1::Uninit(void)
{
    CEnemy::Uninit();
}

//=============================================================================
// [Update] �X�V����
//=============================================================================
void CEnemyType1::Update(void)
{
    D3DXVECTOR3 pos = GetPosition();
    // �O���̖ڕW�ʒu�ɋ߂Â�����
    if (pos.x >= m_Orbit[m_OrbitIndex].x - ENEMY_SPPED_TYPE1 &&
        pos.x <= m_Orbit[m_OrbitIndex].x + ENEMY_SPPED_TYPE1 &&
        pos.y >= m_Orbit[m_OrbitIndex].y - ENEMY_SPPED_TYPE1 &&
        pos.y <= m_Orbit[m_OrbitIndex].y + ENEMY_SPPED_TYPE1)
    {
        // ���̖ڕW�ʒu��ݒ�
        m_OrbitIndex++;
        SetMove(m_Orbit[m_OrbitIndex]);
    }
    CEnemy::Update();
}

//=============================================================================
// [Draw] �`�揈��
//=============================================================================
void CEnemyType1::Draw(void)
{
    CEnemy::Draw();
}

//=============================================================================
// [SetMove] �ړ�����ʒu�̐ݒ�
// ����
// TargetPos : ���̖ڕW���W
//=============================================================================
void CEnemyType1::SetMove(D3DXVECTOR3 TargetPos)
{
    D3DXVECTOR3 pos = GetPosition();
    float fRadian;      // �p�x
                        // �ڕW�܂ł̊p�x�����߂�
    fRadian = (float)atan2(TargetPos.y - pos.y, TargetPos.x - pos.x);

    CEnemy::SetMove( D3DXVECTOR3(cosf(fRadian)*ENEMY_SPPED_TYPE1, sinf(fRadian)*ENEMY_SPPED_TYPE1, 0.0f));

}

//=============================================================================
// [SetOrbit] �G�̋O���̐ݒ�
// ����
// pOrbit : �t�@�C������ǂݍ��񂾋O�Ղ̐擪�A�h���X
//=============================================================================
void CEnemyType1::SetOrbit(D3DXVECTOR3 * pOrbit)
{
    for (int nCntOrbit = 0; nCntOrbit < MAX_ORBIT; nCntOrbit++)
    {
        m_Orbit[nCntOrbit] = pOrbit[nCntOrbit];
    }
    CEnemyType1::SetMove(m_Orbit[m_OrbitIndex]);
}