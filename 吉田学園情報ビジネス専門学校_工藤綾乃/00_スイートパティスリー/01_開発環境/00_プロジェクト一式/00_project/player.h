//=============================================================================
//
// �v���C���[�̏��� [player.h]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef _PLAYER_H_
#define  _PLAYER_H_
#include "scene2d.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define LIMIT_OPTION  (4)                    // �I�v�V�����̃p���[�A�b�v���E�l
#define LIMIT_PLAYER_BULLET (2)              // �����Ɍ��Ă�V���b�g�̐�
#define LIMIT_PLAYER_DOBLE (2)               // �����Ɍ��Ă�V���b�g�̐�(�_�u����)

#define BULLET_INTERVAL     (10)             // �e�̔��ˊԊu
#define MISSILE_INTERVAL    (60)            // �~�T�C���̔��ˊԊu
#define LASER_INTERVAL      (60)            // ���[�U�[�̔��ˊԊu

//*****************************************************************************
// �O���錾
//*****************************************************************************
class CLife;
class COption;
class CBullet;
class CShield;
class CEnergy_UI;

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define MAX_ENERGY (2500)                             // �G�l���M�[�̗�(�Ȃ��Ȃ�ƃ~�X)

//*****************************************************************************
// �N���X�̒�`
//*****************************************************************************
class CPlayer : public CScene2D
{
public:
    // �p���[�A�b�v�Q�[�W�̏��
    typedef enum
    {
        POWERUP_NONE = 0,// �����Ȃ�
        POWERUP_SPPED,   // �����Ȃ�ŁI
        POWERUP_MISSILE, // �~�T�C����I
        POWERUP_DOUBLE,  // ��t�_�u��?
        POWERUP_LASER,   // �����������S
        POWERUP_OPTION,  // ���g�̏p��I
        POWERUP_SHIELD,  // �o�`���A�b�I
        POWERUP_MAX      // �Q�[�W���
    }POWERUP;

    // �V���b�g�̎��
    typedef enum
    {
        SHOTTYPE_BULLET = 0,        // �e(�p���[�A�b�v����)
        SHOTTYPE_DOBLE,             // �e(�_�u�����)
        SHOTTYPE_LASER,             // ���[�U�[
        SHOTTYPE_MAX
    }SHOTTYPE;

    // �v���C���[�̏��
    typedef enum
    {
        PLAYER_STATE_NORMAL=0,       // �ʏ���
        PLAYER_STATE_DAMAGE,         // �_���[�W���
        PLAYER_STATE_INVINCIBLE,     // ���G���
        PLAYER_STATE_MAX
    }STATE;

    CPlayer();
    ~CPlayer();

    static CPlayer *Create(void);

    static HRESULT Load(void);
    static void Unload(void);

    HRESULT Init(void);
    void Uninit(void);
    void Update(void);
    void Draw(void);

    void Move(void);

    void ShootBullet(void);
    void ShootDouble(void);
    void ShootLaser(void);
    void ShootMissile(void);

    void EnergyDown(void);
    void Damage(void);
    void PowerUp(void);
    void CheckState(void);

#if _DEBUG
     void DebugCommand(void);
#endif // _DEBUG

    // �c�@�̃Z�b�^/�Q�b�^
    void SetLife(int nLife) { m_nLife = nLife; }
    int GetLife(void) { return m_nLife; }

    // �v���C���[����ʂɕ\������Ă��邩�̃Z�b�^
    void SetAlive(bool bAlive) { m_bIsDisplayed = bAlive; }

    // �v���C���[��Ԃ̃Z�b�^/�Q�b�^
    void SetPlayerState(STATE PlayerState) { m_State = PlayerState; }
    STATE GetPlayerState(void) { return m_State; }

    // �G�l���M�[�̃Z�b�^/�Q�b�^
    void SetEnergy(int nEnergy) { m_nEnergy = nEnergy; }
    int  GetEnergy(void) { return m_nEnergy; }


    // ���G��Ԃ̃J�E���^
    void SetInvincibleCount(int nInvincibleCount) { m_nInvincibleCount = nInvincibleCount; }
    int GetInvincibleCount( void) {return m_nInvincibleCount; }

    // �p���[�A�b�v�Q�[�W�̃Z�b�^/�Q�b�^
    POWERUP GetPowerUp(void) { return m_powerUp; }
    void SetPowerUp(POWERUP powerUp);

    // �V���b�g�̎�ނ̃Q�b�^
    SHOTTYPE GetShotType(void) { return m_shotType; }

    // �V���b�g�̔��ˊԊu�̃Q�b�^
    int GetInterval(void) { return m_nInterval; }

    // �e�̐��̃Z�b�^/�Q�b�^
    void SetCountBullet(int nCntBullet) { m_nCntBullet = nCntBullet; }
    int GetCountBullet(void) { return m_nCntBullet; }

    // �~�T�C���Z�b�^/�Q�b�^
    void SetCountMissile(int nCountMissile) { m_nCntMissile = nCountMissile; }
    int GetCountMissile(void) { return m_nCntMissile; }

    // �~�T�C�����g�p�ł��邩�̃Z�b�^/ �Q�b�^
    void SetHasMissile(bool bHasMissile) { m_bHasMissile = bHasMissile; }
    int GetHasMissile(void) { return m_bHasMissile; }

    // �I�v�V�������̃Q�b�^
    int GetOptionLv(void) { return m_nOptionLv; }
    COption** GetOption(void) { return m_pOption; }

    // �V�[���h�Z�b�^/�Q�b�^
    void SetShield(bool UsingShield) { m_bUsingShield = UsingShield; }
    bool GetShield(void) { return m_bUsingShield; }

    void SetShieldObjct(CShield* pShild) { m_pShield = pShild ;}
    CShield* GetShieldObjct(void) { return m_pShield; }

private:
    static LPDIRECT3DTEXTURE9 m_pTexture;               // �e�N�X�`���ւ̃|�C���^

    bool                      m_bIsDisplayed;           // ��ʂɕ\������Ă��邩
    int                       m_nLife;                  // �c�@
    CLife                    *m_pLife;                  // �c�@UI�̏��

    STATE                     m_State;            // �v���C���[���
    int                       m_nEnergy;                // �G�l���M�[�̃J�E���g
    CEnergy_UI               *m_pEnergyUI;
    int                       m_nInvincibleCount;       // ���G��Ԃ̃J�E���g
    int                       m_nInterval;              // �V���b�g�����Ă�܂ł̊Ԋu
    SHOTTYPE                  m_shotType;               // ���V���b�g�̃^�C�v
    int                       m_nShotInterval;          // �V���b�g�̔��ˊԊu

    POWERUP                   m_powerUp;                // �p���[�A�b�v�Q�[�W�̏��
    int                       m_nCntBullet;             // �������e�̃J�E���g
    int                       m_nSppedLv;               // �X�s�[�h�̃��x��
    bool                      m_bHasMissile;            // �~�T�C�����g�p�ł��邩
    int                       m_nCntMissile;            // �������~�T�C���̃J�E���g
    int                       m_nIntervalMissile;       // �~�T�C���̔��ˊԊu�J�E���g
    int                       m_nOptionLv;              // �I�v�V�����̃��x��
    COption                  *m_pOption[LIMIT_OPTION];  // �I�v�V�����̃|�C���^
    bool                      m_bUsingShield;           // �V�[���h���g�p���Ă���
    CShield                  *m_pShield;                // �V�[���h�ւ̃|�C���^
};
#endif // !_PLAYER_H_
