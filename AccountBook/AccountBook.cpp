#include <cstdio>
#include "Time.h"
#include "Data.h"

using namespace std;

void printTime(Time & time)
{
	char tempString[15];
	time.getTIme(tempString, 15);
	printf(tempString);
	printf("\n");
}


int main()
{
	Time test,test2,test3("20000631000000");
	Data a;
	test2.setTime(test.getTIme());
	printf("Hello world!\n");
	printTime(a.getApprovedDate());
	printTime(a.getRegisteredDate());
	getchar();
	return 0;
}