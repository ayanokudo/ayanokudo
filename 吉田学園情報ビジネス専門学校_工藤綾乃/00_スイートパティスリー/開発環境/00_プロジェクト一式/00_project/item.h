//=============================================================================
//
// �A�C�e���̏��� [item.h]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef _ITEM_H_
#define _ITEM_H_
#include"scene2d.h"

//*****************************************************************************
// �N���X��`
//*****************************************************************************
// �A�C�e���N���X
class CItem : public CScene2D
{
public:
    // �A�C�e���̎��
    typedef enum
    {
        TYPE_000 = 0, // �p���[�A�b�v
        TYPE_001,     // ���E�\�N
        TYPE_MAX
    }TYPE;

    // �A�C�e���̃f�[�^
    typedef struct
    {
        char* pTextureName;   // �t�@�C����
        D3DXVECTOR3 size;     // �A�C�e���̃T�C�Y
    }ITEM_DATA;

    CItem();
    ~CItem();

    static CItem *Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, TYPE type, bool bIsFlip);

    static HRESULT Load(void);
    static void Unload(void);

    HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 move, TYPE type, bool bIsFlip);
    void Uninit(void);
    void Update(void);
    void Draw(void);

    void PowerUp(void);
    void RecoverEnergy(void);

private:
    static LPDIRECT3DTEXTURE9 m_apTexture[TYPE_MAX];        // �e�N�X�`���ւ̃|�C���^
    static ITEM_DATA m_aItemData[TYPE_MAX];                 // �A�C�e���̏��

    D3DXVECTOR3 m_move;                                     // �ړ���
    TYPE m_type;                                            // ���
    bool m_bIsFlip;                                         // �e�N�X�`���̏㉺�𔽓]�����邩�ǂ���
};
#endif // !_ITEM_H_
