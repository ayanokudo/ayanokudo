//=============================================================================
//
// �������� [explosion.cpp]
// Author : AYANO KUDO
//
//=============================================================================
#include "explosion.h"
#include "manager.h"
#include "renderer.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define EXPLOSION_TEXTURE "data/TEXTURE/explosion000.png"     // �e�̃e�N�X�`����
#define EXPLOSION_SIZE_X (50.0f)                      // �e�̉��̑傫��
#define EXPLOSION_SIZE_Y (50.0f)                      // �e�̏c�̑傫��
#define MAX_TEXTURE (4.0f)                            // �e�N�X�`���A�j���[�V�����̖���
#define ANIMESION_SPEED (15)                          // �A�j���[�V�������x

//*****************************************************************************
// �ÓI�����o�ϐ�������
//*****************************************************************************
LPDIRECT3DTEXTURE9 CExplosion::m_pTexture = NULL;

//=============================================================================
// [CExplosion] �R���X�g���N�^
//=============================================================================
CExplosion::CExplosion()
{
    SetSize(D3DXVECTOR3(EXPLOSION_SIZE_X, EXPLOSION_SIZE_Y,0.0f));
    SetObjtype(OBJTYPE_EXPLOSION);
    m_nCounterAnim = 0;
    m_nPotternAnim = 0;
}

//=============================================================================
// [CExplosion] �f�X�g���N�^
//=============================================================================
CExplosion::~CExplosion()
{
}

//=============================================================================
// [Load] �e�N�X�`���̓ǂݍ���
//=============================================================================
HRESULT CExplosion::Load(void)
{
    // �f�o�C�X�̎擾�@
    LPDIRECT3DDEVICE9 pDevice;
    pDevice = CManager::GetRenderer()->GetDevice();

    // �e�N�X�`���̐���
    D3DXCreateTextureFromFile(pDevice, EXPLOSION_TEXTURE, &m_pTexture);
    return S_OK;
}

//=============================================================================
// [Unload] �e�N�X�`���̔j��
//=============================================================================
void CExplosion::Unload(void)
{
    // �e�N�X�`���̔j��
    if (m_pTexture != NULL)
    {
        m_pTexture->Release();
        m_pTexture = NULL;
    }
}

//=============================================================================
// [Create] �����̐���
//=============================================================================
CExplosion * CExplosion::Create(D3DXVECTOR3 pos)
{
    // �ϐ��錾
    CExplosion *pExplosion = NULL;
    if (!pExplosion) {
        // �������̊m��
        pExplosion = new CExplosion;
        // ����������
        pExplosion->Init(pos);
    }
    return pExplosion;
}

//=============================================================================
// [Init] �����ى�����
//=============================================================================
HRESULT CExplosion::Init(D3DXVECTOR3 pos)
{
    // �e�����o�ϐ�������
    SetPosition(pos);
    CScene2D::Init();
    SetSize(D3DXVECTOR3(EXPLOSION_SIZE_X, EXPLOSION_SIZE_Y,0.0f));
    SetTexture(D3DXVECTOR2((float)m_nPotternAnim, 1.0f), D3DXVECTOR2(MAX_TEXTURE, 1.0f));

    // �e�N�X�`���̊��蓖��
    BindTexture(m_pTexture);

    return S_OK;
}

//=============================================================================
// [Uninit] �I������
//=============================================================================
void CExplosion::Uninit()
{
    CScene2D::Uninit();
}

//=============================================================================
// [Update] �X�V����
//=============================================================================
void CExplosion::Update(void)
{
    CScene2D::Update();
    // �J�E���^�X�V
    m_nCounterAnim++;

    if (m_nCounterAnim % ANIMESION_SPEED == 0)
    {
        m_nCounterAnim = 0;
        // �A�j���[�V�����̖���
        m_nPotternAnim++;

        // �e�N�X�`�����W�X�V
        SetTexture(D3DXVECTOR2((float)m_nPotternAnim , 1.0f), D3DXVECTOR2(MAX_TEXTURE, 1.0f));
        if (m_nPotternAnim >= MAX_TEXTURE)
        {
            Uninit();
        }

    }
}

//=============================================================================
// [Draw] �`�揈��
//=============================================================================
void CExplosion::Draw(void)
{
    // �|���S���̕`��
    CScene2D::Draw();
}
