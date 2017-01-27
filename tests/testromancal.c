/**
 * @file    testromancal.c
 * @brief   Test Roman number Calculator
 * @author  Yunhui Fu (yhfudev@gmail.com)
 * @version 1.0
 * @date    2017-01-26
 * @copyright GNU Lesser General Public License v2.0.
 */

#include <stdlib.h>

#include <check.h>

#include "romancal.h"

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
    PAIR(4000,     "MMMM") \

START_TEST (test_roman2value_basic)
{
#define PAIR(val,str) ck_assert_int_eq(val, roman2value(str));
    PAIR(0, NULL);
    PAIR(0, "");
    ROMANPAIRS_BASE();
#undef PAIR

}
END_TEST

START_TEST (test_roman2value_long)
{
#define PAIR(val,str) ck_assert_int_eq(val, roman2value(str));
    PAIR(1910, "MDCCCCX"); // or MCMX
    ROMANPAIRS_SEQ();
#undef PAIR
}
END_TEST

START_TEST (test_roman2value_overflow)
{
    ck_assert_int_eq(0, roman2value(NULL));
}
END_TEST


START_TEST (test_value2roman_basic)
{
    char buf[10];
    memset(buf, 0, sizeof(buf));
#define PAIR(val,str) value2roman(val, buf, sizeof(buf)); ck_assert_str_eq(buf, str);
    PAIR(0, "");
    ROMANPAIRS_BASE();
#undef PAIR
}
END_TEST

START_TEST (test_value2roman_long)
{
    char buf[10];
    memset(buf, 0, sizeof(buf));
#define PAIR(val,str) value2roman(val, buf, sizeof(buf)); ck_assert_str_eq(buf, str);
    ROMANPAIRS_SEQ();
    PAIR(351, "CCCLI");
    PAIR(453, "CDLIII");
#undef PAIR
}
END_TEST

/* test buffer overflow */
START_TEST (test_value2roman_overflow)
{
    char buf[10];
    memset(buf, 0, sizeof(buf));
#define PAIR(val,str) value2roman(val, buf, 6); ck_assert_str_eq(buf, str);
    PAIR(351, "CCCLI");
    PAIR(453, "");
#undef PAIR
    ck_assert_int_eq(-1, value2roman(351, NULL, sizeof(buf)));
    ck_assert_int_eq(-1, value2roman(351, NULL, 0));
    ck_assert_int_eq(-2, value2roman(351, buf, 0));
    ck_assert_int_eq(-2, value2roman(351, buf, 1));
    ck_assert_int_eq(-2, value2roman(351, buf, 2));
    ck_assert_int_eq(-2, value2roman(351, buf, 3));
    ck_assert_int_eq(-2, value2roman(351, buf, 4));
    ck_assert_int_eq(-2, value2roman(351, buf, 5));
    ck_assert_int_eq( 0, value2roman(351, buf, 6));
}
END_TEST

START_TEST (test_romadd_basic)
{
    char buf[10];
    memset(buf, 0, sizeof(buf));
#define ROP_ADD(r1, r2, rr) roman_add ( r1, r2, buf, sizeof(buf)); ck_assert_str_eq(buf, rr);
    ROP_ADD ( "V", "I", "VI");
    ROP_ADD ( "X", "V", "XV");
    ROP_ADD ( "XIV", "LX", "LXXIV");
    ROP_ADD ( "XX", "II", "XXII");
}
END_TEST

#define BUF_MAX 20
START_TEST (test_romadd_multi1)
{
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
    ck_assert_int_eq (roman2value(p1), 232);
    p2[0] = 0;
    ck_assert_int_eq (roman2value("CCCCXIII"), 413);
    roman_add ( p1, "CCCCXIII", p2, BUF_MAX); // 232 + 413
    ck_assert_int_eq (roman2value(p2), 232 + 413);
    tmp = p1; p1 = p2; p2 = tmp; // swap
    p2[0] = 0;
    ck_assert_int_eq (roman2value("MCCXXXI"), 1231);
    roman_add ( p1, "MCCXXXI", p2, BUF_MAX); // + 1231
    ck_assert_int_eq (roman2value(p2), 232 + 413 + 1231);
    tmp = p1; p1 = p2; p2 = tmp; // swap
    p2[0] = 0;
    ck_assert_int_eq (roman2value("MDCCCLII"), 1852);
    roman_add ( p1, "MDCCCLII", p2, BUF_MAX); // + 1852
    ck_assert_int_eq (roman2value(p2), 232 + 413 + 1231 + 1852);
    ck_assert_int_eq (roman2value(p2), 3728);
    ck_assert_str_eq (p2, "MMMDCCXXVIII");
}
END_TEST

