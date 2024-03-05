//C program to find whether an array is a subset of another array

#include <stdio.h>
#include <stdbool.h>
#define MAX 100

bool isSubset(int arr1[], int m, int arr2[], int n) {
    bool hashset[MAX] = {false};
    for (int i = 0; i < m; i++) {
        hashset[arr1[i]] = true;
    }
    for (int i = 0; i < n; i++) {
        if (!hashset[arr2[i]])
            return false;
    }
    return true;
}
int main() {
    int m,n;
    printf("enter the size of 1st array: ");
    scanf("%d", &m);
    int arr1[m];
    printf("enter the elements of 1st array: ");
    for(int i=0;i<m;i++){
        scanf("%d", &arr1[i]);
    }
    
    printf("enter the size of subset array: ");
    scanf("%d", &n);
    int arr2[n];
    printf("enter the elements of subset array: ");
    for(int i=0;i<n;i++){
        scanf("%d", &arr2[i]);
    }

    if (isSubset(arr1, m, arr2, n))
        printf("arr2[] is subset of arr1[]\n");
    else
        printf("arr2[] is not a subset of arr1[]\n");

    return 0;
}