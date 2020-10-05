#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {

	int i;
	int status;
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
		for (i=0;i<10;i++) {
			printf("Ja som child\n");
		}
		exit(1);
	}	
}

