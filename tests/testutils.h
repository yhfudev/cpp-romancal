/**
 * @file    testutils.h
 * @brief   Unit Test functions
 * @author  Yunhui Fu (yhfudev@gmail.com)
 * @version 1.0
 * @date    2017-01-26
 * @copyright GNU Lesser General Public License v2.0.
 */
#ifndef _TESTUTILS_H
#define _TESTUTILS_H

// Unit Test
#if defined(USE_CI_CHECK) && (USE_CI_CHECK == 1)
#undef USE_CI_CHECK
#define USE_CI_CHECK 1
#include <check.h>
#else
#undef USE_CI_CHECK
#define USE_CI_CHECK 0
#include <catch.hpp>
#endif

#if defined(CHECK_H)
#  define CI_ASSERT(a) ck_assert(a)
#elif defined(CATCH_REQUIRE)
#  define CI_ASSERT(a) REQUIRE(a)
#else
#  define CI_ASSERT(a) assert(a)
#endif

#endif // _TESTUTILS_H

