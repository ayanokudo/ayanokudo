//=============================================================================
//
// �O�p�`�|���S���̏��� [triangle.cpp]
// Author : AYANO KUDO
//
//=============================================================================
#include "triangle.h"
#include "manager.h"
#include "renderer.h"

//=============================================================================
// [CTriangle]�R���X�g���N�^
//=============================================================================
CTriangle::CTriangle()
{
    m_pos = D3DXVECTOR3(0.0, 0.0, 0.0f);
    m_size = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
    m_fScaling = 1.0f;
    m_fRenge = 1.0f;
    m_fRadian = 0.0f;
}

//=============================================================================
// [CTriangle]�R���X�g���N�^
// ����
// pos : �ʒu
//=============================================================================
CTriangle::CTriangle(D3DXVECTOR3 pos)
{
    m_pos = pos;
    m_size = D3DXVECTOR3(POLIGON_SIZE, POLIGON_SIZE, 0.0f);
    m_fScaling = 1.0f;
    m_fRenge = 1.0f;
    m_fRadian = 0.0f;
}
//=============================================================================
// [~CTriangle]�f�X�g���N�^
//=============================================================================
CTriangle::~CTriangle()
{
}

//=============================================================================
// [Create] �O�p�`�̃|���S���̐���
//=============================================================================
CTriangle * CTriangle::Create(D3DXVECTOR3 pos)
{
    CTriangle *pTriangle = NULL;
    if (!pTriangle)
    {
        pTriangle = new CTriangle(pos);
        pTriangle->Init();
    }
    return pTriangle;
}

//=============================================================================
// [Init] ����������
//=============================================================================
HRESULT CTriangle::Init(void)
{
    // �ϐ��錾
    VERTEX_2D *pVtx;// ���_���̃|�C���^

    // �f�o�C�X���擾
    LPDIRECT3DDEVICE9 pDevice;
    pDevice = CManager::GetRenderer()->GetDevice();

    // ���_�o�b�t�@�̐���
    HRESULT hr =pDevice->CreateVertexBuffer(
        sizeof(VERTEX_2D) * NUM_VERTEX_TRIANGLE, // �o�b�t�@�T�C�Y
        D3DUSAGE_WRITEONLY,                      // (�Œ�)
        FVF_VERTEX_2D,                           // ���_�t�H�[�}�b�g
        D3DPOOL_MANAGED,                         // (�Œ�)
        &m_pVtxBuff,                             // ���_�o�b�t�@
        NULL);

    // ���S�_����̋������擾(���a�̓��ɓ��������֐�������)
    float r = sqrtf((m_size.x / 2 * m_size.x / 2) + (m_size.y / 2 * m_size.y / 2));

    // ���O�p�`�̊p�x�����߂�
    float fVtxX = cosf(D3DX_PI / 3) * (r * 2);
    float fVtxY = sinf(D3DX_PI / 3) * r;

    // ���_�f�[�^�͈̔͂����b�N���A���_�o�b�t�@�ւ̃|�C���^���擾

    m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

    // ���_����ݒ�
    pVtx[0].pos = D3DXVECTOR3(m_pos.x - 0.0f, m_pos.y - fVtxY, 0.0f);
    pVtx[1].pos = D3DXVECTOR3(m_pos.x + fVtxX, m_pos.y + fVtxY, 0.0f);
    pVtx[2].pos = D3DXVECTOR3(m_pos.x - fVtxX, m_pos.y + fVtxY, 0.0f);

    // rhw�̐ݒ�
    pVtx[0].rhw = 1.0f;
    pVtx[1].rhw = 1.0f;
    pVtx[2].rhw = 1.0f;

    // ���_�J���[�̐ݒ�
    pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.4f);
    pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.4f);
    pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.4f);

    //���_�f�[�^�A�����b�N
    m_pVtxBuff->Unlock();

    return S_OK;
}

//=============================================================================
// [Uninit] �I������
//=============================================================================
void CTriangle::Uninit(void)
{
    // ���_�o�b�t�@�̔j��
    if (m_pVtxBuff)
    {
        m_pVtxBuff->Release();
        m_pVtxBuff = NULL;
    }
    Release();
}

