//=============================================================================
//
// �������� [explosion.h]
// Author : AYANO KUDO
//
//=============================================================================
#include "scene2d.h"

//******************************************************************************
// �N���X�̒�`
//******************************************************************************
// �����̃N���X
class CExplosion : CScene2D
{
public:
    CExplosion();
    ~CExplosion();

    static HRESULT Load(void);
    static void Unload(void);

    static CExplosion *Create(D3DXVECTOR3 pos);
    HRESULT Init(D3DXVECTOR3 pos);
    void Uninit();
    void Update(void);
    void Draw(void);

private:
    static LPDIRECT3DTEXTURE9 m_pTexture;
    int m_nCounterAnim;     // �J�E���^�[
    int m_nPotternAnim;     // �p�^�[��ID

};