#pragma once

//copyright (c) 2015 woochankim

#include "Time.h"


class Data
{

public:


	//constructure
	Data();
	~Data();

	//interface
	//#####################################################################

	//get Time object
	Time& getDate();

	//get amount of money
	//return moneyValue
	unsigned long getMoneyValue();

	//get categoryCode
	//retutn categoryCode
	unsigned int getCategoryCode();

	//get comment string
	//return comment
	char* getComment();

	//get data id
	//return id;
	unsigned int getId();

	//Set :: if set is success, return true else return false

	//set amount of money
	//moneyValue : amount of money
	bool setMoneyValue(const unsigned long moneyValue);

	//set categoryCode
	//categoryCode : category code
	bool setCategoryCode(const unsigned int categoryCode);

	//set comment
	//commentString : comment
	bool setComment(const char * commentString);

	//#################################################################

	//constants
	const static unsigned int SIZE_OF_COMMENT = 80;

private:
	// dataType
	unsigned int id;
	Time date;
	unsigned long moneyValue;
	unsigned int categoryCode;
	char comment[SIZE_OF_COMMENT];
};