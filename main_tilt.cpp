#include <iostream>
#include <bits/stdc++.h>
#include <sys/time.h> 

using namespace std;

#define n 4096

double A[n][n], B[n][n], C[n][n];

int main(int argc, char** argv) { 
    
    
    // Initialize Matrices
    
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
        {
            A[i][j] = (double)rand()/ (double)RAND_MAX;
	    B[i][j] = (double)rand()/ (double)RAND_MAX;
	    C[i][j] = 0;
        }

    struct timeval start, end; 
  
    // start timer. 
    gettimeofday(&start, NULL); 
  
    // unsync the I/O of C and C++. 
    ios_base::sync_with_stdio(false);
    long TILE_SIZE = strtol(argv[1], NULL, 10);
    int i, j, k;
    // Matrix multiplication
    // #pragma omp parallel for private(i,j,k) shared(A,B,C)
    for(i = 0; i < n; i += TILE_SIZE)
        for(j = 0; j < n; j += TILE_SIZE)
            for(k = 0; k < n; k += TILE_SIZE)
            	for(int ii = i; ii < i + TILE_SIZE; ++ii)
            	    for(int jj = j; jj < j + TILE_SIZE; ++jj)
		    {
		 	// double sum = 0;
            		for(int kk = k; kk < k + TILE_SIZE; ++kk)
            		{
                	    C[ii][jj] += A[ii][kk] * B[kk][jj];
            		}
			// C[ii * N + jj] += sum;
		    }	
    
    gettimeofday(&end, NULL); 
  
    // Calculating total time taken by the program. 
    double time_taken; 
  
    time_taken = (end.tv_sec - start.tv_sec) * 1e6; 
    time_taken = (time_taken + (end.tv_usec -  
                              start.tv_usec)) * 1e-6; 
  
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(6); 
    cout << " sec" << endl;


    return 0;
}
