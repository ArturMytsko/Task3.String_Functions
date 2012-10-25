/**
 * @file   WordsFun.h
 * @brief  Contains declaration functions which solve the task3.15
 * @author Arthur Mytsko
 */ 
#ifndef _WORDS_FUN_H_
#define _WORDS_FUN_H_

#include "stdafx.h"

 /**
   * @brief           Implement allocation memory and valid inputing data
   * @param	[in, out] pcBuffer - pointer to memory with future text
   * @param	[in, out] cLetter - pointer to mem with future inputing letter
   * @return	      true, is function ended normal
   */
bool InputData(char *&pcBuffer, UC *&cLetter); 

 /**
   * @brief           Implement 'hiding' words with given letter
   * @param	[in, out] pcInputStr - pointer to given text
   * @param	[in]      usSize - size of text
   * @param	[in, out] cLetter - pointer to given letter
   * @return	      void
   */
void HideWords(char *pcInputStr, US usSize, char cLetter);

#endif /* _WORDS_FUN_H_ */