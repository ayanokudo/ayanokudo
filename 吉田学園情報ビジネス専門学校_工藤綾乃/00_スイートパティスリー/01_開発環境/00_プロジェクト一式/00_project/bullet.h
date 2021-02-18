//=============================================================================
//
// �e�̏��� [bullet.h]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef  _BULLET_H_
#define _BULLET_H_
#include "scene2d.h"

//*****************************************************************************
// �N���X�̒�`
//*****************************************************************************
// �e�̃N���X
class CBullet : public CScene2D
{
public:
    // �e�̃^�C�v
    typedef enum
    {
        TYPE_PLAYER = 0,
        TYPE_ENEMY,
        TYPE_MAX
    }TYPE;

    CBullet();
    ~CBullet();

    static CBullet *Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, TYPE type, CScene* pScene);

    static HRESULT Load(void);
    static void Unload(void);

    HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 move, TYPE type, CScene* pScene);
    void Uninit(void);
    void Update(void);
    void Draw(void);

    // �e�̃^�C�v�̃Q�b�^/�Z�b�^
    void SetType(TYPE type) { m_type = type; }
    TYPE GetType(void) { return m_type; }
private:
    static LPDIRECT3DTEXTURE9 m_apTexture[TYPE_MAX];   // �e�N�X�`���ւ̃|�C���^�@
    static char *m_apTextureName[TYPE_MAX];

    CScene* m_pScene;//�e�̎�����̃A�h���X
    D3DXVECTOR3 m_move;     // �ړ���
    TYPE m_type;
    int m_nLife;

};

#endif // ! _BULLET_H_