START_TEST (test_romadd_multi2)
{
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
    ck_assert_int_eq (roman2value(p1), 17);
    p2[0] = 0;
    ck_assert_int_eq (roman2value("CCII"), 202);
    roman_add ( p1, "CCII", p2, BUF_MAX);
    ck_assert_int_eq (roman2value(p2), 17 + 202);
    tmp = p1; p1 = p2; p2 = tmp; // swap
    p2[0] = 0;
    ck_assert_int_eq (roman2value("XXXIX"), 39);
    roman_add ( p1, "XXXIX", p2, BUF_MAX); // + 39
    ck_assert_int_eq (roman2value(p2), 17 + 202 + 39);
    tmp = p1; p1 = p2; p2 = tmp; // swap
    p2[0] = 0;
    ck_assert_int_eq (roman2value("LI"), 51);
    roman_add ( p1, "LI", p2, BUF_MAX); // + 51
    ck_assert_int_eq (roman2value(p2), 17 + 202 + 39 + 51);
    tmp = p1; p1 = p2; p2 = tmp; // swap
    p2[0] = 0;
    ck_assert_int_eq (roman2value("LXX"), 70);
    roman_add ( p1, "LXX", p2, BUF_MAX); // + 70
    ck_assert_int_eq (roman2value(p2), 17 + 202 + 39 + 51 + 70);
    tmp = p1; p1 = p2; p2 = tmp; // swap
    p2[0] = 0;
    ck_assert_int_eq (roman2value("XCII"), 92);
    roman_add ( p1, "XCII", p2, BUF_MAX); // + 92
    ck_assert_int_eq (roman2value(p2), 17 + 202 + 39 + 51 + 70 + 92);
    tmp = p1; p1 = p2; p2 = tmp; // swap
    p2[0] = 0;
    ck_assert_int_eq (roman2value("XLV"), 45);
    roman_add ( p1, "XLV", p2, BUF_MAX); // + 45
    ck_assert_int_eq (roman2value(p2), 17 + 202 + 39 + 51 + 70 + 92 + 45);
    tmp = p1; p1 = p2; p2 = tmp; // swap
    p2[0] = 0;
    ck_assert_int_eq (roman2value("LXXXVII"), 87);
    roman_add ( p1, "LXXXVII", p2, BUF_MAX); // + 87
    ck_assert_int_eq (roman2value(p2), 17 + 202 + 39 + 51 + 70 + 92 + 45 + 87);
    ck_assert_int_eq (roman2value(p2), 603);
    ck_assert_str_eq (p2, "DCIII");
}
END_TEST

START_TEST (test_romsub_basic)
{
    char buf[10];
    memset(buf, 0, sizeof(buf));
#define ROP_SUB(r1, r2, rr) roman_sub ( r1, r2, buf, sizeof(buf)); ck_assert_str_eq(buf, rr);
    ROP_SUB ( "V", "I", "IV");
    ROP_SUB ( "X", "V", "V");
}
END_TEST

START_TEST (test_rommul_basic)
{
    char buf[10];
    memset(buf, 0, sizeof(buf));
#define ROP_MUL(r1, r2, rr) roman_mul ( r1, r2, buf, sizeof(buf)); ck_assert_str_eq(buf, rr);
    ROP_MUL ( "V", "I", "V");
    ROP_MUL ( "X", "V", "L");
}
END_TEST

