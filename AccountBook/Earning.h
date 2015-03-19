#pragma once

#include <vector>
#include "EarningData.h"
#include "RegularEarningData.h"

class Earning
{
public:
	Earning();
	~Earning();

private:

	vector<EarningData> instanceEarning;
	vector <RegularEarningData> regularEarning;

};

