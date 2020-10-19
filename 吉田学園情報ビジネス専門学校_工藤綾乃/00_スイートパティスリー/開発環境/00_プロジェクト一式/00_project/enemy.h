//=============================================================================
//
// �G�̏��� [enemy.h]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "scene2d.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define MAX_ORBIT (10)      // �ۑ��ł���O���̍ő吔

#define ENEMY_SIZE_X    (60.0f)
#define ENEMY_SIZE_Y    (60.0f)

//*****************************************************************************
// �N���X�̒�`
//*****************************************************************************
class CEnemy : public CScene2D
{
public:
    // ��Ԃ̗񋓌^
    typedef enum
    {
        STATE_NORMAL = 0,     // �ʏ���
        STATE_ANGER,        // �{����(�{�X�̂ݎg�p)
        STATE_DAMAGE,       // �_���[�W���
    }STATE;

    CEnemy();
    ~CEnemy();

    static CEnemy *Create(void);

    static HRESULT Load(void);
    static void Unload(void);

    HRESULT Init(void);
    void Uninit(void);
    void Update(void);
    void Draw(void);

    void Damage(void);
    void CheckSurvival(void);

    void CheckState(void);

    // �ړ��ʂ̃Z�b�^/�Q�b�^
    void        SetMove(D3DXVECTOR3 move) { m_move = move; }
    D3DXVECTOR3 GetMove(void)             { return m_move; }

    // ���C�t�̃Z�b�^/�Q�b�^
    void SetLife(int nDamage) { m_nLife = nDamage; }
    int  GetLife(void)        { return m_nLife; }

    // ����ԍ��̃Z�b�^/�Q�b�^
    void SetFormaitionNum(int nFormaitionNum) { m_nFormaitionNum = nFormaitionNum; }
    int  GetFormaitionNum(void)               { return m_nFormaitionNum; }

    // ��Ԃ̃Z�b�^/�Q�b�^
    void  SetState(STATE state) { m_State = state; }
    STATE GetState(void)        { return m_State; }

    // ���[�U�[���󂯂�܂ł̃J�E���^�̃Z�b�^/�Q�b�^
    void SetCntLaserInterval(int nCntLaserInterval){ m_nCntLaserInterval = nCntLaserInterval; }
    int  GetnCntLaserInterval(void) { return m_nCntLaserInterval; }

    // �������{�X�ł��邩�ǂ����̃Z�b�^/�Q�b�^
    void SetIsBoss(bool bIsBoss) { m_bIsBoss = bIsBoss; }
    bool GetIsBoss(void) { return m_bIsBoss; }

private:
    static LPDIRECT3DTEXTURE9 m_pTexture;              // �e�N�X�`���ւ̃|�C���^
    static char              *m_apTextureName;         // �e�N�X�`���̃t�@�C����

    D3DXVECTOR3               m_move;                  // �ړ���
    int                       m_nLife;                 // �̗�
    int                       m_nFormaitionNum;        // �ґ��ԍ�
    int                       m_nStateCount;           // ��Ԃ̃J�E���^
    STATE                     m_State;                 // ���

    int m_nCntLaserInterval;                            // ���[�U�[�̃_���[�W���󂯂�悤�ɂȂ�܂ł̃J�E���^
    bool m_bIsBoss;                                     // �������{�X���ǂ���
};

#endif // !_ENEMY_H_
