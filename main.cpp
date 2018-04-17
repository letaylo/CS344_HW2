#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <fstream>

using namespace std;

void show( int[], int );
void shuffle( int[], int );
void swap( int&, int& );
void bsort(int array[], int size, int& cost); // bubble sort
void isort(int array[], int size, int& cost); // insertion sort
void ssort(int array[], int size, int& cost); // selection sort
void msort(int array[], int size, int& cost); // mergesort
void my_qsort(int array[], int start, int size, int& cost, int (*choose_pivot)(int [], int, int )); // quicksort
int find_median(int array[], int start, int size);
int select_partition(int array[], int start, int size);
int main( int argc, char *argv[] )
{
	if ( argc < 3 ) {
		cerr << "Usage: ./test_me <size> <filename>" << endl;
		exit(1);
	}
	int max_size;
	ofstream outfile;

	max_size = atoi( argv[1] );
	cerr << "Size = " << max_size << endl;
	cerr << "Filename = " << argv[2] << endl;
	outfile.open( argv[2] );
	for (int curr_size = 2; curr_size <= max_size; curr_size++) {
		int buffer[curr_size];
		for (int i = 0; i < curr_size; i++) {
			buffer[i] = i;
		}
		shuffle( buffer, curr_size );
		outfile << curr_size << " ";

		int cost = 0;
		bsort( buffer, curr_size, cost );
		assert( buffer[0] == 0 && buffer[curr_size-1] == curr_size-1 );
		outfile << cost << " ";
		
		shuffle( buffer, curr_size );
		
		cost = 0;
                isort( buffer, curr_size, cost );
                assert( buffer[0] == 0 && buffer[curr_size-1] == curr_size-1 );
                outfile << cost << " ";

		shuffle( buffer, curr_size );

		cost = 0;
                ssort( buffer, curr_size, cost );
                assert( buffer[0] == 0 && buffer[curr_size-1] == curr_size-1 );
                outfile << cost << " ";

		shuffle( buffer, curr_size );

		/*cost = 0;
                msort( buffer, curr_size, cost );
                assert( buffer[0] == 0 && buffer[curr_size-1] == curr_size-1 );
                outfile << cost << " ";

		shuffle( buffer, curr_size );*/

		cost = 0;
		my_qsort( buffer, 0, curr_size, cost, select_partition );
		assert( buffer[0] == 0 && buffer[curr_size-1] == curr_size-1 );
		outfile << cost << " ";

		cost = 0;
                my_qsort( buffer, 0, curr_size, cost, find_median );
                assert( buffer[0] == 0 && buffer[curr_size-1] == curr_size-1 );
		outfile << cost << endl;
		
	}
	outfile.close();
}
