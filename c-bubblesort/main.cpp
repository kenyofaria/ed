#include <iostream>

void swap(int* a, int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partition(int a[], int low, int high) {
    int p = a[low];
    int i = low;
    int j = high;
    while (i < j) {
        while (a[i] <= p && i <= high - 1) {
            i++;
        }
        while (a[j] > p && j >= low + 1) {
            j--;
        }
        if (i < j) {
            swap(a, i, j);
        }
    }
    swap(a, low, j);
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1])
                swap(a, j, j + 1);
        }
    }
}

int main() {
    // int a[] = { 6, 0, 3, 5 };
    int a[] = { 5, 3, 4, 7, 6, 8, 2 };
    int n = sizeof(a) / sizeof(a[0]);

    //bubbleSort(a, n);
    quickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}