#include <stdio.h>
 
#include <stdlib.h>
 
#include "mySort.h"
 
 
 
int main(int argc, char * argv[])
 
{
 
    int data[100000]; /* Array of ints to sort */
 
    int nDataItems;   /* number of actual items in the array */

    int cmdarrItems[10000]; //create an array the size of the argument vector
 
    int i;
 

 
    /* Test data */
 
    nDataItems = 4;
 
    data[0] = 20;
 
    data[1] = 10;
 
    data[2] = 40;
 
    data[3] = 30;
 

    /*The following code is for the Requirements 2 of the lab   */ 

    int count;
    fprintf(stderr,"This program was called with %s\n",argv[0]); 

    //if there is argument count is more than 1, there is an argument
    if (argc > 1) {
	fprintf(stderr,"The command line arguments are: \n");

	//loop through the the argument vectors
	for (count = 1; count < argc; count++) {
		fprintf(stderr, " argv[%d] (as int): %d\n",count,atoi(argv[count]));

		cmdarrItems[count-1] = atoi(argv[count]);	//assign the argument vector to the array respectively
	}
	mySort(cmdarrItems, argc-1); //calls mySort method
	
	/* Print sorted array from commandline to stdout */
    	for(i = 0; i < argc-1; i++) {
        	printf("%d\n", cmdarrItems[i]);
   	}

	/* Check that the data array is sorted. */
    	for(i = 0; i < argc-2; i++) {
 
         if (cmdarrItems[i] > cmdarrItems[i+1]) {
 
            fprintf(stderr, "Sort error: cmdarrItems[%d] (= %d)"
 
              " should be <= cmdarrItems[%d] (= %d)- -aborting\n",
 
              i, cmdarrItems[i], i+1, cmdarrItems[i+1]);
 
            exit(1);
 
         }
	}


    }
    else {
	fprintf(stderr, "No command line arguments. Will proceed to sort the internal array:\n");

	mySort(data, nDataItems);	//calls the mySort function if there is no argument

	/* Print sorted array to stdout */
 
   	for(i = 0; i < nDataItems; i++) {
        	printf("%d\n", data[i]);
   	}

	/* Check that the data array is sorted. */
    	for(i = 0; i < nDataItems-1; i++) {
 
         if (data[i] > data[i+1]) {
 
            fprintf(stderr, "Sort error: data[%d] (= %d)"
 
              " should be <= data[%d] (= %d)- -aborting\n",
 
              i, data[i], i+1, data[i+1]);
 
            exit(1);
	 }
 
        }
 
    }
    exit(0);
}
