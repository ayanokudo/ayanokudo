//=============================================================================
//
// �G�̏��� [enemy_type1.cpp]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef _ENEMY_TYPE1_H_
#define _ENEMY_TYPE1_H_
#include "enemy.h"

//*****************************************************************************
// �N���X�̒�`
//*****************************************************************************
class CEnemyType1 : public CEnemy
{
public:
    CEnemyType1();
    ~CEnemyType1();

    static CEnemyType1* Create(D3DXVECTOR3 pos, int Formaition, int nNum);

    HRESULT Init(D3DXVECTOR3 pos, int Formaition, int nNum);
    void Uninit(void);
    void Update(void);
    void Draw(void);

    void SetMove(D3DXVECTOR3 TargetPos);
    void SetOrbit(D3DXVECTOR3* pOrbit);

private:
    int m_OrbitIndex;                               // �O���̃C���f�b�N�X
    D3DXVECTOR3 m_Orbit[MAX_ORBIT];                 // �O���̈ʒu
                                                    // ����ԍ�
};
#endif // !_ENEMY_TYPE1_H_
