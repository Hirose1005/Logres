#pragma once
#include <string>

class Equipment
{
private:
	std::string m_strName;
	int m_nDamageDestroy;

public:
	Equipment() {}
	Equipment(std::string name) { m_strName = name; }
	~Equipment() {};
};

class Armor : public Equipment
{
private:

public:

};

class Accessory : public Equipment
{
private:

public:

};

class Weapon : public Equipment
{
private:
	int m_nHit;

public:

};

class FixedLimitWeapon : public Weapon
{
private:
	int m_nFixedLimit;

public:

};

class FinishWeapon : public Weapon
{
private:
	int m_nDamageLimit;

public:

};