//=============================================================================
//
// �n�`���� [terrain.h]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef _TERRAIN_H_
#define _TERRAIN_H_
#include "main.h"
#include "scene2d.h"
//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define TERRAIN_SIZE_X (50.0f)
#define TERRAIN_SIZE_Y (50.0f)

//*****************************************************************************
// �N���X�̒�`
//*****************************************************************************
class CTerrain : CScene2D
{
public:
    typedef enum
    {
        TYPE_000 = 0,
        TYPE_MAX
    }TYPE;

    CTerrain();
    ~CTerrain();

    static CTerrain *Create(D3DXVECTOR3 pos);

    static HRESULT Load(void);
    static void Unload(void);

    void Init(D3DXVECTOR3 pos);
    void Uninit(void);
    void Update(void);
    void Draw(void);

    // �ړ��ʂ̃Z�b�^/�Q�b�^
    static void        SetMove(D3DXVECTOR3 move) { m_move = move; }
    static D3DXVECTOR3 GetMove(void) { return m_move; }


private:
    static LPDIRECT3DTEXTURE9 m_pTexture[TYPE_MAX]; // �e�N�X�`���ւ̃|�C���^
    static char* m_apTextureName[TYPE_MAX];         // �e�N�X�`���̃t�@�C����

    static D3DXVECTOR3 m_move;                             // �ړ���

};

#endif // ! _TERRAIN_H_

