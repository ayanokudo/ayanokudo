//=============================================================================
//
// ���̏��� [star.cpp]
// Author : AYANO KUDO
//
//=============================================================================
#include "star.h"
#include "scene2d.h"
#include "item.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define MIN_STAR_POS_Y (0.0f - m_size.y)                // ������ւ̌��E�l
#define MAX_STAR_POS_Y (SCREEN_HEIGHT + m_size.y)       // �������ւ̌��E�l
#define MIN_STAR_POS_X (0.0f - m_size.x)                // �������ւ̌��E�l
#define MAX_STAR_POS_X (1280 + m_size.x)                // �E�����ւ̌��E�l

//=============================================================================
// [CStar] �f�t�H���g�R���X�g���N�^
//=============================================================================
CStar::CStar()
{
    memset(m_pTriangle, NULL, sizeof(m_pTriangle));
    m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
    m_move = D3DXVECTOR3(-1.0f, 0.0f, 0.0f);
    m_size = D3DXVECTOR3(POLIGON_SIZE, POLIGON_SIZE, 0.0f);
    SetObjtype(OBJTYPE_STAR);
}

//=============================================================================
// [CStar] �R���X�g���N�^
// ����
// pos  : �ʒu
// move : �ړ���
//=============================================================================
CStar::CStar(D3DXVECTOR3 pos, D3DXVECTOR3 move)
{
    memset(m_pTriangle, NULL, sizeof(m_pTriangle));
    m_pos = pos;
    m_move = move;
    m_size = D3DXVECTOR3(POLIGON_SIZE, POLIGON_SIZE, 0.0f);
    IsItemAppeared = false;
    SetObjtype(OBJTYPE_STAR);
}

//=============================================================================
// [~CStar] �f�X�g���N�^
//=============================================================================
CStar::~CStar()
{

}

//=============================================================================
// [Create] ���̃I�u�W�F�N�g����
//=============================================================================
CStar * CStar::Create(D3DXVECTOR3 pos, D3DXVECTOR3 move)
{
    CStar *pStar = nullptr;
    if (!pStar)
    {
        pStar = new CStar(pos, move);
        pStar->Init();
    }
    return pStar;
}

//=============================================================================
// [Init] ����������
//=============================================================================
HRESULT CStar::Init(void)
{
    for (int nCount = 0; nCount < MAX_TRIANGLE; nCount++)
    {
        m_pTriangle[nCount] = CTriangle::Create(m_pos);
        SetObjtype(OBJTYPE_STAR);
        m_pTriangle[nCount]->SetPosition(m_pos);
    }
    // �O�p�`�̌������݂��Ⴂ�ɂ���
    m_pTriangle[1]->SetRadian(1.0f);
    return S_OK;
}

//=============================================================================
// [Uninit] �I������
//=============================================================================
void CStar::Uninit(void)
{
    for (int nCount = 0; nCount < MAX_TRIANGLE; nCount++)
    {
        if (m_pTriangle[nCount])
        {
            m_pTriangle[nCount]->Uninit();
            m_pTriangle[nCount] = nullptr;
        }
    }
    SetDeathFlag();
}

//=============================================================================
// [Update] �X�V����
//=============================================================================
void CStar::Update(void)
{
    m_pos += m_move;
    for (int nCount = 0; nCount < MAX_TRIANGLE; nCount++)
    {
        m_pTriangle[nCount]->Rotation(0.01f);
        m_pTriangle[nCount]->SetPosition(m_pos);
    }

    // �V���b�g�Ƃ̓����蔻��
    CScene* pScene = CheckRectangleCollision(CScene::OBJTYPE_BULLET);
    if (pScene)
    {
        if (IsItemAppeared == false)
        {
            for (int nCount = 0; nCount < MAX_TRIANGLE; nCount++)
            {
                m_pTriangle[nCount]->SetColor(D3DXCOLOR(1.0f,0.5f,0.5f,0.5f));
            }

            // �G�l���M�[�񕜃A�C�e������
            CItem::Create(m_pos, D3DXVECTOR3(-2.0f, 0.0f, 0.0f),CItem::TYPE_001,false);
            IsItemAppeared = true;
        }
    }

    // ��ʊO�ɏo����폜
    if (m_pos.x <= MIN_STAR_POS_X ||
        m_pos.x >= MAX_STAR_POS_X ||
        m_pos.y <= MIN_STAR_POS_Y ||
        m_pos.y >= MAX_STAR_POS_Y)
    {
        Uninit();
    }
}

