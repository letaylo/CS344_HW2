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

void msort(int array[], int size, int& cost)
{
	int middle = size / 2;
	if(size = 1)
	{
		break;
	}
	else
	{
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
		msort(temp1, middle);
		msort(temp2, size - middle);
	}
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
