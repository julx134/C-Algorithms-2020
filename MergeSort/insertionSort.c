#include "mySort.h"

void mySort(int array[], unsigned int first, unsigned int last)
    {
      int iC,dC, temp;

      for (iC = first+1; iC <= last; iC++) {
	dC = iC -1;
	myCopy(&array[iC],&temp);   
	//temp = array[iC];
     
	while (dC >= first && myCompare(temp,array[dC]) < 0) {
	  myCopy(&array[dC],&array[dC+1]); 
	  // array[dC+1] = array[dC];
	  dC--;
	}
	myCopy(&temp,&array[dC+1]);  
        //array[dC+1] = temp;

      }
    }
