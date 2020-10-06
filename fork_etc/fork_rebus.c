#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {

	int i;
	pid_t pid;

	printf("Bezim\n");
	for (i=0;i<3;i++) {
		pid=fork();
		if (pid<0) {
			printf("Chyba pri fork\n");
			exit(1);
		}
		if (!pid) {
			printf("fork!\n");
		}
	}
}

