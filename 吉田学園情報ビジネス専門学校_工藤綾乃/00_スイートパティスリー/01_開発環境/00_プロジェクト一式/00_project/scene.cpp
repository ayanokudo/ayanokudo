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
CScene *CScene::m_pTop[PRIORITY_MAX] = {};// �擪�̃I�u�W�F�N�g�ւ̃|�C���^
CScene *CScene::m_pCur[PRIORITY_MAX] = {};// ���݂̃I�u�W�F�N�g�ւ̃|�C���^

//=============================================================================
// [CScene] �R���X�g���N�^
// ����
// priority : �`��D�揇��
//=============================================================================
CScene::CScene(PRIORITY priority)
{
    // �擪�̃A�h���X���Ȃ������ꍇ
    if (!m_pTop[priority])
    {
        // �������g��擪�ɂ���
        m_pTop[priority] = this;
        m_pPrev = NULL;
    }
    else
    {
        m_pPrev = m_pCur[priority];// �O�̃I�u�W�F�N�g��ݒ�
        m_pPrev->m_pNext = this;
    }
    m_pCur[priority] = this;// �Ō�̃I�u�W�F�N�g���������g�ɂ���
    m_pNext = NULL;// �������Ō�Ȃ̂�NULL�ɂ���

    m_Priority = priority;
    m_bDeath = false;
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
    for (int nCntPriority = 0; nCntPriority < PRIORITY_MAX; nCntPriority++)
    {
        CScene *pScene = m_pTop[nCntPriority];// �擪�̃A�h���X���擾
        while (pScene)
        {
            // ���̍X�V�������s���I�u�W�F�N�g��ۑ����Ă���(Updete�ō��̃I�u�W�F�N�g��j�����邱�Ƃ����邽��)
            CScene *pIndex = pScene->m_pNext;

            if (!pScene->m_bDeath)
                pScene->Update();// �I�u�W�F�N�g�̍X�V���s��

            pScene = pIndex;// ���̃I�u�W�F�N�g���擾
        }
    }

    // �t���O�m�F
    for (int nCntPriority = 0; nCntPriority < PRIORITY_MAX; nCntPriority++)
    {
        CScene *pScene = m_pTop[nCntPriority];// �擪�̃A�h���X���擾
        while (pScene)
        {
            // ���̍X�V�������s���I�u�W�F�N�g��ۑ����Ă���(Updete�ō��̃I�u�W�F�N�g��j�����邱�Ƃ����邽��)
            CScene *pIndex = pScene->m_pNext;

            // ���S�t���O�𗧂��Ă�����폜
            if (pScene->m_bDeath)
                pScene->ReconnectList();

            pScene = pIndex;// ���̃I�u�W�F�N�g���擾
        }
    }
}

//=============================================================================
// [DrawAll] ���ׂẴI�u�W�F�N�g��`��
//=============================================================================
void CScene::DrawAll(void)
{
    for (int nCntPriority = 0; nCntPriority < PRIORITY_MAX; nCntPriority++)
    {
        CScene *pScene = m_pTop[nCntPriority];// �擪�̃A�h���X���擾
        while (pScene)
        {// ���̃I�t�W�F�N�g�̕ۑ�
         // ���̍X�V�������s���I�u�W�F�N�g��ۑ����Ă���(Updete�ō��̃I�u�W�F�N�g��j�����邱�Ƃ����邽��)
            CScene *pIndex = pScene->m_pNext;

            // ���S�t���O�`�F�b�N
            if (!pScene->m_bDeath)
                pScene->Draw();               // �I�u�W�F�N�g�̕`����s��

            pScene = pIndex;              // ���̃I�u�W�F�N�g���擾
        }
    }
}

//=============================================================================
// [ReconnectList] ���X�g�̍Đڑ�
//=============================================================================
void CScene::ReconnectList(void)
{
    // �������擪�̃A�h���X�̏ꍇ���̃I�u�W�F�N�g�ɐ擪����n��
    if (m_pTop[m_Priority] == this)
    {
        m_pTop[m_Priority] = m_pNext;// ���̃I�u�W�F�N�g��擪�ɂ���
        if (m_pTop[m_Priority])
            m_pTop[m_Priority]->m_pPrev = nullptr;// �擪�̑O�̃I�u�W�F�N�g�̏���NULL�ɂ���
    }
    else
    {// �������擪�ł͂Ȃ��ꍇ
        m_pPrev->m_pNext = m_pNext;
    }
    // ���������݂̃A�h���X�̏ꍇ�O�̃I�u�W�F�N�g�Ɍ��݂̏���n��
    if (m_pCur[m_Priority] == this)
    {
        m_pCur[m_Priority] = m_pPrev;
        if (m_pPrev)
        {
            m_pCur[m_Priority]->m_pNext = nullptr;
        }
    }
    else
    {// �������Ō�ł͂Ȃ��ꍇ
        m_pNext->m_pPrev = m_pPrev;
    }
        delete this;
}

//=============================================================================
// [ReleaseAll] ���ׂẴ����������
//=============================================================================
void CScene::ReleaseAll(void)
{
    // �t���O�m�F
    for (int nCntPriority = 0; nCntPriority < PRIORITY_MAX; nCntPriority++)
    {
        CScene *pScene = m_pTop[nCntPriority];// �擪�̃A�h���X���擾
        while (pScene)
        {
            // ���̍X�V�������s���I�u�W�F�N�g��ۑ�
            CScene *pIndex = pScene->m_pNext;

                pScene->Uninit();
                pScene->ReconnectList();

            pScene = pIndex;// ���̃I�u�W�F�N�g���擾
        }
    }
}
