//=============================================================================
//
// �i���o�[UI���� [number.h]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef _NUMBER_H_
#define _NUMBER_H_
#include "main.h"

//*****************************************************************************
// �N���X��`
//*****************************************************************************
class CNumber
{
public:
    CNumber();
    ~CNumber();

    static CNumber* Create(D3DXVECTOR3 pos, D3DXVECTOR3 size);

    static HRESULT Load(void);
    static void Unload(void);

    void Init(D3DXVECTOR3 pos, D3DXVECTOR3 size);
    void Uninit(void);
    void Update(void);
    void Draw(void);

    void SetPosition(D3DXVECTOR3 pos) { m_pos = pos; }// �ʒu�̐ݒ�
    D3DXVECTOR3 GetPosition(void) { return m_pos; }     // �ʒu�̎擾

    void SetSize( D3DXVECTOR3 size) { m_size = size; }
    D3DXVECTOR3 GetSize(void) { return m_size; }

    // 0�`9�̔ԍ����w�肷�郁�\�b�h
    void SetNumber(unsigned int nNumber);
private:
    // �����o�ϐ�
    static LPDIRECT3DTEXTURE9 m_pTexture;      // �e�N�X�`���ւ̃|�C���^
    LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;     // ���_�o�b�t�@�ւ̃|�C���^

    D3DXVECTOR3 m_pos;        // �|���S���̈ʒu
    D3DXVECTOR3 m_size;       // �|���S���̃T�C�Y

};
#endif // !_NUMBER_H_


