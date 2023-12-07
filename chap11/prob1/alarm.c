#include <stdio.h>
#include <unistd.h>

int main() {
	unsigned int alarm(unsigned int sec);
	alarm(5);
	printf("Loop start \n");
	while (1) {
		sleep(1);
		printf("1 second \n");
	}
	printf("not running \n");
}
