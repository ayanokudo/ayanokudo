//=============================================================================
//
// �G�̏��� [boss.h]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef _BOSS_H_
#define _BOSS_H_
#include "main.h" 
#include "enemy.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define MAX_BOSS_ENEMY (6)      // �{�X�̎���̓G�̐�

//*****************************************************************************
// �O���錾
//*****************************************************************************
class CEnemy_Type3;

//*****************************************************************************
// �N���X��`
//*****************************************************************************
class CBoss : public CEnemy
{
public :
    CBoss();
    ~CBoss();

    static CBoss* Create(D3DXVECTOR3 pos);

    static HRESULT Load(void);
    static void Unload(void);

    HRESULT Init(D3DXVECTOR3 pos);
    void Uninit(void);
    void Update(void);
    void Draw(void);

    void CheckState(void);

private:
    static LPDIRECT3DTEXTURE9 m_pTexture;                    // �e�N�X�`���ւ̃|�C���^
    static char              *m_pTextureName;                // �e�N�X�`����
    static CEnemy_Type3      *m_pEnemy[MAX_BOSS_ENEMY];      // �G�̏��ւ̃|�C���^

};
#endif // !_BOSS_H_