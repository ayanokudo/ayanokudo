//=============================================================================
//
// ���C������ [main.h]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef _MAIN_H_
#define _MAIN_H_

//*****************************************************************************
// �w�b�_�t�@�C���̃C���N���[�h
//*****************************************************************************
#include <WinSock2.h>
#include <Windows.h>
#include "d3dx9.h"
#define DIRECTINPUT_VERSION (0x0800)    // �x���Ώ��p'dinput.h'�̒��O�ɒ�`
#include "dinput.h"
#include <xaudio2.h>                    // �T�E���h�֌W�̏���

//*****************************************************************************
// ���C�u�����t�@�C���̃����N
//*****************************************************************************
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "winmm.lib")       //�V�X�e�������擾�p�ɕK�v
#pragma comment(lib, "dinput8.lib")     // ���͏����ɕK�v
#pragma comment(lib,"ws2_32.lib")       // Winsock�̃��C�u����

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define	WINDOW_POS_X	(0)     // �E�B���h�E�̈ʒu(x��)
#define	WINDOW_POS_Y	(0)     // �E�B���h�E�̈ʒu(y��)
#define SCREEN_WIDTH	(1280)  // �E�B���h�E�T�C�Y(x��)
#define SCREEN_HEIGHT	(720)   // �E�B���h�E�T�C�Y(y��)

#define FVF_VERTEX_2D (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)
#define NUM_VERTEX      (4)     //���_��
#define NUM_POLYGON     (2)     //�|���S����

#define MAX_POLYGON (1024)                     // �|���S���̍ő吔

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
int GetFPS(void);

//*****************************************************************************
// �\���̒�`
//*****************************************************************************
// ���_���̍\����
typedef struct
{
    D3DXVECTOR3 pos;        // ���_���W
    float       rhw;        // ���W�ϊ��p�W��  (1.0�ŌŒ�)
    D3DCOLOR    col;        // ���_�J���[
    D3DXVECTOR2 tex;        // �e�N�X�`�����W
}VERTEX_2D;

// �e�N�X�`�����̍\����
typedef struct
{
    D3DXVECTOR3 pos;        // �ʒu
    D3DXVECTOR3 size;       // �T�C�Y
    char       *textureName; // �e�N�X�`���t�@�C����

}TEXTURE_DATA;
#endif