//=============================================================================
//
// 2D�|���S���̏��� [scene2d.cpp]
// Author : AYANO KUDO
//
//=============================================================================
#include "scene2d.h"
#include "renderer.h"
#include "manager.h"

//=============================================================================
// [CScene2D]�R���X�g���N�^
//=============================================================================
 CScene2D::CScene2D()
 {
     m_pTexture = NULL;
     m_pVtxBuff = NULL;
     m_size = D3DXVECTOR3(50.0f, 50.0f, 0.0f);
 };

//=============================================================================
// [CScene2D] �R���X�g���N�^
//=============================================================================
CScene2D::CScene2D(D3DXVECTOR3 pos , D3DXVECTOR3 size)
{
    m_pTexture = NULL;
    m_pVtxBuff = NULL;
    m_pos = pos;
    m_size = size;
}

//=============================================================================
// [~CScene2D] �f�X�g���N�^
//=============================================================================
CScene2D::~CScene2D()
{

}

//=============================================================================
// [Create]�I�u�W�F�N�g����
//=============================================================================
CScene2D* CScene2D::Create(D3DXVECTOR3 pos , D3DXVECTOR3 size)
{
    // �ϐ��錾
    CScene2D *pScene2D;

    // �������̊m��
    pScene2D = new CScene2D(pos,size);

    // ����������
    pScene2D->Init();
    return pScene2D;
}

//=============================================================================
// [Init] ����������
//=============================================================================
HRESULT CScene2D::Init(void)
{
    VERTEX_2D *pVtx;//���_���̃|�C���^

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
void CScene2D::Uninit(void)
{
    SetObjtype(OBJTYPE_NONE);

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
void CScene2D::Update(void)
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
void CScene2D::Draw(void)
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
// [SetTexture] UV���W�̕ύX(�e�N�X�`���������΂��p)
// tex : �������΂��e�N�X�`���̖���
//=============================================================================
void CScene2D::SetTexture(D3DXVECTOR2 tex)
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

//=============================================================================
// [SetTexture] UV���W�̕ύX(�e�N�X�`���A�j���[�V�����p)
// tex           : ���������e�N�X�`���̕\���͈�
// nSplitPolygon : �e�N�X�`���̕�����
//=============================================================================
void CScene2D::SetTexture(D3DXVECTOR2 tex, const D3DXVECTOR2 nSplitPolygon)
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
// ���_�J���[��ύX
//=============================================================================
void CScene2D::SetColor(D3DXCOLOR coror)
{
    // �ϐ��錾
    VERTEX_2D *pVtx;//���_���̃|�C���^

   //���_�f�[�^�͈̔͂����b�N���A���_�o�b�t�@�ւ̃|�C���^���擾

    m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

    //���_�J���[�̐ݒ�
    pVtx[0].col = D3DXCOLOR(coror.r,coror.g, coror.b, coror.a);
    pVtx[1].col = D3DXCOLOR(coror.r,coror.g, coror.b, coror.a);
    pVtx[2].col = D3DXCOLOR(coror.r,coror.g, coror.b, coror.a);
    pVtx[3].col = D3DXCOLOR(coror.r,coror.g, coror.b, coror.a);

    //���_�f�[�^�A�����b�N
    m_pVtxBuff->Unlock();
}

//=============================================================================
// [JudgeFittingRectangle] ��`�̓����蔻��
// �Ԃ�l : �������Ă���I�u�W�F�N�g�̃|�C���^
//=============================================================================
CScene* CScene2D::JudgeFittingRectangle(CScene::OBJTYPE type)
{
    // �ϐ��錾
    CScene *pScene = NULL;

    // �I�u�W�F�N�g�̐������[�v
    for (int nCount = 0; nCount < MAX_POLYGON; nCount++)
    {
        pScene = GetSceneObject(nCount);
        if (pScene != NULL)
        {
            if (pScene->GetObjectType() == type)
            {
                D3DXVECTOR3 objPos = ((CScene2D*)pScene)->GetPosition();
                D3DXVECTOR3 objSize = ((CScene2D*)pScene)->GetSize();

                // �������Ă�����
                if (m_pos.x - m_size.x / 2 <= objPos.x + objSize.x / 2 &&
                    m_pos.x + m_size.x / 2 >= objPos.x - objSize.x / 2 &&
                    m_pos.y - m_size.y / 2 <= objPos.y + objSize.y / 2 &&
                    m_pos.y + m_size.y / 2 >= objPos.y - objSize.y / 2)
                {
                    return pScene;  // �������Ă�����I�u�W�F�N�g�̃A�h���X��Ԃ�
                }
            }
        }
    }
    return pScene;// �������Ă��Ȃ���NULL��Ԃ�
}

//=============================================================================
// [JudgeFittingRectangle] �~�̓����蔻��
// �Ԃ�l : �������Ă���I�u�W�F�N�g�̃|�C���^
//=============================================================================
CScene * CScene2D::CheckCircleCollision(CScene::OBJTYPE type)
{
    return nullptr;
    // �ϐ��錾
    CScene *pScene = NULL;

    // �I�u�W�F�N�g�̐������[�v
    for (int nCount = 0; nCount < MAX_POLYGON; nCount++)
    {
        pScene = GetSceneObject(nCount);
        if (pScene != NULL)
        {
            if (pScene->GetObjectType() == type)
            {
                D3DXVECTOR3 objPos = ((CScene2D*)pScene)->GetPosition();
                D3DXVECTOR3 objSize = ((CScene2D*)pScene)->GetSize();

                // �������Ă�����
                float distance = powf(m_pos.x - objPos.x, 2.0f) + powf(m_pos.y - objPos.y, 2.0f) + 0.0f;      //�ʒu
                float radius = powf(m_size.x + objSize.x, 2.0f); //���a
                if (distance <= radius)//�������Ă��邩�ǂ���
                {
                    return pScene;  // �������Ă�����I�u�W�F�N�g�̃A�h���X��Ԃ�
                }
            }
        }
    }
    return pScene;// �������Ă��Ȃ���NULL��Ԃ�
}