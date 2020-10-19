//=============================================================================
//
// ���U���g��ʂ̏��� [result.h]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef _RESULT_H_
#define _RESULT_H_
#include "main.h"
#include "manager.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define MAX_RESULT (2) 

//*****************************************************************************
// �O���錾
//*****************************************************************************
class CScene2D;

//*****************************************************************************
// �N���X�̒�`
//*****************************************************************************
class CResult
{
public:
    // ���U���g��ʂ̃e�N�X�`��
    typedef enum
    {
        RESURT_TEXTURE_BG=0,
        RESURT_TEXTURE_GAME_CLEAR,
        RESURT_TEXTURE_GAME_OVER,
        RESURT_TEXTURE_MAX
    }RESURT_TEXTURE;

    CResult();
    ~CResult();

    static CResult *Create(bool IsClearedGame);

    static HRESULT Load(void);
    static void Unload(void);

    HRESULT Init(bool IsClearedGame);
    void Uninit(void);
    void Update(void);
    void Draw(void);

private:
    static char                *m_apTextureName[RESURT_TEXTURE_MAX];
    static LPDIRECT3DTEXTURE9   m_pTexture[RESURT_TEXTURE_MAX-1];
    static D3DXVECTOR3          m_pos[RESURT_TEXTURE_MAX-1];
    static D3DXVECTOR3          m_size[RESURT_TEXTURE_MAX-1];
    CScene2D                   *m_apPolygon[RESURT_TEXTURE_MAX-1];
    static bool                 m_IsClearedGame;                               // �Q�[�����N���A�������ǂ���

};
#endif // _RESULT_H_
