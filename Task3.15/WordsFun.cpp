/**
 * @file   WordsFun.cpp
 * @brief  implement functions of inputing data and solving task3.15
 * @author Arthur Mytsko
 */
#include "stdafx.h"
#define BUFF_TEXT_SIZE 101
#define BUFF_CHAR_SIZE 2

bool InputData(char *&pcBuffer, UC *&ucLetter)
{
	//allocate memory
	try
	{
		pcBuffer =  (char *)malloc(BUFF_TEXT_SIZE);
		ucLetter = (UC *)malloc(BUFF_CHAR_SIZE);
	}
	catch(std::bad_alloc& baObj)
	{
		printf("Error to allocate memory: %s", baObj.what());
		return false;
	}
	do
	{
		printf("Enter text(accept only the first %u characters):\n", BUFF_TEXT_SIZE - 1);
		fgets(pcBuffer, BUFF_TEXT_SIZE, stdin);
		if(pcBuffer[strlen(pcBuffer) - 1] == 0xa)
		{
			pcBuffer[strlen(pcBuffer) - 1] = 0;
		}
		// clear stdin buffer
		fflush(stdin); 
	}
	while(!*pcBuffer);
	
	do
	{
		printf("\nEnter letter(english): ");
		fgets( (char *)ucLetter, BUFF_CHAR_SIZE, stdin);
		// clear stdin buffer
		fflush(stdin); 
	}
	while( !isalpha( *ucLetter) ); /* check for english letter */

	system("cls");
	return true;
}

void HideWords(char *pcInputStr, US usSize, char cLetter)
{
	// cheking input parameters 
	if(usSize == 0 || !isalpha(cLetter)  || !pcInputStr)
	{
		return;
	}
	
	// changed register of cLetter
	char cInvetrLetter = isupper(cLetter) ? cLetter + 32 : cLetter - 32;

	// start position of current word
	US usPosWord = 0;

	for(register int i = 0; i < usSize; ++i)
	{
		if(!isalpha( (UC)pcInputStr[i]) )
		{
			// cheking for given letter if current word
			if( memchr(pcInputStr + usPosWord, cLetter, i - usPosWord) ||
				memchr(pcInputStr + usPosWord, cInvetrLetter, i - usPosWord) )
			{
				memset(pcInputStr + usPosWord, '*', i - usPosWord);
			}
			usPosWord = i + 1;
		}
	}
}
				