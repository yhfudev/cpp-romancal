/**
 * @file    romancal.h
 * @brief   Roman number Calculator
 * @author  Yunhui Fu (yhfudev@gmail.com)
 * @version 1.0
 * @date    2017-01-26
 * @copyright GNU Lesser General Public License v2.0.
 */
#ifndef _ROMANCAL_H
#define _ROMANCAL_H

#include <stddef.h> // size_t

#define PAIRS() \
    PAIR(   1,  "I") \
    PAIR(   4, "IV") \
    PAIR(   5,  "V") \
    PAIR(   9, "IX") \
    PAIR(  10,  "X") \
    PAIR(  40, "XL") \
    PAIR(  50,  "L") \
    PAIR(  90, "XC") \
    PAIR( 100,  "C") \
    PAIR( 400, "CD") \
    PAIR( 500,  "D") \
    PAIR( 900, "CM") \
    PAIR(1000,  "M") \

#define NUM_ARRAY(a) (sizeof(a)/sizeof(a[0]))

#if DEBUG
#include <stdio.h> // stderr
#define TRACE(fmt, ...) fprintf (stderr, "[%s()]" fmt " {ln:%d}\n", __func__, ##__VA_ARGS__, __LINE__)
#else
#define TRACE(...)
#endif

extern unsigned long roman2value(const char * romanstr);

extern int value2roman(unsigned long value, char * romanstr, size_t maxlen);

int roman_add (const char * roman1, const char * roman2, char * roman_ret, size_t maxlen);
int roman_sub (const char * roman1, const char * roman2, char * roman_ret, size_t maxlen);
int roman_mul (const char * roman1, const char * roman2, char * roman_ret, size_t maxlen);

#endif // _ROMANCAL_H

