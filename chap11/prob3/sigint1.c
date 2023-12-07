#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void intHandler();
int main() {
	unsigned int alarm(unsigned int second);
	signal(SIGINT, intHandler);
	while (1)
		pause();
	printf("not running\n");
}

void intHandler(int signo) {
	printf("Inturrupt signal\n");
	printf("signal number : %d\n", signo);
	exit(0);
}

