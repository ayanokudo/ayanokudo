//=============================================================================
//
// �t�F�[�h�̏��� [fade.h]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef _FADE_H_
#define _FADE_H_
#include "main.h"
#include "manager.h"

//*****************************************************************************
// �O���錾
//*****************************************************************************
class CPolygon;

//*****************************************************************************
// �N���X�̒�`
//*****************************************************************************
class CFade
{
public:
    typedef enum
    {
        FADE_NONE = 0,
        FADE_IN,
        FADE_OUT
    }FADE;

    CFade();
    ~CFade();

    static CFade *Create(void);

    void Init(void);
    void Uninit(void);
    void Update(void);
    void Draw(void);

    static void SetFade(CManager::MODE modeNext);
    FADE GetFade(void) { return m_fade; };

private:
    static FADE             m_fade;               // �t�F�[�h�̏��
    static CManager::MODE   m_modeNext;           // ���̃��[�h

    CPolygon        *m_pScene2D;           // �|���S���̏��
    D3DXCOLOR        m_colorFade;          //�t�F�[�h�̐F
};
#endif // _FADE_H_
