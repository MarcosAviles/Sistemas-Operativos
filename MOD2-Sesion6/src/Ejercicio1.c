#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdbool.h>	

int main(int argc, char *argv[]) {
	if(argc != 4) {
		printf("Argumentos introducidos incorrectos: %s ordenDeLinux simbolo nombreDeArchivo\n", argv[0]);
		exit(1);
	} else {
		char *str_command;
		char *str_file;
		int fd;

		str_command = argv[1];
		str_file = argv[3];

		if (strcmp(argv[2], "<") == 0) {
			fd = open (str_file, O_RDONLY);
			close(STDIN_FILENO);
			if (fcntl(fd, F_DUPFD, STDIN_FILENO) == -1 ) perror ("Error");
		} else if (strcmp(argv[2], ">") == 0) {
			fd = open (str_file, O_CREAT|O_WRONLY);
			close (STDOUT_FILENO);
			if (fcntl(fd, F_DUPFD, STDOUT_FILENO) == -1 ) perror ("Error");
		} else {
			printf("Debe ponerse las comillas dobles (" ")para el simbolo\n", argv[2]);
			exit(1);

		}
	    if( (execlp(str_command, "", NULL) < 0)) {
			perror("Error en el execlp\n");
			exit(-1);
		}
		close(fd);
	}
}
