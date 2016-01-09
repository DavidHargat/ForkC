#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(char argc, char **argv){

	pid_t pid;
	
	pid = fork();

	if(pid == -1)
		printf("%s", "[!] fork error\n");

	printf("pid: %d\n", pid);

	return 0;
}
