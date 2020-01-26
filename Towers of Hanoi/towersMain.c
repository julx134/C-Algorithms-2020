#include <stdlib.h>
#include <stdio.h>
#include "towers.h"

int main(int argc, char **argv)
{
    int n = 3;
    int from = 1;
    int dest = 2;
    if (argc > 1) {
        if (argc == 2) {
		n = atoi(argv[1]);
		towers(n,from, dest);
	}
	else if (argc == 4) {
		n = atoi(argv[1]);
		towers(n, atoi(argv[2]), atoi(argv[3]));
	}
	else {
		fprintf(stderr, "error!\n");
		exit(-1);
	}
    }
    else {

    towers(n, from, dest);

   }

    exit(0);
}

