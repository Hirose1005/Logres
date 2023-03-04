#include "Job.h"
#include <string.h>

Despe::Despe()
{
	m_nHit = 1;
	m_nDamageDestroy = (130000 - 1);
	m_strName = "デスペラード";
}

Despe::~Despe()
{
	
}

Kenki::Kenki()
{
	m_nHit = 2;
	m_nDamageDestroy = (130000 - 1);
	m_strName = "剣姫";
}

Kenki::~Kenki()
{

}


Kodai::Kodai()
{
	m_nHit = 2;
	m_nDamageDestroy = (130000 - 1);
	m_nGaugeHit = 3;
	m_strName = "古代機鋼兵";
}

Kodai::~Kodai()
{

}
