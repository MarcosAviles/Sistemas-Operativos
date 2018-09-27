#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

int main(int argc, char *argv[]){
	
	int limite_inferior=atoi(argv[1]);
	int limite_superior=atoi(argv[2]);		

	int fd[2];
	pid_t pid;
	char buff[20], aux[20];
	char argumento1[20], argumento2[20];

	if (argc < 3){
		perror("Introduzca: ./maestro <inicio> <fin>\n");
	exit(-1);
}
	int i;
	for(i=0; i<2; i++){
		
		if(i==0){// calculamos el intervalo para el primer esclavo
			limite_superior=limite_inferior+(limite_superior-limite_inferior)/2;
			limite_inferior=atoi(argv[1]);
		}
		if(i==1){// en la siguiente vuelta calculamos el intervalo para el segundo esclavo
			limite_inferior=limite_superior+1;
			limite_superior=atoi(argv[2]);
		}
		sprintf(argumento1,"%i", limite_inferior);
		sprintf(argumento2,"%i", limite_superior);
		sprintf(aux,"%i", limite_superior);

		pipe(fd);
		if ( (pid= fork())<0){
			perror("fork");
			exit(1);
		}
	
		if (pid == 0){
			//Proceso hijo

			close(fd[0]);
			dup2(fd[1],STDOUT_FILENO);
			if( (execl("./esclavo","esclavo",argumento1,argumento2,NULL)<0)) {
				perror("\nError en el execl");
				exit(-1);
			}
		}else{
			//Proceso padre

			close(fd[1]);
			while(1){
				read(fd[0],buff,sizeof(int));
				if(strcmp(buff, aux)==0)
					break; // compara con el limite superior para saber
					       // si ha llegado al final.
				else
					printf ("Es primo %s \n", buff);
					close(fd[0]);
			}
		}
	}
	return 0;
}
