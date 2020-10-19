//=============================================================================
//
// �|���S���̕`�揈�� [renderer.h]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef _RENDERER_H_
#define _RENDERER_H_
#include "main.h"



//*****************************************************************************
// �O���錾
//*****************************************************************************
class CFade;

//******************************************************************************
// �N���X�̒�`
//******************************************************************************
class CRenderer
{
public:
    CRenderer();
    ~CRenderer();
    HRESULT Init( HWND hWnd, bool bWindow);
    void Uninit(void);
    void Update(void);
    void Draw(void);
    // �f�o�C�X�̃Q�b�^�[�֐�
    const LPDIRECT3DDEVICE9 GetDevice(void);// �w�b�_�t�@�C���̓f�o�b�N�ł��Ȃ�

private:
    static CFade *m_pFade;
#ifdef _DEBUG
    void DrawFPS(void);
#endif

    LPDIRECT3D9				m_pD3D;			// Direct3D�I�u�W�F�N�g
    LPDIRECT3DDEVICE9		m_pD3DDevice;	// Device�I�u�W�F�N�g(�`��ɕK�v)

#ifdef _DEBUG
    LPD3DXFONT				g_pFont;			// �t�H���g�ւ̃|�C���^
#endif
};

#endif // _RENDERER_H_