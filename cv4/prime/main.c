#include <stdio.h>

int isPrime(int input) {
    if (input > 100) {
        return -1;
    }

    for (int i = 2; i < input; i++) {
        if (input % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    printf("%d",isPrime(7));
}
