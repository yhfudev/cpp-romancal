/**
 * @file    testromancal.c
 * @brief   Test Roman number Calculator
 * @author  Yunhui Fu (yhfudev@gmail.com)
 * @version 1.0
 * @date    2017-01-26
 * @copyright GNU Lesser General Public License v2.0.
 */

#include <stdlib.h>

#if defined (_WIN)
// for test psapi
#include <windows.h>
#include <psapi.h>
#endif // _WIN

#include "testutils.h"
#include "romancal.h"

void
ut_roman2value_basic(void)
{
    unsigned long retval;
#define PAIR(val,str) CI_ASSERT(0 == roman2value(str, &retval)); CI_ASSERT(val == retval);
    PAIR(0, "");
    ROMANPAIRS_BASE();
    PAIR(1910, "MDCCCCX"); // or MCMX
    ROMANPAIRS_SEQ();
#undef PAIR
}

void
ut_roman2value_overflow(void)
{
    unsigned long retval;
    CI_ASSERT(-1 == roman2value(NULL, &retval));
    CI_ASSERT(-1 == roman2value("", NULL));
    CI_ASSERT(-3 == roman2value("MMMM", &retval));
}

void
ut_value2roman_basic(void)
{
    char buf[10];
#define PAIR(val,str) value2roman(val, buf, sizeof(buf)); CI_ASSERT(0 == strcmp(buf, str));
    memset(buf, 1, sizeof(buf));
    PAIR(0, "");
    memset(buf, 1, sizeof(buf));
    PAIR(4000,     "");
    memset(buf, 1, sizeof(buf));
    ROMANPAIRS_BASE();
    memset(buf, 1, sizeof(buf));
    ROMANPAIRS_SEQ();
    memset(buf, 1, sizeof(buf));
    PAIR(351, "CCCLI");
    memset(buf, 1, sizeof(buf));
    PAIR(453, "CDLIII");
#undef PAIR
}

/* test buffer overflow */
void
ut_value2roman_overflow(void)
{
    char buf[10];
    memset(buf, 1, sizeof(buf));
#define PAIR(val,str) value2roman(val, buf, 6); CI_ASSERT(0 == strcmp(buf, str));
    PAIR(351, "CCCLI");
    PAIR(453, "");
#undef PAIR
    CI_ASSERT(-1 == value2roman(351, NULL, sizeof(buf)));
    CI_ASSERT(-1 == value2roman(351, NULL, 0));
    CI_ASSERT(-2 == value2roman(351, buf, 0));
    CI_ASSERT(-2 == value2roman(351, buf, 1));
    CI_ASSERT(-2 == value2roman(351, buf, 2));
    CI_ASSERT(-2 == value2roman(351, buf, 3));
    CI_ASSERT(-2 == value2roman(351, buf, 4));
    CI_ASSERT(-2 == value2roman(351, buf, 5));
    CI_ASSERT( 0 == value2roman(351, buf, 6));
}

void
ut_romadd_basic(void)
{
    char buf[10];
    memset(buf, 0, sizeof(buf));
#define ROP_ADD(r1, r2, rr) roman_add ( r1, r2, buf, sizeof(buf)); CI_ASSERT(0 == strcmp(buf, rr));
    ROP_ADD ( "V", "I", "VI");
    ROP_ADD ( "X", "V", "XV");
    ROP_ADD ( "XIV", "LX", "LXXIV");
    ROP_ADD ( "XX", "II", "XXII");
}

#define BUF_MAX 20
void
ut_romadd_multi1(void)
{
#define CHK_VAL(p, val) CI_ASSERT (0 == roman2value((p), &retval)); CI_ASSERT (retval == (val));
    unsigned long retval;
    char *tmp;
    char *p1;
    char *p2;
    char buf1[BUF_MAX];
    char buf2[BUF_MAX];

    memset(buf1, 0, sizeof(buf1));
    memset(buf2, 0, sizeof(buf2));
    p1 = buf1;
    p2 = buf2;
    strcpy (p1, "CCXXXII"); // 232
    CHK_VAL(p1, 232);
    p2[0] = 0;
    CHK_VAL("CCCCXIII", 413);
    roman_add ( p1, "CCCCXIII", p2, BUF_MAX); // 232 + 413
    CHK_VAL(p2, 232 + 413);
    tmp = p1; p1 = p2; p2 = tmp; // swap
    p2[0] = 0;
    CHK_VAL("MCCXXXI", 1231);
    roman_add ( p1, "MCCXXXI", p2, BUF_MAX); // + 1231
    CHK_VAL(p2, 232 + 413 + 1231);
    tmp = p1; p1 = p2; p2 = tmp; // swap
    p2[0] = 0;
    CHK_VAL("MDCCCLII", 1852);
    roman_add ( p1, "MDCCCLII", p2, BUF_MAX); // + 1852
    CHK_VAL(p2, 232 + 413 + 1231 + 1852);
    CI_ASSERT(0 == strcmp(p2, "MMMDCCXXVIII"));
}

