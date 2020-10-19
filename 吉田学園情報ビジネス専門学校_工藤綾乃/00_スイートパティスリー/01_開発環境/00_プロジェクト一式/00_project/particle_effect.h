//=============================================================================
//
// ���q�G�t�F�N�g���� [particle_effect.h]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef _PARTICLE_EFFECT_H_
#define _PARTICLE_EFFECT_H_
#include "scene2d.h"

//*****************************************************************************
// �N���X��`
//*****************************************************************************
class CParticle_Effect : public CScene2D
{
public :
    // �G�t�F�N�g�̎��
    typedef enum
    {
        PARTICLE_TYPE_CIRCLE=0,
        PARTICLE_TYPE_STAR,
        PARTICLE_TYPE_COOKIE,
        PARTICLE_TYPE_MAX
    }PARTICLE_TYPE;

    CParticle_Effect();
    ~CParticle_Effect();

    static CParticle_Effect* Create(D3DXVECTOR3 pos, D3DXVECTOR3 m_move, D3DXVECTOR3 m_ReductionMove,D3DXCOLOR   m_Collor, float m_fSize, float fReductionSize, float m_fReductionAlpha, PARTICLE_TYPE type);

    static HRESULT Load(void);
    static void Unload(void);

    HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 m_move, D3DXVECTOR3 m_ReductionMove,D3DXCOLOR   m_Collor, float m_fSize, float fReductionSize, float m_fReductionAlpha, PARTICLE_TYPE type);
    void Uninit(void);
    void Update(void);
    void Draw(void);

    static void SetBom(D3DXVECTOR3 pos, D3DXVECTOR3 move, D3DXVECTOR3 ReductionMove, D3DXCOLOR Collor, float fSize, float fReductionSize, float fReductionAlpha, PARTICLE_TYPE type);
    static void SetTrajectory(D3DXVECTOR3 pos, D3DXVECTOR3 move, D3DXVECTOR3 ReductionMove, D3DXCOLOR Collor, float fSize, float fReductionSize, float fReductionAlpha, PARTICLE_TYPE type);

private:
    D3DXVECTOR3 m_pos;                            // �ʒu
    D3DXVECTOR3 m_move;                           // �ړ���
    D3DXVECTOR3 m_ReductionMove;                  // �ړ��̌�����
    D3DXCOLOR   m_Collor;                         // �|���S���̐F
    float       m_fSize;                          // �傫��
    float       m_fReductionSize;                 // �傫���̌�����
    float       m_fReductionAlpha;                // �A���t�@�l�̌�����


    static LPDIRECT3DTEXTURE9 m_pTexture[PARTICLE_TYPE_MAX];       // �e�N�X�`���ւ̃|�C���^
    static char *m_pTextureName[PARTICLE_TYPE_MAX];                // �e�N�X�`����

};
#endif // !_PARTICLE_EFFECT_H_
