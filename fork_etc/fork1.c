#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {

	int i;
	pid_t pid;

	printf("Bezim\n");
	pid=fork();
	if (pid<0) {
		printf("Chyba pri fork\n");
		exit(1);
	}
	if (pid) {
		for (i=0;i<500;i++) {
			printf("Ja som parent, child proces ma pid %d\n",pid);
		}
	}
	else {
		for (i=0;i<500;i++) {
			printf("Ja som child\n");
		}
	}	
}

