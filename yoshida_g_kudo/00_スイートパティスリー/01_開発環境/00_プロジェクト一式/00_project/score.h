//=============================================================================
//
// �X�R�A�֌W�̏��� [score.h]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef  _SCORE_H_
#define _SCORE_H_
#include "scene2d.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define MAX_SCORE_NUM (8)       // �X�R�A�̌���

//*****************************************************************************
// �O���錾
//*****************************************************************************
class CNumber;

//*****************************************************************************
// �N���X�̒�`
//*****************************************************************************
class CScore : public CScene
{
public:
    CScore();
    ~CScore();

    static CScore *Create(D3DXVECTOR3 pos);

    HRESULT Init(void);
    HRESULT Init(D3DXVECTOR3 pos);
    void Uninit(void);

    void Update(void);
    void Draw(void);

    void SetPosition(D3DXVECTOR3 pos) { m_pos = pos; }// �ʒu�̐ݒ�
    D3DXVECTOR3 GetPosition(void) { return m_pos; }
    D3DXVECTOR3 GetSize(void) { return m_size; }

    // �X�R�A�̃Z�b�^/�Q�b�^
    void SetScore(int nValue);
    int GetScore(void) { return m_nScere; }

private:
    D3DXVECTOR3 m_pos;
    D3DXVECTOR3 m_size;

    static LPDIRECT3DTEXTURE9 m_pTexture;     // �e�N�X�`���ւ̃|�C���^
    CNumber                  *m_apNumber[MAX_SCORE_NUM];       // �X�R�A�̃I�u�W�F�N�g[�X�R�A�̌���]
    unsigned int              m_nScere;       // �X�R�A�̒l

};
#endif // ! _SCORE_H_
