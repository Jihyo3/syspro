#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void alarmHandler();
int main() {
	unsigned int alarm(unsigned int sec);
	signal(SIGALRM, alarmHandler);
	alarm(5);
	printf("Loop Start\n");
	while (1) {
		sleep(1);
		printf("1 second\n");
	}
	printf("not running\n");
}
void alarmHandler(int signo) {
	printf("Wake up\n");
	exit(0);
}
