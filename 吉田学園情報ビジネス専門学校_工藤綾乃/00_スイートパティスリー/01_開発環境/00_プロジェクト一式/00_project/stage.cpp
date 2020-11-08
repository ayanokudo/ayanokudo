//=============================================================================
//
// �X�e�[�W�̏��� [stage.cpp]
// Author : AYANO KUDO
//
//=============================================================================
#define _CRT_SECURE_NO_WARNINGS
#include "stage.h"
#include <stdio.h>
#include "item.h"
#include "enemy.h"
#include "star.h"
#include "terrain.h"
#include "enemy_type1.h"
#include "boss.h"

//******************************************************************************
// �ÓI�����o�ϐ�
//******************************************************************************
int CStage::m_nFreme=0;
STAGEDATA CStage::m_pStageData[MAX_POLYGON] = {};

//******************************************************************************
// �}�N����`
//******************************************************************************
#define FILE_NAME "data/TXT/stage001.txt"   // �ǂݍ��ރt�@�C����
#define READ_BUFFER (128)                   // �ǂݍ��ݗp�o�b�t�@

//=============================================================================
// [CStage] �R���X�g���N�^
//=============================================================================
CStage::CStage()
{
    m_nNumber = 0;
    m_nIndex = 0;
}

//=============================================================================
// [~CStage] �f�X�g���N�^
//=============================================================================
CStage::~CStage()
{

}

//=============================================================================
// [ReadFile] �t�@�C���̓ǂݍ���
//=============================================================================
void CStage::ReadFile(void)
{
    FILE *pFile;
    char cRead[READ_BUFFER];	// �����ǂݎ��p
    char cHead[READ_BUFFER];	// ��r�p
    char cDie[READ_BUFFER];		// �s�K�v�ȕ�����ǂݍ���
    m_nNumber = 0;      // �o�^�I�u�W�F�N�g�����Z�b�g

    //�e�L�X�g�t�@�C���ǂݍ���
    pFile = fopen(FILE_NAME, "r");//�t�@�C���I�[�v��

    if (pFile != NULL)//�t�@�C�����J���Ă����Ԃ̎�
    {
        while (strcmp(cHead, "SCRIPT"))// SCRIPT��ǂݍ��ނ܂Ń��[�v
        {
            fgets(cRead, sizeof(cRead), pFile);// �s�P�ʂŕ������ǂݍ���
            sscanf(cRead, "%s", &cHead);// �ǂݍ��񂾃e�L�X�g���r�p�ϐ��ɑ��
        }
        // SCRIPT��ǂݍ��񂾎�
        if (strcmp(cHead, "SCRIPT") == 0)
        {
            while (strcmp(cHead, "END_SCRIPT") != 0)//END_SCRIPT��ǂݍ��ނ܂Ń��[�v
            {
                // ������̓ǂݍ���
                fgets(cRead, sizeof(cRead), pFile);//�ʒu�s�P�ʂŕ������ǂݍ���
                sscanf(cRead, "%s", &cHead);//�ǂݍ��񂾃e�L�X�g���r�p�ϐ��ɑ��

                // �G�̐ݒ�
                if (strcmp(cHead, "OBJSET") == 0)// ENEMYSET��ǂݍ��񂾎�
                {
                    while (strcmp(cHead, "END_OBJSET") != 0)// END_ENEMYSET��ǂݍ��ނ܂Ń��[�v
                    {
                        fgets(cRead, sizeof(cRead), pFile); // 1�s�P�ʂŕ������ǂݍ���
                        sscanf(cRead, "%s", &cHead);        // �ǂݍ��񂾃e�L�X�g���r�p�ϐ��ɑ��

                        // �o���^�C�~���O�̐ݒ�
                        if (strcmp(cHead, "FRAME") == 0)//�G�̔����t���[����ǂݍ��񂾎�
                        {
                            sscanf(cRead, "%s %d", &cDie, &m_pStageData[m_nNumber].nFlame);//�����t���[�����i�[
                        }

                        // �ʒu�̐ݒ�
                        if (strcmp(cHead, "POS") == 0)
                        {
                            sscanf(cRead, "%s %f %f %f", &cDie, &m_pStageData[m_nNumber].pos.x, &m_pStageData[m_nNumber].pos.y, &m_pStageData[m_nNumber].pos.z);//�ʒu���i�[
                        }

                        // ��ނ̐ݒ�
                        if (strcmp(cHead, "TYPE") == 0)
                        {
                            sscanf(cRead, "%s %d", &cDie, &m_pStageData[m_nNumber].type);//�I�u�W�F�N�g�̎�ނ��i�[
                        }
                        // ���E�\�N�̌������m�F
                        if (strcmp(cHead, "FLIP") == 0)
                        {
                            sscanf(cRead, "%s %d", &cDie, &m_pStageData[m_nNumber].nFlip);//�I�u�W�F�N�g�̎�ނ��i�[
                        }
                        // �ґ��̐��̐ݒ�
                        if (strcmp(cHead, "FORMAITION") == 0)
                        {
                            sscanf(cRead, "%s %d", &cDie, &m_pStageData[m_nNumber].Formaition);//�I�u�W�F�N�g�̎�ނ��i�[
                        }
                        // �O���̏�񂪂���ꍇ�O���̏���ǂݍ���
                        if (strcmp(cHead, "ORBITSET") == 0)
                        {
                                int nCntObit = 0;// �O���̏��J�E���g
                            while (strcmp(cHead, "END_ORBITSET") != 0)
                            {
                                fgets(cRead, sizeof(cRead), pFile); // 1�s�P�ʂŕ������ǂݍ���
                                sscanf(cRead, "%s", &cHead);        // �ǂݍ��񂾃e�L�X�g���r�p�ϐ��ɑ��
                                if (strcmp(cHead, "OBIT") == 0)// �O�����
                                {
                                    sscanf(cRead, "%s %f %f %f", &cDie, &m_pStageData[m_nNumber].orbit[nCntObit].x, &m_pStageData[m_nNumber].orbit[nCntObit].y, &m_pStageData[m_nNumber].orbit[nCntObit].z );
                                    nCntObit++;
                                }
                            }
                        }

                    }
                    m_nNumber++;
                }
            }
        }
        fclose(pFile);//�t�@�C�������
    }
}

