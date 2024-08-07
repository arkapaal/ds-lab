
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}


int sumOfPrimes(int* arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) {
            sum += arr[i];
        }
    }
    return sum;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    int sum = sumOfPrimes(arr, n);
    printf("Sum of prime elements: %d\n", sum);

    free(arr);
    arr = NULL;

    return 0;
}