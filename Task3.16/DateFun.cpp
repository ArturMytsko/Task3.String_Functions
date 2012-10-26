/**
 * @file   DateFun.cpp
 * @brief  implement functions of inputing data and solving task3.16
 * @author Arthur Mytsko
 */
#include "stdafx.h"
#include "DateFun.h"
#define BUFF_DATA_SIZE 151

bool InputData(char *&pcBuffer)
{
	//allocate memory
	try
	{
		pcBuffer = (char *)malloc(BUFF_DATA_SIZE);
	}
	catch(std::bad_alloc& baObj)
	{
		printf("Error to allocate memory: %s", baObj.what());
		return false;
	}

	// input data
	do
	{
		printf("Enter dates in fomat dd.mm.yyyy(year must be in range 0-2050; \
split dates by ' ' accept only the first %u characters):\n", BUFF_DATA_SIZE - 1);
		fgets(pcBuffer, BUFF_DATA_SIZE, stdin);
		if(pcBuffer[strlen(pcBuffer) - 1] == 0xa)
		{
			pcBuffer[strlen(pcBuffer) - 1] = 0;
		}
		// clear stdin buffer
		fflush(stdin);
	}
	while(!*pcBuffer);

	return true;
}

bool GetNumberOfDay(char *pcDate, US *pRes)
{
	UL usDay, usMonth, usYear;
	// each 2 bit has a number that need to add to 28 to
	// recive right number of days in each month
	UI DaysPerMonth = 0x00EEF773; 
	
	char cToken[2];

	US usConut = sscanf(pcDate, "%u.%u.%u%1s", &usDay, &usMonth, &usYear, cToken);
	
	if(usConut != 3 )
		return false;

	if(usYear < 0 || usYear > 2050 || usMonth < 0 || usMonth > 12)
	{
		return false;
	}
	// add 1 to Febr. if year is leap
	DaysPerMonth += IsLeapYear(usYear) << 2;
	if(usDay < 0 || usDay > 28 + ( (DaysPerMonth >> (usMonth - 1) * 2) & 0X3) )
	{
		return false;
	}
	// calculate day number
	*pRes = 28 * (usMonth - 1) + usDay;
	for(register int i = 0; i < usMonth - 1; i++)
	{
		*pRes += (DaysPerMonth >> (2 * i) ) & 0x3;
	}
	
	return true;
}

bool IsLeapYear(US usYear)
{
	if(usYear % 400 == 0)
	{
		return true;
	}
	else if(usYear % 100 == 0)
	{
		return false;
	}
	else if (usYear % 4 == 0)
	{
		return true;
	}
	return false;
}