/**
 * @file   DateFun.h
 * @brief  Contains declaration functions which solve the task3.16
 * @author Arthur Mytsko
 */ 
#ifndef _WORDS_FUN_H_
#define _WORDS_FUN_H_

#include "stdafx.h"

 /**
   * @brief           Implement allocation memory and valid inputing data
   * @param	[in, out] pcBuffer - pointer to memory with dates
   * @return	      true, is function ended normal
   */
bool InputData(char *&pcBuffer); 

 /**
   * @brief           Checking valid Date and gerint day number
   * @param	[in]      pcDate - pointer to memory with dates
   * @param	[in, out] pRes - pointer DayNumber variable 
   * @return	      true, is date is correct
   */
bool GetNumberOfDay(char *pcDate, US *pRes);

 /**
   * @brief           Checking for leaping year
   * @param	[in]      usYear - year to check
   * @return	      true, if the year is leap
   */
bool IsLeapYear(US usYear);


#endif /* _WORDS_FUN_H_ */