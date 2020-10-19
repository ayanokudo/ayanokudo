//=============================================================================
//
// �I�v�V�����̏���[option.h]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef _OPTION_H_
#define _OPTION_H_
#include "scene2D.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define OPTION_LENGTH (15)//�I�v�V�����̊Ԋu

//*****************************************************************************
// �N���X��`
//*****************************************************************************
class COption :public CScene2D
{
public:
    COption();
    ~COption();

    static COption* Create(D3DXVECTOR3 pos);

    static HRESULT Load(void);
    static void Unload(void);

    HRESULT Init(D3DXVECTOR3 pos);
    void Uninit(void);
    void Update(void);
    void Draw(void);

    void Move(void);

    // �e�̐��̃Z�b�^/�Q�b�^
    void SetCountBullet(int nCntBullet) { m_nCntBullet = nCntBullet; }
    int GetCountBullet(void) { return m_nCntBullet; }

    // �~�T�C���̐��Z�b�^/�Q�b�^
    void SetCountMissile(int nCountMissile) { m_nCntMissile = nCountMissile; }
    int GetCountMissile(void) { return m_nCntMissile; }

private:
    static LPDIRECT3DTEXTURE9 m_pTexture;        // �e�N�X�`���ւ̃|�C���^
    static char* m_pTextureName;        // �e�N�X�`����
    D3DXVECTOR3 m_aOrbit[OPTION_LENGTH];// �I�v�V�����̋O��
    int m_nOptNum;// �I�v�V�����̔ԍ�
    int m_nIndex;
    int m_nCntBullet;       //�e�̐�
    int m_nCntMissile;      // �~�T�C���̐�

    int m_nShotInterval;    // �V���b�g�̔��ˊԊu
    int m_nIntervalMissile; // �~�T�C���̔��ˊԊu

};
#endif // !_OPTION_H_
