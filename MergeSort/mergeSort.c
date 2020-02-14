#include "mySort.h"

void merge(int array[], int first, int middle, int last) {

    int lC = first, rC = middle +1, i;	//lC is leftArrayCounter and rC is rightArrayCounter
    int tempArray[1000];	//declaring a temporary array
 
    //copies content of the subarrays into a temporary array and sort them
    //iterates until lC and rC reaches all of the elements in the subarray
    for (i = first; (myCompare(lC,middle) < 0 || lC == middle) && (myCompare(rC,last) < 0 || rC == last); i++ ) {	//lC <= middle && rC <= last
	
	//This "subsection" of the entire array is sorted and placed into the temp array
	//splits the array in half and compares the first element from both sides. If one side is less than the other,
	//set that element into the temp array and increment that side by one and so on.
        if (myCompare(array[lC],array[rC]) < 0 || array[lC] == array[rC]) { 	//array[lC] <= array[rC]
	    myCopy(&array[lC],&tempArray[i]);		//tempArray[i] = array[lC++];
	    lC++;
	}
        else {
            myCopy(&array[rC],&tempArray[i]);		//tempArray[i] = array[rC++];
	    rC++;
	}
    }
    
    //copies the remaining elements for the left subarray
    while (myCompare(lC, middle) < 0 || lC == middle) {		//lC <= middle
        myCopy(&array[lC],&tempArray[i]);		//tempArray[i++] = array[lC++];
	lC++;
	i++;
    }
    
    //copies the remaining elements for the right subarray
    while (myCompare(rC, last) < 0 || rC == last) {		//rC <= last
        myCopy(&array[rC],&tempArray[i]);		//tempArray[i++] = array[rC++];
	rC++;
	i++;
    }

    //copies the content of the temp array into the real array
    for (i = first; i <= last; i++) {
        myCopy(&tempArray[i],&array[i]);		//array[i] = tempArray[i];
    }
}

void mySort(int array[], unsigned int first, unsigned int last)
    {
	//actual recursion call for the mergeSort algorithm
	if (first < last) {
		int middle = (last+first)/2;

		mySort(array, first, middle);
		mySort(array,middle +1, last);
		
		merge(array,first,middle,last);
	}
	
    }



