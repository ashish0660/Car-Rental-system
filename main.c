#include<stdio.h>
/*
int main(){
    int a[50],size,i;
    printf("Enter the size of array");
    scanf("%d",&size);
    printf("Enter element of array");
    for(i=0;i<size;i++){
        scanf("%d",&a[i]);
    }
    printf("Element in array are:");
    for(i=0;i<size;i++){
        printf("%d ",a[i]);
    }
}
*/

int main(){

    int a[50],size,i,num,pos;
    printf("Enter  the size of array");
    scanf("%d",&size);
    printf("Enter element of array");
    for(i=0;i<=size;i++){
        scanf("%d",&a[i]);
    }
     printf("Element in array are:");
    for(i=0;i<size;i++){
        printf("%d ",a[i]);
    }

    printf("\n");

    printf("Enter data you want to store.. ");
    scanf("%d",&num);
    printf("Enter your position: ");
    scanf("%d",&pos);
    for(i=size;i>=pos-1;i--){
        a[i+1]=a[i];
    }
    a[pos-1]=num;
    size++;
    printf("Element in array are:");
    for(i=0;i<size;i++){
        printf("%d ",a[i]);
    }
}


