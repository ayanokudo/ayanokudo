//=============================================================================
//
// ���̏��� [star.h]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef _STAR_H_
#define _STAR_H_
#include "triangle.h"

//*********************************************************+********************
// �}�N����`
//*****************************************************************************
#define MAX_TRIANGLE  (2)

//*********************************************************+********************
// �N���X�̒�`
//*****************************************************************************
// ���̃I�u�W�F�N�g�N���X
class CStar : public CScene
{
public:
    CStar();
    CStar(D3DXVECTOR3 pos, D3DXVECTOR3 move);
    ~CStar();

    static CStar *Create(D3DXVECTOR3 pos, D3DXVECTOR3 move);

    HRESULT Init();
    void Uninit(void);
    void Update(void);
    void Draw(void);

    void SetPosition(D3DXVECTOR3 pos) { m_pos = pos; }// �ʒu�̐ݒ�
    D3DXVECTOR3 GetPosition(void) { return m_pos; }

    void SetSize(const float x, const float y) { m_size = D3DXVECTOR3(x, y, 0.0f); }
    D3DXVECTOR3 GetSize(void) { return m_size; }

    // �ړ��ʂ̃Z�b�^/�Q�b�^
    void SetMove(D3DXVECTOR3 move) { m_move = move; }
    D3DXVECTOR3 GetMove(void) { return m_move; }

    // �����蔻��
    CScene* JudgeFittingRectangle(CScene::OBJTYPE type);
    CScene* CheckCircleCollision(CScene::OBJTYPE type);
private:
    CScene* m_pScene;//������̃A�h���X(�^�C�g����ʗp)
    CTriangle *m_pTriangle[MAX_TRIANGLE];

    D3DXVECTOR3 m_pos;      // �ʒu
    D3DXVECTOR3 m_move;     // �ړ���
    D3DXVECTOR3 m_size;     // �傫��
    

    bool IsItemAppeared;// �A�C�e�����o��������
};
#endif // !_STAR_H_
