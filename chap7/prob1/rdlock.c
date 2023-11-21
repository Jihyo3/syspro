#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "student.h"

int main(int argc, char *argv[]) {
    int fd, id;
    struct student record;
    struct flock lock;

    if(argc < 2) {
        printf(stderr, "How to use : %s File \n", srgv[0]);
        exit(1);
    }
    
    if((fd = open(argv[1], O_RDONLY)) == -1) {
        perror(argv[1]);
        exit(2);
    }

    printf("\nEnter StudentID to search : ");
    while (scanf("%d", &id) == 1) {
        lock.l type = F_RDLCK;
        lock.l whence = SEEK_SET;
        lock.l start = (id-START_ID)*sizeof(record);
        lock.l len = sizeof(record);

        if(fcntl(fd,F_SETLKW,&lock) == -1) {
            perror(argv[1]);
            exit(3);
        }
        lseek(fd,(id-START_ID)*sizeof(record), SEEK_SET);
        if((read(fd, (char *) &record, sizeof(record)) > 0) && (record.id != 0))