//=============================================================================
// [Draw] �`�揈��
//=============================================================================
void CStar::Draw(void)
{
    for (int nCount = 0; nCount < MAX_TRIANGLE; nCount++)
    {
        m_pTriangle[nCount]->Draw();
    }
}

//=============================================================================
// [CheckRectangleCollision] ��`�̓����蔻��
// �Ԃ�l : �������Ă���I�u�W�F�N�g�̃|�C���^
//=============================================================================
CScene * CStar::CheckRectangleCollision(CScene::OBJTYPE type)
{
    // �ϐ��錾
    CScene *pScene = nullptr;

    // �擪�̃A�h���X���擾
    pScene = CScene::GetTop(PRIORITY_MIDDLE_VIEW);
    while (pScene)
    {
        // ���̃A�h���X��ۑ�
        CScene *pNext = pScene->GetNext();
        if (pScene->GetObjectType() == type)
        {
            D3DXVECTOR3 objPos = ((CScene2D*)pScene)->GetPosition();
            D3DXVECTOR3 objSize = ((CScene2D*)pScene)->GetSize();

            // �������Ă�����
            if (m_pos.x - m_size.x / 2 <= objPos.x + objSize.x / 2 &&
                m_pos.x + m_size.x / 2 >= objPos.x - objSize.x / 2 &&
                m_pos.y - m_size.y / 2 <= objPos.y + objSize.y / 2 &&
                m_pos.y + m_size.y / 2 >= objPos.y - objSize.y / 2)
            {
                return pScene;  // �������Ă�����I�u�W�F�N�g�̃A�h���X��Ԃ�
            }
        }
        // ���̃A�h���X���擾
        pScene = pNext;
    }
    return nullptr;// �������Ă��Ȃ���NULL��Ԃ�
}

//=============================================================================
// [CheckCircleCollision] �~�̓����蔻��
// �Ԃ�l : �������Ă���I�u�W�F�N�g�̃|�C���^
//=============================================================================
CScene * CStar::CheckCircleCollision(CScene::OBJTYPE type)
{
    // �ϐ��錾
    CScene *pScene = nullptr;
    // �擪�̃A�h���X���擾
    for (int nPliority = 0; nPliority < PRIORITY_MAX; nPliority++)
    {
        pScene = CScene::GetTop(nPliority);

        while (pScene == NULL)
        {
            // ���̃A�h���X��ۑ�
            CScene *pNext = pScene->GetNext();
            if (pScene != NULL)
            {
                D3DXVECTOR3 objPos = ((CScene2D*)pScene)->GetPosition();
                D3DXVECTOR3 objSize = ((CScene2D*)pScene)->GetSize();

                // �������Ă�����
                float distance = powf(m_pos.x - objPos.x, 2.0f) + powf(m_pos.y - objPos.y, 2.0f) + 0.0f;      //�ʒu
                float radius = powf(m_size.x + objSize.x, 2.0f); //���a
                if (distance <= radius)//�������Ă��邩�ǂ���
                {
                    return pScene;  // �������Ă�����I�u�W�F�N�g�̃A�h���X��Ԃ�
                }
                // ���̃A�h���X���擾
                pScene = pNext;
            }
        }
    }
    return nullptr;// �������Ă��Ȃ���NULL��Ԃ�
}
