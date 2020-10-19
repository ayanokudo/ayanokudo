//=============================================================================
//
// �T�E���h���� [sound.h]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef _SOUND_H_
#define _SOUND_H_
#include "main.h"

//*****************************************************************************
// �N���X�̒�`
//*****************************************************************************
class CSound
{
public:
    CSound();
    ~CSound();
    // �T�E���h�t�@�C��
    typedef enum
    {
        SOUND_LABEL_BGM000 = 0,
        SOUND_LABEL_BGM001,
        SOUND_LABEL_BGM002,
        SOUND_LABEL_BGM003,
        SOUND_LABEL_SE_000,
        SOUND_LABEL_SE_001,
        SOUND_LABEL_SE_002,
        SOUND_LABEL_SE_003,
        SOUND_LABEL_SE_004,
        SOUND_LABEL_SE_005,
        SOUND_LABEL_SE_006,// ���艹
        SOUND_LABEL_SE_007,// �A�C�e���擾
        SOUND_LABEL_SE_008,// �p���[�A�b�v
        SOUND_LABEL_MAX,
    } SOUND_LABEL;      // �T�E���h�ԍ�

    HRESULT Init(HWND hWnd);           // �T�E���h����������
    void Uninit(void);                 // �T�E���h�I������
    HRESULT Play(SOUND_LABEL label);   // �Ȃ̍Đ�
    void Stop(SOUND_LABEL label);      // �Ȃ̒�~(����̕�)
    void Stop(void);                   // �Ȃ̒�~�i���ׂāj

private:
    HRESULT CheckChunk(HANDLE hFile, DWORD format, DWORD *pChunkSize, DWORD *pChunkDataPosition);
    HRESULT ReadChunkData(HANDLE hFile, void *pBuffer, DWORD dwBuffersize, DWORD dwBufferoffset);

    // �T�E���h�f�[�^�\����
    typedef struct
    {
        char *pFilename;    // �t�@�C����
        int nCntLoop;       // ���[�v�J�E���g
    } PARAM;

    IXAudio2 *m_pXAudio2 = NULL;                                     // XAudio2�I�u�W�F�N�g�ւ̃C���^�[�t�F�C�X
    IXAudio2MasteringVoice *m_pMasteringVoice = NULL;                // �}�X�^�[�{�C�X
    IXAudio2SourceVoice *m_apSourceVoice[SOUND_LABEL_MAX] = {};      // �\�[�X�{�C�X
    BYTE *m_apDataAudio[SOUND_LABEL_MAX] = {};                       // �I�[�f�B�I�f�[�^
    DWORD m_aSizeAudio[SOUND_LABEL_MAX] = {};                        // �I�[�f�B�I�f�[�^�T�C�Y

    static PARAM m_aParam[SOUND_LABEL_MAX];
};


#endif