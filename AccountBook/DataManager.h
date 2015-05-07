#pragma once

#include "Data.h"

class DataManager
{
public:
	DataManager();
	~DataManager();

	//interface
	//#############

private:
	Data* list;
	Data* freeNode;
};

