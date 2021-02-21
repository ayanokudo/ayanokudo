//=============================================================================
//
// オブジェクト処理 [scene.h]
// Author : AYANO KUDO
//
//=============================================================================
#ifndef _SCENE_H_
#define _SCENE_H_
#include "main.h"

//*****************************************************************************
// クラスの定義
//*****************************************************************************
// オブジェクトクラス
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

    // 描画順
    typedef enum
    {
        PRIORITY_BACKGROUND = 0,       // 後景
        PRIORITY_MIDDLE_VIEW,       // 中景
        PRIORITY_FOREGROUND,        // 前景
        PRIORITY_MAX
    }PRIORITY;

    // メンバ関数
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

    // オブジェクトの種類のセッタ/ゲッタ
    void SetObjtype(OBJTYPE objtype) { m_objtype = objtype; };
    OBJTYPE GetObjectType(void) { return m_objtype; }

    // 描画順のセッタ/ゲッタ
    void SetPriority(PRIORITY priority) { m_Priority = priority; }
    PRIORITY GetPriority(void) { return m_Priority; }

    static CScene*GetTop(int nIndex) { return m_pTop[nIndex]; }// 先頭アドレスのゲッタ
    static CScene*GetCur(int nIndex) { return m_pCur[nIndex]; }// 現在のアドレスのゲッタ
    CScene*GetNext(void) { return m_pNext; }                    // 次のアドレスのゲッタ
    CScene*GetPrev(void) { return m_pPrev; }                    // 前のアドレスのゲッタ

protected:
    // 死亡フラグを立てる
    void SetDeathFlag(void) { m_bDeath = true; }

private:
    static  CScene *m_pCur[PRIORITY_MAX];     // 現在のオブジェクトへのポインタ
    static  CScene *m_pTop[PRIORITY_MAX];     // 先頭のオブジェクトへのポインタ
    CScene  *m_pPrev;                         // 前のオブジェクトへのポインタ
    CScene  *m_pNext;                         // 次のオブジェクトへのポインタ

    OBJTYPE  m_objtype;                       // オブジェクトの種類
    PRIORITY m_Priority;                      // 描画優先順

    bool    m_bDeath;                         // 死亡フラグが立っているか
};

#endif // !_SCENE_H_