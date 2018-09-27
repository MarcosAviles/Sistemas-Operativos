#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>


int main(int argc, char *argv[]){

	if (argc != 2){
		perror("\nIntroduzca un numero como parametro\n");
		exit(1);
	}
	int numero = atoi(argv[1]);
	pid_t pid;
	pid=fork();
	

	if(pid==0){
		printf("\n(Hijo) Mi PID es: %d", getpid());
		if(numero%2==0){
			printf("\n(Hijo)El numero introducido es par");
		}
		else{
			printf("\n(Hijo)El numero introducido no es par");
		}
	}
	else{
		printf("\n(Padre) Mi PID es: %d", getppid());
		if(numero%4==0){
			printf("\n(Padre)El numero introducido es multiplo de 4");
		}
		else{
			printf("\n(Padre)El numero introducido no es multiplo de 4");
		}
	}
	return 0;	
}
