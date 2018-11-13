#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dlfcn.h>
#include <time.h>
#include <sys/time.h>

double timestamp(){
	
	struct timeval val;
	
	gettimeofday(&val, (struct timezone * ) 0 );
	return ((double) (val.tv_sec + (val.tv_usec /1000000.0)) );
	
}