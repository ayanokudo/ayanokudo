//=============================================================================
//
// �`���[�g���A������ [tutorial.h]
// Author : AYANO KUDO
//
//=============================================================================
#include "tutorial.h"
#include "manager.h"
#include "renderer.h"
#include "inputkeyboard.h"
#include "inputcontroller.h"
#include "fade.h"
#include "polygon.h"
#include "player.h"
#include "bg.h"
#include "item.h"
#include "particle_effect.h"
#include "sound.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define TUTORIAL_POS D3DXVECTOR3(SCREEN_WIDTH/2.0f,SCREEN_HEIGHT/2.0f,0.0f)
#define TUTORIAL_SIZE D3DXVECTOR3(SCREEN_WIDTH,SCREEN_HEIGHT,0.0f)

#define ITEM_TYPE_000_POS D3DXVECTOR3(350.0f,SCREEN_HEIGHT-250.0f,0.0f)                  // �x���[�̏o���ʒu
#define ITEM_TYPE_001_POS D3DXVECTOR3(SCREEN_WIDTH-325.0f,SCREEN_HEIGHT-250.0f,0.0f)     // ���E�\�N�̏o���ʒu
#define ITEM_MOVE D3DXVECTOR3(0.0f,0.0f,0.0f)                                            // �A�C�e���̈ړ���

//*****************************************************************************
// �ÓI�����o�ϐ��̏�����
//*****************************************************************************
LPDIRECT3DTEXTURE9 CTutorial::m_pTexture     = NULL;                                     // �e�N�X�`���ւ̃|�C���^
char*              CTutorial::m_pTextureName = "data/TEXTURE/tutorial001.png";           // �e�N�X�`���̃t�@�C����

//CPolygon          *CTutorial::m_pPolygon     = NULL;                                     // �|���S���ւ̃|�C���^
CPlayer           *CTutorial::m_pPlayer      = NULL;                                     // �v���C���[�I�u�W�F�N�g�ւ̃|�C���^
CBg               *CTutorial::m_pBg          = NULL;                                     // �w�i�I�u�W�F�N�g�ւ̃|�C���^

//=============================================================================
// [CTutorial] �R���X�g���N�^
//=============================================================================
CTutorial::CTutorial()
{
    // �e�탁���o�ϐ�������

}

//=============================================================================
// [~CTutorial] �f�X�g���N�^
//=============================================================================
CTutorial::~CTutorial()
{

}

//=============================================================================
// [Create] �I�u�W�F�N�g�̐���
//=============================================================================
CTutorial *CTutorial::Create(void)
{
    CTutorial* pTutorial = NULL;

    if (pTutorial == NULL)
    {
        pTutorial = new CTutorial;
        pTutorial->Init();
    }

    return pTutorial;
}

//=============================================================================
// [Load] �e�N�X�`���̓ǂݍ���
//=============================================================================
HRESULT CTutorial::Load(void)
{
    //CPlayer::Load();
    //CBg::Load();
    // �f�o�C�X�̎擾�@
    LPDIRECT3DDEVICE9 pDevice;
    pDevice = CManager::GetRenderer()->GetDevice();

    // �e�N�X�`���̐���
    D3DXCreateTextureFromFile(pDevice, m_pTextureName, &m_pTexture);
    CItem::Load();
    CParticle_Effect::Load();
    return S_OK;
}

//=============================================================================
// [Unload] �e�N�X�`���̔j��
//=============================================================================
void CTutorial::Unload(void)
{
    //CPlayer::Unload();
    //CBg::Unload();
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
void CTutorial::Init(void)
{
    // �ϐ��錾
    CSound *pSound = CManager::GetSound();

    // �e�N�X�`���̓ǂݍ���
    Load();
    m_pPolygon = CScene2D::Create(TUTORIAL_POS,TUTORIAL_SIZE);
    m_pPolygon->BindTexture(m_pTexture);
    m_pPolygon->SetObjtype(CScene::OBJTYPE_BG);
    // �e��I�u�W�F�N�g�̐���
    CItem::Create(ITEM_TYPE_000_POS, ITEM_MOVE, CItem::TYPE_000, false);
    CItem::Create(ITEM_TYPE_001_POS, ITEM_MOVE,CItem::TYPE_001,false);

    pSound->Play(CSound::SOUND_LABEL_SE_001);
    //m_pPlayer = CPlayer::Create();
    //m_pBg = CBg::Create();
}

//=============================================================================
// [Uninit] �I������
//=============================================================================
void CTutorial::Uninit(void)
{
    // �ϐ��錾
    CSound *pSound = CManager::GetSound();

    // 2D�|���S���̃������̊J��
    CScene2D::ReleaseAll();

    CScene::ReleaseAll();
    
    // �e�N�X�`���̔j��
    Unload();

    pSound->Stop();
}

//=============================================================================
// [Update] �X�V����
//=============================================================================
void CTutorial::Update(void)
{
    // �ϐ��錾
    CInputKeyboard   *pInputKeyboard = CManager::GetInputKeyboard();
    CInputController *pInputController = CManager::GetInputController();
    // �`���[�g���A���̃X�e�b�v���m�F

    // �X�e�b�v�̍ő吔�ɒB������Q�[�����[�h�ɑJ��
    // �G���^�[�L�[�ŃQ�[�����[�h�ɑJ��
    m_pPolygon->Update();
    if (pInputKeyboard->GetKeyTrigger(DIK_RETURN)||
        pInputController->GetConTrigger(CInputController::BUTTON_10))
    {
        CFade::SetFade(CManager::MODE_GAME);
    }
}

//=============================================================================
// [Draw] �`�揈��
//=============================================================================
void CTutorial::Draw(void)
{
    m_pPolygon->Draw();
}
