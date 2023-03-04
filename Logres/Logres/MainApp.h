#pragma once
#include "Job.h"
#include <memory>
#include <vector>

// íËêî
#define CB_SELECT (525293)


class Logres
{
private:
	std::vector <std::shared_ptr<Job>> m_pJobs;

public:
	Logres();
	~Logres();

	int GetJobNum() { return m_pJobs.size(); }
	std::shared_ptr<Job> GetJob(int index) { return m_pJobs[index]; }
};