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

//////////////////////////////////////////////////
// DEBUG

#if DEBUG
#include <stdio.h> // stderr
#define TRACE(fmt, ...) fprintf (stderr, "[%s()] " fmt " {ln:%d}\n", __func__, ##__VA_ARGS__, __LINE__)
#else
#define TRACE(...)
#endif

//////////////////////////////////////////////////
#define NUM_ARRAY(a) (sizeof(a)/sizeof(a[0]))

#define ROMANPAIRS_BASE() \
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

// see http://www.tuomas.salste.net/doc/roman/numeri-romani.html
// or https://en.wikipedia.org/wiki/Roman_numerals
#define ROMANPAIRS_SEQ() \
    PAIR(   0,         "") \
    PAIR(   1,        "I") \
    PAIR(   2,       "II") \
    PAIR(   3,      "III") \
    PAIR(   4,       "IV") \
    PAIR(   5,        "V") \
    PAIR(   6,       "VI") \
    PAIR(   7,      "VII") \
    PAIR(   8,     "VIII") \
    PAIR(   9,       "IX") \
    PAIR(  10,        "X") \
    PAIR(  11,       "XI") \
    PAIR(  12,      "XII") \
    PAIR(  13,     "XIII") \
    PAIR(  14,      "XIV") \
    PAIR(  15,       "XV") \
    PAIR(  16,      "XVI") \
    PAIR(  17,     "XVII") \
    PAIR(  18,    "XVIII") \
    PAIR(  19,      "XIX") \
    PAIR(  20,       "XX") \
    PAIR(  21,      "XXI") \
    PAIR(  22,     "XXII") \
    PAIR(  23,    "XXIII") \
    PAIR(  24,     "XXIV") \
    PAIR(  25,      "XXV") \
    PAIR(  26,     "XXVI") \
    PAIR(  27,    "XXVII") \
    PAIR(  28,   "XXVIII") \
    PAIR(  29,     "XXIX") \
    PAIR(  30,      "XXX") \
    PAIR(  31,     "XXXI") \
    PAIR(  32,    "XXXII") \
    PAIR(  33,   "XXXIII") \
    PAIR(  34,    "XXXIV") \
    PAIR(  35,     "XXXV") \
    PAIR(  36,    "XXXVI") \
    PAIR(  37,   "XXXVII") \
    PAIR(  38,  "XXXVIII") \
    PAIR(  39,    "XXXIX") \
    PAIR(  40,       "XL") \
    PAIR(  41,      "XLI") \
    PAIR(  42,     "XLII") \
    PAIR(  43,    "XLIII") \
    PAIR(  44,     "XLIV") \
    PAIR(  45,      "XLV") \
    PAIR(  46,     "XLVI") \
    PAIR(  47,    "XLVII") \
    PAIR(  48,   "XLVIII") \
    PAIR(  49,     "XLIX") \
    PAIR(  50,        "L") \
    PAIR(  51,       "LI") \
    PAIR(  52,      "LII") \
    PAIR(  53,     "LIII") \
    PAIR(  54,      "LIV") \
    PAIR(  55,       "LV") \
    PAIR(  56,      "LVI") \
    PAIR(  57,     "LVII") \
    PAIR(  58,    "LVIII") \
    PAIR(  59,      "LIX") \
    PAIR(  60,       "LX") \
    PAIR(  61,      "LXI") \
    PAIR(  62,     "LXII") \
    PAIR(  63,    "LXIII") \
    PAIR(  64,     "LXIV") \
    PAIR(  65,      "LXV") \
    PAIR(  66,     "LXVI") \
    PAIR(  67,    "LXVII") \
    PAIR(  68,   "LXVIII") \
    PAIR(  69,     "LXIX") \
    PAIR(  70,      "LXX") \
    PAIR(  71,     "LXXI") \
    PAIR(  72,    "LXXII") \
    PAIR(  73,   "LXXIII") \
    PAIR(  74,    "LXXIV") \
    PAIR(  75,     "LXXV") \
    PAIR(  76,    "LXXVI") \
    PAIR(  77,   "LXXVII") \
    PAIR(  78,  "LXXVIII") \
    PAIR(  79,    "LXXIX") \
    PAIR(  80,     "LXXX") \
    PAIR(  81,    "LXXXI") \
    PAIR(  82,   "LXXXII") \
    PAIR(  83,  "LXXXIII") \
    PAIR(  84,   "LXXXIV") \
    PAIR(  85,    "LXXXV") \
    PAIR(  86,   "LXXXVI") \
    PAIR(  87,  "LXXXVII") \
    PAIR(  88, "LXXXVIII") \
    PAIR(  89,   "LXXXIX") \
    PAIR(  90,       "XC") \
    PAIR(  91,      "XCI") \
    PAIR(  92,     "XCII") \
    PAIR(  93,    "XCIII") \
    PAIR(  94,     "XCIV") \
    PAIR(  95,      "XCV") \
    PAIR(  96,     "XCVI") \
    PAIR(  97,    "XCVII") \
    PAIR(  98,   "XCVIII") \
    PAIR(  99,     "XCIX") \
    PAIR( 100,        "C") \
    PAIR( 101,       "CI") \
    PAIR( 102,      "CII") \
    PAIR( 103,     "CIII") \
    PAIR( 104,      "CIV") \
    PAIR( 105,       "CV") \
    PAIR( 106,      "CVI") \
    PAIR( 107,     "CVII") \
    PAIR( 108,    "CVIII") \
    PAIR( 109,      "CIX") \
    PAIR( 110,       "CX") \
    PAIR( 111,      "CXI") \
    PAIR( 112,     "CXII") \
    PAIR( 113,    "CXIII") \
    PAIR( 114,     "CXIV") \
    PAIR( 115,      "CXV") \
    PAIR( 116,     "CXVI") \
    PAIR( 117,    "CXVII") \
    PAIR( 118,   "CXVIII") \
    PAIR( 119,     "CXIX") \
    PAIR( 120,      "CXX") \
    PAIR( 125,     "CXXV") \
    PAIR( 150,       "CL") \
    PAIR( 200,       "CC") \
    PAIR( 212,    "CCXII") \
    PAIR( 250,      "CCL") \
    PAIR( 300,      "CCC") \
    PAIR( 353,  "CCCLIII") \
    PAIR( 400,       "CD") \
    PAIR( 404,     "CDIV") \
    PAIR( 500,        "D") \
    PAIR( 501,       "DI") \
    PAIR( 530,     "DXXX") \
    PAIR( 555,      "DLV") \
    PAIR( 600,       "DC") \
    PAIR( 700,      "DCC") \
    PAIR( 707,   "DCCVII") \
    PAIR( 800,     "DCCC") \
    PAIR( 890,   "DCCCXC") \
    PAIR( 846, "DCCCXLVI") \
    PAIR( 900,       "CM") \
    PAIR( 927,  "CMXXVII") \
    PAIR(1000,        "M") \
    PAIR(1008,    "MVIII") \
    PAIR(1400,      "MCD") \
    PAIR(1500,       "MD") \
    PAIR(1600,      "MDC") \
    PAIR(1700,     "MDCC") \
    PAIR(1800,    "MDCCC") \
    PAIR(1900,      "MCM") \
    PAIR(1910,     "MCMX") \
    PAIR(1984, "MCMLXXXIV") \
    PAIR(1999,  "MCMXCIX") \
    PAIR(2000,       "MM") \
    PAIR(2001,      "MMI") \
    PAIR(2002,     "MMII") \
    PAIR(2003,    "MMIII") \
    PAIR(2004,     "MMIV") \
    PAIR(2005,      "MMV") \
    PAIR(2006,     "MMVI") \
    PAIR(2007,    "MMVII") \
    PAIR(2008,   "MMVIII") \
    PAIR(2009,     "MMIX") \
    PAIR(2010,      "MMX") \
    PAIR(2011,     "MMXI") \
    PAIR(2012,    "MMXII") \
    PAIR(2013,   "MMXIII") \
    PAIR(2014,    "MMXIV") \
    PAIR(2015,     "MMXV") \
    PAIR(2016,    "MMXVI") \
    PAIR(2017,   "MMXVII") \
    PAIR(2018,  "MMXVIII") \
    PAIR(2019,    "MMXIX") \
    PAIR(2020,     "MMXX") \
    PAIR(2021,    "MMXXI") \
    PAIR(2022,   "MMXXII") \
    PAIR(2023,  "MMXXIII") \
    PAIR(2024,   "MMXXIV") \
    PAIR(2420,   "MMCDXX") \
    PAIR(3000,      "MMM") \
    PAIR(3999,"MMMCMXCIX") \
    //PAIR(4000,     "MMMM") \

#ifdef  __cplusplus
extern "C" {
#endif

extern int roman2value(const char * romanstr, unsigned long * value);
extern int value2roman(unsigned long value, char * romanstr, size_t maxlen);

extern int roman_add (const char * roman1, const char * roman2, char * roman_ret, size_t maxlen);
extern int roman_sub (const char * roman1, const char * roman2, char * roman_ret, size_t maxlen);

#ifdef  __cplusplus
}
#endif
#endif // _ROMANCAL_H

