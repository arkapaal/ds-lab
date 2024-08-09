#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}
int main(){
    int n,i,sum=0;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int*arr=(int*)malloc(n*sizeof(int));
    printf("Enter the elements of the array:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",arr+i);
    }
    for(int i = 0; i < n; i++){
        if (isPrime(*(arr+i))){
            sum += arr[i];
        }
    }
    printf("\n%d",sum);
    free(arr);
    return 0;
       
}
