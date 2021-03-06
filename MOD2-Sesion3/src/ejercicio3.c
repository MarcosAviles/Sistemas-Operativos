#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


int main(int argc, char *argv[]){

/*
Jerarquía de procesos tipo 1
*/
	int nprocs=21, i;
	pid_t childpid;
	for (i=1; i < nprocs; i++) {
		if((childpid = fork()) < 0){
			fprintf(stderr, "Could not create child %d: %s\n",i,strerror(errno));
			exit(-1);
		}
		if(childpid==0){
			printf("Soy el Hijo: %d", i);
			printf(" Mi PID es: %d", getpid());
			printf(" El PID de mi padre es: %d\n", getppid());
			exit(0);
		}
		if (!childpid){
			break;
		}
	}
}
