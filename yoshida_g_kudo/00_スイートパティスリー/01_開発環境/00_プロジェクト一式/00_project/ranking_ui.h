//=============================================================================
//
// �����L���OUI���� [ranking_ui.h]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef _RANKING_UI_H_
#define _RANKING_UI_H_
#include "main.h"
#include "scene2d.h"
#include "ranking.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define MAX_RANKING_UI ((MAX_RANKING_SCORE * 2)+2)      // UI�̐�

//*****************************************************************************
// �N���X��`
//*****************************************************************************
class CRanking_UI : public CScene2D
{
public:
    // �\������|���S���̗̂񋓌^
    typedef enum
    {
        UI_000 = 0,// �w�i
        UI_001,    // �����L���O�̕���
        UI_002,    // ���ʂ̕���
        UI_003,    // ���_�̕���
        UI_MAX
    }UI;

    CRanking_UI();
    ~CRanking_UI();

    static CRanking_UI* Create(void);

    static HRESULT      Load(void);
    static void         Unload(void);

    HRESULT Init(void);
    void    Uninit(void);
    void    Update(void);
    void    Draw(void);

private:
    static LPDIRECT3DTEXTURE9 m_apTexture[UI_MAX];     // �e�N�X�`���ւ̃|�C���^
    static TEXTURE_DATA textureData[UI_MAX];     // �e�N�X�`�����
    CScene2D *apScene2D[MAX_RANKING_UI];               // 2D�|���S���ւ̃|�C���^
};
#endif // !_RANKING_UI_H_
