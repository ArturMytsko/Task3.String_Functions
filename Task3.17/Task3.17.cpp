/**
 * @file   Task3.17.cpp
 * @brief  Implement main function
 * @author Arthur Mytsko
 */
#include "stdafx.h"
#include "ReplaceDigits.h"

 /**
   * @brief      Main function
   * @return	 0
   */
int _tmain(int argc, _TCHAR* argv[])
{
	long *plInputVector;
	UC ucItemConut = 0;
	
	ucItemConut = InputData(plInputVector);

	PrintResults(plInputVector, ucItemConut);

	_getch();
	return 0;
}

