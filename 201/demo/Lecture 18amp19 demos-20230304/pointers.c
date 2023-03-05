#include <stdio.h>

void demo1DIntArray(){

	int array[10] = {1,2,3,4,5,6,7,8,9,10};

	int *p;

	p = array; //the name of any array is basically the address of its first element so it is 
				//the same as &array[0]. Since array[0] is of type int, then
				//a pointer of type int* is the right pointer type to save its address (in
				//other words to point to it)

	printf("printing *p after p = array: %d\n", *p);//should print 1
	printf("printing *array=%d\n", *array);//should print 1

	p = &array[4]; //same thing as last case
	printf("printing *p after p=&array[4] = %d\n", *p); //should print 5
	printf("printing array[4]=%d\n", array[4]); //should also print 5

	p = array + 3;//what is array? array is the address of the first element in the array so when
					//we add 3, it basically moves the address by 3 elements so now p points to a[3]

	printf("printing *p after p=array+3 = %d\n", *p);//should print 4
	
}

void demo1DCharArray(){

	char array[10] = "hello";// the string here is used to initialize the array

	char *p;

	p = array; //the name of any array is basically the address of its first element so it is 
				//the same as &array[0]. Since array[0] is of type int, then
				//a pointer of type int* is the right pointer type to save its address (in
				//other words to point to it)

	printf("printing *p after p=array: %c\n", *p);//should print h
	printf("printing p after p=array: %s\n", p);//this prints the whole string hello. p is of type char* so it is a string
	printf("printing array: %s\n", array);//this again prints the whole string hello

	p = &array[4]; //compatable pointer time.. see prev. explanation
	printf("printing *p after p=&array[4]: %c\n", *p); //should print o
	printf("printing array[4]: %c\n", array[4]); //should also print o

	p = array + 2;
	printf("printing *p after p=array+2: %c\n", *p);//should print l
	printf("printing p after p=array+2: %s\n", p);//should print llo
}

void demo2DCharArray(){

	char array[3][6] = {"hello", "Rat", "apple"};

	printf("Array values:\n");
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 6; j++)
			printf("%c", array[i][j]);

		printf("\n");
	}


	//char *p = array; IS NOT CORRECT!! See slide 30 of Lecture 11

	char (*myArrPtr)[6]; //this creates a pointer to a character array of length 6 (to match # of cols)

	myArrPtr = array;//now I can do this assignment

	printf("printing *array: %s\n", *array);//should print hello. Remember that the name of the array
											//is the the same as the address of its first element. Since this
											//is a 2D array, that first element is the first 1D array in it
											//That means that array is an address of an array of characters
											//which means it has the type (char*)[NCOLS] so to print the string
											//itself in the array, we need to dereference that ptr

	printf("printing *myArrPtr after myArrPtr=array: %s\n", *myArrPtr);//same reasoning as above

	printf("printing array[0]: %s\n", array[0]);//should print hello. This is the same as printing *array
	printf("printing array[2]: %s\n", array[2]);//should print apple
	printf("printing *(myArrPtr + 1): %s\n", *(myArrPtr + 1));//should print Rat
	printf("printing *(myArrPtr + 1)[2]: %c\n", (*(myArrPtr + 1))[2]);//should print t .. The *(myArrPtr +1) moves me to the second row then the [2] accesses the 3rd letter in that string
	printf("printing myArrPtr[1]: %s\n", myArrPtr[1]);//should print Rat
	printf("printing *(myArrPtr[1] + 1): %c\n", *(myArrPtr[1] + 1));//should print a
}


void demo1DCharPtrArray(){
	char *array[3] = {"hello", "Rat", "apple"};

	printf("Array values:\n");
	for(int i = 0; i < 3; i++){
		printf("%s", array[i]);
		printf("\n");
	}

	char **myArrPtr; //this creates a pointer that can store the address of a pointer.. Hence, the double pointer. See Slide 25 in Lecture 13
					//If the type of the array element was int, then I need an int*
					//Since the type of the array element is char*, then I need an char** 

	myArrPtr = array;//now I can do this assignment

	printf("printing *array: %s\n", *array);//should print hello. Remember that the name of the array
											//is the the same as the address of its first element.
											//In this case, the name of the array would be the address of the first
											//pointer in its elements so to print that string, I need to dereference
											//array 




	printf("printing *myArrPtr after myArrPtr=array: %s\n", *myArrPtr);//same reasoning as above

	printf("printing array[0]: %s\n", array[0]);//should print hello. This is the same as printing *array
	printf("printing array[2]: %s\n", array[2]);//should print apple
	printf("printing *(myArrPtr + 1): %s\n", *(myArrPtr + 1));//should print Rat
	printf("printing *(myArrPtr + 1)[2]: %c\n", (*(myArrPtr + 1))[2]);//should print t .. The *(myArrPtr +1) moves me to the second row then the [2] accesses the 3rd letter in that string
	printf("printing myArrPtr[1]: %s\n", myArrPtr[1]);//should print Rat
	printf("printing *(myArrPtr[1] + 1): %c\n", *(myArrPtr[1] + 1));//should print a
}

int main(){

	printf("========demo1DIntArray========\n");
	demo1DIntArray();
	printf("========demo1DCharArray========\n");
	demo1DCharArray();
	printf("==========demo2DCharArray=======\n");
	demo2DCharArray();
	printf("========demo1DCharPtrArray=========\n");
	demo1DCharPtrArray();

	return 0;
	
}