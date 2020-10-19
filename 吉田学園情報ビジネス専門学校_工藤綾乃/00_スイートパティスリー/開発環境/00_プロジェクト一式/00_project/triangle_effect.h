//=============================================================================
//
// �G�t�F�N�g���� [triangle_effect.h]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef _TRIANGLE_EFFECT_H_
#define _TRIANGLE_EFFECT_H_
#include "main.h"
#include "scene.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define MAX_EFFECT (1024)       // �G�t�F�N�g�̍ő吔

//*****************************************************************************
// �O���錾
//*****************************************************************************
class CTriangle;

//*****************************************************************************
// �N���X�̒�`
//*****************************************************************************
// �G�t�F�N�g�N���X
class CTriangle_Effect : public CScene
{
public:
    CTriangle_Effect(D3DXVECTOR3 pos, int nNum);
    ~CTriangle_Effect();

    static CTriangle_Effect* Create(D3DXVECTOR3 pos, int nNum);

    HRESULT Init();
    void Uninit(void);
    void Update(void);
    void Draw(void);

    void SetMove(D3DXVECTOR3 TargetPos);

private:
    D3DXVECTOR3 m_pos;      // �G�t�F�N�g�̊�ʒu
    D3DXVECTOR3 m_move;      // �G�t�F�N�g�̊�ʒu
    int         m_nLife;                    // �v���C���[�����܂ł̑ҋ@����
    int         m_nEffectCount;
    int         m_nNumEffect;       // ��������G�t�F�N�g�̐�
    CTriangle   *m_pTriangle[MAX_EFFECT];   // �G�t�F�N�g�̏��
};
#endif // !_TRIANGLE_EFFECT_H_

