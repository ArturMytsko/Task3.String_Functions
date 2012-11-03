/**
 * @file   ReplaceDigits.h
 * @brief  Contains declaration functions which solve the task3.16
 * @author Arthur Mytsko
 */ 
#ifndef _REPLACE_DIGITS_H
#define _REPLACE_DIGITS_H

#include "stdafx.h"

 /**
   * @brief           Implement allocation memory and valid inputing data
   * @param	[in, out] pcBuffer - pointer to memory with dates
   * @return	      true, is function ended normal
   */
UC InputData(long *&plInputArray);

 /**
   * @brief           Checking valid Date and gerint day number
   * @param	[in]      pcDate - pointer to memory with dates
   * @param	[in, out] pRes - pointer DayNumber variable 
   * @return	      true, is date is correct
   */
bool ReplaceDigit(long *lNumber);

 /**
   * @brief           Print given data and results
   * @param	[in]      plInputData - pointer to given vector og longs numbers
   * @param	[in]      ucConut - number of items
   * @return	      void   
   */
void PrintResults(long *plInputData, UC ucCount);

#endif /* _REPLACE_DIGITS_H */