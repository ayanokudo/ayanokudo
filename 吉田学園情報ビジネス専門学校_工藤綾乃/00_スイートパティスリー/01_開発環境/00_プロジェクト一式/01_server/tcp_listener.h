//=============================================================================
//
// TCP�ڑ���t�̏��� [tcp_listener.h]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef _TCP_SERVER_H_
#define _TCP_SERVER_H_

#include <WinSock2.h>
#include "main.h"

//*****************************************************************************
// �O���錾
//*****************************************************************************
// ���������N���X�������Ƃ�����`
// �ăR���p�C�����Ȃ��Ă悭�Ȃ�
class CTcpClient;

//*****************************************************************************
// �N���X�̒�`
//*****************************************************************************
//TCP�ڑ���t�N���X
class CTcpListener
{
public:
    CTcpListener();
    ~CTcpListener();

    static CTcpListener* Create(int nPortNum);
    void Release(void);

    CTcpClient* Accept(void);

private:
    bool Init(int nPortNum, int nAcceptConnNum);
    void Close(void);

    SOCKET m_sockServer;// �ڑ��҂��󂯃\�P�b�g

};

#endif // !_TCP_SERVER_H_