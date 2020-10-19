//=============================================================================
//
// �^�C�g���̏��� [title.h]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef _TITLE_H_
#define _TITLE_H_
#include "manager.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define MAX_STAR_TITLE (64)    // �^�C�g����ʂɕ\���ł��鐯�I�u�W�F�N�g�̐�

//*****************************************************************************
// �O���錾
//*****************************************************************************
class CScene2D;
class CStar;

//*****************************************************************************
// �N���X�̒�`
//*****************************************************************************
class CTitle
{
public:

    // �^�C�g����ʂ̕\��
    typedef enum
    {
        TITLE_BG = 0,       // �w�i
        TITLE_LOGO,         // �^�C�g�����S
        TITLE_PRESS_BUTTON, // �{�^���������Ă���������UI
        TITLE_MAX
    }TITLE;    // �{�^���������Ă�������

    CTitle();
    ~CTitle();

    static CTitle *Create(void);

    static HRESULT Load(void);
    static void Unload(void);

    HRESULT Init(void);
    void Uninit(void);
    void Update(void);
    void Draw(void);
    
    void UpdatePolygon(void);

private:
    static LPDIRECT3DTEXTURE9 m_pTexture[TITLE_MAX];// �e�N�X�`���ւ̃|�C���^
    static TEXTURE_DATA m_aTextureDate[TITLE_MAX];  // �^�C�g���̃e�N�X�`���̃f�[�^

    CScene2D *m_apPolygon[TITLE_MAX];               // �\������|���S���ւ̃|�C���^

    float   m_fAlpha;                               // UI�̃A���t�@�l�̕ύX�p�ϐ�
    D3DXCOLOR m_color;                              // UI�_�ŗp�J���[�ϐ�

    int m_nCountWait;                               // �ҋ@����
    static CStar* m_pStar[MAX_STAR_TITLE];// ���̏��̃|�C���^
};
#endif // _TITLE_H_
