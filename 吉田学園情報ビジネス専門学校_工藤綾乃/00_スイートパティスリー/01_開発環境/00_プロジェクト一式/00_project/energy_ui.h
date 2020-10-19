//=============================================================================
//
// �G�l���M�[�\���̏��� [energy_ui.h]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef _ENERGY_UI_H_
#define _ENERGY_UI_H_
#include "main.h"
#include "scene.h"

//*****************************************************************************
// �O���錾
//*****************************************************************************
class CPolygon;

//*****************************************************************************
// �N���X��`
//*****************************************************************************
class CEnergy_UI : public CScene
{
public:
    CEnergy_UI();
    ~CEnergy_UI();

    static CEnergy_UI* Create(void);

    static HRESULT Load(void);
    static void Unload(void);

    HRESULT Init(void);
    void Uninit(void);
    void Update(void);
    void Draw(void);

private:
    D3DXVECTOR3                   m_pos;
    D3DXVECTOR3                   m_size;
    CPolygon                     *m_pPolygon;              // �|���S���ւ̃|�C���^
    static LPDIRECT3DTEXTURE9     m_pTexture;               // �e�N�X�`���ւ̃|�C���^
    static char                  *m_pTextureName;          // �e�N�X�`����
};
#endif // !_ENERGY_UI_H_
