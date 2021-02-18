//=============================================================================
//
// �e�̏��� [laser.h]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef  _LASER_H_
#define _LASER_H_
#include "scene2d.h"

//*****************************************************************************
// �N���X�̒�`
//*****************************************************************************
// �e�̃N���X
class CLaser : public CScene2D
{
public:

    CLaser();
    ~CLaser();

    static CLaser *Create(D3DXVECTOR3 pos, CScene2D* pScene2D);

    static HRESULT Load(void);
    static void Unload(void);

    HRESULT Init(D3DXVECTOR3 pos, CScene2D* pScene2D);
    void Uninit(void);
    void Update(void);
    void Draw(void);

private:
    static LPDIRECT3DTEXTURE9 m_pTexture;       // �e�N�X�`���ւ̃|�C���^
    static char* m_apTextureName;               // �e�N�X�`���̃t�@�C����

    CScene2D* m_pScene2D;                         //���[�U�[�̎�����̃A�h���X
    int m_nLaserLength;                         // ���[�U�[�̒���
};

#endif // ! _LASER_H_
