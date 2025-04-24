#include <stdio.h>
#include <stdlib.h>
void merge(int arr[], int st, int mid, int end){
    int n1=mid-st+1;
    int n2=end-mid;
    int*left=(int*)malloc(n1 * sizeof(int));
    int*right=(int*)malloc(n2 * sizeof(int));
    for(int i=0;i<n1; i++)
        left[i]=arr[st+i];
    for(int j=0;j<n2;j++)
        right[j]=arr[mid+1+j];
    int i=0,j=0,k=st;
    while (i<n1 && j<n2){
        if(left[i]<=right[j])
            arr[k++]=left[i++];
        else
            arr[k++]=right[j++];
    }
    while (i<n1)
        arr[k++]=left[i++];
    while (j<n2)
        arr[k++]=right[j++];
    free(left);
    free(right);
}
void mergesort(int arr[], int st, int end){
    if(st<end){
        int mid=st+(end-st)/2;
        mergesort(arr,st,mid);
        mergesort(arr,mid+1,end);
        merge(arr,st,mid,end);
    }
}
int main(){
         int n;
         printf("enter the size of array: ");
         scanf("%d", &n);
         int*arr=(int*)malloc(n * sizeof(int));
         printf("enter the %d elements:\n",n);
         for(int i=0;i<n;i++){
            scanf("%d", &arr[i]);
         }
         mergesort(arr,0,n-1);
         printf("sorted array:\n");
         for(int i=0;i<n;i++){
            printf("%d\n", arr[i]);
         }
         printf("\n");
         free(arr);
         return 0;
}

