/**
 * @file    testmain4check.c
 * @brief   main function for Check Unit Test lib
 * @author  Yunhui Fu (yhfudev@gmail.com)
 * @version 1.0
 * @date    2017-01-26
 * @copyright GNU Lesser General Public License v2.0.
 */

#include <stdlib.h>

#include "testutils.h"

extern void ut_roman2value_basic(void);
extern void ut_roman2value_overflow(void);
extern void ut_value2roman_basic(void);
extern void ut_value2roman_overflow(void);
extern void ut_romadd_basic(void);
extern void ut_romadd_multi1(void);
extern void ut_romadd_multi2(void);
extern void ut_romsub_basic(void);
extern void ut_romsub_overflow(void);
extern void ut_romadd_overflow(void);

extern void ut_link_win_psapi(void);

START_TEST (test_roman2value_basic)
{
    ut_roman2value_basic();
}
END_TEST

START_TEST (test_roman2value_overflow)
{
    ut_roman2value_overflow();
}
END_TEST

START_TEST (test_value2roman_basic)
{
    ut_value2roman_basic();
}
END_TEST

START_TEST (test_value2roman_overflow)
{
    ut_value2roman_overflow();
}
END_TEST

START_TEST (test_romadd_basic)
{
    ut_romadd_basic();
}
END_TEST

START_TEST (test_romadd_multi1)
{
    ut_romadd_multi1();
}
END_TEST

START_TEST (test_romadd_multi2)
{
    ut_romadd_multi2();
}
END_TEST

START_TEST (test_romsub_basic)
{
    ut_romsub_basic();
}
END_TEST

START_TEST (test_romsub_overflow)
{
    ut_romsub_overflow();
}
END_TEST

/* test buffer overflow */
START_TEST (test_romadd_overflow)
{
    ut_romadd_overflow();
}
END_TEST

START_TEST (test_link_win_psapi)
{
    ut_link_win_psapi();
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

    s = suite_create("Roman Number Calculator");

    /* test case */
    tc_v2r = tcase_create("value2roman");
    tcase_add_test(tc_v2r, test_value2roman_basic);
    suite_add_tcase(s, tc_v2r);

    tc_v2r = tcase_create("value2roman overflow");
    tcase_add_test(tc_v2r, test_value2roman_overflow);
    suite_add_tcase(s, tc_v2r);

    tc_r2v = tcase_create("roman2value");
    tcase_add_test(tc_r2v, test_roman2value_basic);
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
    tcase_add_test(tc_sub, test_romsub_basic);
    suite_add_tcase(s, tc_sub);

    tc_sub = tcase_create("roman sub overflow");
    tcase_add_test(tc_sub, test_romsub_overflow);
    suite_add_tcase(s, tc_sub);

    return s;
}

static Suite *
winlib_suite(void)
{
    Suite * s;
    TCase * tc_lib;

    s = suite_create("Windows Libraries");

    tc_lib = tcase_create("link win psapi");
    tcase_add_test(tc_lib, test_link_win_psapi);
    suite_add_tcase(s, tc_lib);

    return s;
}

int
main(void)
{
    int ret;
    int number_failed = 0;
    Suite *s;
    SRunner *sr;

    s = value2roman_suite();
    sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    ret = srunner_ntests_failed(sr);
    srunner_free(sr);
    number_failed += ret;

    s = winlib_suite();
    sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    ret = srunner_ntests_failed(sr);
    srunner_free(sr);
    number_failed += ret;

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
