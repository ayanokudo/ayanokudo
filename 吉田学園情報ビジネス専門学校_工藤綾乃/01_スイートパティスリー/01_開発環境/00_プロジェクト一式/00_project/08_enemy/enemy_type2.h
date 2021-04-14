//=============================================================================
//
// �G�̏��� [enemytype2.h]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef _ENEMYTYPE2_H_
#define _ENEMYTYPE2_H_
#include "main.h"
#include "enemy.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************

//*****************************************************************************
// �N���X�̒�`
//*****************************************************************************
class CEnemy_Type2 : public CEnemy
{
public:
    CEnemy_Type2();
    ~CEnemy_Type2();

    static CEnemy_Type2* Create(D3DXVECTOR3 pos, int Formaition, int nNum);

    static HRESULT Load(void);
    static void Unload(void);

    HRESULT Init(D3DXVECTOR3 pos, int Formaition, int nNum);
    void Uninit(void);
    void Update(void);
    void Draw(void);

    void move(void);
private:
    static LPDIRECT3DTEXTURE9 m_pTexture; // �e�N�X�`���ւ̃|�C���^
    static char* m_pTextureName;          // �e�N�X�`���̃t�@�C����
    int m_nTex;                           // ���݃e�N�X�`���̔ԍ�
    int m_nAnimationCounter;              // �A�j���[�V�����J�E���^
    float m_fAngle;                       // �p�x
};

#endif // _ENEMYTYPE2_H_