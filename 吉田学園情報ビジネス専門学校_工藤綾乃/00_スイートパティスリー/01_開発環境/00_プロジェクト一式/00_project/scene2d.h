//=============================================================================
//
// 2D�|���S���`�揈�� [scene2d.h]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef _SCENE2D_H_
#define _SCENE2D_H_
#include "scene.h"

//*****************************************************************************
// �N���X�̒�`
//*****************************************************************************
class CScene2D : public CScene
{
public:
    // �����o�֐�
    CScene2D();
    CScene2D(D3DXVECTOR3 pos, D3DXVECTOR3 size);
    ~CScene2D();

    static CScene2D* Create(D3DXVECTOR3 pos , D3DXVECTOR3 size);

    // �e�N�X�`���̊��蓖��
    void BindTexture(LPDIRECT3DTEXTURE9 pTexture) { m_pTexture = pTexture; }

     HRESULT Init(void);
     void Uninit(void);
     void Update(void);
     void Draw(void);

     // �ʒu�̃Z�b�^/�Q�b�^
     void SetPosition(D3DXVECTOR3 pos) { m_pos = pos; }// �ʒu�̐ݒ�
     D3DXVECTOR3 GetPosition(void) { return m_pos; }

     // �T�C�Y�̃Z�b�^/�Q�b�^
     void SetSize(D3DXVECTOR3 size) { m_size = size; }
     D3DXVECTOR3 GetSize(void) { return m_size; }

     // ���_���̃Z�b�^
     void SetTexture(D3DXVECTOR2 tex, const D3DXVECTOR2 nSplitPolygon);
     void SetTexture(D3DXVECTOR2 tex);
     void SetColor(D3DXCOLOR coror);

     // �����蔻��
     CScene* JudgeFittingRectangle(CScene::OBJTYPE type);
     CScene* CheckCircleCollision(CScene::OBJTYPE type);

private:
    // �����o�ϐ�
    LPDIRECT3DTEXTURE9       m_pTexture;      // �e�N�X�`���ւ̃|�C���^
    LPDIRECT3DVERTEXBUFFER9  m_pVtxBuff;     // ���_�o�b�t�@�ւ̃|�C���^

    D3DXVECTOR3              m_pos;        // �|���S���̈ʒu
    D3DXVECTOR3              m_size;       // �|���S���̃T�C�Y
};

#endif // !_SCENE2D_H_