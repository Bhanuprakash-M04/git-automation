#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int *spiralOrder(int **matrix, int matrixSize, int *matrixColSize, int *returnSize)
{
    int *arr = malloc(sizeof(int) * (matrixSize * matrixColSize[0]));
    int ind = 0;
    int left = 0;
    int right = matrixColSize[0] - 1;
    int top = 0;
    int bottom = matrixSize - 1;

    while (top <= bottom && left <= right)
    { // stops when boundaries meet
        for (int i = top; i <= right; i++)
        { // left to right traversal
            arr[ind++] = matrix[top][i];
        }
        top++;

        for (int i = top; i <= bottom; i++)
        { // top to bottom traversal
            arr[ind++] = matrix[i][right];
        }
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            { // right to left traversla (if needed)
                arr[ind++] = matrix[bottom][i];
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            { // bottom to top traversal (if needed)
                arr[ind++] = matrix[i][left];
            }
            left++;
        }
    }
    *returnSize = matrixSize * matrixColSize[0];
    return arr;
}