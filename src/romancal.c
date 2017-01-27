/**
 * @file    romancal.c
 * @brief   Roman number Calculator
 * @author  Yunhui Fu (yhfudev@gmail.com)
 * @version 1.0
 * @date    2017-01-26
 * @copyright GNU Lesser General Public License v2.0.
 */
#include <string.h>

#include "romancal.h"

/**
 * @brief Convert a Roman number string to value
 *
 * @param romanstr : the C string of a Roman number
 *
 * @return the value
 *
 * Convert the Roman number string to value
 */
unsigned long
roman2value(const char * romanstr)
{
    return 0;
}

typedef struct _roman_map_str_t {
    int val;
    const char * str;
} roman_map_str_t;

/**
 * @brief Convert a value to a Roman number string
 *
 * @param value : the value
 * @param romanstr : the C string of a Roman number
 * @param maxlen : the buffer size of the string
 *
 * @return 0 on success, other error
 *
 * Convert a value to a Roman number string
 */
int
value2roman(unsigned long value, char * romanstr, size_t maxlen)
{
    int i;
    unsigned long div;
    roman_map_str_t map[] = {
#define PAIR(val,str) {val, str},
        PAIRS()
#undef PAIR
    };
    romanstr[0] = 0;
    for (i = NUM_ARRAY(map); i > 0 && value > 0; i --) {
        div = value / map[i - 1].val;
        value %= map[i - 1].val;
        for ( ; div > 0; div --) {
            strcat (romanstr, map[i - 1].str);
        }
    }
    return 0;
}

