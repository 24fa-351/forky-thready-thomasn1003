#include <stdio.h>
#include <stdlib.h>
#include "pattern1.h"
#include "pattern2.h"
#include "pattern3.h"

int main(int argc, char *argv[]) {


    int pattern = atoi(argv[1]);

    int num_processes = atoi(argv[2]);

    if (num_processes < 1 || num_processes > 256) {

        fprintf(stderr, "Number of processes must be between 1 and 256.\n");

        exit(EXIT_FAILURE);

    }

    switch (pattern) {

        case 1:

            pattern1(num_processes);

            break;

        case 2:

            pattern2(num_processes);

            break;

        case 3:

            pattern3(num_processes);

            break;


    }

    return 0;
}
