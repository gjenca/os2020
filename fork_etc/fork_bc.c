#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

#define PRIKLAD "6*11*(2+2)\n"

int main() {

	int i,n;
	pid_t pid;
	int pipefd_vyr[2];
	int pipefd_vys[2];
	char buf[50];

	if (pipe(pipefd_vyr)) {
		perror("pipe");
		exit(1);
	}
	if (pipe(pipefd_vys)) {
		perror("pipe");
		exit(1);
	}
	pid=fork();
	if (pid<0) {
		perror("fork");
		exit(1);
	}
	if (pid) {
		printf("Ja som parent\n");
		close(pipefd_vys[1]);
		close(pipefd_vyr[0]);
		write(pipefd_vyr[1],PRIKLAD,11);
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

