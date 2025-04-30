#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../solutions/solution.c"

bool compareArrays(int *arr1, int size1, int *arr2, int size2)
{
    if (size1 != size2)
        return false;
    for (int i = 0; i < size1; i++)
    {
        if (arr1[i] != arr2[i])
            return false;
    }
    return true;
}

void printArray(int *arr, int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("]\n");
}

int runTestCases()
{
    int passed = 0, failed = 0;

    // Test Cases
    int test1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int expected1[] = {1, 2, 3, 6, 9, 8, 7, 4, 5};

    int test2[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int expected2[] = {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};

    int test3[2][2] = {{1, 2}, {3, 4}};
    int expected3[] = {1, 2, 4, 3};

    int test4[1][1] = {{1}};
    int expected4[] = {1};

    int test6[3][1] = {{1}, {2}, {3}};
    int expected6[] = {1, 2, 3};

    int *matrices[] = {(int *)test1, (int *)test2, (int *)test3, (int *)test4, (int *)test6};
    int rows[] = {3, 3, 2, 1, 3};
    int cols[] = {3, 4, 2, 1, 1};
    int *expectedResults[] = {expected1, expected2, expected3, expected4, expected6};
    int expectedSizes[] = {9, 12, 4, 1, 3};

    for (int t = 0; t < 5; t++)
    {
        int m = rows[t], n = cols[t];

        int **matrix = (int **)malloc(m * sizeof(int *));
        for (int i = 0; i < m; i++)
            matrix[i] = matrices[t] + (i * n);

        int matrixColSize = n;
        int returnSize;
        int *result = spiralOrder(matrix, m, &matrixColSize, &returnSize);

        printf("Test Case %d:\n", t + 1);
        printf("Expected: ");
        printArray(expectedResults[t], expectedSizes[t]);
        printf("Got:      ");
        printArray(result, returnSize);

        if (compareArrays(result, returnSize, expectedResults[t], expectedSizes[t]))
        {
            printf("✅ Passed\n\n");
            passed++;
        }
        else
        {
            printf("❌ Failed\n\n");
            failed++;
        }

        free(result);
        free(matrix);
    }

    printf("Test Cases Passed: %d\n", passed);
    printf("Test Cases Failed: %d\n", failed);
    printf("Total Test Cases: %d\n", passed + failed);

    return failed; // return number of failed cases
}

int main()
{
    int failed = runTestCases();
    return failed > 0 ? 1 : 0;
}
