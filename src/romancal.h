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

#define NUM_ARRAY(a) (sizeof(a)/sizeof(a[0]))

#if DEBUG
#include <stdio.h> // stderr
#define TRACE(fmt, ...) fprintf (stderr, "[%s()]" fmt " {ln:%d}\n", __func__, ##__VA_ARGS__, __LINE__)
#else
#define TRACE(...)
#endif

extern int value2roman(unsigned long value, char * romanstr, size_t maxlen);

#endif // _ROMANCAL_H

