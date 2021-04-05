//=============================================================================
//
// TCP�ڑ���t�̏��� [tcp_listener.cpp]
// Author : 
//
//=============================================================================
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "tcp_client.h"
#include "tcp_listener.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define MAX_ACCEPT_CONN    (100)			// �ڑ���t�ő吔

//=============================================================================
// CTcpListener����
//=============================================================================
CTcpListener* CTcpListener::Create(int nPortNum)
{
    // TCP�ڑ���t�N���X�̃C���X�^���X����
    CTcpListener *pListener = new CTcpListener;

    // �ÓI�����o�֐����Ŋ֐����Ăяo���Ƃ��̓I�u�W�F�N�g��������
    pListener->Init(nPortNum, MAX_ACCEPT_CONN);

    return pListener;
}

//=============================================================================
// CTcpListener�R���X�g���N�^
//=============================================================================
CTcpListener::CTcpListener()
{

}

//=============================================================================
// CTcpListener�f�X�g���N�^
//=============================================================================
CTcpListener::~CTcpListener()
{

}

//=============================================================================
// ����������
//=============================================================================
bool CTcpListener::Init(int nPortNum, int nAcceptConnNum)
{
    struct  sockaddr_in addr;        // �ڑ���̐ݒ�

                                     // �ڑ���t�p�\�P�b�g�̐��� (socket)
    m_sockServer = socket(AF_INET, SOCK_STREAM, 0);

    // �ڑ���t���̐ݒ�
    addr.sin_family = AF_INET;// IPv4
    addr.sin_port = htons(nPortNum);// ()���̓|�[�g�ԍ� �C�ӂ̐���
    addr.sin_addr.S_un.S_addr = INADDR_ANY; // ���ׂĂ̐ڑ����󂯕t����(�����IP�A�h���X�̂ݐڑ����󂯕t����悤�ɂ��邱�Ƃ��\)

                                            // �\�P�b�g��IP�A�h���X�ƃ|�[�g�ԍ���ݒ肷�� (bind)
    bind(m_sockServer, (struct sockaddr*) &addr, sizeof(addr));

    // �ڑ��v����t���J�n���� (listen)
    listen(m_sockServer, nAcceptConnNum);

    return true;
}

//=============================================================================
// �ڑ���t����
//=============================================================================
CTcpClient* CTcpListener::Accept(void)
{
    if (m_sockServer < 0)
    {
        return NULL;
    }

    // �ϐ��錾
    struct  sockaddr_in client;      // �N���C�A���g�̏�񂪓���
    int nLenght = sizeof(client);

    // �ڑ���t����
    // �\�P�b�g�ڑ����󂯕t����(�󂯕t����܂Ńv���O�����̓u���b�N�����)
    //accept�֐��ŕԂ����\�P�b�g(�A�N�Z�v�g��͂�������g��)
    SOCKET sock = accept(m_sockServer, (struct sockaddr*)&client, &nLenght);
    CTcpClient *pTcpClint = CTcpClient::Create(sock);


    return pTcpClint;
}

//=============================================================================
// �j������
//=============================================================================
void CTcpListener::Release(void)
{
    // �ؒf����
    Close();

    // �C���X�^���X�폜
    delete this;
}

//=============================================================================
// �N���[�Y����
//=============================================================================
void CTcpListener::Close(void)
{
    if (m_sockServer < 0)
    {
        return;
    }

    // �\�P�b�g�ڑ����N���[�Y
    closesocket(m_sockServer);

    m_sockServer = 1;
}
