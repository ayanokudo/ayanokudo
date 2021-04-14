//=============================================================================
//
// �I�u�W�F�N�g���� [scene.h]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef _SCENE_H_
#define _SCENE_H_
#include "main.h"

//*****************************************************************************
// �N���X�̒�`
//*****************************************************************************
// �I�u�W�F�N�g�N���X
class  CScene
{
    // �I�u�W�F�N�g�̃^�C�v
public:
    typedef enum
    {
        OBJTYPE_NONE = 0,   // ����
        OBJTYPE_BG,         // �w�i
        OBJTYPE_TERRAIN,    // �n�`
        OBJTYPE_EFFECT,     // �G�t�F�N�g
        OBJTYPE_UI,         // UI
        OBJTYPE_ITEM,       // �A�C�e��
        OBJTYPE_STAR,       // ��
        OBJTYPE_BULLET,     // �e
        OBJTYPE_BOSS,       // �{�X
        OBJTYPE_ENEMY,      // �G
        OBJTYPE_OPTION,     // �I�v�V����
        OBJTYPE_SHIELD,     // �V�[���h
        OBJTYPE_PLAYER,     // �v���C���[
        OBJTYPE_EXPLOSION,  // ����
        OBJTYPW_PAUSE,      // �|�[�Y
        OBJTYPE_FADE,       // �t�F�[�h
        OBJTYPE_MAX         // ��ނ̐�
    } OBJTYPE;

    // �`�揇
    typedef enum
    {
        PRIORITY_BACKGROUND = 0,    // ��i
        PRIORITY_MIDDLE_VIEW,       // ���i
        PRIORITY_FOREGROUND,        // �O�i
        PRIORITY_MAX
    }PRIORITY;

    // �����o�֐�
    CScene(PRIORITY priority = PRIORITY_MIDDLE_VIEW);
    virtual  ~CScene();

    static void UpdateAll(void);
    static void DrawAll(void);
    static void ReleaseAll(void);

    virtual HRESULT Init(void) = 0;
    virtual void    Uninit() = 0;
    virtual void    Update(void) = 0;
    virtual void    Draw(void) = 0;

    void ReconnectList(void);

    // �I�u�W�F�N�g�̎�ނ̃Z�b�^/�Q�b�^
    void SetObjtype(OBJTYPE objtype) { m_objtype = objtype; };
    OBJTYPE GetObjectType(void) { return m_objtype; }

    // �`�揇�̃Z�b�^/�Q�b�^
    void SetPriority(PRIORITY priority) { m_Priority = priority; }
    PRIORITY GetPriority(void) { return m_Priority; }

    static CScene*GetTop(int nIndex) { return m_pTop[nIndex]; } // �擪�A�h���X�̃Q�b�^
    static CScene*GetCur(int nIndex) { return m_pCur[nIndex]; } // ���݂̃A�h���X�̃Q�b�^
    CScene*GetNext(void) { return m_pNext; }                    // ���̃A�h���X�̃Q�b�^
    CScene*GetPrev(void) { return m_pPrev; }                    // �O�̃A�h���X�̃Q�b�^

protected:
    // ���S�t���O�𗧂Ă�
    void SetDeathFlag(void) { m_bDeath = true; }

private:
    static  CScene *m_pCur[PRIORITY_MAX];     // ���݂̃I�u�W�F�N�g�ւ̃|�C���^
    static  CScene *m_pTop[PRIORITY_MAX];     // �擪�̃I�u�W�F�N�g�ւ̃|�C���^
    CScene  *m_pPrev;                         // �O�̃I�u�W�F�N�g�ւ̃|�C���^
    CScene  *m_pNext;                         // ���̃I�u�W�F�N�g�ւ̃|�C���^

    OBJTYPE  m_objtype;                       // �I�u�W�F�N�g�̎��
    PRIORITY m_Priority;                      // �`��D�揇

    bool    m_bDeath;                         // ���S�t���O�������Ă��邩
};

#endif // !_SCENE_H_