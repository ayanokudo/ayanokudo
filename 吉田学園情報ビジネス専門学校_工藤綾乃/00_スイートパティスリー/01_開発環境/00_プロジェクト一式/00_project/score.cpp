//=============================================================================
//
// �X�R�A�֌W�̏��� [score.h]
// Author : AYANO KUDO
//
//=============================================================================
#include "score.h"
#include "manager.h"
#include "renderer.h"
#include "number.h"

//*****************************************************************************
// �ÓI�����o�ϐ��錾
//*****************************************************************************
LPDIRECT3DTEXTURE9 CScore::m_pTexture;

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define NUM_RADIX    (10.0f)    // �X�R�A�̊
#define SCORE_SIZE_X (30.0f)    // �X�R�A�̐����̕�
#define SCORE_SIZE_Y (60.0f)    // �X�R�A�̐����̍���

//=============================================================================
// [CScore] �R���X�g���N�^
//=============================================================================
CScore::CScore()
{
    SetObjtype(OBJTYPE_UI);
}

//=============================================================================
// [~CScore] �f�X�g���N�^
//=============================================================================
CScore::~CScore()
{

}

//=============================================================================
// [Create] �I�u�W�F�N�g�̐���
//=============================================================================
CScore * CScore::Create(D3DXVECTOR3 pos)
{
    CScore *pScore = NULL;
    if (!pScore)
    {
        pScore = new CScore;
        pScore->Init(pos);
    }
    return pScore;
}


//=============================================================================
// [Init] ����������
//=============================================================================
HRESULT CScore::Init(void)
{
    return E_FAIL;
}

//=============================================================================
// [Init] ����������
// ����
// pos : �ʒu
//=============================================================================
HRESULT CScore::Init(D3DXVECTOR3 pos)
{
    for (int nCount = 0; nCount < MAX_SCORE_NUM; nCount++)
    {
        m_pos = D3DXVECTOR3(pos.x - SCORE_SIZE_X / 2 -(nCount * SCORE_SIZE_X), pos.y + SCORE_SIZE_Y / 2.0f, 0.0f);
        m_apNumber[nCount] = CNumber::Create(m_pos, D3DXVECTOR3(SCORE_SIZE_X, SCORE_SIZE_Y, 0.0f));
        m_apNumber[nCount]->SetNumber(0);   // ����������(0��\������)
        m_nScere = 0;
    }
    return S_OK;
}

//=============================================================================
// [Uninit] �I������
//=============================================================================
void CScore::Uninit(void)
{
    // �X�R�A�̌������I������
    for (int nCount = 0; nCount < MAX_SCORE_NUM; nCount++)
    {
        if ( m_apNumber[nCount])
        {
            m_apNumber[nCount]->Uninit();
            delete m_apNumber[nCount];
            m_apNumber[nCount] = NULL;
        }
    }
    Release();      // �X�R�A���g���폜
}

//=============================================================================
// [Update] �X�V����
//=============================================================================
void CScore::Update(void)
{

}

//=============================================================================
// [Draw] �`�揈��
//=============================================================================
void CScore::Draw(void)
{
    for (int nCount = 0; nCount < MAX_SCORE_NUM; nCount++)
    {
        m_apNumber[nCount]->Draw();
    }
}

//=============================================================================
// [SetScore] �X�R�A�̐ݒ�
// nValue : ���������X�R�A
//=============================================================================
void CScore::SetScore(int nValue)
{
    m_nScere += nValue;

    for (int nCount = 0; nCount < MAX_SCORE_NUM; nCount++)
    {
        int nScore = (int)powf(NUM_RADIX, (float)nCount + 1);
        int nScore2 = (int)powf(NUM_RADIX, (float)nCount);
        int nAnswer = m_nScere % nScore / nScore2;

        m_apNumber[nCount]->SetNumber(nAnswer);
    }
}