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

void bsort(int array[], int size, int& cost)
{
	for(int i = 0; i < size-1; i++)
	{
		for(int j = 0; j < size - i - 1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				swap(arr[j], arr[j+1]);
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
		while(j >= 0 && arr[j] > value)
		{
			arr[j+1] = arr[j];
			j = j-1;
			cost++;
		}
		arr[j+1] = value;
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
			if(arr[j] < arr[min])
			{
				min = j;
			}
			cost++;
		}
		swap(arr[min], arr[j]);
	}
}
