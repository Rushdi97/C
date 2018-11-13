/* Rushdi AL-Hasan
project 6
due: 4/23/18
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dlfcn.h>
#include <time.h>
#include <sys/time.h>

int main(int argc, char **argv){
	
	alarm(60);
	
	void* handler;
	char* error;
	double (*noarg)();
	double (*onearg)(double);
	double (*twoarg)(double, double);
	double x, y, z;
	
	handler = dlopen(argv[1], RTLD_LAZY);
	if(!handler){
		fprintf(stderr, "%s\n", dlerror());
		exit(1);
	}
	
	if (argc == 3){
		noarg = dlsym(handler,argv[2]);
			if((error = dlerror()) != NULL){
				fprintf(stderr, "%s\n", error);
				exit(1);
			}
		x = noarg();
		printf("%f\n", x);
			
		}
	if (argc == 4){
		onearg = dlsym(handler,argv[2]);
			if((error = dlerror()) != NULL){
				fprintf(stderr, "%s\n", error);
				exit(1);
			}
		y = onearg(atof(argv[3]));
		printf("%f\n", y);
			
		}
		
	if (argc == 5){
		twoarg = dlsym(handler,argv[2]);
			if((error = dlerror()) != NULL){
				fprintf(stderr, "%s\n", error);
				exit(1);
			}
		z= twoarg(atof(argv[3]), atof(argv[4]));
		printf("%f\n", z);
			
		}
	dlclose(handler);
	return 0;
	}