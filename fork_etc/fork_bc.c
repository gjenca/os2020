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
	int vys;
	char buf[50];
	FILE *fpw;
	FILE *fpr;

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
		close(pipefd_vys[1]);
		close(pipefd_vyr[0]);
		fpw=fdopen(pipefd_vyr[1],"w");
		fpr=fdopen(pipefd_vys[0],"r");
		//write(pipefd_vyr[1],PRIKLAD,11);
		for (i=0;i<100;i++) {
			fprintf(fpw,"9*%d\n",i);
			fflush(fpw);// az teraz zapise, inak to zostane v buffri FILE objektu
		}
		fclose(fpw);
		for (i=0;i<100;i++) {
			fscanf(fpr,"%d\n",&vys);
			printf("9*%d=%d\n",i,vys);
		}
		fclose(fpr);
/*
		//close(pipefd_vyr[1]);
		while (1) {
			n=read(pipefd_vys[0],buf,sizeof(buf)-1);
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
*/
		
	}
	else {
		close(pipefd_vys[0]);
		close(pipefd_vyr[1]);
		dup2(pipefd_vyr[0],0);
		dup2(pipefd_vys[1],1);
		close(pipefd_vyr[0]);
		close(pipefd_vys[1]);
		if (execl("/usr/bin/bc","/usr/bin/bc",NULL)) {
			perror("execl");
			exit(-1);
		}
		// sem sa nikdy nedostane vypocet
	}	
}

