#include <stdio.h>
int main(){
    int n,b,c,a,d;
    printf("enter the number of elements in array\n");
    scanf("%d",&n);
    int arr[100];
    int ans[100];

    printf("enter the elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
    //insert an element 
    printf("enter a number to be inserted\n");
    scanf("%d",&a);
    printf("enter at which position to be inserted\n");
    scanf("%d",&b);
    for(int i=0;i<n;i++)
    {
        if(i!=b-1){
            ans[i]=arr[i];
            

        }
        else{
            ans[i]=a;
            i++;
        }
        
    }
    printf("new array\n");

    for(int i=0;i<n;i++){
        printf("%d ",ans[i]);
    }
    //delete an element
    
    printf("enter at which position to be deleted\n");
    scanf("%d",&c);
    for(int i=0;i<n;i++){
        if(i!=c-1){
            arr[i]=arr[i+1];
        }
    }
    printf("deleted array\n");
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    
    printf("enter a number to search\n");
    scanf("%d",&d);
    for(int i=0;i<n;i++){
        if(arr[i]==d){
            printf("number found at position%d",i+1);
        }
        else printf("not found\n");
    }
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}
