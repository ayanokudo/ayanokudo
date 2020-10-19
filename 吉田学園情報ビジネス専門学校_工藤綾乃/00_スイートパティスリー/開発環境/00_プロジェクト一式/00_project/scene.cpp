//=============================================================================
//
// �I�u�W�F�N�g���� [scene.cpp]
// Author : AYANO KUDO
//
//=============================================================================
#include "scene.h"
#include "renderer.h"

//*****************************************************************************
// �ÓI�����o�ϐ�������
//*****************************************************************************
CScene* CScene::m_apScene[MAX_POLYGON] = {};
int CScene::m_nNumAll = 0;

//=============================================================================
// [CScene] �R���X�g���N�^
//=============================================================================
CScene::CScene()
{
    for (int nNumPolygon = 0; nNumPolygon < MAX_POLYGON; nNumPolygon++)
    {
        if (m_apScene[nNumPolygon] == NULL)
        {
            m_apScene[nNumPolygon] = this;

            m_nIndex = nNumPolygon;//�ԍ���ۑ�

            m_nNumAll++; // �����𑝂₷

            break;// 1�̂��ݒ肷�邽�߂Ƀ��[�v������
        }
    }
}

//=============================================================================
// [CScene] �f�X�g���N�^
//=============================================================================
CScene::~CScene()
{

}

//=============================================================================
// [UpdateAll] ���ׂẴI�u�W�F�N�g���X�V
//=============================================================================
void CScene::UpdateAll(void)
{
    for (int nNumPolygon = 0; nNumPolygon < MAX_POLYGON; nNumPolygon++)
    {
        if (m_apScene[nNumPolygon] != NULL)
        {
            m_apScene[nNumPolygon]->Update();
        }
    }
}

//=============================================================================
// [DrawAll] ���ׂẴI�u�W�F�N�g��`��
//=============================================================================
void CScene::DrawAll(void)
{
    for (int nCountType = 0; nCountType < OBJTYPE_MAX; nCountType++)
    {
        for (int nNumPolygon = 0; nNumPolygon < MAX_POLYGON; nNumPolygon++)
        {
            if (m_apScene[nNumPolygon] != NULL)
            {
                if (m_apScene[nNumPolygon]->m_objtype == nCountType)
                {
                    m_apScene[nNumPolygon]->Draw();
                }

            }
        }
    }
}

//=============================================================================
// [Release] �������̊J��
//=============================================================================
void CScene::Release(void)
{
    if (m_apScene[m_nIndex] != NULL)
    {
        int nID = m_nIndex;// delete���m_nIndex���g���Ȃ��Ȃ�̂Ŕԍ���ۑ�

        // ���������J�����ă|�C���^�̒��g��NULL�ɂ���
        delete m_apScene[m_nIndex];
        m_apScene[nID] = NULL;

    }
}

//=============================================================================
// [ReleaseAll] ���ׂẴ����������
//=============================================================================
void CScene::ReleaseAll(void)
{
    for (int nNumPolygon = 0; nNumPolygon < MAX_POLYGON; nNumPolygon++)
    {
        if (m_apScene[nNumPolygon] != NULL)
        {
            m_apScene[nNumPolygon]->Release();
        }
    }
}

