//=============================================================================
//
// �V�[���h���� [shield.cpp]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef _SHIELD_H_
#define _SHIELD_H_
#include "scene2d.h"

//*****************************************************************************
// �O���錾
//*****************************************************************************
class CPlayer;

//*****************************************************************************
// �N���X�̒�`
//*****************************************************************************
class CShield : CScene2D
{
public:
    CShield();
    ~CShield();

    static CShield *Create(D3DXVECTOR3 pos, CPlayer* pPlayer);

    static HRESULT Load(void);
    static void Unload(void);

    HRESULT Init(D3DXVECTOR3 pos, CPlayer* pPlayer);
    void Uninit(void);
    void Update(void);
    void Draw(void);

    //�V�[���h�̃_���[�W�ݒ�
    void Damage(void);
    // �V�[���h�̑ϋv�l�̃Z�b�^/�Q�b�^
    void SetDurableValue(int DurableValue) { m_nDurableValue = DurableValue; }
    int GetDurableValue(void) { return m_nDurableValue; }

private:
    static LPDIRECT3DTEXTURE9       m_pTexture;       // �e�N�X�`���ւ̃|�C���^
    static char                    *m_pTextureName;   // �e�N�X�`���̃t�@�C����
    int                             m_nDurableValue;  // �V�[���h�̑ϋv�l
    CPlayer*                         m_pPlayer;        // �V�[���h�̎�����ւ̃|�C���^
};
#endif // !_SHIELD_H_