/* test buffer overflow */
START_TEST (test_romadd_overflow)
{
    char buf[10];
    memset(buf, 0, sizeof(buf));

    ck_assert_int_eq( 0, roman_add(NULL, NULL, buf, sizeof(buf))); ck_assert_str_eq(buf, "");
    ck_assert_int_eq(-1, roman_add(NULL, NULL, NULL, sizeof(buf)));
    ck_assert_int_eq(-1, roman_add(NULL, NULL, NULL, 0));
    ck_assert_int_eq(-2, roman_add(NULL, NULL, buf, 0));
    ck_assert_int_eq( 0, roman_add(NULL, NULL, buf, 1));
    ck_assert_int_eq( 0, roman_add(NULL, NULL, buf, 2));

    ck_assert_int_eq( 0, roman_sub(NULL, NULL, buf, sizeof(buf))); ck_assert_str_eq(buf, "");
    ck_assert_int_eq(-1, roman_sub(NULL, NULL, NULL, sizeof(buf)));
    ck_assert_int_eq(-1, roman_sub(NULL, NULL, NULL, 0));
    ck_assert_int_eq(-2, roman_sub(NULL, NULL, buf, 0));
    ck_assert_int_eq( 0, roman_sub(NULL, NULL, buf, 1));
    ck_assert_int_eq( 0, roman_sub(NULL, NULL, buf, 2));

    ck_assert_int_eq( 0, roman_mul(NULL, NULL, buf, sizeof(buf))); ck_assert_str_eq(buf, "");
    ck_assert_int_eq(-1, roman_mul(NULL, NULL, NULL, sizeof(buf)));
    ck_assert_int_eq(-1, roman_mul(NULL, NULL, NULL, 0));
    ck_assert_int_eq(-2, roman_mul(NULL, NULL, buf, 0));
    ck_assert_int_eq( 0, roman_mul(NULL, NULL, buf, 1));
    ck_assert_int_eq( 0, roman_mul(NULL, NULL, buf, 2));
}
END_TEST

static Suite *
value2roman_suite(void)
{
    Suite * s;
    TCase * tc_v2r;
    TCase * tc_r2v;
    TCase * tc_add;
    TCase * tc_sub;
    TCase * tc_mul;

    s = suite_create("Roman Number Calculator");

    /* test case */
    tc_v2r = tcase_create("value2roman");
    tcase_add_test(tc_v2r, test_value2roman_basic);
    suite_add_tcase(s, tc_v2r);

    tc_v2r = tcase_create("value2roman long");
    tcase_add_test(tc_v2r, test_value2roman_long);
    suite_add_tcase(s, tc_v2r);

    tc_v2r = tcase_create("value2roman overflow");
    tcase_add_test(tc_v2r, test_value2roman_overflow);
    suite_add_tcase(s, tc_v2r);

    tc_r2v = tcase_create("roman2value");
    tcase_add_test(tc_r2v, test_roman2value_basic);
    suite_add_tcase(s, tc_r2v);

    tc_r2v = tcase_create("roman2value long");
    tcase_add_test(tc_r2v, test_roman2value_long);
    suite_add_tcase(s, tc_r2v);

    tc_r2v = tcase_create("roman2value overflow");
    tcase_add_test(tc_r2v, test_roman2value_overflow);
    suite_add_tcase(s, tc_r2v);

    tc_add = tcase_create("roman add");
    tcase_add_test(tc_add, test_romadd_basic);
    suite_add_tcase(s, tc_add);

    tc_add = tcase_create("roman add multiple numbers 1");
    tcase_add_test(tc_add, test_romadd_multi1);
    suite_add_tcase(s, tc_add);

    tc_add = tcase_create("roman add multiple numbers 2");
    tcase_add_test(tc_add, test_romadd_multi2);
    suite_add_tcase(s, tc_add);

    tc_add = tcase_create("roman add overflow");
    tcase_add_test(tc_add, test_romadd_overflow);
    suite_add_tcase(s, tc_add);

    tc_sub = tcase_create("roman sub");
    tcase_add_test(tc_sub, test_romadd_basic);
    suite_add_tcase(s, tc_sub);

    tc_mul = tcase_create("roman mul");
    tcase_add_test(tc_mul, test_rommul_basic);
    suite_add_tcase(s, tc_mul);

    return s;
}

int
main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = value2roman_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
