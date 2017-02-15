/**
 * @file    main.c
 * @brief   Roman number Calculator Main
 * @author  Yunhui Fu (yhfudev@gmail.com)
 * @version 1.0
 * @date    2017-01-26
 * @copyright GNU Lesser General Public License v2.0.
 */

#include <stdio.h>
#include <stdlib.h> // exit()
#include <string.h> // memset()

#include "romancal.h"

void
usage(const char *progname)
{
    fprintf(stderr, "\n");
    fprintf(stderr, "Usage: %s <left> <op> <right>\n", progname);
    fprintf(stderr, "\n");
    fprintf(stderr, "Examples:\n");
    fprintf(stderr, "   %s V - I\n", progname);
    fprintf(stderr, "   %s X + V\n", progname);
}

int
main(int argc, char * argv[])
{
    int ret = -1;
    char op;
    char buf[250];
    if (argc != 4) {
        fprintf(stderr, "Error: argument number should be 3!\n");
        usage(argv[0]);
        exit (1);
    }
    memset(buf, 0, sizeof(buf));
    op = argv[2][0];
    switch (op) {
    case '+':
        ret = roman_add(argv[1], argv[3], buf, sizeof(buf));
        break;
    case '-':
        ret = roman_sub(argv[1], argv[3], buf, sizeof(buf));
        break;
    default:
        fprintf(stderr, "Error: unknown op: '%c'!\n", op);
        break;
    }
    if (ret < 0) {
        fprintf(stderr, "Error: in calculation!\n");
    } else {
        fprintf(stdout, "%s\n", buf);
    }
    return 0;
}

