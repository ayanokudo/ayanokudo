//=============================================================================
//
// �w�i�̏��� [bg.h]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef _BG_H_
#define _BG_H_
#include "scene.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define MAX_BG       (3)        // �w�i�̖���
#define SCROLL_SPEED (0.0005f)    // �X�N���[���X�s�[�h

//*****************************************************************************
// �O���錾
//*****************************************************************************
class CScene2D;

//*****************************************************************************
// �N���X�̒�`
//*****************************************************************************
class  CBg : public CScene
{
public:
     CBg();
    ~CBg();

    static CBg *Create(void);
    static HRESULT Load(void);
    static void Unload(void);

    HRESULT Init(void);
    void Uninit(void);
    void Update(void);
    void Draw(void);

    void SetPosition(D3DXVECTOR3 pos) { m_pos = pos; }// �ʒu�̐ݒ�
    D3DXVECTOR3 GetPosition(void) { return m_pos; }
    D3DXVECTOR3 GetSize(void) { return m_size; }

    // �v���C���[�̓����ɂ��킹���X�N���[���̃Z�b�^/�Q�b�^
    void SetPlayerScroll(D3DXVECTOR2 playerScroll) { m_playerScroll = playerScroll; }
    D3DXVECTOR2 GetPlayerScroll(void) {return m_playerScroll; }

private:
    D3DXVECTOR2 m_Scroll;
    D3DXVECTOR2 m_playerScroll;     // �v���C���[�̓����ɍ��킹�ăX�N���[������
    D3DXVECTOR3 m_pos;
    D3DXVECTOR3 m_size;

    static LPDIRECT3DTEXTURE9 m_apTexture[MAX_BG];   // �e�N�X�`���ւ̃|�C���^
    CScene2D *m_apScene2D[MAX_BG];                   // 2D�|���S���ւ̃|�C���^
    static char* m_pTextureName[MAX_BG];             // �e�N�X�`���t�@�C����

};
#endif // !_BG_H_
