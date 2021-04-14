//=============================================================================
//
// �i���o�[�̏��� [number.cpp]
// Author : AYANO KUDO
//
//=============================================================================
#include "number.h"
#include "manager.h"
#include "renderer.h"
#include "manager.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define NUMVER_TEXTURE_NAME "data/TEXTURE/number000.png"

//*****************************************************************************
// �ÓI�����o�ϐ�
//*****************************************************************************
LPDIRECT3DTEXTURE9 CNumber::m_pTexture = NULL;

//=============================================================================
// [CNumber] �R���X�g���N�^
//=============================================================================
CNumber::CNumber()
{
    m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
    m_size= D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}

//=============================================================================
// [~CNumber] �f�X�g���N�^
//=============================================================================
CNumber::~CNumber()
{

}

//=============================================================================
// [Create] �i���o�[�I�u�W�F�N�g�̐���
//=============================================================================
CNumber *CNumber::Create(D3DXVECTOR3 pos, D3DXVECTOR3 size)
{
    CNumber *pNumber = NULL;

    if (!pNumber)
    {
        pNumber = new CNumber;
        pNumber->Init(pos, size);
    }
    return pNumber;
}


//=============================================================================
// [Load] �e�N�X�`���̓ǂݍ���
//=============================================================================
HRESULT CNumber::Load(void)
{
    LPDIRECT3DDEVICE9 pDevice;
    pDevice = CManager::GetRenderer()->GetDevice();

   D3DXCreateTextureFromFile(pDevice, NUMVER_TEXTURE_NAME, &m_pTexture);
    return S_OK;
}

//=============================================================================
// [Unload] �e�N�X�`���̔j��
//=============================================================================
void CNumber::Unload(void)
{
    // �e�N�X�`���̊J��
    if (m_pTexture != NULL)
    {
        m_pTexture->Release();
        m_pTexture = NULL;
    }
}

//=============================================================================
// [Init] ����������
// pos : ������\��������ʒu
//=============================================================================
void CNumber::Init(D3DXVECTOR3 pos, D3DXVECTOR3 size)
{
    VERTEX_2D *pVtx;//���_���̃|�C���^
    m_pos = pos;
    m_size = size;

    // �f�o�C�X�̎擾�@
    LPDIRECT3DDEVICE9 pDevice;
    pDevice = CManager::GetRenderer()->GetDevice();

    // ���_�o�b�t�@�̐���
    pDevice->CreateVertexBuffer(
        sizeof(VERTEX_2D) * NUM_VERTEX,//�o�b�t�@�T�C�Y
        D3DUSAGE_WRITEONLY,//(�Œ�j
        FVF_VERTEX_2D,//���_�t�H�[�}�b�g
        D3DPOOL_MANAGED,//�i�Œ�j
        &m_pVtxBuff,//�ϐ������ς��ƕύX���K�v
        NULL);

    //���_�f�[�^�͈̔͂����b�N���A���_�o�b�t�@�ւ̃|�C���^���擾
    m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

    // ���_����ݒ�
    pVtx[0].pos = D3DXVECTOR3(m_pos.x - m_size.x / 2, m_pos.y - m_size.y / 2, 0.0f);
    pVtx[1].pos = D3DXVECTOR3(m_pos.x + m_size.x / 2, m_pos.y - m_size.y / 2, 0.0f);
    pVtx[2].pos = D3DXVECTOR3(m_pos.x - m_size.x / 2, m_pos.y + m_size.y / 2, 0.0f);
    pVtx[3].pos = D3DXVECTOR3(m_pos.x + m_size.x / 2, m_pos.y + m_size.y / 2, 0.0f);

    //rhw�̐ݒ�
    pVtx[0].rhw = 1.0f;
    pVtx[1].rhw = 1.0f;
    pVtx[2].rhw = 1.0f;
    pVtx[3].rhw = 1.0f;

    //���_�J���[�̐ݒ�
    pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
    pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
    pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
    pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

    //�e�N�X�`���̍��W
    pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
    pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
    pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
    pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

    //���_�f�[�^�A�����b�N
    m_pVtxBuff->Unlock();
}


//=============================================================================
// [Uninit] �I������
//=============================================================================
void CNumber::Uninit(void)
{
    // ���_�o�b�t�@�̔j��
    if (m_pVtxBuff)
    {
        m_pVtxBuff->Release();
        m_pVtxBuff = NULL;
    }
}

//=============================================================================
// [Update] �X�V����
//=============================================================================
void CNumber::Update(void)
{

}

//=============================================================================
// [Draw] �`�揈��
//=============================================================================
void CNumber::Draw(void)
{
    // �ϐ��錾
    LPDIRECT3DDEVICE9 pDevice;

    // �f�o�C�X���擾
    pDevice = CManager::GetRenderer()->GetDevice();

    // ���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
    pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_2D));

    // ���_�t�H�[�}�b�g�̐ݒ�
    pDevice->SetFVF(FVF_VERTEX_2D);

    //�e�N�X�`���̐ݒ�
    pDevice->SetTexture(0, m_pTexture);

    // �|���S���̕`��
    pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, NUM_POLYGON);

}

//=============================================================================
// [SetTexture] �e�N�X�`�����W�̐ݒ�
// nNumber : �\�������鐔��(�O�`�X)
//=============================================================================
void CNumber::SetNumber(unsigned int nNumber)
{
    // �ϐ��錾
    VERTEX_2D *pVtx;//���_���̃|�C���^

    //���_�f�[�^�͈̔͂����b�N���A���_�o�b�t�@�ւ̃|�C���^���擾
    m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

    //�e�N�X�`���̍��W
    pVtx[0].tex = D3DXVECTOR2((0.0f + nNumber) / 10.0f, 0.0f);
    pVtx[1].tex = D3DXVECTOR2((1.0f + nNumber) / 10.0f, 0.0f);
    pVtx[2].tex = D3DXVECTOR2((0.0f + nNumber) / 10.0f, 1.0f);
    pVtx[3].tex = D3DXVECTOR2((1.0f + nNumber) / 10.0f, 1.0f);

    //���_�f�[�^�A�����b�N
    m_pVtxBuff->Unlock();
}
