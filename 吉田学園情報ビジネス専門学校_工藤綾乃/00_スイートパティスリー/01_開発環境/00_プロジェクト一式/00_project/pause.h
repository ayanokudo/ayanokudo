//=============================================================================
//
// �|�[�Y���� [pause.h]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef _PAUSE_H_
#define _PAUSE_H_
#include "main.h"
#include "scene.h"

//*****************************************************************************
// �O���錾
//*****************************************************************************
class CPolygon;

//*****************************************************************************
// �N���X��`
//*****************************************************************************
class CPause : public CScene
{
public:
    // �|�[�Y���j���[
    typedef enum
    {
        PAUSE_000,// �Q�[���𑱂���
        PAUSE_001,// �Q�[������߂�
        PAUSE_MAX
    }PAUSE;

    CPause();
    ~CPause();

    static CPause* Create(void);

    static HRESULT Load(void);
    static void    Unload(void);

    HRESULT Init(void);
    void Uninit(void);
    void Update(void);
    void Draw(void);

private:
    static LPDIRECT3DTEXTURE9 m_pTexture;  // �e�N�X�`���ւ̃|�C���^
    static char* m_pTextureName;            // �ǂݍ��ރe�N�X�`���t�@�C����
    CPolygon *m_apPolygon[PAUSE_MAX];// �|�[�Y���ɕ\������|���S���ւ̃|�C���^

    int m_nSelectNum;               // �I�����Ă��郁�j���[�ԍ�
};
#endif // !_PAUSE_H_