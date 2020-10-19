//=============================================================================
//
// �����L���O���� [ranking.h]
// Author : AYANO KUDO
//
//=============================================================================
#include "scene.h"
#include "ranking.h"
#include "number.h"
#include "score.h"
#include "tcp_client.h"
#include "manager.h"
#include "fade.h"
#include "inputkeyboard.h"
#include "inputcontroller.h"
#include "sound.h"
#include "ranking_ui.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define SERVER_PORT_NUM (12345)          // �ڑ���|�[�g
#define IPADDRESS       "20.48.2.39"     // IP�A�h���X

#define MAX_DATA_SIZE (256)         // �ő�o�b�t�@�T�C�Y

//*****************************************************************************
// �ÓI�����o�ϐ��錾
//*****************************************************************************
CScore            *CRanking::m_pScore[MAX_RANKING_SCORE] = {};
CRanking_UI       *CRanking::m_pRankingUI = NULL;

//=============================================================================
// [CRanking] �R���X�g���N�^
//=============================================================================
CRanking::CRanking()
{

}

//=============================================================================
// [~CRanking] �f�X�g���N�^
//=============================================================================
CRanking::~CRanking()
{

}

//=============================================================================
// [Load] �e�N�X�`���̓ǂݍ���
//=============================================================================
void CRanking::Load(void)
{
    CNumber::Load();
    CRanking_UI::Load();
}

//=============================================================================
// [Unload] �e�N�X�`���̔j��
//=============================================================================
void CRanking::Unload(void)
{
    CNumber::Unload();
    CRanking_UI::Unload();
}

//=============================================================================
// [Create] �I�u�W�F�N�g�̐���
//=============================================================================
CRanking * CRanking::Create(void)
{
    CRanking *pRanking = NULL;
    if (!pRanking)
    {
        pRanking = new CRanking;
        pRanking->Init();
    }
    return pRanking;
}

//=============================================================================
// [Init] ����������
//=============================================================================
void CRanking::Init(void)
{
    Load();     // �e�N�X�`���̓ǂݍ���
    
    // UI�̐���
    m_pRankingUI = CRanking_UI::Create();

    // �X�R�A�̐���
    for (int nCount = 0; nCount < MAX_RANKING_SCORE; nCount++)
    {
        m_pScore[nCount] = CScore::Create((D3DXVECTOR3(SCREEN_WIDTH -400, 170.0f + (100.0f * nCount), 0.0f)));
    }

    CRanking::GetRanking();     // �����L���O�̎擾

    // �T�E���h�̍Đ�
    CSound *pSound = CManager::GetSound();
}

//=============================================================================
// [Uninit] �I������
//=============================================================================
void CRanking::Uninit(void)
{
    // �T�E���h�̒�~
    CSound *pSound = CManager::GetSound();
    pSound->Stop(CSound::SOUND_LABEL_BGM002);

    // ���ׂẴI�u�W�F�N�g�̉��
    CScene::ReleaseAll();
}

//=============================================================================
// [Update] �X�V����
//=============================================================================
void CRanking::Update(void)
{
    // �ϐ��錾
    CInputKeyboard   *pInputKeyboard = CManager::GetInputKeyboard();
    CInputController *pInputController = CManager::GetInputController();

    if (pInputKeyboard->GetKeyTrigger(DIK_SPACE) ||
        pInputKeyboard->GetKeyTrigger(DIK_RETURN) ||
        pInputController->GetConTrigger(CInputController::BUTTON_10))
    {
        // �T�E���h�炷
        CSound *pSound = CManager::GetSound();
        pSound->Play(CSound::SOUND_LABEL_SE_006);
        // �^�C�g����ʂ֑J��
        CFade::SetFade(CManager::MODE_TITLE);
    }
}

//=============================================================================
// [Draw] �`�揈��
//=============================================================================
void CRanking::Draw(void)
{

}

//=============================================================================
// [SetRanking] �����L���O�̐ݒ�
// ����
// nScore : ����̃X�R�A
// �Ԃ�l : ����̏���
//=============================================================================
int CRanking::SetRanking(int nScore)
{
    //TCP���M�N���X�̐���
    CTcpClient *pClient = NULL;
    char aSendBuf[256] = {};// ���M�p������
    char nRecvBuf[128] = {};// ���ʎ擾�p������
    int nIndex = 0;

    // �������̊m��
    if (pClient == NULL)
    {
        pClient = CTcpClient::Create(IPADDRESS, SERVER_PORT_NUM);

        if (pClient == NULL)
        {
            return 0;
        }

        // �����L���O�ݒ胊�N�G�X�g�̑��M
        //  1�o�C�g��:COMMAND_TYPE_SET_RANKING��ݒ�
        aSendBuf[0] = COMMAND_TYPE_SET_RANKING;

        nIndex += 1;

        // 2�`5�o�C�g��:�X�R�A�ݒ�(�G���f�B�A���ϊ�)
        int nSendScore = htonl(nScore);
        memcpy(&aSendBuf[nIndex], &nScore, sizeof(int));
        pClient->Send(aSendBuf, sizeof(aSendBuf));

        // �����L���O�ݒ�̃��X�|���X����M
        pClient->Recv(nRecvBuf, sizeof(nRecvBuf));

        // �ؒf����
        // �\�P�b�g�ڑ����N���[�Y
        if (pClient != NULL)
        {
            pClient->Release();
            pClient = NULL;
        }
    }
        return nRecvBuf[0];// �����N�C���������ʂ�ς���
}

//=============================================================================
// [GetRanking] �����L���O�̎擾
//=============================================================================
void CRanking::GetRanking(void)
{
    // �ϐ��錾
    CTcpClient *pClient = NULL;

    // �������̊m��
    if (pClient == NULL)
    {
        pClient = CTcpClient::Create(IPADDRESS, SERVER_PORT_NUM);

    }
    if (pClient)
    {

        //CTcpClient�T�[�o�[�ɐڑ�
        // �����L���O�ꗗ�擾���N�G�X�g�𑗐M
        char aSendBuf[256];
        aSendBuf[0] = COMMAND_TYPE_GET_RANKING;

        // Send�����s
        pClient->Send(aSendBuf, sizeof(aSendBuf[0]));

        // �����L���O�ꗗ�擾���X�|���X����M
        char aRectBuf[MAX_DATA_SIZE];
        memset(aRectBuf, 0, sizeof(aRectBuf));

        // Recv�����s
        pClient->Recv(aRectBuf, sizeof(aRectBuf));

        for (int nCntRanl = 0; nCntRanl < MAX_RANKING_SCORE; nCntRanl++)
        {
            // �X�R�A��ۑ�
            m_pScore[nCntRanl]->SetScore(ntohl(*(int*)&aRectBuf[nCntRanl * sizeof(int)]));
        }
        // �\�P�b�g�ڑ����N���[�Y

        if (pClient != NULL)
        {

            pClient->Release();
            pClient = NULL;
        }
    }
    else
    {// �ڑ��ł��Ȃ������Ƃ��͌��݂̃X�R�A��1�ʂɂ���
        m_pScore[0]->SetScore(1);
        // �]�T������΃t�@�C���ǂݍ��݂Ƀ`�������W���Ă݂�
    }
}
