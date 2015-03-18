#include "Data.h"
#include <cstring>

Time Data::getApprovedDate() const
{
	return oApprovedDate;
}

Time Data::getRegisteredDate() const
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

bool Data::setMoney(unsigned long lAmount)
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




Data::Data()
{

}


Data::~Data()
{
}
