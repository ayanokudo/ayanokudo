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
public:
    typedef enum
    {
        OBJTYPE_NONE = 0,
        OBJTYPE_BG,
        OBJTYPE_TERRAIN,
        OBJTYPE_EFFECT,
        OBJTYPE_UI,
        OBJTYPE_ITEM,
        OBJTYPE_STAR,
        OBJTYPE_BULLET,
        OBJTYPE_BOSS,
        OBJTYPE_ENEMY,
        OBJTYPE_OPTION,
        OBJTYPE_SHIELD,
        OBJTYPE_PLAYER,
        OBJTYPE_EXPLOSION,
        OBJTYPW_PAUSE,
        OBJTYPE_FADE,
        OBJTYPE_MAX
    } OBJTYPE;

    // �����o�֐�
    CScene();
    virtual  ~CScene();

    static void UpdateAll(void);
    static void DrawAll(void);
    static void ReleaseAll(void);

    virtual HRESULT Init(void) = 0;
    virtual void    Uninit(void) = 0;
    virtual void    Update(void) = 0;
    virtual void    Draw(void) = 0;

    // �I�u�W�F�N�g�̎�ނ̃Z�b�^/�Q�b�^
    OBJTYPE GetObjectType(void) { return m_objtype; }
    void SetObjtype(OBJTYPE objtype) { m_objtype = objtype; };

    static CScene *GetSceneObject(int nIndex) { return m_apScene[nIndex]; }



protected:
    void Release(void);

private:
    static CScene *m_apScene[MAX_POLYGON];
    static int     m_nNumAll;               // �I�u�W�F�N�g�̐�
    int            m_nIndex;                // �I�u�W�F�N�g�̔ԍ�
    OBJTYPE m_objtype;                      // �I�u�W�F�N�g�̎��
};

#endif // !_SCENE_H_