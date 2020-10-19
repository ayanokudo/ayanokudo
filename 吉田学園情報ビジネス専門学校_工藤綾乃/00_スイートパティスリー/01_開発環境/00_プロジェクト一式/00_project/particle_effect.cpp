//=============================================================================
//
// ���q�G�t�F�N�g���� [particle_effect.cpp]
// Author : AYANO KUDO
//
//=============================================================================
#include "particle_effect.h"
#include "manager.h"
#include "renderer.h"

//*****************************************************************************
// �ÓI�����o�ϐ�
//*****************************************************************************
LPDIRECT3DTEXTURE9 CParticle_Effect::m_pTexture[PARTICLE_TYPE_MAX] = {};
char *CParticle_Effect::m_pTextureName[PARTICLE_TYPE_MAX] =
{
    { "data/TEXTURE/effect000.png" },
    { "data/TEXTURE/effect001.png" },
    { "data/TEXTURE/effect004.png" }
};

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define PARTICLE_EFFECT_SIZE_X (30)
#define PARTICLE_EFFECT_SIZE_Y (30)
#define NUM_BOM_PARTICLE       (10)

//=============================================================================
// [CParticle_Effect] �R���X�g���N�^
//=============================================================================
CParticle_Effect::CParticle_Effect()
{
    SetObjtype(OBJTYPE_EFFECT);
    m_Collor = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0);
}

//=============================================================================
// [~CParticle_Effect] �f�X�g���N�^
//=============================================================================
CParticle_Effect::~CParticle_Effect()
{
}

//=============================================================================
// [Create] �I�u�W�F�N�g�̐���
//=============================================================================
CParticle_Effect *CParticle_Effect::Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, D3DXVECTOR3 ReductionMove, D3DXCOLOR Collor, float fSize, float fReductionSize, float fReductionAlpha, PARTICLE_TYPE type)
{
    CParticle_Effect *pParticleEffect = NULL;
    if (pParticleEffect==NULL)
    {
        pParticleEffect = new CParticle_Effect;
        pParticleEffect->Init(pos, move, ReductionMove, Collor, fSize, fReductionSize,fReductionAlpha, type);
    }
    return pParticleEffect;
}

//=============================================================================
// [Load] �e�N�X�`���̓ǂݍ���
//=============================================================================
HRESULT CParticle_Effect::Load(void)
{
    // �f�o�C�X�̎擾�@
    LPDIRECT3DDEVICE9 pDevice;
    pDevice = CManager::GetRenderer()->GetDevice();
    for (int nCntTecture = 0; nCntTecture < PARTICLE_TYPE_MAX; nCntTecture++)
    {
        // �e�N�X�`���̐���
        D3DXCreateTextureFromFile(pDevice, m_pTextureName[nCntTecture], &m_pTexture[nCntTecture]);
    }
    return S_OK;
}


//=============================================================================
// [Unload] �e�N�X�`���̔j��
//=============================================================================
void CParticle_Effect::Unload(void)
{
    // �e�N�X�`���̊J��
    for (int nCntTecture = 0; nCntTecture < PARTICLE_TYPE_MAX; nCntTecture++)
    {
        if (m_pTexture[nCntTecture] != NULL)
        {
            m_pTexture[nCntTecture]->Release();
            m_pTexture[nCntTecture] = NULL;
        }
    }
}

//=============================================================================
// [Init] ����������
//=============================================================================
HRESULT CParticle_Effect::Init(D3DXVECTOR3 pos, D3DXVECTOR3 move, D3DXVECTOR3 ReductionMove, D3DXCOLOR Collor, float fSize, float fReductionSize, float fReductionAlpha, PARTICLE_TYPE type)
{
    // �e�ϐ��ɑ��
    m_pos = pos;
    m_move = move;
    m_ReductionMove = ReductionMove;
    m_Collor = Collor;
    m_fSize = fSize;
    m_fReductionSize = fReductionSize;
    m_fReductionAlpha = fReductionAlpha;

    // �G�t�F�N�g�̏�����
    SetPosition(m_pos);
    SetSize(D3DXVECTOR3(m_fSize, m_fSize, 0.0f));
    CScene2D::Init();
    SetColor(m_Collor);

    // �e�N�X�`���̊��蓖��
    BindTexture(m_pTexture[type]);
    return S_OK;
}

