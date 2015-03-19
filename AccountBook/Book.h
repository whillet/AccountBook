#pragma once

#include"Earning.h"
#include"Spending.h"

class Book
{
public:
	Book();
	~Book();
private:
	Earning earnData;
	Spending spendData;
};

