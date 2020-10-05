#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {

	int i;
	int status;
	int fd_new;
	pid_t pid,pid_wait;

	printf("Bezim\n");
	pid=fork();
	if (pid<0) {
		printf("Chyba pri fork\n");
		exit(1);
	}
	if (pid) {
		// Parent proces
		printf("Ja som parent, child proces ma pid %d\n",pid);
		printf("Čakám na ukončenie child procesu\n");
		pid_wait=wait(&status);
		printf("wait vratil %d, exit status==%d\n",pid_wait,WEXITSTATUS(status));	
	}
	else {
		fd_new=open("out.txt",O_CREAT|O_WRONLY,0666);
		if (fd_new<0) {
			perror("open");
			exit(1);
		}
		if (dup2(fd_new,1)) {
			perror("open");
			exit(1);
		}
		// teraz stdout (fd==1) smeruje do rovnakeho otvoreneho suboru ako fd_new
		if (execl("/bin/ls","/bin/ls","-l",NULL)) {
			perror("execl");
			close(fd_new);
			exit(1);
		}
		// Kod umiestneny tu sa nikdy nevykona
		
	}	
}

