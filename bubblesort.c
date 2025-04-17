int main()
{
    int a[100], n, i, j, flag, temp;
    
    printf("Enter the size of the array: \n");
    scanf("%d", &n);
    
    printf("Enter the elements of the array: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    for (i = 0; i < n - 1; i++) {
        flag = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                // Swap elements
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 1; // Set flag to indicate swapping
            }
        }
        // If no two elements were swapped in the inner loop, break
        if (flag == 0) {
            break;
        }
    }
    
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    return 0;
}