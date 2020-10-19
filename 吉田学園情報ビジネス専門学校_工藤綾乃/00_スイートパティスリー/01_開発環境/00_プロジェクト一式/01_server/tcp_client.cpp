//============================================================
//
// �Q�[���G���W��II �N���C�A���g���v���W�F�N�g
// bot�T�[�o�[ [tcp_client.cpp]
// Author : AYANO KUDO
//
//============================================================
#include "tcp_client.h"
#include <stdio.h>

//============================================================
// �R���X�g���N�^
//============================================================
CTcpClient::CTcpClient()
{
    m_sock = -1;
}

//============================================================
// �f�X�g���N�^
//============================================================
CTcpClient::~CTcpClient()
{

}

//============================================================
// ����������
// ����
//  [in] IP�A�h���X
//  [in] nPortNum : �|�[�g�ԍ�
//============================================================
bool CTcpClient::Init(const char *pHostName, int nPortNum)
{
    // �ڑ��p�\�P�b�g�̐���
    m_sock = socket(AF_INET, SOCK_STREAM, 0);

    // �G���[����
    if (m_sock == INVALID_SOCKET)
    {
        printf("socket : %d\n", WSAGetLastError());

        printf("ENTER�L�[����͂��Ă�������>\n");

        // �L�[���͑҂�
        rewind(stdin);
        getchar();

        return false;
    }

    // �ڑ�����̐ݒ�
    struct sockaddr_in addr;                               //�ڑ���̏��

    addr.sin_family = AF_INET;                             //IPv4
    addr.sin_port = htons(nPortNum);                       //�ǂ̃|�[�g�ɐڑ����邩
    addr.sin_addr.S_un.S_addr = inet_addr(pHostName);      //�T�[�o�[��IP�A�h���X

                                                           // �T�[�o�[�ɐڑ�����
                                                           // connect�֐��͎��s�����0�ȊO��Ԃ�
                                                           // �T�[�o�[�ɐڑ��ł��Ȃ��������A�T�[�o�[���N�����Ă��Ȃ��Ƃ��AIP��|�[�g���Ԉ���Ă���A�t�@�C�A�[�E�H�[���ł͂����ꂽ�Ƃ��ɃG���[
    if (connect(m_sock, (struct sockaddr*)&addr, sizeof(addr)) != 0)
    {
        printf("connect:%d\n", WSAGetLastError());
        // �\�P�b�g�ڑ����N���[�Y
        CTcpClient::Close();

        printf("ENTER�L�[����͂��Ă�������\n");

        // �L�[���͑҂�
        rewind(stdin);
        getchar();

        return false;
    }
    return true;
}

//============================================================
// ������̑��M
//============================================================
int CTcpClient::Send(char *pSendData, int nSendDataSize)
{
    if (m_sock < 0)

    {// �ʐM���ؒf���ꂽ�Ƃ�
        printf("�ʐM���ؒf����܂���\n");
        printf("ENTER�L�[����͂��Ă�������\n");

        // �L�[���͑҂�
        rewind(stdin);
        getchar();

        return 0;
    }

    // ���b�Z�[�W�𑗐M
    int nSendsize = send(m_sock, pSendData, nSendDataSize, 0);
    return nSendDataSize;
}

//============================================================
// ������̎�M
//============================================================
int CTcpClient::Recv(char *pRecvBuf, int nRecvBufSize)
{
    // �o�b�t�@��0�N���A����
    memset(pRecvBuf, 0, nRecvBufSize);

    int nRecvSize = recv(m_sock, pRecvBuf, nRecvBufSize, 0);

    printf("%s", pRecvBuf);

    if (m_sock < 0)
    {// �ʐM���ؒf���ꂽ�Ƃ�

        printf("�ʐM���ؒf����܂���\n");
        printf("ENTER�L�[����͂��Ă�������\n");

        // �L�[���͑҂�
        rewind(stdin);
        getchar();

        return 0;
    }

    return nRecvSize;// ��M����������̃T�C�Y��Ԃ�

}

//============================================================
// �N���C�A���g�p�̃������̊m��
//============================================================
CTcpClient* CTcpClient::Create(const char *pHostName, int nPortNum)
{
    CTcpClient *pClient;
    // �������̊m��
    pClient = new CTcpClient;

    if (!pClient->Init(pHostName, nPortNum))
    {// �������Ɏ��s�����Ƃ��Ƀ����������
        delete pClient;
        pClient = NULL;
    }
    return pClient;
}

//============================================================
// �T�[�o�[�p�̐�������
//============================================================
CTcpClient *CTcpClient::Create(SOCKET sock)
{
    CTcpClient *pClient;
    // �������̊m��
    pClient = new CTcpClient;

    if (!pClient->Init(sock))
    {// �������Ɏ��s�����Ƃ��Ƀ����������
        delete pClient;
        pClient = NULL;
    }

    return pClient;
}

//============================================================
// �\�P�b�g�̃N���[�Y
//============================================================
void CTcpClient::Close(void)
{
    if (m_sock < 0)
    {
        return;
    }

    // �\�P�b�g�ڑ����N���[�Y
    closesocket(m_sock);

    m_sock = 1;
}

//============================================================
// �T�[�o�[�p�̏���������
//============================================================
bool CTcpClient::Init(SOCKET sock)
{
    m_sock = sock;
    return true;
}

//============================================================
// �������̊J��
//============================================================
void CTcpClient::Release(void)
{
    Close();
    delete this;
}
