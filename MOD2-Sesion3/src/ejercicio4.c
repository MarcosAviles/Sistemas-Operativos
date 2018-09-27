#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


int main(int argc, char *argv[]){

	int nprocs=5, i;
	pid_t childpid;
	for (i=0; i < nprocs; i++) {
		if((childpid = fork()) < 0){
			perror("Error en crear hijo\n");
			exit(-1);
		}
		if(childpid==0){
			printf("Soy el Hijo: %d\n", getpid());
			exit(0);
		}
		if (!childpid){
			break;
		}
	}
	for(i=1; i<nprocs; i++){
		childpid = wait();
		printf("Ha finalizado mi hijo con PID = %i\n", childpid);
		printf("Solo me quedan %i hijos vivos\n", nprocs-i);
	}
	
}
