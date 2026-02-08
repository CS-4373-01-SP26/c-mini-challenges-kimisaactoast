/* 
3. Implement matrix – vector multiplication. Read in the following text file (mv.txt) which contains the matrix
and vector to be multiplied. Print your answer to the screen and time the computation. The format of mv.txt 
is: line 1 contains numrows, numcols. The next numrows contains the rows of the matrix, each with numcols 
integer values. The next line contains the length of the vector. The next line contains the vector of that length.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    
    // opening file
    FILE *file = fopen("mv.txt", "r");
    if (!file) {
        return 1;
    }
    
    // -- 1. reading matrix dimensions --
    int numrows, numcols;
    fscanf(file, "%d %d", &numrows, &numcols);

    // -- 2. reading matrix values --
    
    // allocate memory for the matrix values
    // matrix is a double pointer for first row of pointers
    int **matrix = malloc(numrows * sizeof(int*));

    // each pointer points to a data value
    for (int i = 0; i < numrows; i++) {
        matrix[i] = malloc(numcols * sizeof(int));
    }

    // feed data values into matrix
    for (int i = 0; i < numrows; i++) {
        for (int j = 0; j < numcols; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }

    // -- 3. reading vector dimensions --
    int vectorLength;
    fscanf(file, "%d", &vectorLength);

    // -- 4. reading vector values --
    
    // allocate memory for vector 
    int *vector = malloc(vectorLength * sizeof(int));

    // feed vector values into vector
    for (int i = 0; i < vectorLength; i++) {
        fscanf(file, "%d", &vector[i]);
    }

    fclose(file);

    // -- 5. computation -- 

    int *result = malloc(numrows * sizeof(int));
    for (int i = 0; i < numrows; i++) {
        result[i] = 0;
    }

    clock_t start = clock();

    for(int i = 0; i < numrows; i++) {
        for(int j = 0; j < numcols; j++){
            result[i] += matrix[i][j] * vector[j];
        }
    }

    clock_t end = clock();

    // printing results
    printf("Result Vector: ");
    for(int i = 0; i < numrows; i++) {
        printf("%d ", result[i]);
    }

    printf("\nTime Taken: %f s\n", (double)(end - start) / CLOCKS_PER_SEC); 

    // free memory
    for (int i = 0; i < numrows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(vector);
    free(result);

    return 0;
}