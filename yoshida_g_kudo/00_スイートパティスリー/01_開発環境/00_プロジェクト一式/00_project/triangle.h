//=============================================================================
//
// �O�p�`�̃|���S���̏��� [triangle.cpp]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_
#include "scene.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define NUM_POLYGON_TRIANGLE (1)              // �O�p�`�̃|���S����
#define NUM_VERTEX_TRIANGLE (3)               // �O�p�`�̒��_��
#define POLIGON_SIZE (50.0f)                  // �|���S���̃T�C�Y

//*****************************************************************************
// �N���X�̒�`
//*****************************************************************************
// �O�p�`�̃|���S���N���X
class CTriangle : public CScene
{
public:
    CTriangle();
    CTriangle(D3DXVECTOR3 pos);
    ~CTriangle();

    static CTriangle *Create(D3DXVECTOR3 pos);

    HRESULT Init(void);
    void Uninit(void);
    void Update(void);
    void Draw(void);

    // �ʒu�̃Z�b�^�[/�Q�b�^�[
    void SetPosition(D3DXVECTOR3 pos) { m_pos = pos; }
    D3DXVECTOR3 GetPosition(void) { return m_pos; }

    // �ړ��ʂ̃Z�b�^�[/ �Q�b�^�[
    void SetMove(D3DXVECTOR3 move) { m_move = move; }
    D3DXVECTOR3 GetMove(void) { return m_move; }

    // �T�C�Y�̃Z�b�^�[/�Q�b�^�[
    void SetSize(const float x, const float y) { m_size = D3DXVECTOR3(x, y, 0.0f); }
    D3DXVECTOR3 GetSize(void) { return m_size; }

    // ������܂ł̎��ԃZ�b�^�[/�Q�b�^�[
    void SetLife(int nDamage) { m_nLife = nDamage; }
    int GetLife(void) { return m_nLife; }

    void SetColor(D3DXCOLOR color);

    void SetRadian(float fRadian) { m_fRadian = fRadian; }

    void Rotation(float fRadian);
private:
    D3DXVECTOR3 m_pos;      // �ʒu
    D3DXVECTOR3 m_move;     // �ړ���
    D3DXVECTOR3 m_size;     // �傫��
    int m_nLife;            // ������܂ł̃J�E���g

    LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;     // ���_�o�b�t�@�ւ̃|�C���^

    float m_fRadian;          // ��]�p
    float m_fRenge;           // �����_�܂ł̋��� (�g�k�p)
    float m_fScaling;         // (�g�k�p)
};
#endif // !_TRIANGLE_H_
