#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	int pid, gid;
	printf("PARENT: PID = %d GID = %d\n", getpid(), getpgrp());
	pid = fork();
	if(pid == 0) {
		printf("CHILD: PID = %d GID = %d\n", getpid(), getpgrp());
	}
}

