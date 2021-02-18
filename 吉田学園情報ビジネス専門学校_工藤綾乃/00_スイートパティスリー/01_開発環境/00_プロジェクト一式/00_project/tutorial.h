//=============================================================================
//
// �`���[�g���A������ [tutorial.h]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef _TUTORIAL_H_
#define _TUTORIAL_H_
#include "main.h"

//*****************************************************************************
// �O���錾
//*****************************************************************************
class CScene2D;
class CPlayer;
class CBg;

//*****************************************************************************
// �N���X��`
//*****************************************************************************
class CTutorial
{
public:
    // �`���[�g���A���̃X�e�b�v�̗񋓌^
    typedef enum
    {
        STEP_ITEM,
        STEP_POWERUP,
        STEP_MAX
    }STEP;

    CTutorial();
    ~CTutorial();

    static CTutorial *Create(void);

    static HRESULT Load(void);
    static void Unload(void);

    void Init(void);
    void Uninit(void);
    void Update(void);
    void Draw(void);

private:
    static LPDIRECT3DTEXTURE9 m_pTexture;      // �e�N�X�`���ւ̃|�C���^
    static char              *m_pTextureName;  // �e�N�X�`���̃t�@�C����

     CScene2D          *m_pPolygon;      // �|���S���ւ̃|�C���^
    static CPlayer           *m_pPlayer;       // �v���C���[�I�u�W�F�N�g�ւ̃|�C���^
    static CBg               *m_pBg;           // �w�i�I�u�W�F�N�g�ւ̃|�C���^

};
#endif // !_TUTORIAL_H_