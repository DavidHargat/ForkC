#define _GNU_SOURCE
#include <sys/wait.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STACK_SIZE (1024 * 1024)

// Error checking excluded for clarify

void err(char *msg){
	printf("error: %s\n", msg);
	exit(EXIT_FAILURE);
}

static int clonefunc(void *arg){
	printf("child *%d\n", getpid());
	return 0;
}

int main(int argc, char *argv[])
{
	char *stack;
	pid_t pid;

	// allocate memory for the clone
	stack = malloc(STACK_SIZE);
	
	if(stack==NULL)
		err("malloc");

	// point to the top (end) of the stack.
	pid = clone(clonefunc, (stack+STACK_SIZE), SIGCHLD, argv[1]);

	if(pid==-1)
		err("clone");

	printf("parent *%d\n", getpid());

	// (ensure the clone executes before the program ends)
	sleep(2);

	exit(EXIT_SUCCESS);
}

