//=============================================================================
//
// �c�@UI���� [life.h]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef _LIFE_H_
#define _LIFE_H_
#include "scene.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define MAX_LIFE (3)                                    // �c�@�̍ő吔

//*****************************************************************************
// �O���錾
//*****************************************************************************
class CPolygon;

//*****************************************************************************
// �N���X��`
//*****************************************************************************
class CLife : public CScene
{
public:
    CLife();
    CLife(int nLife);
    ~CLife();

    static CLife *Create(int nLife);

    static HRESULT Load(void);
    static void Unload(void);

    HRESULT Init(void);
    void Uninit(void);
    void Update(void);
    void Draw(void);

    void SetLife(int nLife) { m_nLife = nLife; }
private:
    D3DXVECTOR3                 m_pos;
    D3DXVECTOR3                 m_size;
    CPolygon*                   m_apPolygon[MAX_LIFE];

    static LPDIRECT3DTEXTURE9 m_pTexture;      // �e�N�X�`���ւ̃|�C���^
    static char* m_pTextureName;               // �e�N�X�`����

    int m_nLife;
};

#endif // !_LIFE_H_
