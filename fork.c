#define _GNU_SOURCE
#include <sys/wait.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void err(char *msg){
	printf("error: %s\n", msg);
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]){
	pid_t pid;

	pid = fork();

	if( pid == -1 )
		err("fork");

	if( pid != 0 )
		printf("parent *%d\n", getpid());
	
	if( pid == 0 )
		printf("child  *%d\n", getpid());

	sleep(2);

	exit(EXIT_SUCCESS);
}

