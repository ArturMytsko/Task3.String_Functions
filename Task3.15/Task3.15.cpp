/**
 * @file   Task3.15.cpp
 * @brief  Implement main function
 * @author Arthur Mytsko
 */
#include "stdafx.h"
#include "WordsFun.h"

 /**
   * @brief      Main function
   * @return	 0
   */
int _tmain(int argc, _TCHAR* argv[])
{
	char *pcInputBuffer; //text
	UC *ucChar;			 //letter

	if(!InputData(pcInputBuffer, ucChar) )
	{
		printf("\nError has been occurred");
		_getch();
		return 0;
	}
	printf("text: \n%s\nHide words with letter: %c\n",
			pcInputBuffer, ucChar[0]);

	HideWords(pcInputBuffer, strlen(pcInputBuffer), ucChar[0]);
	printf("--------------result--------------------\n%s", pcInputBuffer);

	delete[] pcInputBuffer;
	delete[] ucChar;
	_getch();
	return 0;
}

