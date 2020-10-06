#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {

	int i,n;
	pid_t pid;
	int pipefd[2];
	char buf[50];

	printf("Bezim\n");
	if (pipe(pipefd)) {
		perror("pipe");
		exit(1);
	}
	pid=fork();
	if (pid<0) {
		printf("Chyba pri fork\n");
		exit(1);
	}
	if (pid) {
		printf("Ja som parent\n");
		close(pipefd[1]);
		while (1) {
			n=read(pipefd[0],buf,sizeof(buf)-1);
			if (!n) { // end of file (== zapisovy koniec rury je zavrety)
				break;
			}
			if (n<0) {
				perror("read");
				exit(1);
			}
			// n je pocet bytov precitanych z rury
			write(1,buf,n);
		}
		
	}
	else {
		printf("Ja som child\n");
		close(pipefd[0]);
		write(pipefd[1],"AHOJ\n",5);
	}	
}

