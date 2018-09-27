#include <sys/types.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <signal.h> 
#include <errno.h> 
#include <stdlib.h> 

static int c1=0, c2=0, c3=0; 


static void signal_e(int sigNum){ 
	if(sigNum == SIGHUP){ 
		c1++; 
		printf("La señal %d se ha recibido %d veces.\n", sigNum, c1); 
    	}else if(sigNum == SIGINT){ 
		c2++; 
		printf("La señal %d se ha recibido %d veces.\n", sigNum, c2); 
    	}else if(sigNum == SIGCONT){ 
		c3++; 
		printf("La señal %d se ha recibido %d veces.\n", sigNum, c3); 
	} 
} 

int main(int argc, char *argv[]){ 
    	struct sigaction sig; 
    	if(setvbuf(stdout,NULL,_IONBF,0)){ 
    		perror("\nError en setvbuf"); 
    	} 
	 
	sig.sa_handler=signal_e; 
	sigemptyset (&sig.sa_mask); 
	sig.sa_flags = SA_RESTART; 

	if( sigaction(SIGHUP,&sig,NULL) <0){ 
		perror("\nError al intentar establecer el manejador de señal"); 
		exit(-1); 
    	} 
	if( sigaction(SIGINT,&sig,NULL) <0){ 
		perror("\nError al intentar establecer el manejador de señal"); 
		exit(-1); 
    	} 
	if( sigaction(SIGCONT,&sig,NULL) <0){ 
		perror("\nError al intentar establecer el manejador de señal"); 
		exit(-1); 
    	} 

	while(1); 

}
