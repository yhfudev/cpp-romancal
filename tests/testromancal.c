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

START_TEST (test_roman2value_basic)
{
#define PAIR(val,str) ck_assert_int_eq(val, roman2value(str));
    PAIR(0, "");
    PAIRS();
#undef PAIR
}
END_TEST

START_TEST (test_roman2value_long)
{
#define PAIR(val,str) ck_assert_int_eq(val, roman2value(str))
    PAIR(0, "");
    PAIR(351, "CCCLI");
    PAIR(453, "CDLIII");
    PAIR(1453, "MCDLIII");
    PAIR(2000, "MM");
    PAIR(3000, "MMM");
    PAIR(4931, "MMMMCMXXXI");
#undef PAIR
}
END_TEST

START_TEST (test_value2roman_basic)
{
    char buf[10];
    memset(buf, 0, sizeof(buf));
#define PAIR(val,str) value2roman(val, buf, sizeof(buf)); ck_assert_str_eq(buf, str);
    PAIR(0, "");
    PAIRS();
#undef PAIR
}
END_TEST

START_TEST (test_value2roman_long)
{
    char buf[10];
    memset(buf, 0, sizeof(buf));
#define PAIR(val,str) value2roman(val, buf, sizeof(buf)); ck_assert_str_eq(buf, str)
    PAIR(351, "CCCLI");
    PAIR(453, "CDLIII");
    PAIR(1453, "MCDLIII");
    PAIR(2000, "MM");
    PAIR(3000, "MMM");
    PAIR(4931, "MMMMCMXXXI");
#undef PAIR
}
END_TEST

/* test buffer overflow */
START_TEST (test_value2roman_overflow)
{
    char buf[10];
    memset(buf, 0, sizeof(buf));
#define PAIR(val,str) value2roman(val, buf, 5); ck_assert_str_eq(buf, str)
    PAIR(351, "CCCLI");
    PAIR(453, "");
#undef PAIR
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

static Suite *
value2roman_suite(void)
{
    Suite * s;
    TCase * tc_v2r;
    TCase * tc_r2v;
    TCase * tc_add;

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

    tc_add = tcase_create("roman add");
    tcase_add_test(tc_add, test_romadd_basic);
    suite_add_tcase(s, tc_add);

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
