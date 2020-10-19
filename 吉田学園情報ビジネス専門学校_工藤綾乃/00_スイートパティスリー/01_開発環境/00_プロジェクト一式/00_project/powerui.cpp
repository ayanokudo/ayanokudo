//=============================================================================
//
// �p���[�A�b�vUI���� [effect.cpp]
// Author : AYANO KUDO
//
//=============================================================================
#include "powerui.h"
#include "manager.h"
#include "renderer.h"
#include "polygon.h"
#include "player.h"

//*****************************************************************************
// �ÓI�����o�ϐ�
//*****************************************************************************
LPDIRECT3DTEXTURE9 CPowerUI::m_pTexture = NULL;

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define POWERUI_SIZE_X (140.0f)
#define POWERUI_SIZE_Y (60.0f)
#define POWERUP_TEXTURE "data/TEXTURE/puwerUp.png"

//=============================================================================
// [CPowerUI] �R���X�g���N�^
//=============================================================================
CPowerUI::CPowerUI()
{

    m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
    m_size = D3DXVECTOR3(POWERUI_SIZE_X, POWERUI_SIZE_Y, 0.0f);
    SetObjtype(OBJTYPE_UI);
    for (int nCount = 0; nCount < MAX_POWERUI; nCount++)
    {
        m_apPolygon[nCount] = NULL;
    }
}

//=============================================================================
// [~CPowerUI] �f�X�g���N�^
//=============================================================================
CPowerUI::~CPowerUI()
{

}

//=============================================================================
// [Create] �I�u�W�F�N�g�̐���
//=============================================================================
CPowerUI * CPowerUI::Create(void)
{
    CPowerUI *pPowerUI = NULL;
    if (!pPowerUI)
    {
        pPowerUI = new CPowerUI;
        pPowerUI->Init();
    }
    return nullptr;
}

//=============================================================================
// [Load] �e�N�X�`���̓ǂݍ���
//=============================================================================
HRESULT CPowerUI::Load(void)
{
    // �f�o�C�X�̎擾
    LPDIRECT3DDEVICE9 pDevice;
    pDevice = CManager::GetRenderer()->GetDevice();

    // �e�N�X�`���̐���
    D3DXCreateTextureFromFile(pDevice, POWERUP_TEXTURE, &m_pTexture);
    return S_OK;
}

//=============================================================================
// [Unload] �e�N�X�`���̔j��
//=============================================================================
void CPowerUI::Unload(void)
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
//=============================================================================
HRESULT CPowerUI::Init()
{
    for (int nCount = 0; nCount < MAX_POWERUI; nCount++)
    {
        if (!m_apPolygon[nCount])
        {
            m_apPolygon[nCount] = CPolygon::Create(D3DXVECTOR3(POWERUI_SIZE_X /2+(POWERUI_SIZE_X*nCount+10),SCREEN_HEIGHT- POWERUI_SIZE_Y/2,0.0f), m_size);
            m_apPolygon[nCount]->BindTexture(m_pTexture);
            m_apPolygon[nCount]->SetTexture(D3DXVECTOR2((float)nCount, 0.0f), (D3DXVECTOR2(MAX_POWERUI, 1.0f)));
        }
    }
    return S_OK;
}

//=============================================================================
// [Uninit] �I������
//=============================================================================
void CPowerUI::Uninit(void)
{
    for (int nCount = 0; nCount < MAX_POWERUI; nCount++)
    {
        if (m_apPolygon[nCount] != NULL)
        {
            m_apPolygon[nCount]->Uninit();
            delete m_apPolygon[nCount];
            m_apPolygon[nCount] = NULL;
        }
    }
    Release();
}

//=============================================================================
// [Update] �X�V����
//=============================================================================
void CPowerUI::Update(void)
{
    ChangeColor();
}

//=============================================================================
// [Draw] �`�揈��
//=============================================================================
void CPowerUI::Draw(void)
{
    for (int nCount = 0; nCount < MAX_POWERUI; nCount++)
    {
        m_apPolygon[nCount]->Draw();
    }
}

//=============================================================================
// [ChangeColor] �F�̕ύX
//=============================================================================
void CPowerUI::ChangeColor(void)
{
    //���@�Ƃ̓����蔻��
    for (int nCount = 0; nCount < MAX_POLYGON; nCount++)
    {
        CScene *pScene = GetSceneObject(nCount);
        if (pScene != NULL)
        {
            if (pScene->GetObjectType() == CScene::OBJTYPE_PLAYER)
            {
                int nPowerUp = ((CPlayer*)pScene)->GetPowerUp();
                // �v���C���[�̃p���[�A�b�v�����擾
                for (int nCount = 0; nCount < MAX_POWERUI; nCount++)
                {
                    if (nCount == nPowerUp-1)
                    {
                        m_apPolygon[nCount]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.8f));
                    }
                    else
                    {
                        m_apPolygon[nCount]->SetColor(D3DXCOLOR(0.462f, 0.262f, 0.141f, 0.8f));
                    }
                }
            }
        }
    }
}
