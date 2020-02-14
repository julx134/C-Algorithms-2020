#include "mySort.h"

void merge(int array[], int first, int middle, int last) {
    int lC = first, rC = middle + 1, i = 0;	//lC is leftCounter and rC is rightCounter
    

    int tempArray[last+1];	//declaring a temporary array
 
	//copies content of the array into a temporary array and sort them
    for (i = first; lC <= middle && rC <= last; i++ ) {
	//This "subsection" of the entire array is sorted and placed into the temp array
        if (array[lC] <= array[rC])	
            tempArray[i] = array[lC++];
        else 
            tempArray[i] = array[rC++];
    }
    
    //copies the content of the temp array into the real array
    while (lC <= middle) {
        tempArray[i++] = array[lC++];
    }
    while (rC <= last) {
        tempArray[i++] = array[rC++];
    }
    for (i = first; i <= last; i++) {
        array[i] = tempArray[i];
    }
}

void mySort(int array[], unsigned int first, unsigned int last)
    {
	int middle = (last-first)/2;

	mySort(array, first, middle);
	mySort(array,middle +1, last);
	merge(array,first,middle,last);
    }


