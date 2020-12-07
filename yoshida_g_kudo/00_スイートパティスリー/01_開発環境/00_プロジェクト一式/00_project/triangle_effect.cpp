//=============================================================================
//
// �O�p�`�G�t�F�N�g���� [triangle_effect.cpp]
// Author : AYANO KUDO
//
//=============================================================================
#include "triangle_effect.h"
#include "triangle.h"
#include "player.h"
#include <stdlib.h>     // �����g�p

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define EFFECT_SPEED (10)
#define EFFECT_LIFE (20)            // �G�t�F�N�g��������܂ł̎���

//=============================================================================
// [CTriangle_Effect] �R���X�g���N�^
// ����
// pos  : �ʒu
// nNum : ��������G�t�F�N�g�̐�
//=============================================================================
CTriangle_Effect::CTriangle_Effect(D3DXVECTOR3 pos, int nNum)
{
    // �e�����o�ϐ�������
    m_pos = pos;
    m_nLife = 0;
    m_nEffectCount = 0;
    m_nNumEffect = nNum;
    for (int nCntEffect = 0; nCntEffect < MAX_EFFECT; nCntEffect++)
    {
        m_pTriangle[nCntEffect] = NULL;
    }
}

//=============================================================================
// [~CTriangle_Effect] �f�X�g���N�^
//=============================================================================
CTriangle_Effect::~CTriangle_Effect()
{
}

//=============================================================================
// [Create] �I�u�W�F�N�g�̐���
//=============================================================================
CTriangle_Effect *CTriangle_Effect::Create(D3DXVECTOR3 pos, int nNum)
{
    CTriangle_Effect *pEffect = NULL;
    if (!pEffect)
    {
        pEffect = new CTriangle_Effect(pos, nNum);
        pEffect->Init();
    }
    return pEffect;
}

//=============================================================================
// [Init] ����������
//=============================================================================
HRESULT CTriangle_Effect::Init()
{
    m_nLife = EFFECT_LIFE;                      // ������܂ł̎���

    // �G�t�F�N�g�̐������[�v
    for (int nCntEffect = 0; nCntEffect < m_nNumEffect; nCntEffect++)
    {
        // �G�t�F�N�g�̐ݒ�
        float fSpeed = (float)(rand() % EFFECT_SPEED + 1);                           // ���x(�����_��)
        float fAngle = (rand() % 314 / 100.0f)*(rand() % 20) * -1;          // �p�x
        D3DXVECTOR3 move = D3DXVECTOR3((float)sin(fAngle)*fSpeed, (float)cos(fAngle)*fSpeed, 0.0f);
        m_pTriangle[nCntEffect] = CTriangle::Create(m_pos);
        m_pTriangle[nCntEffect]->SetColor(D3DCOLOR_RGBA(rand() % 255, rand() % 255, rand() % 255, rand() % 255));
        m_pTriangle[nCntEffect]->SetSize((float)(rand() % 50 + 1), (float)(rand() % 20 + 1));
        m_pTriangle[nCntEffect]->SetObjtype(OBJTYPE_EFFECT);
        m_pTriangle[nCntEffect]->SetMove(move);
    }
    return S_OK;
}

//=============================================================================
// [Uninit] �I������
//=============================================================================
void CTriangle_Effect::Uninit(void)
{
    for (int nCntEffect = 0; nCntEffect < MAX_EFFECT; nCntEffect++)
    {
        if (m_pTriangle[nCntEffect])
        {
            m_pTriangle[nCntEffect]->Uninit();
            m_pTriangle[nCntEffect] = NULL;
        }
    }
    Release();
}

//=============================================================================
// [Update] �X�V����
//=============================================================================
void CTriangle_Effect::Update(void)
{
    m_nLife--;

    // �ʒu�̍X�V
    for (int nCntEffect = 0; nCntEffect < MAX_EFFECT; nCntEffect++)
    {
        // �G�t�F�N�g��NULL�ɂȂ��Ă��Ȃ����m�F
        if (m_pTriangle[nCntEffect])
        {
            D3DXVECTOR3 pos = m_pTriangle[nCntEffect]->GetPosition();
            D3DXVECTOR3 move = m_pTriangle[nCntEffect]->GetMove();
            pos += move;
            m_pTriangle[nCntEffect]->SetPosition(pos);
            m_pTriangle[nCntEffect]->Rotation(0.1f);

            // �G�t�F�N�g�̊�ʒu���v���C���[�̏����ʒu�ɋ߂Â�����
            if (pos.x >= 200 - 70.0f &&
                pos.x <= 200 + 70.0f &&
                pos.y >= 300 - 70.0f &&
                pos.y <= 300 + 70.0f)
            {
                m_nEffectCount++;
            }
        }

    }

    //�v���C���[�̏��擾
    for (int nCount = 0; nCount < MAX_POLYGON; nCount++)
    {
        CScene *pScene = GetSceneObject(nCount);
        if (pScene != NULL)
        {
            if (pScene->GetObjectType() == CScene::OBJTYPE_PLAYER)
            {
                if (m_nLife <= 0 && ((CPlayer*)pScene)->GetLife() > 0)
                {
                    SetMove(D3DXVECTOR3(200.0f, 360.0f, 0.0f));// �v���C���\�̏����ʒu�ɃG�t�F�N�g���W�߂�
                }
                if (m_nEffectCount >= MAX_EFFECT)
                {
                    // �v���C���[�̈ʒu�������ʒu�ɂ��ĉ�ʂɕ\��
                    ((CPlayer*)pScene)->SetPosition(D3DXVECTOR3(200.0f, 360.0f, 0.0f));
                    ((CPlayer*)pScene)->SetAlive(true);
                    ((CPlayer*)pScene)->SetPlayerState(CPlayer::PLAYER_STATE_INVINCIBLE);
                    ((CPlayer*)pScene)->SetInvincibleCount(60);// ���G���Ԃ̐ݒ�
                    // �G�t�F�N�g�̍폜
                    Uninit();
                }
            }
        }
    }
}

//=============================================================================
// [Draw] �`�揈��
//=============================================================================
void CTriangle_Effect::Draw(void)
{
    
}
//=============================================================================
// [SetMove] �ړ�����ʒu�̐ݒ�
// ����
// Orbit : ���̖ڕW���W
//=============================================================================
void CTriangle_Effect::SetMove(D3DXVECTOR3 TargetPos)
{
    for (int nCntEffect = 0; nCntEffect < MAX_EFFECT; nCntEffect++)
    {
        // �G�t�F�N�g��NULL�ɂȂ��Ă��Ȃ����m�F
        if (m_pTriangle[nCntEffect])
        {
    D3DXVECTOR3 pos = m_pTriangle[nCntEffect]->GetPosition();
    // �ڕW�܂ł̊p�x�����߂�
    float fRadian = (float)atan2(TargetPos.y - pos.y, TargetPos.x - pos.x);
    m_move = D3DXVECTOR3(cosf(fRadian)*EFFECT_SPEED, sinf(fRadian)*EFFECT_SPEED, 0.0f);
    m_pTriangle[nCntEffect]->SetMove(D3DXVECTOR3(cosf(fRadian)*EFFECT_SPEED, sinf(fRadian)*EFFECT_SPEED, 0.0f));
        }
    }

}
