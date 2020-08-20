/*

CS 340 Assignment #4 (Part 2) - Using  Dijkstra's Algorithm to solve the matrices.

Prajna Chakma  (Kevin)
200361931

===Code References from===
DATA STRUCTUERS AND ALGORITHIM ANALYSIS IN C++ (FOURTH EDITION)
	by Mark Allen Weiss


*/
#include <iostream>
#include <limits.h>

// Defining the matrix(AKA the array size of the search algorithim)
#define mSize 5

using namespace std;

int array2[];

// the "findsSV" integer function will create the search to count up the array 
// it will find the smallest value within the array which will display the shortest length in a matrix
int findSV(int array1[], bool size1[])
{
	// sValue integer will allow me to create a value to find the minimum inputs within the matrix
	int sValue = INT_MAX, valueInput;

	// This for loop, will search through the defined size of the matrix set by me.
	// #define mSize 5 ---- I wanted the values within the array to be 5.
	for (int i = 0; i < mSize; i++)
	{
		// This if statement will only apply if the boolean value will stop searching up the array.
		// and if the array values are less than or equal to the maxinput
		// int sValue = INT_MAX, valueInput;
		if (size1[i] == false && array1[i] <= sValue)
		{
			// sValue will now equal the values within the array. (matrix)
			sValue = array1[i], valueInput = i;
		}
	}
	return sValue;
}


// This void function will use the "findSV"... Here I can display the outputs of the arrays.
void Algo1(int matrix[mSize][mSize], int indexValue)
{
	// This bool value will be used to show the matrix size value
	bool size1[mSize]; 

	// This integer array1 will input the values of what "size1" has
	int array1[mSize]; 


	// Basic for loop to count up and find the values within array1
	for (int i = 0; i < mSize; i++)
	{
		// Reference code from Previous Labs
		// It uses the array1 to allow the boolean size1 to maintain the inputs in its array
		array1[i] = INT_MAX, size1[i] = false;

		// and keeping indexValue = 0 will allow it to start from the start//
		array1[indexValue] = 0;
	}

	// the for loop will go down the array values chosen from mSize which is 5
	for (int j = 0; j < mSize - 1; j++) 
	{
		//cmpute1 calls the 'findSV' function to go down the array to find the smallest value
		int cmpute1 = findSV(array1, size1);

		// the for loop will go up the mSize values set = 5
		for (int i = 0; i < mSize; i++)
		{
			// this will allow the findSV to be used within the size1 array to project the min values when we print them.
			size1[cmpute1] = true;

			// Reference code from lab & StacksOverFlow Forums
			// this if-statement will only go through if, the values within the array matrix do not equal the size of the matrice
			// It will also not go through if, the values are not found from end to end.
			if (!size1[i] && matrix[cmpute1][i] && array1[cmpute1] != INT_MAX && array1[cmpute1] + matrix[cmpute1][i] < array1[i])
			{
				// total sum weight of the flow to the minimum value is not reached.
				array1[i] = array1[cmpute1] + matrix[cmpute1][i];
			}	
		}
	}

	
	// we will print out the matrix and the shortest values with the Dijkstra's Algorithm
	cout << "Matrix " << "\t" << "shortest Distance" << endl;
	for (int i = 0; i < mSize; i++)
	{
		cout << i << "\t" << array2[i] << endl;// prints the matrtix
	}

	
}


int main()
{
	// printing the matrix with the shortest values.
	int matrix[mSize][mSize] = {{ 0, 3, 0, 7, 0 },{ 3, 0, 0, 10, 0 },{ 0, 7, 0, 0, 2 },{ 0, 0, 7, 0, 0 },{ 0, 7, 6, 7, 0 }};

	// calling the algo function for the print.
	Algo1(matrix, 0);

	return 0;
}

// IT's supposed to print the matrix values and the shortest distances on due with following the Dijkstra's Algorithm.. however it did not compile