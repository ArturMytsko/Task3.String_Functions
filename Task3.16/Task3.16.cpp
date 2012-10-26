/**
 * @file   Task3.16.cpp
 * @brief  Implement main function
 * @author Arthur Mytsko
 */
#include "stdafx.h"
#include "DateFun.h"

 /**
   * @brief      Main function
   * @return	 0
   */
int _tmain(int argc, _TCHAR* argv[])
{
	char *pDates;
	US usDayNumber;
	
	if (!InputData(pDates) )
	{
		getch();
		return 0;
	}
	 // get first date ( ' ' - splitter)
	char *pOneDate = strtok(pDates, " ");
	while(pOneDate != NULL)
	{
	
		if(GetNumberOfDay(pOneDate, &usDayNumber) )
		{
			printf("%-17s - day number %d\n", pOneDate, usDayNumber);
		}
		else
		{
			printf("%-17s - wrong date\n", pOneDate);
		}
		// get next date
		pOneDate = strtok (NULL, " ");
	}

	delete[] pDates;
	_getch();
	return 0;
}

