// spiral_solution.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to compute the spiral order traversal
void spiralOrder(int** matrix, int m, int n, int* result, int* size) {
    if (m == 0 || n == 0) {
        *size = 0;
        return;
    }

    int top = 0, bottom = m - 1, left = 0, right = n - 1;
    int index = 0;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++)
            result[index++] = matrix[top][i];
        top++;

        for (int i = top; i <= bottom; i++)
            result[index++] = matrix[i][right];
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                result[index++] = matrix[bottom][i];
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                result[index++] = matrix[i][left];
            left++;
        }
    }

    *size = index;
}

// Function to compare two integer arrays
bool compareArrays(int* arr1, int size1, int* arr2, int size2) {
    if (size1 != size2) return false;
    for (int i = 0; i < size1; i++) {
        if (arr1[i] != arr2[i]) return false;
    }
    return true;
}

// Function to print the spiral order result
void printArray(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++)
        printf("%d%s", arr[i], (i < size - 1) ? ", " : "");
    printf("]\n");
}