//=============================================================================
// [Update] �X�V����
//=============================================================================
void CTriangle::Update(void)
{

}

//=============================================================================
// [Draw] �`�揈��
//=============================================================================
void CTriangle::Draw(void)
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
    pDevice->SetTexture(0, NULL);

    // �����_�����O�X�e�[�g�̕ύX
    pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

    // �|���S���̕`��
    pDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, NUM_POLYGON_TRIANGLE);

    // �����_�����O�X�e�[�g��߂�
    pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
}

//=============================================================================
// [Rotation] �O�p�`�̉�]
// fRadian : ��]���x
//=============================================================================
void CTriangle::Rotation(float fRadian)
{

    D3DXVECTOR3 vertex1 = D3DXVECTOR3(0.0f, 0.0f, 0.0f);    // �O�p�`�̏�
    D3DXVECTOR3 vertex2 = D3DXVECTOR3(0.0f, 0.0f, 0.0f);    // �O�p�`�̉E
    D3DXVECTOR3 vertex3 = D3DXVECTOR3(0.0f, 0.0f, 0.0f);    // �O�p�`�̍�

    // �p�x�ɉ�]���x�𑫂�
    m_fRadian -= fRadian;

    // ����𒴂��Ȃ��悤�ɂ���
    if (m_fRadian < -D3DX_PI)
    {
        m_fRadian = m_fRadian*(-1.0f);
    }

    // �摜���A�摜�̒��S�����ɉ�]������(���[�J�����W)
    // ��̒��_
    vertex1.x = 0 * cosf(m_fRadian)
        - (-m_size.x * sqrtf(3) / 3) * sinf(m_fRadian);
    vertex1.y = 0 * sinf(m_fRadian)
        + (-m_size.y * sqrtf(3) / 3) * cosf(m_fRadian);
    vertex1.z = 0.0f;

    // �E���̒��_
    vertex2.x = (m_size.x / 2) * cosf(m_fRadian)
        - (m_size.x * sqrtf(3) / 6) * sinf(m_fRadian);
    vertex2.y = (m_size.y / 2) * sinf(m_fRadian)
        + (m_size.y * sqrtf(3) / 6) * cosf(m_fRadian);
    vertex2.z = 0.0f;

    // �����̒��_
    vertex3.x = -(m_size.x / 2) * cosf(m_fRadian)
        - (m_size.x * sqrtf(3) / 6) * sinf(m_fRadian);
    vertex3.y = -(m_size.y / 2) * sinf(m_fRadian)
        + (m_size.y * sqrtf(3) / 6) * cosf(m_fRadian);
    vertex3.z = 0.0f;

    VERTEX_2D *pVtx;//���_���̃|�C���^
                    //���_�f�[�^�͈̔͂����b�N���A���_�o�b�t�@�ւ̃|�C���^���擾
    m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

    // ���_����ݒ�

    pVtx[0].pos = m_pos + vertex1;
    pVtx[1].pos = m_pos + vertex2;
    pVtx[2].pos = m_pos + vertex3;

    //���_�f�[�^�A�����b�N
    m_pVtxBuff->Unlock();
}

//=============================================================================
// [SetColor] ���_�J���[��ύX
//=============================================================================
void CTriangle::SetColor(D3DXCOLOR color)
{
    // �ϐ��錾
    VERTEX_2D *pVtx;//���_���̃|�C���^

    //���_�f�[�^�͈̔͂����b�N���A���_�o�b�t�@�ւ̃|�C���^���擾
    m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

    //���_�J���[�̐ݒ�
    pVtx[0].col = D3DXCOLOR(color.r , color.g , color.b , color.a );
    pVtx[1].col = D3DXCOLOR(color.r , color.g , color.b , color.a );
    pVtx[2].col = D3DXCOLOR(color.r , color.g , color.b , color.a );

    //���_�f�[�^�A�����b�N
    m_pVtxBuff->Unlock();
}
