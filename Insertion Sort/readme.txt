Everything in the requirements was met. Code ran without trouble.


1.

Similar to a divide and conquer algorithm, the modified mySort algorithim will divide
the array into smaller segments using the betterSort method. Using the betterSort method
will decrease pre-sort segments of the data[] and then use insertionSort to clean-up
the array.

Pseudo Code:

mySort(....) {
	//divide data[] by however many segments, for this example I will divide data[] into two sections
	  to be sorted by betterSort
	betterSort[data[], 0,nDataItems/2];
	betterSort[data[],nDataItems/2, nDataItems];

	//By this point data[] is already pre-sorted. The more segments that is pre-sorted the better.
	->Insert psuedo code for insertion sort

}