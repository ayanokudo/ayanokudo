//=============================================================================
//
// �R���g���[���̏��� [inputcontroller.cpp]
// Author : AYANO KUDO
//
//=============================================================================
#include "inputcontroller.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define DEADZONE        2500            // �e����25%�𖳌��]�[���Ƃ���
#define RANGE_MAX       10000           // �L���͈͂̍ő�l
#define RANGE_MIN       -10000          // �L���͈͂̍ŏ��l
#define MAX_CONTROLLER  4               //�Ȃ��R���g���[���[�̍ő吔

//=============================================================================
// [CInputController] �R���X�g���N�^
//=============================================================================
CInputController::CInputController()
{
    // �L�[�̏��N���A
    memset(m_State.rgbButtons, 0, sizeof(m_State.rgbButtons));
    memset(m_Trigger.rgbButtons, 0, sizeof(m_Trigger.rgbButtons));
    memset(m_Release.rgbButtons, 0, sizeof(m_Release.rgbButtons));

    // �\���L�[��0�ŏ���������Ə�Ɉړ����Ă��܂��̂�-1�ŏ���������
    memset(m_State.rgdwPOV, -1, sizeof(m_State.rgdwPOV));
    memset(m_Trigger.rgdwPOV, -1, sizeof(m_Trigger.rgdwPOV));
    memset(m_Release.rgdwPOV, -1, sizeof(m_Release.rgdwPOV));
}

//=============================================================================
// [~CInputController] �f�X�g���N�^
//=============================================================================
CInputController::~CInputController()
{
}

//=============================================================================
//	�W���C�X�e�B�b�N�E�f�o�C�X��񋓁i�R�[���o�b�N�֐��j
//=============================================================================
HRESULT CALLBACK  CInputController::GetJoystickCallback(LPDIDEVICEINSTANCE lpddi)
{
    HRESULT hr;

    hr = m_pInputDevice->CreateDevice(lpddi->guidInstance, &m_pConDevice, NULL);
    if (FAILED(hr))
    {
        return DIENUM_CONTINUE; // ���̃f�o�C�X���
    }

    return DIENUM_CONTINUE;	    // �f�o�C�X�̗񋓂𒆎~

}

//=============================================================================
// [Input] �X�V����
//=============================================================================
HRESULT CInputController::Init(HINSTANCE hInstance, HWND hWnd)
{
    HRESULT	hr;

    //Direct�I�u�W�F�N�g�̍쐬
    if (FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_pInputDevice, NULL)))
    {
        return E_FAIL;
    }

    // �R���g���[���[��T��
    m_pInputDevice->EnumDevices(DI8DEVCLASS_GAMECTRL, (LPDIENUMDEVICESCALLBACK)GetJoystickCallback, NULL, DIEDFL_ATTACHEDONLY);

    if (!m_pConDevice)
        return false;

    for (int nCntButton = 0; nCntButton < MAX_BUTTON; nCntButton++)
    {//�{�^���̏�����
        m_Trigger.rgbButtons[nCntButton] = '\0';
    }

    // �R���g���[���[�p�̃f�[�^�E�t�H�[�}�b�g��ݒ�
    hr = m_pConDevice->SetDataFormat(&c_dfDIJoystick2);
    if (FAILED(hr))
        return false; // �f�[�^�t�H�[�}�b�g�̐ݒ�Ɏ��s

                      // ���[�h��ݒ�i�t�H�A�O���E���h����r�����[�h�j
    hr = m_pConDevice->SetCooperativeLevel(hWnd, DISCL_FOREGROUND | DISCL_EXCLUSIVE);
    if (FAILED(hr))
        return false; // ���[�h�̐ݒ�Ɏ��s

    // ���̒l�͈̔͂�ݒ�
    // X���AY���̂��ꂼ��ɂ��āA�I�u�W�F�N�g���񍐉\�Ȓl�͈̔͂��Z�b�g����B
    // (max-min)�́A�ő�10,000(?)�B(max-min)/2�������l�ɂȂ�B
    // ����傫������΁A�A�i���O�l�ׂ̍��ȓ�����߂炦����B(�p�b�h�́A�֌W�Ȃ�)
    DIPROPRANGE diprg;
    ZeroMemory(&diprg, sizeof(diprg));
    diprg.diph.dwSize = sizeof(diprg);
    diprg.diph.dwHeaderSize = sizeof(diprg.diph);
    diprg.diph.dwHow = DIPH_BYOFFSET;
    diprg.lMin = RANGE_MIN;
    diprg.lMax = RANGE_MAX;
    // X���͈̔͂�ݒ�
    diprg.diph.dwObj = DIJOFS_X;
    m_pConDevice->SetProperty(DIPROP_RANGE, &diprg.diph);
    // Y���͈̔͂�ݒ�
    diprg.diph.dwObj = DIJOFS_Y;
    m_pConDevice->SetProperty(DIPROP_RANGE, &diprg.diph);
    // Z���͈̔͂�ݒ�
    diprg.diph.dwObj = DIJOFS_Z;
    m_pConDevice->SetProperty(DIPROP_RANGE, &diprg.diph);
    // Z��]�͈̔͂�ݒ�
    diprg.diph.dwObj = DIJOFS_RZ;
    m_pConDevice->SetProperty(DIPROP_RANGE, &diprg.diph);

    // �e�����ƂɁA�����̃]�[���l��ݒ肷��B
    // �����]�[���Ƃ́A��������̔����ȃW���C�X�e�B�b�N�̓����𖳎�����͈͂̂��ƁB
    // �w�肷��l�́A10000�ɑ΂��鑊�Βl(2000�Ȃ�20�p�[�Z���g)�B
    DIPROPDWORD	dipdw;
    dipdw.diph.dwSize = sizeof(DIPROPDWORD);
    dipdw.diph.dwHeaderSize = sizeof(dipdw.diph);
    dipdw.diph.dwHow = DIPH_BYOFFSET;
    dipdw.dwData = DEADZONE;
    //X���̖����]�[����ݒ�
    dipdw.diph.dwObj = DIJOFS_X;
    m_pConDevice->SetProperty(DIPROP_DEADZONE, &dipdw.diph);
    //Y���̖����]�[����ݒ�
    dipdw.diph.dwObj = DIJOFS_Y;
    m_pConDevice->SetProperty(DIPROP_DEADZONE, &dipdw.diph);
    //Z���̖����]�[����ݒ�
    dipdw.diph.dwObj = DIJOFS_Z;
    m_pConDevice->SetProperty(DIPROP_DEADZONE, &dipdw.diph);
    //Z��]�̖����]�[����ݒ�
    dipdw.diph.dwObj = DIJOFS_RZ;
    m_pConDevice->SetProperty(DIPROP_DEADZONE, &dipdw.diph);
    //�R���g���[���[���͐���J�n
    m_pConDevice->Acquire();

    return S_OK;
}


