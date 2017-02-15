/**
 * @file    romancal.c
 * @brief   Roman number Calculator
 * @author  Yunhui Fu (yhfudev@gmail.com)
 * @version 1.0
 * @date    2017-01-26
 * @copyright GNU Lesser General Public License v2.0.
 */
#include <string.h>
#include <assert.h>

#include "romancal.h"

#define PAIRS0() \
    PAIR(   1,  'I') \
    PAIR(   5,  'V') \
    PAIR(  10,  'X') \
    PAIR(  50,  'L') \
    PAIR( 100,  'C') \
    PAIR( 500,  'D') \
    PAIR(1000,  'M') \

static unsigned long
r2v(const char ch)
{
    switch (ch) {
#define PAIR(val,chr) case chr: return val;
        PAIRS0()
#undef PAIR
    }
    return 0;
}

/**
 * @brief Convert a Roman number string to value
 *
 * @param romanstr : the C string of a Roman number
 * @param value : the value of the Roman number
 *
 * @return 0 on success, -1 on NULL buffer, -2 on value overflow
 *
 * Convert the Roman number string to value
 */
int
roman2value(const char * romanstr, unsigned long * value)
{
    size_t i;
    size_t max;
    unsigned long prev = 0;
    unsigned long cur = 0;
    unsigned long retval = 0;

    if ((NULL == romanstr) || (NULL == value)) {
        return -1;
    }
    max = strlen(romanstr);
    for (i = 0; i < max; i ++) {
        cur = r2v(romanstr[i]);
        retval += cur - ((prev < cur)?(prev << 1):0);
        prev = cur;
        if (retval > 3999) {
            return -3;
        }
    }
    *value = retval;
    return 0;
}

typedef struct _roman_map_str_t {
    int val;
    const char * str;
    size_t str_len;
} roman_map_str_t;

/**
 * @brief Convert a value to a Roman number string
 *
 * @param value : the value
 * @param romanstr : the C string of a Roman number
 * @param maxlen : the buffer size of the string
 *
 * @return 0 on success, -1 on NULL buffer, -2 on not enough buffer size
 *
 * Convert a value to a Roman number string
 */
int
value2roman(unsigned long value, char * romanstr, size_t maxlen)
{
    int i;
    size_t str_size;
    unsigned long div;
    roman_map_str_t map[] = {
#define PAIR(val,str) {val, str, sizeof(str)-1},
        ROMANPAIRS_BASE()
#undef PAIR
    };
    if (NULL == romanstr) {
        return -1;
    }
    romanstr[0] = 0;
    if (maxlen < 1) {
        return -2;
    }
    if (value > 3999) {
        return -3;
    }
    str_size = 0;
    for (i = NUM_ARRAY(map); i > 0 && value > 0; i --) {
        div = value / map[i - 1].val;
        value %= map[i - 1].val;
        for ( ; div > 0; div --) {
            if (str_size + map[i - 1].str_len >= maxlen) {
                romanstr[0] = 0;
                return -2;
            }
            str_size += map[i - 1].str_len;
            strcat (romanstr, map[i - 1].str);
        }
    }
    return 0;
}

/**
 * @brief Add two Roman number strings (roman1 + roman2 --> roman_ret)
 *
 * @param roman1 : the first C string of a Roman number
 * @param roman2 : the second C string of a Roman number
 * @param roman1 : the adding result of C string of a Roman number
 * @param maxlen : the buffer size of the string
 *
 * @return 0 on success, -1 on NULL buffer, -2 on not enough buffer size
 *
 * Convert a value to a Roman number string
 */
int
roman_add (const char * roman1, const char * roman2, char * roman_ret, size_t maxlen)
{
    unsigned long val1;
    unsigned long val2;

    if (roman2value(roman1, &val1) < 0) {
        return -1;
    }
    if (roman2value(roman2, &val2) < 0) {
        return -2;
    }
    TRACE ("romadd %lu + %lu = %lu", val1, val2, val1 + val2);
    return value2roman (val1 + val2, roman_ret, maxlen);
}

/**
 * @brief Substract two Roman number strings (roman1 - roman2 --> roman_ret)
 *
 * @param roman1 : the first C string of a Roman number
 * @param roman2 : the second C string of a Roman number
 * @param roman1 : the adding result of C string of a Roman number
 * @param maxlen : the buffer size of the string
 *
 * @return 0 on success, -1 on NULL buffer, -2 on not enough buffer size
 *
 * Convert a value to a Roman number string
 */
int
roman_sub (const char * roman1, const char * roman2, char * roman_ret, size_t maxlen)
{
    unsigned long val1;
    unsigned long val2;

    if (roman2value(roman1, &val1) < 0) {
        return -1;
    }
    if (roman2value(roman2, &val2) < 0) {
        return -2;
    }
    if (val1 < val2) {
        return -3;
    }
    TRACE ("romsub %lu - %lu = %lu", val1, val2, val1 - val2);
    return value2roman (val1 - val2, roman_ret, maxlen);
}
