//=================================================================
//
// �^�b�`�i���o�[�����@�T�[�o�[
// Author : AYANO KUDO
//
//=================================================================
#include <stdio.h>
#include <WinSock2.h>
#include <thread>       // �}���`�X���b�h�Ή�
#include "main.h"
#include "tcp_listener.h"
#include "tcp_client.h"

//*****************************************************************
// �}�N����`
//*****************************************************************
#define FILE_NAME "data/test.txt"        // �ǂݍ��ރt�@�C����
#define SERVER_PORT_NUM (12345)             // �|�[�g�ԍ�

//*****************************************************************
// �v���g�^�C�v�錾
//*****************************************************************
void ReadFile(void);
void WriteFile(void);
void WorkerThread(CTcpClient *pTcpClient);
int SetRanking(int nTime, char *pName);

//*****************************************************************
// �O���[�o���ϐ��錾
//*****************************************************************
RankingData g_aRankinData[MAX_RANKING];

//=================================================================
// [main] ���C���֐�
//=================================================================
void main(void)
{
    // �ϐ��錾
    WSADATA WsaData;

    // winsock������
    int nErr = WSAStartup(WINSOCK_VERSION, &WsaData);
    if (nErr)
    {// �������Ɏ��s����
        printf("Winsock�̏������Ɏ��s���܂���\n");

        // �L�[���͑҂�
        rewind(stdin);
        getchar();
        return;
    }

    // �O���[�o���ϐ�������
    memset(g_aRankinData,0,sizeof(g_aRankinData));

        // �����L���O�t�@�C���ǂݍ���
        ReadFile();

        CTcpListener *pTcpListener = CTcpListener::Create(SERVER_PORT_NUM);

        while (1)
        {
            // �N���C�A���g�̐ڑ����󂯕t����
            CTcpClient *pTcpClient = pTcpListener->Accept();

            // �`���b�g�p�̃X���b�h����
            std::thread thChat(WorkerThread, pTcpClient);

            // �`���b�g�p�X���b�h��؂藣��
            thChat.detach();

        }

        if (pTcpListener!=NULL)
        {
            pTcpListener->Release();
            pTcpListener = NULL;
        }

        // winsock�I������
        WSACleanup();
}

//=================================================================
// [ReadFile] �t�@�C���̓ǂݍ���
//=================================================================
void ReadFile(void)
{
    FILE *pFile;
    pFile = fopen(FILE_NAME, "r");// �ǂݍ��݃��[�h "r" �Ńt�@�C���I�[�v��
    if (pFile!=NULL)
    {
        for (int nCount = 0; nCount < MAX_RANKING; nCount++)
        {
            fscanf(pFile, "%d", &g_aRankinData[nCount].nClearTime);
            //fscanf(pFile, "%s", &g_aRankinData[nCount].aName);

        }
        fclose(pFile);
    }

}

//=================================================================
// [WriteFile] �t�@�C���̏�������
//=================================================================
void WriteFile(void)
{
    FILE *pFile;
    pFile = fopen(FILE_NAME, "w");// �ǂݍ��݃��[�h "w" �Ńt�@�C���I�[�v��
    if (pFile != NULL)
    {
        for (int nCount = 0; nCount < MAX_RANKING; nCount++)
        {
            fprintf(pFile, "%d\n", g_aRankinData[nCount].nClearTime);
            //fprintf(pFile, "%s\n", g_aRankinData[nCount].aName);
        }
        fclose(pFile);
    }
}

//=================================================================
// [WorkerThread] 
//=================================================================
void WorkerThread(CTcpClient *pTcpClient)
{
    // �ϐ��錾
    char aRecvBuf[256];
    char aSendBuf[256];
    int nTime;//����̃N���A�^�C��
    char aName[MAX_NAME];

    // �ڑ���҂��󂯂�
    // �o�b�t�@��0�N���A����
    // ���b�Z�[�W���󂯎��
    pTcpClient->Recv(aRecvBuf, sizeof(aRecvBuf));

    COMMAND_TYPE command = (COMMAND_TYPE)aRecvBuf[0];
     
    // �擪��1�o�C�g�̓��e�ŏ�����ς���
    switch (command)
    {
        // �����L���O�ꗗ�擾���N�G�X�g����
    case COMMAND_TYPE_GET_RANKING:
        // �����L���O�擾
        ReadFile();
        printf("�����L���O���M\n");
        // �l�������[�v
        for (int nCntRank = 0; nCntRank < MAX_RANKING; nCntRank++)
        {
            // pRankingData[nCntRank]��aRecvBuf�̃f�[�^�ݒ�
            // �^�C����ۑ�
            int nData = htonl(g_aRankinData[nCntRank].nClearTime);
            memcpy(&aSendBuf[nCntRank * sizeof(int)], &nData, sizeof(int));
            //// ���O��ۑ�
            //g_aRankinData[nCntRank].aName[MAX_NAME - 1] = '\0';// ���O�̍Ō��NULL����������
            //memcpy(&aSendBuf[nCntRank * sizeof(RankingData) + sizeof(int)], &g_aRankinData[nCntRank].aName, MAX_NAME);
        }
        pTcpClient->Send(aSendBuf,sizeof(aSendBuf));

        break;

    case COMMAND_TYPE_SET_RANKING:
        // �����L���O���N�G�X�g
        //2�`5�o�C�g�ڂ����M�����X�R�A���擾
        int nTime = (int)(*(int*)&aRecvBuf[1]);            //�G���f�B�A���ϊ�
        
            //// 6�`13�o�C�g�ڂ��疼�O���擾
            //char aName[MAX_NAME];
            //memcpy(aName, &aRecvBuf[5], MAX_NAME);
            //aName[MAX_NAME - 1] = '\0';         // ������̍Ō��NULL����������

        // �����L���O���X�V
        int nRank = SetRanking(nTime,aName);// ����̏��ʂ�ϐ��ɕۑ�

        // ���ʂ𑗐M
        aSendBuf[0] = (char)nRank;
            pTcpClient->Send(aSendBuf, sizeof(char));

        break;

    }
 }

//=================================================================
// [SetRanking] 
//=================================================================
int SetRanking(int nTime, char *pName)
{
    int nCount;
    for ( nCount = 0; nCount < MAX_RANKING; nCount++)
    {
        // �����L���O���X�V����ꏊ�̔���
        if (nTime>g_aRankinData[nCount].nClearTime||
            g_aRankinData[nCount].nClearTime == 0)
        {
            //�ȍ~�̃����L���O�f�[�^�����ɕۑ�
            for (int nCntMove = MAX_RANKING-1; nCntMove > nCount ; nCntMove--)
            {
                g_aRankinData[nCntMove].nClearTime = g_aRankinData[nCntMove - 1].nClearTime;

            }
            g_aRankinData[nCount].nClearTime = nTime;
            //strcpy(g_aRankinData[nCount].aName, pName);
            break;
        }
    }
        WriteFile();
        return nCount + 1;
}