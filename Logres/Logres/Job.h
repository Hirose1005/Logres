#pragma once
#include <string>

// ��
enum EJob
{
	PERA,
	HIME,
	KODAI,

	MAX_JOB
};

// �W���u�N���X �W���u�֘A�̃x�[�X�N���X
class Job
{
protected:
	int m_nHit;				// �W���u�A�r���e�B�̃q�b�g��
	int m_nDamageDestroy;	// �_���[�W�f�X�g���C�̏��
	
	std::string m_strName;
public:
	Job(){}
	~Job(){}

	const char* GetJobName() { return m_strName.data(); }
};

// �f�X�y���[�h�̃f�[�^�Ǘ�
class Despe : public Job
{
private:
	int m_nGaugeBlackCritical;		// �u���N�����~�b�g

public:
	Despe();
	~Despe();
};

// ���P�̃f�[�^�Ǘ�
class Kenki : public Job
{
private:
	int m_nMultistageLimit;			// ���i���̃��~�b�g

public:
	Kenki();
	~Kenki();
};

// �Ñ�@�|���̃f�[�^�Ǘ�
class Kodai : public Job
{
private:
	int m_nGaugeMagickStrikeNum;	// �}�W�b�N�X�g���C�N�̑��i��
	int m_nGaugeLimit;				// �}�W�b�N�X�g���C�N�̃��~�b�g
	int m_nGaugeHit;				// �Q�[�W�g�p���̃q�b�g��

public:
	Kodai();
	~Kodai();
};