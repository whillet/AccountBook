#pragma once

#include <vector>
#include "SpendingData.h"
#include "RegularSpendingData.h"

class Spending
{
public:
	Spending();
	~Spending();

private:

	vector<SpendingData> instanceSpend;
	vector<RegularSpendingData> regularSpend;

};

