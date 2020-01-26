Everything ran without problem. I had to modify the towers.c file in order to only have stdout formatted as specified
in the requirements.




//Suppose that towers (5,2,3) is invoked

1) How will the first recursive call to towers() be invoked? Answer this
question in the form: towers(x, y, z) where you give the actual values to the
three parameters.

 The first recursive call to towers will be: 
	towers(5, 2, 3)


2) How many recursive calls to towers() will be made before this first recursive
call actually returns to the initial invocation? 

 Using a recursive tree, I can see that each the formula for each top level/iteration
	is [sigma n^2] -1 (the -1 being that the first call of the method is not considered a recursive call).
	Therefore, in order to return to the original invocation of the first recursive call, we use the
	formula derived. It is the sum of n = 0, n=1...n=4 which is 16+8+4+2+1 = 31.
	Therefore, there will be 31 recursive calls before it returns to the initial invocation of the first 
	recursion call.


3) Once towers(5, 2, 3) has invoked its first recursive call to towers() and this
invocation has returned, what will be printed to stdout? (i.e. What actual
move will be made by towers(5, 2, 3) ?) 

 What will be printed at stdout is : 2 3
	To be be precise, at the call out of move #16, is the return of the program into
	the initial invocation of towers (5, 2, 3)


4)How will the second recursive call to towers() be invoked? Answer this
question in the form: towers(x, y, z) where you give the actual values to the
three parameters. 

 The second recursive call to towers is: towers (3,2,3)


5) Suppose that towers(8, 1, 2) is invoked. How many lines will be printed to stdout? 

 Using theoretical analysis we can determine that the number of lines printed to stdout 
	can be found by using the following formula (([sigma(n^2)]-1)/2	which if n = 8,
	then the number of lines is 255.

 
