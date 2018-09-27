#include<sys/types.h>	 
#include<unistd.h>		 
#include<sys/stat.h> 
#include<fcntl.h> 
#include<stdio.h> 
#include<errno.h> 
#include<string.h> 
#include<dirent.h>
#include<stlib.h>

int main(int argc, char *argv[])
{

if (argc != 3){
	printf("Debe introducir 2 argumentos: <directorio> y <permisos>\n");
	exit(1);
}

DIR *dirp;
struct dirent *direntp;
struct stat atributos;
int mode;

mode=strtol(argv[2], 0, 8);

dirp = opendir(argv[1]);

if (dirp == NULL){
	printf("Error: No se puede abrir el directorio\n");
	exit(2);
}

// Falta imprimir ("un ls -l") para los atributos originales
while((direntp = readdir(dirp)) != NULL){

	if(direntp->d_name[0]!='.'){
			stat(direntp->d_name,&atributos);
			if((chmod(direntp->d_name, mode))<0){
				printf("\t %s \t :", direntp->d_name);
				exit(-1);
			}
			printf("\t %s \t :", direntp->d_name);
			stat(direntp->d_name,&atributos);
		printf("\n");
	}
}
// Falta imprimir ("un ls -l") para los atributos nuevos
closedir(dirp);

return 0;
}
