/*
tarea21.c
Trabajo con llamadas al sistema del Sistema de Archivos ''POSIX 2.10 compliant''
*/

#include<unistd.h>  /* POSIX Standard: 2.10 Symbolic Constants <unistd.h> */
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>  /* Primitive system data types for abstraction	\
			   of implementation-dependent data types.
			   POSIX Standard: 2.6 Primitive System Data Types
			   <sys/types.h>
		       */
#include<sys/stat.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
char buf[20]=0;

if(argc<2) {
	printf("\nSintaxis de ejecucion: tarea2 [<nombre_archivo>]+\n\n");
	exit(-1);
}
int fd;
int fd2;
int contador=1;

if(argv[1]==NULL){
	fd=STDIN_FILENO;
}

if( (fd=open(argv[1],S_IRUSR))<0) {
	printf("\nError %d en open",errno);
	perror("\nError en open");
	exit(EXIT_FAILURE);
}


if( (fd2=open("archivo",O_CREAT|O_TRUNC|O_WRONLY,S_IRUSR|S_IWUSR))<0) {
	printf("\nError %d en open",errno);
	perror("\nError en open");
	exit(EXIT_FAILURE);
}

if(read(fd,buf,20) != 20) {
		perror("\nError en primer read");
		exit(EXIT_FAILURE);
}
while(buf[19]!=0){

	printf("Bloque: %d\n", contador);
	printf(buf, "%s\n");
	fd2<< "Bloque: "+ contador + "\n";

	if(lseek(fd2,40,SEEK_SET) < 0) {
		perror("\nError en lseek");
		exit(EXIT_FAILURE);
	}

	if(write(fd2,buf,20) != 20) {
		perror("\nError n primer write");
		exit(EXIT_FAILURE);
	}
		
	
	if(lseek(fd,80,SEEK_SET) < 0) {
		perror("\nError en lseek");
		exit(EXIT_FAILURE);
	}
	if(read(fd,buf,20) != 20) {
		perror("\nError en segundo read");
		exit(EXIT_FAILURE);
	}
	
	contador++;
}
return 0;
}
