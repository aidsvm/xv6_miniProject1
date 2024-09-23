#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int myPrime(int n) {
    if (n <= 1) {
        return 0;

    } else {
        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                return 0;
            }
        }
    }
    return 1;
}

void childPrimeCalculate(int ranges[], int size) {

    printf("I am the parent with pid: %d, ", (int) getpid());

    for (int i = 0; i < size; i+=2) {
        if (i == size - 2) {
            printf(" and sending range %d-%d to child %d", ranges[i], ranges[i+1], (i/2) + 1);
        } else {
            printf("sending range %d-%d to child %d", ranges[i], ranges[i+1], (i/2) + 1);
        }
    }
    printf("\n");
}


int main(int argc, char * argv[])
{

    int ranges[] = {1, 10, 11, 20};
    int size = sizeof(ranges) / sizeof(ranges[0]);
    childPrimeCalculate(ranges, size);
    return 0;
}

