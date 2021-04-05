//=============================================================================
//
// �����L���OUI���� [ranking_ui.cpp]
// Author : AYANO KUDO
//
//=============================================================================
#include "ranking_ui.h"
#include "manager.h"
#include "renderer.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define RANKING_UI_POS(type) D3DXVECTOR3(textureData[type].pos.x,textureData[type].pos. y+ (nCountRank*100),0.0f)

//*****************************************************************************
// �ÓI�����o�ϐ��錾
//*****************************************************************************
LPDIRECT3DTEXTURE9 CRanking_UI::m_apTexture[CRanking_UI::UI_MAX] = {};

TEXTURE_DATA       CRanking_UI::textureData[CRanking_UI::UI_MAX] = {
    { D3DXVECTOR3(SCREEN_WIDTH / 2.0f,SCREEN_HEIGHT / 2.0f,0.0f), D3DXVECTOR3(SCREEN_WIDTH,SCREEN_HEIGHT,0.0f),"data/TEXTURE/RankingBg.png" },    // �w�i�摜
    { D3DXVECTOR3(SCREEN_WIDTH / 2.0f,80.0f,0.0f), D3DXVECTOR3(650,100.0f,0.0f),"data/TEXTURE/ranking.png" },                                     // �����L���O�̕���
    { D3DXVECTOR3(300.0f,200.0f,0.0f), D3DXVECTOR3(140.0f,80.0f,0.0f),"data/TEXTURE/rank.png" },                                                  // ���ʂ̕���
    { D3DXVECTOR3(SCREEN_WIDTH - 350.0f, 210.0f, 0.0f), D3DXVECTOR3(90.0f,40.0f,0.0f),"data/TEXTURE/point.png" },                                 // ���_�̕���
}; 

//=============================================================================
// [CRanking_UI] �R���X�g���N�^
//=============================================================================
CRanking_UI::CRanking_UI()
{
    // �����o�ϐ��̏�����
    memset(apScene2D, NULL, sizeof(apScene2D));
}

//=============================================================================
// [~CRanking_UI] �f�X�g���N�^
//=============================================================================
CRanking_UI::~CRanking_UI()
{
}

//=============================================================================
// [Create] �I�u�W�F�N�g�̐���
//=============================================================================
CRanking_UI * CRanking_UI::Create(void)
{
    CRanking_UI *pRankingUI = NULL;
    if (!pRankingUI)
    {
        pRankingUI = new CRanking_UI;
        pRankingUI->Init();
    }
    return pRankingUI;
}

//=============================================================================
// [Load] �e�N�X�`���̓ǂݍ���
//=============================================================================
HRESULT CRanking_UI::Load(void)
{
    // �f�o�C�X�̎擾�@
    LPDIRECT3DDEVICE9 pDevice;
    pDevice = CManager::GetRenderer()->GetDevice();

    for (int nCountTexture = 0; nCountTexture < UI_MAX; nCountTexture++)
    {
        // �e�N�X�`���̐���
        D3DXCreateTextureFromFile(pDevice, textureData[nCountTexture].textureName, &m_apTexture[nCountTexture]);
    }
    return S_OK;
}

//=============================================================================
// [Unload] �e�N�X�`���̔j��
//=============================================================================
void CRanking_UI::Unload(void)
{
    // �e�N�X�`���̊J��
    for (int nCountTexture = 0; nCountTexture < UI_MAX; nCountTexture++)
    {
        if (m_apTexture[nCountTexture] != NULL)
        {
            m_apTexture[nCountTexture]->Release();
            m_apTexture[nCountTexture] = NULL;
        }
    }
}

//=============================================================================
// [Init] ����������
//=============================================================================
HRESULT CRanking_UI::Init(void)
{
    // �w�i�ƕ�����UI�̐ݒ�
    for (int nCountPolygon = 0; nCountPolygon <= UI_001; nCountPolygon++)
    {
        apScene2D[nCountPolygon] = CScene2D::Create(textureData[nCountPolygon].pos, textureData[nCountPolygon].size);
        apScene2D[nCountPolygon]->SetObjtype(CScene::OBJTYPE_BG);
        apScene2D[nCountPolygon]->BindTexture(m_apTexture[nCountPolygon]);
    }
    // ���ʂ̕\��
    for (int nCountRank = 0; nCountRank < MAX_RANKING_SCORE; nCountRank++)
    {
        apScene2D[nCountRank + UI_002] = CScene2D::Create(RANKING_UI_POS(UI_002), textureData[UI_002].size);
        apScene2D[nCountRank + UI_002]->SetObjtype(CScene::OBJTYPE_BG);
        apScene2D[nCountRank + UI_002]->BindTexture(m_apTexture[UI_002]);
        apScene2D[nCountRank + UI_002]->SetTexture(D3DXVECTOR2(0.0f, nCountRank), D3DXVECTOR2(1.0f,5.0f));
    }

    // ���_�̕\��
    for (int nCountRank = 0; nCountRank < MAX_RANKING_SCORE; nCountRank++)
    {
        apScene2D[nCountRank + UI_003] = CScene2D::Create(RANKING_UI_POS(UI_003), textureData[UI_003].size);
        apScene2D[nCountRank + UI_003]->SetObjtype(CScene::OBJTYPE_BG);
        apScene2D[nCountRank + UI_003]->BindTexture(m_apTexture[UI_003]);
    }

    return S_OK;
}

//=============================================================================
// [Uninit] �I������
//=============================================================================
void CRanking_UI::Uninit(void)
{
    // �e�N�X�`���̊J��
    for (int nCntTexture = 0; nCntTexture < UI_MAX; nCntTexture++)
    {
        if (m_apTexture[nCntTexture])
        {
            m_apTexture[nCntTexture]->Release();
            m_apTexture[nCntTexture] = NULL;
        }
    }
}

//=============================================================================
// [Update] �X�V����
//=============================================================================
void CRanking_UI::Update(void)
{
}

//=============================================================================
// [Draw] �`�揈��
//=============================================================================
void CRanking_UI::Draw(void)
{
}
