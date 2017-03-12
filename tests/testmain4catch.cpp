/**
 * @file    testmain4check.c
 * @brief   main function for Check Unit Test lib
 * @author  Yunhui Fu (yhfudev@gmail.com)
 * @version 1.0
 * @date    2017-01-26
 * @copyright GNU Lesser General Public License v2.0.
 */

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "testromancal.c"

// validating
TEST_CASE("Roman Number convert to values", "[rn2val]")
{
    SECTION("rn2val basic"){
        ut_roman2value_basic();
    }
    SECTION("rn2val overflow"){
        ut_roman2value_overflow();
    }
    SECTION("val2rn basic"){
        ut_value2roman_basic();
    }
    SECTION("val2rn overflow"){
        ut_value2roman_overflow();
    }
}

TEST_CASE("Roman Number operations", "[rnOpera]")
{
    SECTION("rn add basic"){
        ut_romadd_basic();
    }
    SECTION("rn add overflow"){
        ut_romadd_overflow();
    }
    SECTION("rn add multiple 1"){
        ut_romadd_multi1();
    }
    SECTION("rn add multiple 2"){
        ut_romadd_multi2();
    }
    SECTION("rn sub basic"){
        ut_romsub_basic();
    }
    SECTION("rn sub overflow"){
        ut_romsub_overflow();
    }
}

TEST_CASE("Link win psapi", "[psapi]")
{
    SECTION("call psapi"){
        ut_link_win_psapi();
    }
}