//=============================================================================
//
// �~�T�C���̏��� [missile.h]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef _MISSILE_H_
#define _MISSILE_H_
#include "scene2d.h"

//*****************************************************************************
// �N���X�̒�`
//*****************************************************************************
class CMissile  : CScene2D
{
    public:

    CMissile();
    ~CMissile();

    static CMissile *Create(D3DXVECTOR3 pos,CScene* pScene);

    static HRESULT Load(void);
    static void Unload(void);

    HRESULT Init(D3DXVECTOR3 pos,CScene* pScene);
    void Uninit(void);
    void Update(void);
    void Draw(void);

private:
    static LPDIRECT3DTEXTURE9 m_pTexture;       // �e�N�X�`���ւ̃|�C���^
    static char* m_apTextureName;               // �e�N�X�`���̃t�@�C����
    CScene* m_pScene;                           // �~�T�C���̎�����̃A�h���X
    static int m_nCntMissile;                   // �~�T�C���̐�
};
#endif // !_MISSILE_H_