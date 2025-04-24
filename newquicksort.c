#include<stdio.h>
void swap(int*p,int*q){
int temp;
temp = *p;
*p = *q;
*q = temp;
}
void quicksort(int arr[],int low,int high)
{
    int p;
    if(low<high)
    {
        p = partition(arr,low,high);
        quicksort(arr,low,p-1);
        quicksort(arr,p+1,high);
    }
}
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;

    for (int j = low + 1; j <= high; j++) {

        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
     swap(&arr[low], &arr[i - 1]);
    return i - 1;
}
int main(){
    int arr[]={20, 50, 10, 30, 40, 60, 55};
    int n = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,n-1);
    printf("sorted array: ");
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
