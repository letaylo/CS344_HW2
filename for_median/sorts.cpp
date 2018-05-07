#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <fstream>

using namespace std;

int find_median(int array[], int start, int size, int n);
int partition(int array[], int left, int right, int pivotIndex);
int pivot(int array[], int left, int right);
int select_partition(int array[], int start, int size, int n);

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
   if ( a != b) {
      int temp = a;
      a = b;
      b = temp;
   }
}

int select_partition(int array[], int start, int size, int n) 
{
	return start;
}

int find_median( int array[], int left, int right, int n)
{
	//int left = start;
	//int right = start + size - 1;
	int pivotIndex;
	while(1) {
		if (left == right) return left;
		pivotIndex = pivot(array, left, right);
		pivotIndex = partition(array, left, right, pivotIndex);
		if (n == pivotIndex) return n;
		else if (n < pivotIndex) right = pivotIndex - 1;
		else left = pivotIndex + 1;
	}
}

int partition( int array[], int left, int right, int pivotIndex) {
    int pivotValue = array[pivotIndex];
    swap(array[pivotIndex], array[right]);
    int storeIndex = left;
    for (int i = left; i < right-1; i++) {
        if (array[i] < pivotValue) {
	    swap(array[storeIndex], array[i]);
	    storeIndex++;
	}
    }
    swap(array[right],array[storeIndex]);
    return storeIndex;
}

int partition5(int array[], int left, int right) {
    int l,g = 0;
    for (int i = left; i <= right; i++) {
        for (int j = left; j <= right; j++) {
	    if (array[i] < array[j]) g++;
	    if (array[i] > array[j]) l++;
	}
	if ( l == g || l - g == 1 || g - l == 1 ) return i;
	l = 0;
	g = 0;
    }
}

int pivot( int array[], int left, int right) {
    //int size = right - left + 1;
    int subRight;
    int median5;
    int temp;
    int temp1;
    if (right-left < 5 ) return partition5(array,left,right);
    for (int i = left; i < right; i=i+5) {
	subRight = i+4;
	if (subRight > right) subRight = right;
	median5 = partition5(array, i, subRight);
	temp = (i-left)/5;
	swap(array[median5],array[temp]);
    }
    temp1 = left + (right - left)/10;
    temp = left + (right - left)/5;
    int ans = find_median(array, left, temp, temp1);
    return ans;
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

void msort(int array[], int start, int size, int& cost)
{

	if(size > 1)
	{
		int middle = size / 2;
		int other = size - middle;
                int lstart = start;
                int rstart = start+middle;

		
		msort(array, lstart,  middle, cost);
		msort(array, rstart, other, cost);
		
		int k = lstart;
		int n = rstart;
		int p = start;
		int temp = array[k];
		while(k < rstart && n < rstart+other)
		{
			if(array[k] > array[n])
			{
				array[p] = array[n];
				p++;
			}
			else
			{
				k++;
				temp = array[k];
			}
			p++;
			cost++;
		}
	
		while (k < rstart)
		{
			array[p] = array[k];
			k++;
			p++;
		}
		while(n < rstart+other)
		{
			array[p] = array[n];
			n++;
			p++;
		}	
	}
	//cout << "Size: " << size << endl;
	//for (int i = 0; i < size; i++ )
	//{
	//	cout << array[i] << endl;
	//}
}

void my_qsort( int array[], int start, int size, int& cost, int (*choose_pivot) (int[] , int, int, int) )
{
    int right = start + size - 1;
    if (size == 2) {
	if (array[start] > array[start+1]) {
	    swap(array[start],array[start+1]);
	}
	cost++;
    }else if (size > 2) {
	int pivot = choose_pivot(array, start, right, 0);
	int x = array[pivot];
        swap(array[pivot], array[start + size-1]);
        int i = start-1;
        for (int j = start; j < (start + size - 1); j++) {
	    if (array[j] < x) {
		i++;
	        swap(array[i],array[j]);
	    }
	    cost++;
        }
        swap(array[i+1], array[start + size-1]);
	int size_l = i + 1 - start;
	int size_r = size - size_l - 1;
	int start_r = i+2;
	if (i > 0) {my_qsort( array, start, size_l, cost, choose_pivot );}
	//return;
	if (size_r > 1 && start_r < start + size) {my_qsort( array, start_r, size_r, cost, choose_pivot );}
        
    }
}