void
ut_romadd_multi2(void)
{
    unsigned long retval;
    char *tmp;
    char *p1;
    char *p2;
    char buf1[BUF_MAX];
    char buf2[BUF_MAX];
    memset(buf1, 0, sizeof(buf1));
    memset(buf2, 0, sizeof(buf2));

    p1 = buf1;
    p2 = buf2;
    strcpy (p1, "XVII"); // 17
    CHK_VAL(p1, 17);
    p2[0] = 0;
    CHK_VAL("CCII", 202);
    roman_add ( p1, "CCII", p2, BUF_MAX);
    CHK_VAL(p2, 17 + 202);
    tmp = p1; p1 = p2; p2 = tmp; // swap
    p2[0] = 0;
    CHK_VAL("XXXIX", 39);
    roman_add ( p1, "XXXIX", p2, BUF_MAX); // + 39
    CHK_VAL(p2, 17 + 202 + 39);
    tmp = p1; p1 = p2; p2 = tmp; // swap
    p2[0] = 0;
    CHK_VAL("LI", 51);
    roman_add ( p1, "LI", p2, BUF_MAX); // + 51
    CHK_VAL(p2, 17 + 202 + 39 + 51);
    tmp = p1; p1 = p2; p2 = tmp; // swap
    p2[0] = 0;
    CHK_VAL("LXX", 70);
    roman_add ( p1, "LXX", p2, BUF_MAX); // + 70
    CHK_VAL(p2, 17 + 202 + 39 + 51 + 70);
    tmp = p1; p1 = p2; p2 = tmp; // swap
    p2[0] = 0;
    CHK_VAL("XCII", 92);
    roman_add ( p1, "XCII", p2, BUF_MAX); // + 92
    CHK_VAL(p2, 17 + 202 + 39 + 51 + 70 + 92);
    tmp = p1; p1 = p2; p2 = tmp; // swap
    p2[0] = 0;
    CHK_VAL("XLV", 45);
    roman_add ( p1, "XLV", p2, BUF_MAX); // + 45
    CHK_VAL(p2, 17 + 202 + 39 + 51 + 70 + 92 + 45);
    tmp = p1; p1 = p2; p2 = tmp; // swap
    p2[0] = 0;
    CHK_VAL("LXXXVII", 87);
    roman_add ( p1, "LXXXVII", p2, BUF_MAX); // + 87
    CHK_VAL(p2, 17 + 202 + 39 + 51 + 70 + 92 + 45 + 87);
    CI_ASSERT(0 == strcmp(p2, "DCIII"));
}

void
ut_romsub_basic(void)
{
    char buf[10];
    memset(buf, 0, sizeof(buf));
#define ROP_SUB(r1, r2, rr) roman_sub ( r1, r2, buf, sizeof(buf)); CI_ASSERT(0 == strcmp(buf, rr));
    ROP_SUB ( "V", "I", "IV");
    ROP_SUB ( "X", "V", "V");
}

void
ut_romsub_overflow(void)
{
    char buf[10];
    memset(buf, 0, sizeof(buf));

    CI_ASSERT( 0 == roman_sub("", "", buf, sizeof(buf))); CI_ASSERT(0 == strcmp(buf, ""));
    CI_ASSERT(-1 == roman_sub("", "", NULL, sizeof(buf)));
    CI_ASSERT(-1 == roman_sub("", "", NULL, 0));
    CI_ASSERT(-2 == roman_sub("", "", buf, 0));
    CI_ASSERT( 0 == roman_sub("", "", buf, 1));
    CI_ASSERT( 0 == roman_sub("", "", buf, 2));

    CI_ASSERT(-1 == roman_sub(NULL, "", NULL, 0));
    CI_ASSERT(-2 == roman_sub("", NULL, NULL, 0));
    CI_ASSERT(-1 == roman_sub("",   "", NULL, 0));
    CI_ASSERT(-2 == roman_sub("",   "", buf, 0));
    CI_ASSERT( 0 == roman_sub("M", "M", buf, 1));
    CI_ASSERT(-3 == roman_sub("M", "MM", buf, 1));
    CI_ASSERT( 0 == roman_sub("MM", "MM", buf, 1));
    CI_ASSERT(-2 == roman_sub("MMM", "MM", buf, 1));
    CI_ASSERT( 0 == roman_sub("MMM", "MM", buf, 2));
    CI_ASSERT(-1 == roman_sub("MMMM", "MM", buf, 1));
    CI_ASSERT(-1 == roman_sub("MMMM", "MM", buf, 2));
    CI_ASSERT(-1 == roman_sub("MMMM", "MM", buf, 3));
}

/* test buffer overflow */
void
ut_romadd_overflow(void)
{
    char buf[10];
    memset(buf, 0, sizeof(buf));

    CI_ASSERT( 0 == roman_add("", "", buf, sizeof(buf))); CI_ASSERT(0 == strcmp(buf, ""));
    CI_ASSERT(-1 == roman_add("", "", NULL, sizeof(buf)));
    CI_ASSERT(-1 == roman_add("", "", NULL, 0));
    CI_ASSERT(-2 == roman_add("", "", buf, 0));
    CI_ASSERT( 0 == roman_add("", "", buf, 1));
    CI_ASSERT( 0 == roman_add("", "", buf, 2));

    CI_ASSERT(-3 == roman_add("MMM", "M", buf, sizeof(buf)));
    CI_ASSERT(-3 == roman_add("MMM", "MM", buf, 1));
}

/* Test linking win32 library psapi */
void
ut_link_win32_psapi(void)
{
    int len = 0;
#if defined (_WIN)
    char buf[200];
    len = GetModuleFileName (NULL, buf, sizeof(buf));
#endif
    CI_ASSERT (len >= 0);
}
