/******************************************************************************
* FILE: omp_mm.c
* DESCRIPTION:  
*   OpenMp Example - Matrix Multiply - C Version
*   Demonstrates a matrix multiply using OpenMP. Threads share row iterations
*   according to a predefined chunk size.
* AUTHOR: Blaise Barney
* LAST REVISED: 06/28/05
******************************************************************************/
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NRA 62                 /* number of rows in matrix A */
#define NCA 15                 /* number of columns in matrix A */
#define NCB 7                  /* number of columns in matrix B */

int main (int argc, char *argv[]) 
{
int	tid, nthreads, i, j, k, chunk;
double	a[NRA][NCA],           /* matrix A to be multiplied */
	b[NCA][NCB],           /* matrix B to be multiplied */
	c[NRA][NCB];           /* result matrix C */

chunk = 10;                    /* set loop iteration chunk size */
clock_t t;
double time_taken, time_taken1;

/*** Spawn a parallel region explicitly scoping all variables ***/
#pragma omp parallel shared(a,b,c,nthreads,chunk) private(tid,i,j,k,t,time_taken)
{
  tid = omp_get_thread_num();
  if (tid == 0)
    {
    nthreads = omp_get_num_threads();
    printf("Starting matrix multiple example with %d threads\n",nthreads);
    printf("Initializing matrices...\n");
    #pragma omp critical(Start)
      t = clock();
      printf("Timer starts\n");
    }
  /*** Initialize matrices ***/
  #pragma omp for schedule (static, chunk) 
  for (i=0; i<NRA; i++)
    for (j=0; j<NCA; j++)
      a[i][j]= i+j;
  #pragma omp for schedule (static, chunk)
  for (i=0; i<NCA; i++)
    for (j=0; j<NCB; j++)
      b[i][j]= i*j;
  #pragma omp for schedule (static, chunk)
  for (i=0; i<NRA; i++)
    for (j=0; j<NCB; j++)
      c[i][j]= 0;

  if (tid == 0){
    #pragma omp critical(Initialize)
      t = clock() - t;
      time_taken = ((double)t)/CLOCKS_PER_SEC; // calculate the elapsed time
  }

  /*** Do matrix multiply sharing iterations on outer loop ***/
  /*** Display who does which iterations for demonstration purposes ***/
  #pragma omp for schedule (static, chunk)
  for (j=0; j<NCB; j++){
    char file_name[150];
    sprintf(file_name, "./result/%d_columna.txt", j);
    FILE *out_file = fopen(file_name, "w");
    for(i=0; i<NRA; i++){       
      for (k=0; k<NCA; k++){
        c[i][j] += a[i][k] * b[k][j];
        }
        fprintf(out_file, "%6.2f \n", c[i][j]);
      }
    fclose(out_file);
    }
  }   /*** End of parallel region ***/
  t = clock() - time_taken;
  time_taken1 = ((double)t)/CLOCKS_PER_SEC;

  printf("\n");
  printf("Timer Initialize \n");
  printf("The program took %f seconds to execute \n", time_taken);

  printf("Timer Performing \n");
  printf("The program took %f seconds to execute \n", time_taken1);
}

