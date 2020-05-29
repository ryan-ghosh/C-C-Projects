#include "lab2.h"
#include <math.h>

void print_tree(float arr[], int n) {
    int rows = floor(log2(n)), space, i, j;
    for(int i = 0; i <= rows; i++)
    {
        for(int space = 0; space < n - i; space++)
        {
            printf("   ");
        }
        for(int j = 0; j <= i; j++){
            printf("%-5d ", i);
        }
        printf("\n");
    }
}


float get_parent_value(float arr[], int n, int index) {
    int p_index = (index - 1)/2;
    if(index == 0 || index > n)
        return -1;
    else
        return arr[p_index];
}

float get_left_value(float arr[], int n, int index) {
    int left = 2*index + 1;
    if (left>n || index>n)
        return -1;
    else
        return arr[left];
}

float get_right_value(float arr[], int n, int index) {
    int right = 2*index + 2;
    if (right>n || index>n)
        return -1;
    else
        return arr[right];
}

int is_max_heap(float arr[], int n) {
    for(int i = 0; i <= (n - 2)/2; i++){
        if (arr[2*i+1] > arr[i] || arr[2*i+2] > arr[i])
            return 0;
    }
    return 1;
}

void heapify(float arr[], int n) {
    int i = 0;
    while(i <= n){
        int largest = i;
        int left = 2*largest + 1;
        int right = 2*largest + 2;
        int temp = arr[i];
        if (arr[left] > arr[largest] && left < n)
            largest = left;
        if (arr[right] > arr[largest] && right < n)
            largest = right;
        if (largest != i) {
            arr[i] = arr[largest];
            arr[largest] = temp;
        }else
            i++;
    }
}

void heapsort(float arr[], int n) {
    for (int i = 1; i < n; i++){
        int temp = arr[0];
        arr[0] = arr[n-i];
        arr[n-i] = temp;
        heapify(arr,n-i);
    }
}
float find_most_common_element(float arr[], int n) {
    int maxV = 0, maxC = 0, i, j;
    heapsort(arr, n);
    for (i = 0; i < n; ++i) {
        int count = 0;

        for (j = 0; j < n; ++j) {
            if (arr[j] == arr[i])
                ++count;
        }

        if (count > maxC) {
            maxV = arr[i];
            maxC = count;
        }
    }

    return maxV;
}
