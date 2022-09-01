/******************************************************************************
* FILE: ser_mm.c
* DESCRIPTION:  
*   Serial Matrix Multiply - C Version
* AUTHOR: Blaise Barney
* LAST REVISED: 04/12/05
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NRA 62          /* number of rows in matrix A */
#define NCA 15       /* number of columns in matrix A */
#define NCB 7        /* number of columns in matrix B */

int main(int argc, char *argv[])
{
int    i, j, k;         /* misc */
double a[NRA][NCA],     /* matrix A to be multiplied */
       b[NCA][NCB],        /* matrix B to be multiplied */
       c[NRA][NCB];     /* result matrix C */

printf("Starting serial matrix multiple example...\n");
printf("Using matrix sizes a[%d][%d], b[%d][%d], c[%d][%d]\n",
        NRA,NCA,NCA,NCB,NRA,NCB);

clock_t t;
t = clock();
printf("Timer starts\n");

/* Initialize A, B, and C matrices */
printf("Initializing matrices...\n");
for (i=0; i<NRA; i++)
   for (j=0; j<NCA; j++)
      a[i][j]= i+j;
for (i=0; i<NCA; i++)
   for (j=0; j<NCB; j++)
      b[i][j]= i*j;
for(i=0;i<NRA;i++)
   for(j=0;j<NCB;j++)
      c[i][j] = 0.0;


t = clock() - t;
double time_taken = ((double)t)/CLOCKS_PER_SEC; // calculate the elapsed time

/* Perform matrix multiply */
printf("Performing matrix multiply...\n");
for(i=0;i<NRA;i++)
   for(j=0;j<NCB;j++)
      for(k=0;k<NCA;k++)
         c[i][j]+= a[i][k] * b[k][j];


t = clock() - t;
double time_taken1 = ((double)t)/CLOCKS_PER_SEC; // calculate the elapsed time

printf("Here is the result matrix:");
for (i=0; i<NRA; i++) { 
   printf("\n"); 
   for (j=0; j<NCB; j++) 
      printf("%6.2f   ", c[i][j]);
   }

printf("\n");

printf("Timer Initialize \n");
printf("The program took %f seconds to execute \n", time_taken);

printf("Timer Performing \n");
printf("The program took %f seconds to execute \n", time_taken1);

printf("Timer ends \n");
t = clock() - t;
double time_taken2 = ((double)t)/CLOCKS_PER_SEC; // calculate the elapsed time
printf("The program took %f seconds to execute \n", time_taken2);
printf ("\nDone.\n");
}