//=============================================================================
// [Uninit] �I������
//=============================================================================
void CInputController::Uninit(void)
{
    CInput::Uninit();
}

//=============================================================================
// [Update] �X�V����
//=============================================================================
void CInputController::Update(void)
{
    DIJOYSTATE2 ControllerState;

    HRESULT hr;
    int nCntButton;

    if (m_pConDevice != NULL)
    {
        hr = m_pConDevice->Poll();

        hr = m_pConDevice->GetDeviceState(sizeof(DIJOYSTATE2), &ControllerState);

        //�f�o�C�X����f�[�^���擾
        if (SUCCEEDED(hr = m_pConDevice->GetDeviceState(sizeof(DIJOYSTATE2), &ControllerState)))
        {

            //�v���X���
            m_State.lY = ControllerState.lY;
            m_State.lX = ControllerState.lX;

            m_State.lZ = ControllerState.lZ;		//�X�e�B�b�N�̉��iZ���j
            m_State.lRz = ControllerState.lRz;		//�X�e�B�b�N�̏c�iZ��]�j

            //�\���L�[�̏��
            for (int nCnt = 0; nCnt < 3; nCnt++)
            {
                //�\���L�[�v���X����ۑ�
                m_State.rgdwPOV[nCnt] = ControllerState.rgdwPOV[nCnt];

            }

            //�{�^���̏��
            for (nCntButton = 0; nCntButton < MAX_BUTTON; nCntButton++)
            {
                //�L�[�g���K�[����ۑ�
                m_Trigger.rgbButtons[nCntButton] = (m_State.rgbButtons[nCntButton] ^ ControllerState.rgbButtons[nCntButton]) & ControllerState.rgbButtons[nCntButton];

                //�L�[�����[�X����ۑ�
                m_Release.rgbButtons[nCntButton] = (m_State.rgbButtons[nCntButton] ^ ControllerState.rgbButtons[nCntButton]) & ControllerState.rgbButtons[nCntButton];

                //�L�[�v���X����ۑ�
                m_State.rgbButtons[nCntButton] = ControllerState.rgbButtons[nCntButton];
            }
        }
        else
        {
            //�R���g���[���[�̃A�N�Z�X�����擾
            m_pConDevice->Acquire();
        }
    }
}