//=============================================================================
// [Uninit] �I������
//=============================================================================
void CParticle_Effect::Uninit(void)
{
    CScene2D::Uninit();
}

//=============================================================================
// [Update] �X�V����
//=============================================================================
void CParticle_Effect::Update(void)
{
    m_move += m_ReductionMove;
    m_pos += m_move;

    // �A���t�@�l������������
    m_Collor.a -= m_fReductionAlpha;

    // �A���t�@�l��0�ɂȂ�����G�t�F�N�g���폜
    if (m_Collor.a<0.0f)
    {
        Uninit();
        return;
    }

    //�T�C�Y������������
    m_fSize -= m_fReductionSize;

    if (m_fSize < 0.0f)
    {
        Uninit();
        return;
    }
    SetSize(D3DXVECTOR3(m_fSize, m_fSize,0.0f));
    SetPosition(m_pos);
    SetColor(m_Collor);
    CScene2D::Update();
}

//=============================================================================
// [Draw] �`�揈��
//=============================================================================
void CParticle_Effect::Draw(void)
{
    // �f�o�C�X���擾
    LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

    // �����_�����O�X�e�[�g�̕ύX
    pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

    // �|���S���̕`��
    CScene2D::Draw();

    // �����_�����O�X�e�[�g��߂�
    pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
}

//=============================================================================
// [SetTrajectory] �O�ՃG�t�F�N�g
// ����
// pos               : �G�t�F�N�g��\��������ʒu
// move              : �G�t�F�N�g�̈ړ���
// ReductionMove     : �ړ��ʂ̌�����
// Collor            : �G�t�F�N�g�̐F
// fSize             : �G�t�F�N�g�̃T�C�Y
// fReductionAlpha   : �A���t�@�l�̌�����
// type              : �g�p����G�t�F�N�g�̉摜
//=============================================================================
void CParticle_Effect::SetTrajectory(D3DXVECTOR3 pos, D3DXVECTOR3 move, D3DXVECTOR3 ReductionMove, D3DXCOLOR Collor, float fSize, float fReductionSize, float fReductionAlpha, PARTICLE_TYPE type)
{
    Create(pos, move, ReductionMove, Collor, fSize, fReductionSize, fReductionAlpha, type);
}

//=============================================================================
// [SetBom] �����G�t�F�N�g
// ����
// pos               : �G�t�F�N�g��\��������ʒu
// move              : �G�t�F�N�g�̈ړ���
// ReductionMove     : �ړ��ʂ̌�����
// Collor            : �G�t�F�N�g�̐F
// fSize             : �G�t�F�N�g�̃T�C�Y
// fReductionAlpha   : �A���t�@�l�̌�����
// type              : �g�p����G�t�F�N�g�̉摜
//=============================================================================
void CParticle_Effect::SetBom(D3DXVECTOR3 pos, D3DXVECTOR3 move, D3DXVECTOR3 ReductionMove, D3DXCOLOR Collor, float fSize, float fReductionSize, float fReductionAlpha, PARTICLE_TYPE type)
{
    // �G�t�F�N�g�̐������[�v
    for (int nCntEffect = 0; nCntEffect < NUM_BOM_PARTICLE; nCntEffect++)
    {
        // �G�t�F�N�g�̐ݒ�
        float fAngle = (rand() % 314 / 100.0f)*(rand() % 20) * -1;          // �p�x���v�Z����
        D3DXVECTOR3 actualMove = D3DXVECTOR3((float)sin(fAngle) * move.x, (float)cos(fAngle) * move.y, 0.0f);
        Create(pos, actualMove, ReductionMove, Collor, fSize, fReductionSize, fReductionAlpha, type);
    }
}
