/**
 * @file main.c
 * @brief Multiply matrices.
 *
 * @author Jack Wiegman
 *
 */

#include <stdio.h>
#include <stdlib.h>

int exitProgram();
int getRows();
int getCols();
void populateMatrix(int rows, int cols, int matrix[rows][cols]);
void printMatrix(int rows, int cols, int matrix[rows][cols]);
void multiplyMatrix(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2,
                    int matrix2[rows2][cols2], int rowsP, int colsP, int product[rowsP][colsP]);

const int MAX_MATRIX_VALUE = 99;
const int MAX_MATRIX_DEMENSION = 20;
int main() {

    int matrix1Rows, matrix1Cols, matrix2Rows, matrix2Cols, matrixPRows, matrixPCols;

    while (1) {

        puts("This program will multiply two matrices: ");
        puts("Keep in mind, in order to multiply matrices, the column deminsion of the first "
             "matrix must match the row deminsion of the second.");
        puts("Please enter the information for the first matrix.");

        if (!(matrix1Rows = getRows())) {
            return exitProgram();
        }

        if (!(matrix1Cols = getCols())) {
            return exitProgram();
        }

        int matrix1[matrix1Rows][matrix1Cols];

        /* Populate and print first matrix */
        populateMatrix(matrix1Rows, matrix1Cols, matrix1);
        printMatrix(matrix1Rows, matrix1Cols, matrix1);

        matrix2Rows = matrix1Cols;
        printf("%s%d%s", "The second matrix will have ", matrix1Cols, " rows.");

        if (!(matrix2Cols = getCols())) {
            return exitProgram();
        }

        matrixPRows = matrix1Rows;
        matrixPCols = matrix2Cols;

        int matrix2[matrix2Rows][matrix2Cols];
        int productMatrix[matrix1Rows][matrix2Cols];

        populateMatrix(matrix2Rows, matrix2Cols, matrix2);
        printMatrix(matrix2Rows, matrix2Cols, matrix2);

        multiplyMatrix(matrix1Rows, matrix1Cols, matrix1, matrix2Rows, matrix2Cols, matrix2,
                       matrixPRows, matrixPCols, productMatrix);

        puts("The product of the two matrices:");
        printMatrix(matrixPRows, matrixPCols, productMatrix);
    }
    return 0;
}

int exitProgram() {
    puts("Thank you, come again!");
    return 1;
}
/**
 * @brief Multiplies two matrices into a new, third matrix.
 *
 * @param rows1 Number of rows in the first matrix.
 * @param cols1 Number of columns in the first matrix, should be the same as rows2.
 * @param matrix1 Another 2D matrix to multiply
 * @param rows2 Number of rows in the second matrix, should be the same as cols1.
 * @param cols2 Number of columns in the second matrix.
 * @param matrix2 A differenet 2D matrix to multiply.
 * @param rowsP Number of rows in the product matrix, should be the same as rows1.
 * @param colsP Number of rows in the product matrix, should be the same as cols2.
 * @param product The product matrix equal to matrix 1 * matrix 2.
 *
 * @return void
 */
void multiplyMatrix(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2,
                    int matrix2[rows2][cols2], int rowsP, int colsP, int product[rowsP][colsP]) {

    int sum = 0;

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < rows2; k++) {
                // Multiply corresponding places in arrays
                sum += matrix1[i][k] * matrix2[j][k];
            }
            product[i][j] = sum; // Put the final sum of products into result array
            sum = 0;             // Reset sum
        }
    }
}

/**
 * @brief Print a matrix
 *
 * @param rows      Number of rows in matrix
 * @param cols      Number of columns in matrix
 * @param matrix    2D array of ints with deminsions [rows][cols]
 * @return void
 */
void printMatrix(int rows, int cols, int matrix[rows][cols]) {

    printf("%s", "{");
    for (int i = 0; i < rows; i++) {
        printf("%s", "\n{ ");

        for (int j = 0; j < cols; j++) {
            printf("%d%s", matrix[i][j], ", ");
        }

        printf("%s", "}");
    }
    /*printf("%s", "}");*/
    puts("\n}");
}

/**
 * @brief Populate matrix with random integers from 0 to \ref MAX_MATRIX_DEMENSION
 * Take in a matrix and the deminsions of said matrix. Loop through all elements in matrix and
 * generate a random integer to set the element.
 *
 * @param rows      Number of rows in matrix
 * @param cols      Number of columns in matrix
 * @param matrix    2D array of ints with deminsions [rows][cols]
 * @return Matrix populated with random integers
 */
void populateMatrix(int rows, int cols, int matrix[rows][cols]) {
    int randInt;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            randInt = rand() % MAX_MATRIX_VALUE;
            matrix[i][j] = randInt;
        }
    }
}

/**
 * @brief Get matrix row deminsions from user.
 *
 * @return int Number of rows from user
 */
int getRows() {
    int input;

    while (1) {

        printf("%s%d%s", "Please enter the number of rows for the matrix from 1 to ",
               MAX_MATRIX_DEMENSION, " or -1 to eixt: ");
        scanf("%d", &input);

        if (-1 == input || 0 == input) {
            return 0;
        } else if (0 < input && input <= MAX_MATRIX_DEMENSION) {
            return input;
        }

        puts("Input invalid. Try again.");
    }
    return MAX_MATRIX_DEMENSION;
}

/**
 * @brief Get matrix column deminsions from user.
 *
 * @return int Number of columns from user
 */
int getCols() {
    int input;

    while (1) {
        printf("%s%d%s", "Please enter the number of columns for the matrix from 1 to ",
               MAX_MATRIX_DEMENSION, " or -1 to eixt: ");
        scanf("%d", &input);

        if (-1 == input) {
            return -1;
        } else if (0 < input && input <= MAX_MATRIX_DEMENSION) {
            return input;
        }
        puts("Input invalid. Try again.");
    }
    return MAX_MATRIX_DEMENSION;
}
