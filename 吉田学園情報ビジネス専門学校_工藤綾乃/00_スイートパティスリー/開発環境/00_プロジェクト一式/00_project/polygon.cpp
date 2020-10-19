//=============================================================================
//
// �|���S���̏��� [polygon.cpp]
// Author : AYANO KUDO
//
//=============================================================================
#include "polygon.h"
#include "manager.h"
#include "renderer.h"

//=============================================================================
// [CPolygon] �R���X�g���N�^
//=============================================================================
CPolygon::CPolygon()
{
    m_pTexture = NULL;
    m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
    m_size = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}

//=============================================================================
// [~CPolygon] �f�X�g���N�^
//=============================================================================
CPolygon::~CPolygon()
{
}

//=============================================================================
// [Create] �I�u�W�F�N�g�̐���
//=============================================================================
CPolygon * CPolygon::Create(D3DXVECTOR3 pos, D3DXVECTOR3 size)
{
    CPolygon* pPolygon = NULL;
    if (!pPolygon)
    {
        pPolygon = new CPolygon;
        pPolygon->Init(pos,size);
    }
    return pPolygon;
}

//=============================================================================
// [Init] ����������
//=============================================================================
HRESULT CPolygon::Init(D3DXVECTOR3 pos, D3DXVECTOR3 size)
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

    return S_OK;
}

//=============================================================================
// [Uninit] �I������
//=============================================================================
void CPolygon::Uninit(void)
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
void CPolygon::Update(void)
{
    VERTEX_2D *pVtx;//���_���̃|�C���^
                    //���_�f�[�^�͈̔͂����b�N���A���_�o�b�t�@�ւ̃|�C���^���擾
    m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

    pVtx[0].pos = D3DXVECTOR3(m_pos.x - (m_size.x / 2.0f), m_pos.y - (m_size.y / 2.0f), 0.0f);
    pVtx[1].pos = D3DXVECTOR3(m_pos.x + (m_size.x / 2.0f), m_pos.y - (m_size.y / 2.0f), 0.0f);
    pVtx[2].pos = D3DXVECTOR3(m_pos.x - (m_size.x / 2.0f), m_pos.y + (m_size.y / 2.0f), 0.0f);
    pVtx[3].pos = D3DXVECTOR3(m_pos.x + (m_size.x / 2.0f), m_pos.y + (m_size.y / 2.0f), 0.0f);

    //���_�f�[�^�A�����b�N
    m_pVtxBuff->Unlock();
}

//=============================================================================
// [Draw] �`�揈��
//=============================================================================
void CPolygon::Draw(void)
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
     HRESULT hr=pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, NUM_POLYGON);

}

//=============================================================================
// [SetColor] ���_�J���[��ύX
//=============================================================================
void CPolygon::SetColor(D3DXCOLOR color)
{
    // �ϐ��錾
    VERTEX_2D *pVtx;//���_���̃|�C���^

    //���_�f�[�^�͈̔͂����b�N���A���_�o�b�t�@�ւ̃|�C���^���擾

    m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

    //���_�J���[�̐ݒ�
    pVtx[0].col = D3DXCOLOR(color.r, color.g, color.b, color.a);
    pVtx[1].col = D3DXCOLOR(color.r, color.g, color.b, color.a);
    pVtx[2].col = D3DXCOLOR(color.r, color.g, color.b, color.a);
    pVtx[3].col = D3DXCOLOR(color.r, color.g, color.b, color.a);

    //���_�f�[�^�A�����b�N
    m_pVtxBuff->Unlock();
}

//=============================================================================
// [SetTexture] �e�N�X�`�����W�̐ݒ�
// tex           : ���������e�N�X�`���̉��R�}�ڂ�\�����邩
// nSplitPolygon : �e�N�X�`���̕�����
//=============================================================================
void CPolygon::SetTexture(D3DXVECTOR2 tex, const D3DXVECTOR2 nSplitPolygon)
{
    // �ϐ��錾
    VERTEX_2D *pVtx;//���_���̃|�C���^

    //���_�f�[�^�͈̔͂����b�N���A���_�o�b�t�@�ւ̃|�C���^���擾

    m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

    //�e�N�X�`���̍��W
    pVtx[0].tex = D3DXVECTOR2((0.0f + tex.x) / nSplitPolygon.x, (0.0f + tex.y) / nSplitPolygon.y);
    pVtx[1].tex = D3DXVECTOR2((1.0f + tex.x) / nSplitPolygon.x, (0.0f + tex.y) / nSplitPolygon.y);
    pVtx[2].tex = D3DXVECTOR2((0.0f + tex.x) / nSplitPolygon.x, (1.0f + tex.y) / nSplitPolygon.y);
    pVtx[3].tex = D3DXVECTOR2((1.0f + tex.x) / nSplitPolygon.x, (1.0f + tex.y) / nSplitPolygon.y);

    //���_�f�[�^�A�����b�N
    m_pVtxBuff->Unlock();
}

//=============================================================================
// [SetTexture] UV���W�̕ύX(�e�N�X�`���������΂��p)
// tex : �������΂��e�N�X�`���̖���
//=============================================================================
void CPolygon::SetTexture(D3DXVECTOR2 tex)
{
    // �ϐ��錾
    VERTEX_2D *pVtx;//���_���̃|�C���^

                    //���_�f�[�^�͈̔͂����b�N���A���_�o�b�t�@�ւ̃|�C���^���擾
    m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

    //�e�N�X�`���̍��W
    pVtx[0].tex = D3DXVECTOR2(0.0f * tex.x, 0.0f * tex.y);
    pVtx[1].tex = D3DXVECTOR2(1.0f * tex.x, 0.0f * tex.y);
    pVtx[2].tex = D3DXVECTOR2(0.0f * tex.x, 1.0f * tex.y);
    pVtx[3].tex = D3DXVECTOR2(1.0f * tex.x, 1.0f * tex.y);

    //���_�f�[�^�A�����b�N
    m_pVtxBuff->Unlock();
}