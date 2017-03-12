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
#include <libgen.h> // basename()

#include <getopt.h>

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
    char *show = (char *)"";

    int c;
    struct option longopts[]  = {
        { "show",         1, 0, 's' },

        { "help",         0, 0, 'h' },
        { "verbose",      0, 0, 'v' },
        { 0,              0, 0,  0  },
    };

    while ((c = getopt_long( argc, argv, "s:vh", longopts, NULL )) != EOF) {
        switch (c) {
        case 's':
            show = optarg;
            break;
        case 'h':
            usage (argv[0]);
            exit (0);
            break;
        default:
            fprintf (stderr, "Unknown parameter: '%c'.\n", c);
            fprintf (stderr, "Use '%s -h' for more information.\n", basename(argv[0]));
            exit (-1);
            break;
        }
    }

    if (argc - optind != 3) {
        fprintf(stderr, "Error: argument number should be 3!\n");
        usage(argv[0]);
        exit (1);
    }
    ret = -1;
    memset(buf, 0, sizeof(buf));
    op = argv[optind + 1][0];
    switch (op) {
    case '+':
        ret = roman_add(argv[optind], argv[optind + 2], buf, sizeof(buf));
        break;
    case '-':
        ret = roman_sub(argv[optind], argv[optind + 2], buf, sizeof(buf));
        break;
    default:
        fprintf(stderr, "Error: unknown op: '%c'!\n", op);
        break;
    }
    if (ret < 0) {
        fprintf(stderr, "Error: in calculation!\n");
        return -1;
    }
    fprintf(stdout, "%s%s\n", show, buf);
    return 0;
}
