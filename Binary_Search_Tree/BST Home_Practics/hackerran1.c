#include <stdio.h>
#include <stdlib.h>

long* findSum(int numbers_count, int* numbers, int queries_rows, int** queries, int* result_count) {
    // Allocate memory for the result array
    long* subarray_sums = (long*)malloc(queries_rows * sizeof(long));

    for (int i = 0; i < queries_rows; i++) {
        int start_index = queries[i][0];
        int end_index = queries[i][1];
        int x = queries[i][2];

        long subarray_sum = 0;
        int zero_count = 0;

        for (int j = start_index - 1; j < end_index; j++) {
            if (numbers[j] == 0) {
                zero_count++;
                subarray_sum += x;
            } else {
                subarray_sum += numbers[j];
            }
        }

        subarray_sums[i] = subarray_sum + (zero_count * x);
    }

    *result_count = queries_rows;
    return subarray_sums;
}

int main() {
    int numbers[] = {20, 30, 0, 10};
    int queries[][3] = {{1, 3, 10}};

    int numbers_count = sizeof(numbers) / sizeof(numbers[0]);
    int queries_rows = sizeof(queries) / sizeof(queries[0]);
    
    int **queries_ptr = (int **)malloc(queries_rows * sizeof(int *));
    for (int i = 0; i < queries_rows; i++) {
        queries_ptr[i] = queries[i];
    }

    int* result_count = (int*)malloc(sizeof(int));
    long* result = findSum(numbers_count, numbers, queries_rows, queries_ptr, result_count);

    for (int i = 0; i < *result_count; i++) {
        printf("%ld\n", result[i]);
    }

    free(result);
    free(result_count);
    free(queries_ptr);

    return 0;
}
