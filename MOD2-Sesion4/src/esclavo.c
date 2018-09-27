#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<math.h>

int main(int argc, char *argv[]){

	char buffer[20];
	bool es_primo=true;
	int limite_inferior=atoi(argv[1]);
	int limite_superior=atoi(argv[2]);	

	for(int i=limite_inferior; i<=limite_superior; i++){
		for(int x=2; (x<=sqrt(i)) && es_primo; x++){
			if(i%x==0){
				sprintf(buffer,"%i", i);
				//system("sleep 1");
				//write(STDOUT_FILENO,buffer,strlen(buffer));
				write(STDOUT_FILENO, &i, sizeof(int));
				strcpy(buffer, "");
		}
	}
	exit(0);
}
