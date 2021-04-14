//=============================================================================
//
// ���˂�G�̏��� [enemy_type2.cpp]
// Author : AYANO KUDO
//
//=============================================================================
#include "enemy_type2.h"
#include "manager.h"
#include "renderer.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define FRICTION_FACTOR (0.07f)                 // ���C�W��
#define TEXTUER_SPLIT {1.0f,2.0f}               // �e�N�X�`���̕�����
#define TEXTUER_POS {1.0f,(float)((m_nTex%2))}         // �e�N�X�`�����W
#define TEXTUER_COUNTER (60)                    // �e�N�X�`���̃R�}��؂�ւ���^�C�~���O

//*****************************************************************************
// �ÓI�����o�ϐ�������
//*****************************************************************************
LPDIRECT3DTEXTURE9 CEnemy_Type2::m_pTexture = NULL;                           // �e�N�X�`���ւ̃|�C���^
char*              CEnemy_Type2::m_pTextureName = "data/TEXTURE/enemy001.png";    // �e�N�X�`���̃t�@�C����

//=============================================================================
// [CEnemy_Type2] �R���X�g���N�^
//=============================================================================
CEnemy_Type2::CEnemy_Type2()
{
    m_nTex = 1;
    m_nAnimationCounter = 0;
    m_fAngle = 0;
    SetMove(D3DXVECTOR3(-2.0f, 0.0f, 0.0f));

}

//=============================================================================
// [~CEnemy_Type2] �f�X�g���N�^
//=============================================================================
CEnemy_Type2::~CEnemy_Type2()
{

}

//=============================================================================
// [Create] �I�u�W�F�N�g�̐���
//=============================================================================
CEnemy_Type2 *CEnemy_Type2::Create(D3DXVECTOR3 pos, int Formaition, int nNum)
{
    // �ϐ��錾
    CEnemy_Type2 *pCEnemy_Type2 = NULL;
    if (pCEnemy_Type2==NULL)
    {
        // �������̊m��
        pCEnemy_Type2 = new CEnemy_Type2;
        pCEnemy_Type2->Init(pos, Formaition, nNum);
    }
    return pCEnemy_Type2;
}

//=============================================================================
// [Load] �e�N�X�`���̓ǂݍ���
//=============================================================================
HRESULT CEnemy_Type2::Load(void)
{
    // �f�o�C�X�̎擾
    LPDIRECT3DDEVICE9 pDevice;
    pDevice = CManager::GetRenderer()->GetDevice();
    D3DXCreateTextureFromFile(pDevice, m_pTextureName, &m_pTexture);
    return S_OK;
}

//=============================================================================
// [UnLoad] �e�N�X�`���̔j��
//=============================================================================
void CEnemy_Type2::Unload(void)
{
    // �e�N�X�`���̔j��

    if (m_pTexture != NULL)
    {
        m_pTexture->Release();
        m_pTexture = NULL;
    }

}

//=============================================================================
// [Init] ����������
//=============================================================================
HRESULT CEnemy_Type2::Init(D3DXVECTOR3 pos, int Formaition, int nNum)
{
    SetPosition({ pos.x + (ENEMY_SIZE_X * nNum), pos.y, 0.0f });
    SetFormaitionNum(Formaition);
    CEnemy::Init();
    // �e�N�X�`���̊��蓖��
    BindTexture(m_pTexture);

    return S_OK;
}

//=============================================================================
// [Uninit] �I������
//=============================================================================
void CEnemy_Type2::Uninit(void)
{
    CEnemy::Uninit();
}

//=============================================================================
// [~CEnemy] �X�V����
//=============================================================================
void CEnemy_Type2::Update(void)
{

    move();

    // �A�j���[�V����
    m_nAnimationCounter++;
    if (m_nAnimationCounter % TEXTUER_COUNTER == 0)
    {
        m_nTex++;
    }

    SetTexture(TEXTUER_POS, TEXTUER_SPLIT);

    CEnemy::Update();
}
//=============================================================================
// [Draw] �`�揈��
//=============================================================================
void CEnemy_Type2::Draw(void)
{
    CEnemy::Draw();
}

//=============================================================================
// [move] �G�̈ړ�
//=============================================================================
void CEnemy_Type2::move(void)
{
    // ����������
    D3DXVECTOR3 pos = GetPosition();
    //pos.y *= FRICTION_FACTOR;
    m_fAngle+=3;
    pos.y =  5*sinf(D3DXToRadian( m_fAngle )) + pos.y;


    SetPosition(pos);


}