//=============================================================================
// [Init] ����������
//=============================================================================
void CStage::Init(void)
{
    // �e�����o�ϐ�������
    m_nNumber = 0;
    m_nIndex = 0;
    m_nFreme = 0;
    m_nFormaition = 1;
    ReadFile();
}

//=============================================================================
// [Update] �X�V����
//=============================================================================
void CStage::Update(void)
{
    CEnemyType1 *pEnemy = NULL;
    m_nFreme++;//�J�E���^�̍X�V
    if (m_nFreme == m_pStageData[m_nIndex].nFlame)//�J�E���^���G�̔����t���[���ɂȂ�����
    {
        switch (m_pStageData[m_nIndex].type)
        {
            // �A�C�e�����o��������
        case CScene::OBJTYPE_ITEM:
            // �G�l���M�[�񕜃A�C�e������
            CItem::Create(m_pStageData[m_nIndex].pos, D3DXVECTOR3(-2.0f, 0.0f, 0.0f),CItem::TYPE_001, m_pStageData[m_nIndex].nFlip);
            break;

            // �{�X���o��������
        case CScene::OBJTYPE_BOSS:
            CBoss::Create(m_pStageData[m_nIndex].pos);
            break;

            // �G���o��������
        case CScene::OBJTYPE_ENEMY:
            for (int nCntEnemy = 0; nCntEnemy < m_pStageData[m_nIndex].Formaition; nCntEnemy++)
            {
                pEnemy = CEnemyType1::Create(m_pStageData[m_nIndex].pos, m_nFormaition, nCntEnemy);
                pEnemy->SetOrbit(m_pStageData[m_nIndex].orbit);
            }
            m_nFormaition++;
            break;

            // �����o��������
        case CScene::OBJTYPE_STAR:
            CStar::Create(m_pStageData[m_nIndex].pos,D3DXVECTOR3(-1.0f,0.0f,0.0f));
            break;

            // �n�`���o��������
        case CScene::OBJTYPE_TERRAIN:
            for (int nCntTerrain = 0; nCntTerrain < m_pStageData[m_nIndex].Formaition; nCntTerrain++)
            {
                CTerrain::Create(D3DXVECTOR3(m_pStageData[m_nIndex].pos.x + (nCntTerrain*TERRAIN_SIZE_X), m_pStageData[m_nIndex].pos.y, 0.0));
            }
            break;
        }

        m_nIndex++;
        m_nFreme = 0;//�J�E���^���Z�b�g
    }
}
