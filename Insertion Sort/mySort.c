void mySort(int d[], unsigned int n)
{
	//iC and dC stands for incrementCounter and decrementCounter respectively
	unsigned int iC, dC;	
	
	//loops through all the elements of the array starting at index 1
	for (iC = 1; iC < n; iC++) {
		int key = d[iC]; //assign the current iteration to key
		int dC = iC-1;  //setting dC to iC-1 as a variable to compare
		
		//while loop iterates everytime d[dC] is more than key and more or equal to 0
		while (dC >= 0 && d[dC] >= key) {
			//'pushes' the loop invariant (already sorted numbers) by one index up
			d[dC+1] = d[dC];
			//decrement dC
			dC--;
				
		}
		//set the key to the appropriate spot when while loop terminates
		d[dC + 1] = key;
	
	}

}
