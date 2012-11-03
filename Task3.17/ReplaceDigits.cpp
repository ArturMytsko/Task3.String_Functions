/**
 * @file   ReplaceDigits.cpp
 * @brief  implement functions of inputing data and solving task3.17
 * @author Arthur Mytsko
 */
#include "stdafx.h"
#include "ReplaceDigits.h"
#define MAX_BUF_LEN 151

UC InputData(long *&plInputArray)
{
	char *pcBuffer;
	char *pcToken;
	long lTempScanf;
	char cTempScanf[20];
	//allocate memory
	try
	{
		pcBuffer = (char *)malloc(MAX_BUF_LEN);
	}
	catch(std::bad_alloc& baObj)
	{
		printf("Error to allocate memory: %s", baObj.what());
		return false;
	}
ENTER_NUMBERS:
	do
	{
		printf("\nEnetr long numbers, separated by ' ':\n\
	(max size of line is %d characterss)\n", MAX_BUF_LEN - 1);

		fgets(pcBuffer, MAX_BUF_LEN, stdin);
		if(pcBuffer[strlen(pcBuffer) - 1] == 0xa)
		{
			pcBuffer[strlen(pcBuffer) - 1] = 0;
		}
		fflush(stdin);
	}
	while(!*pcBuffer);

	// calculate numbers of items
	UC ucNumberCnt = 0;
	pcToken = strtok (pcBuffer," ");
	while (pcToken != NULL)
	{
		int iCount = sscanf(pcToken, "%d%1s", &lTempScanf, cTempScanf);
		if(iCount != 1)
		{
			printf("\nBad numbers \n");
			goto ENTER_NUMBERS;
		}
		++ucNumberCnt;
		*(pcToken + strlen(pcToken)) = ' ';
		pcToken = strtok (NULL, " ");
	}

	if(!ucNumberCnt)
	{
		printf("\nBad numbers \n");
		goto ENTER_NUMBERS;
	}

	//allocate memory
	try
	{
		plInputArray = (long *)malloc(ucNumberCnt);
	}
	catch(std::bad_alloc& baObj)
	{
		printf("Error to allocate memory: %s", baObj.what());
		return false;
	}

	register int i = 0;
	pcToken = strtok (pcBuffer," ");
	while (pcToken != NULL)
	{

		plInputArray[i++] = atol(pcToken);
		pcToken = strtok (NULL, " ");
	}
	
	return ucNumberCnt;
}

bool ReplaceDigit(long *lNumber)
{
	UC ucDigitCount = 1 + log10(abs( (double)*lNumber) );
	long lReversNumber = 0;

	for (register int i = 0; i < ucDigitCount; ++i)
	{
		lReversNumber += (long)(*lNumber % 10 * pow(10.0, ucDigitCount - i - 1) ); 
		*lNumber /= 10;
	}
	*lNumber = lReversNumber;
	return true;
}

void PrintResults(long *plInputData, UC ucCount)
{
	register int i = 0;

	system("cls");
	printf("Given data:\n");

	for(i = 0; i < ucCount; ++i)
	{
		printf("%d ", plInputData[i]);
	}

	printf("\nResult of replacement digits:\n");
	for(i = 0; i < ucCount; ++i)
	{
		if(ReplaceDigit(plInputData + i) )
		{
			printf("%d ", plInputData[i]);
		}
		else
		{
			printf("n\Error to replace digits");
			return;
		}
	}
}
