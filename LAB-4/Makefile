##############################################################################
# FILE: Makefile
# DESCRIPTION: 
#   Makefile for OpenMP and Serial C Language Matrix Multiply codes
# AUTHOR: Blaise Barney
# MODIFIED: Marisa Gil
# LAST REVISED:  09/26/11
###############################################################################

#Uncomment your choice of compiler
#CC    =   icc
CC    =   gcc
#CC    =   pathcc
#CC    =   pgcc

#Add your choice of flags
FLAGS   =   -O1

all:	mm		\
	ser_mm          \
	omp_mm_base	\
	omp_mm_columns 	\
	omp_mm_independent \
	omp_mm_shared \
	

clean:	
	/bin/rm  -rf    \
	initial.dat     \
	final.dat       \
	mm		\
	ser_mm          \
	omp_mm_base	\
	omp_mm_columns 	\
	omp_mm_independent \
	omp_mm_shared \
        *.o	

mm: omp_mm.c
	$(CC) -fopenmp omp_mm.c -o mm

ser_mm: ser_mm.c
	${CC} ${FLAGS} ser_mm.c -o ser_mm 

omp_mm_base: omp_mm_base.c
	$(CC) -fopenmp omp_mm_base.c -o omp_mm_base

omp_mm_columns: omp_mm_columns.c
	$(CC) -fopenmp omp_mm_columns.c -o omp_mm_columns

omp_mm_independent: omp_mm_independent.c
	$(CC) -fopenmp omp_mm_independent.c -o omp_mm_independent

omp_mm_shared: omp_mm_shared.c
	$(CC) -fopenmp omp_mm_shared.c -o omp_mm_shared





