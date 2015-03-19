#include "Data.h"
#include <cstring>


Time & Data::getApprovedDate() 
{
	return oApprovedDate;
}

Time & Data::getRegisteredDate() 
{
	return oRegisteredDate;
}

short Data::getType() const
{
	return sType;
}

short Data::getProperty() const
{
	return sProperty;
}

int Data::getMetadata()const
{
	return iMetadata;
}

const char * Data::getComment() 
{
	return acComment;
}
unsigned long Data::getMoney() const
{
	return lMoney;
}

bool Data::setMoney(const unsigned long lAmount)
{
	if (lAmount < 0)
		return false;
	
	lMoney = lAmount;
	return true;
}


bool Data::setComment(char Commnet[])
{
	if (strlen(Commnet) >SIZE_OF_COMMENTS-1)
		return false;

	strcpy_s(acComment,SIZE_OF_COMMENTS, Commnet);
	return true;
}



bool Data::setProperty(const short sDataProperty)
{
	sProperty = sDataProperty;
	return true;
}

bool Data::setType(const short sDataType)
{

}



Data::Data()
	:oRegisteredDate(time(NULL))
{

}


Data::~Data()
{
}
