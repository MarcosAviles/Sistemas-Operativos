#include <sys/types.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <signal.h> 
#include <errno.h> 
#include <stdlib.h> 

static int contadores[31];

static void signal_e(int sigNum){ 
	contadores[sigNum]++;
	printf("\n La señal %d , se ha realizado %d veces. " , sigNum ,contadores[sigNum]);
} 

int main(){ 

    	struct sigaction sig; 
    	if(setvbuf(stdout,NULL,_IONBF,0)){ 
    		perror("\nError en setvbuf"); 
    	} 
	 
	sig.sa_handler=signal_e; 
	sigemptyset (&sig.sa_mask); 
	sig.sa_flags = SA_RESTART; 

	for(int i=1; i<=31; i++){
		contadores[i]=0;
	}

	for ( int i = 1 ; i<=60 ; i++){
		if (sigaction(i, &sig, NULL) == -1){
			printf("error en el manejador");
		}
	}while(1);

	

}
