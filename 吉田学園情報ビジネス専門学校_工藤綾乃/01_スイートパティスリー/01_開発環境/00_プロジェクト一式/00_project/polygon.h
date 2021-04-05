//=============================================================================
//
// �|���S���̏��� [polygon.h]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef _POLYGON_H_
#define _POLYGON_H_
#include "main.h"

//*****************************************************************************
// �N���X�̒�`
//*****************************************************************************
class CPolygon
{
public:
    CPolygon();
    ~CPolygon();

    static CPolygon* Create(D3DXVECTOR3 pos, D3DXVECTOR3 size);

    void BindTexture(LPDIRECT3DTEXTURE9 pTexture) { m_pTexture = pTexture; }

    HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 size);
    void Uninit(void);
    void Update(void);
    void Draw(void);
    // �ʒu�̃Z�b�^/�Q�b�^
    void SetPosition(D3DXVECTOR3 pos) { m_pos = pos; }// �ʒu�̐ݒ�
    D3DXVECTOR3 GetPosition(void) { return m_pos; }     // �ʒu�̎擾

    // �T�C�Y�̃Z�b�^/�Q�b�^
    void SetSize(D3DXVECTOR3 size) { m_size = size; }
    D3DXVECTOR3 GetSize(void) { return m_size; }

    void SetTexture(D3DXVECTOR2 tex, const D3DXVECTOR2 nSplitPolygon);
    void SetTexture(D3DXVECTOR2 tex);

    void SetColor(D3DXCOLOR color);

private:
    LPDIRECT3DTEXTURE9 m_pTexture;      // �e�N�X�`���ւ̃|�C���^
    LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;        // ���_�o�b�t�@�ւ̃|�C���^

    D3DXVECTOR3 m_pos;                         // �|���S���̈ʒu
    D3DXVECTOR3 m_size;                        // �|���S���̃T�C�Y
};
#endif // !_POLYGON_H_
#pragma once
