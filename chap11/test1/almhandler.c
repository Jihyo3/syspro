#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
void alarmHandler();

int main() {
	signal(SIGALRM, alarmHandler);
	alarm(5);
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
