#include <cstdio>
#include "Time.h"

using namespace std;

void printTime(Time & time)
{
	char tempString[15];
	time.getTIme(tempString, 15);
	printf(tempString);
}


int main()
{
	Time test,test2,test3("20000631000000");
	test2.setTime(test.getTIme());
	printf("Hello world!\n");
	printTime(test);
	printf("\n");
	printTime(test2);
	printf("\n");
	printTime(test3);
	test3.setHour(12);
	printf("\n");
	printTime(test3);

	getchar();
	return 0;
}