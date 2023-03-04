#pragma once
#include <string>

// 列挙
enum EJob
{
	PERA,
	HIME,
	KODAI,

	MAX_JOB
};

// ジョブクラス ジョブ関連のベースクラス
class Job
{
protected:
	int m_nHit;				// ジョブアビリティのヒット数
	int m_nDamageDestroy;	// ダメージデストロイの上限
	
	std::string m_strName;
public:
	Job(){}
	~Job(){}

	const char* GetJobName() { return m_strName.data(); }
};

// デスペラードのデータ管理
class Despe : public Job
{
private:
	int m_nGaugeBlackCritical;		// ブラクリリミット

public:
	Despe();
	~Despe();
};

// 剣姫のデータ管理
class Kenki : public Job
{
private:
	int m_nMultistageLimit;			// 多段数のリミット

public:
	Kenki();
	~Kenki();
};

// 古代機鋼兵のデータ管理
class Kodai : public Job
{
private:
	int m_nGaugeMagickStrikeNum;	// マジックストライクの多段数
	int m_nGaugeLimit;				// マジックストライクのリミット
	int m_nGaugeHit;				// ゲージ使用時のヒット数

public:
	Kodai();
	~Kodai();
};