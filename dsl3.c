#include <stdio.h>
int main(){
    int n;
    
    printf("enter the rows and element of square matrix");
    scanf("%d",&n);
    int count;
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);

        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]!=0) count++;

            
        }
    }printf("the number of non-zero elements%d",count);
    printf("upper-triangular matrix");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j>i){
                printf("%d ",arr[i][j]);
            }else{
                printf("0");
            }printf("\n");

    }
    printf("lower-triangular matrix");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j<i){
                printf("%d ",arr[i][j]);
            }
            else{
                printf("0");
            }
        }printf("\n");

    }
}