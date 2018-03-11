#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <fstream>

using namespace std;

void shuffle(int arr[], int size)
{
   srand(time(0));
   int randLoc;
   for(int i = 0; i < size; i++)
   {
      randLoc = rand() % size;
      swap(arr[i], arr[randLoc]);
   }
}

void swap(int& a, int& b)
{
   int temp = a;
   a = b;
   b = temp;
}

int select_partition(int array[], int size) 
{
	return ((size/2) + 1);
}

int find_median( int array[], int size)
{
	int less, greater;
	for ( int i = 0; i < size; i++ )
	{
		less = 0;
		greater = 0;
		for (int j = 0; j < size; j++ )
		{
			if ( array[j] < array[i]) { less++; }
			else if (array[j] > array[i]) { greater++;}
		}
		if ( less == greater || less == greater + 1 || less == greater - 1 ) { return i; }
	}
}

void bsort(int array[], int size, int& cost)
{
	for(int i = 0; i < size-1; i++)
	{
		for(int j = 0; j < size - i - 1; j++)
		{
			if(array[j] > array[j+1])
			{
				swap(array[j], array[j+1]);
			}
			cost++;
		}
	}
}

void isort(int array[], int size, int& cost)
{
	int value;
	for (int i = 0; i < size; i++)
	{
		int j = i - 1;
		value = array[i];
		cost++;
		while(j >= 0 && array[j] > value)
		{
			array[j+1] = array[j];
			j = j-1;
			cost++;
		}
		array[j+1] = value;
	}
}

void ssort(int array[], int size, int& cost)
{
	int min;
	for(int i = 0; i < size - 1; i++)
	{
		min = i;
		for(int j = i+1; j < size; j++)
		{
			if(array[j] < array[min])
			{
				min = j;
			}
			cost++;
		}
		swap(array[min], array[i]);
	}
}

void msort(int array[], int size, int& cost)
{

	if(size > 1)
	{
		int middle = size / 2;
		int temp1[middle];
		int temp2[size - middle];

		for(int i = 0; i < middle; i++)
		{
			temp1[i] = array[i];
		}
		for(int j = 0; j < size - middle; j++)
		{
			temp2[j] = array[j + middle];
		}
		msort(temp1, middle, cost);
		msort(temp2, size - middle, cost);
		
		int k = 0;
		int n = 0;
		int p = 0;
		while(k < middle && n < size - middle)
		{
			if(temp1[k] <= temp2[n])
			{
				array[p] = temp1[k];
				k++;
			}
			else
			{
				array[p] = temp2[n];
				n++;
			}
			p++;
			cost++;
		}
	
		while (k < middle)
		{
			array[p] = temp1[k];
			k++;
			p++;
		}
		while(n < size - middle)
		{
			array[p] = temp2[k];
			n++;
			p++;
		}	
	}
	cout << "Size: " << size << endl;
	for (int i = 0; i < size; i++ )
	{
		cout << array[i] << endl;
	}
}

void my_qsort( int array[], int size, int& cost, int (*choose_pivot)(int array[], int size) )
{
	if ( size > 1 ) {
		int l,r = 1;
		int* arr_left = NULL;
		arr_left = new int[l];
		int* arr_right = NULL;
		arr_right = new int[r];
		int part = choose_pivot( array, size );
		int pivot = array[part];
		for ( int i = 0; i < size; i++ ) 
		{
			if ( array[i] < pivot ) 
			{
				arr_left[l-1] = array[i];
				l++;
			}
			else
			{
				arr_right[r-1] = array[i];
				r++;
			}		
			cost++;
		}
		
		my_qsort( arr_left, l, cost, choose_pivot );
		my_qsort( arr_right, r, cost, choose_pivot );
		int i = 0;
		for (int j = 0; j < l; j++ ) 
		{
			array[i] = arr_left[j];
			i++;
		}
		array[l] = pivot;
		i++;
		for (int j = 0; j < r; j++ )
		{
			array[i] = arr_right[j];
			i++;
		}
		delete [] arr_left;
		arr_left = NULL;
		delete [] arr_right;
		arr_right = NULL;
	}
}