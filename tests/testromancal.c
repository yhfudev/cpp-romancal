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

START_TEST (test_value2roman_basic)
{
}
END_TEST

static Suite *
value2roman_suite(void)
{
    Suite * s;
    TCase * tc_v2r;
    TCase * tc_r2v;

    s = suite_create("Roman Number Calculator");

    /* test case */
    tc_v2r = tcase_create("value2roman");
    tcase_add_test(tc_v2r, test_value2roman_basic);
    suite_add_tcase(s, tc_v2r);

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
