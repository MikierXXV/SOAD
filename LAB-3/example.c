#include "libfiber.h"
#include <stdio.h>

#include <unistd.h>

void fiber1()
{
	int i;
	for ( i = 0; i < 500000; ++ i )
	{
		printf( "Hey, I'm fiber #1: %d\n", i );
	}
	return;
}

void fibonacchi()
{
	int i;
	int fib[2] = { 0, 1 };
	
	/*sleep( 2 ); */
	printf( "fibonacchi(0) = 0\nfibonnachi(1) = 1\n" );
	for( i = 2; i < 1500000; ++ i )
	{
		int nextFib = fib[0] + fib[1];
		printf( "fibonacchi(%d) = %d\n", i, nextFib );
		fib[0] = fib[1];
		fib[1] = nextFib;
	}
}

void squares()
{
	int i;
	
	while(sched_handoff(0) == 0);
	
	/*sleep( 5 ); */
	for ( i = 0; i < 1000000; ++ i )
	{
		printf( "%d*%d = %d\n", i, i, i*i );
	}
}

int main()
{
	/* Initialize the fiber library */
	printf("AAAH\n");
	initFibers();
	/* Go fibers! */
	spawnFiber( &fiber1 );
	spawnFiber( &fibonacchi );
	spawnFiber( &squares );
	
	waitForAllFibers();
	
	/* The program quits */
	return 0;
}
