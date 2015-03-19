#pragma once
#include "Time.h"


class Data
{

public:

	Data();
	~Data();

	bool setMoney(const unsigned long lAmount);
	bool setComment(char Comment[]);
	bool setType(const short sDataType);
	bool setProperty(const short sDataProperty);

	Time & getRegisteredDate() ;
	Time & getApprovedDate();

	const char * getComment() ;
	unsigned long getMoney() const;
	short getType() const;
	short getProperty() const;
	int getMetadata() const;
	
	const static unsigned int SIZE_OF_COMMENTS = 31;

private:



	Time oRegisteredDate;
	Time oApprovedDate;

	char acComment[SIZE_OF_COMMENTS];

	unsigned long lMoney;

	short sType;
	short sProperty;
	int iMetadata;

};

