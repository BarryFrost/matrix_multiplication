# Matrix_multiplication
## Matrix multiplication from native to optimization
Use different optimization way of matrix multiplication.
- native
- loop blocking
- loop reordering
- parallel execution
- compiler flags optimization
Use `gettimeofday` before and after the multiplication to record the excution time.

## Native matrix multiplication
native : Time taken by program is : 928.619283 sec  
```C++
for(i = 0; i < n; ++i)
        for(j = 0; j < n; ++j)
            for(k = 0; k < n; ++k)
            {
                C[i][j] += A[i][k] * B[k][j];
            }

```
## Loop blocking (tiling)
loop tiling (block size:  32): Time taken by program is : 229.647346 sec  
loop tiling (block size:  64): Time taken by program is : 262.295068 sec
```C++
for(i = 0; i < n; i += TILE_SIZE)
        for(j = 0; j < n; j += TILE_SIZE)
            for(k = 0; k < n; k += TILE_SIZE)
                for(int ii = i; ii < i + TILE_SIZE; ++ii)
                    for(int jj = j; jj < j + TILE_SIZE; ++jj)
                    {
                        for(int kk = k; kk < k + TILE_SIZE; ++kk)
                        {
                            C[ii][jj] += A[ii][kk] * B[kk][jj];
                        }
                    }
```
## Loop reordering
loop reordering : Time taken by program is : 147.967984 sec  
```C++
for(i = 0; i < n; ++i)
        for(k = 0; k < n; ++k)
            for(j = 0; j < n; ++j)
            {
                C[i][j] += A[i][k] * B[k][j];
            }

```
## Vectorization using compiler flags
using optimization flag will enable vectorization automatically.  
```
g++ -O3 main.c -o main_flagsO3
```
O3 flag : Time taken by program is : 19.329983 sec  
or only use vectorization only
```
g++ -ftree-vectorize main.c -o main_flagsVectorize
```
To disable vectorization
```
g++ -fno-tree-vectorize main.c -o main
```
# Reference 
The lab is referenced to Vipul Vaibhaw's [performance engineering article](https://vaibhaw-vipul.medium.com/matrix-multiplication-optimizing-the-code-from-6-hours-to-1-sec-70889d33dcfa) and his [source code](https://github.com/vaibhawvipul/performance-engineering).
