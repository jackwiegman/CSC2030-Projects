/**
 * @file MatrixMultiplication.c
 * @author Jack Wiegman
 *
 * @brief Multiply matrices.
 *
 * Prompts user for matrix dimensions where the dimensions are between 1 and \ref
 * MAX_MATRIX_DIMENSION. Prompt for first matrix (M1) rows and columns, then build and print matrix,
 * exiting if the user inputs a sentinel value. Build the matrix with random values from 0 to \ref
 * MAX_MATRIX_VALUE. So the matrices can be multiplied, set the column dimensions of the second
 * matrix (M2) to the row dimensions of the first, then prompt for row dimensions for the second
 * matrix and build then print it.
 *
 * Multiply the matrices by obtaining the dot product of each row and column for the matrices.
 * Take the Nth row of M1 and the Mth column of M2. These have the same number of elements, so take
 * the product of M1[n][1] and M2[1][m] summed to M1[n][2] * M2[2][m] and so on for all the elements
 * in the row/column. This sum will be placed in the resulting matrix (M3) at the element M3[n][m].
 *
 * The program will then print the resulting product matrix. The loop will then end, and restart
 * prompting the user for a matrix dimension. The user will continue to multiply matrices until
 * they type -1, when prompted, to exit.
 *
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

const int MAX_MATRIX_VALUE = 99;     /**< Max value of a matrix element. */
const int MAX_MATRIX_DIMENSION = 20; /**< Max value of matrix rows and columns. */

/**
 * @brief Runs main loop to multiply matrices.
 * Initializes matrix dimensions and the matrices themsleves. Then multiplies the matrices and
 * prints out the result. Runs loop until condition from user to exit.
 *
 * @return Integer exit value.
 */
int main() {

    /* Declaring integers for all arrays. */
    int matrix1Rows, matrix1Cols, matrix2Rows, matrix2Cols, matrixPRows, matrixPCols;

    /** Main loop, exits from return statements ending the loop, funtion, and program */
    while (1) {

        /* Print program information for the user. */
        puts("This program will multiply two matrices: ");
        puts("Keep in mind, in order to multiply matrices, the column deminsion of the first "
             "matrix must match the row deminsion of the second.");
        puts("Please enter the information for the first matrix.");

        /* getRows() and getCols() returns row value and 0 if they choose to quit. So we can take
         * the opposite of the value of the assignment to check if we should exit program and run
         * exit function, returning from main and quitting the program.
         */
        if (!(matrix1Rows = getRows())) {
            return exitProgram();
        }
        if (!(matrix1Cols = getCols())) {
            return exitProgram();
        }

        /**< First matrix with user inputted dimensions. */
        int matrix1[matrix1Rows][matrix1Cols];

        /* Populate and print first matrix */
        populateMatrix(matrix1Rows, matrix1Cols, matrix1);
        printMatrix(matrix1Rows, matrix1Cols, matrix1);

        /* M1 cols has to be the same as M2 rows in order to multiply. */
        matrix2Rows = matrix1Cols;
        /* Let user know M2 Rows is set */
        printf("%s%d%s", "The second matrix will have ", matrix1Cols, " rows.");

        /* Same getCols() idea */
        if (!(matrix2Cols = getCols())) {
            return exitProgram();
        }

        /* Product matrix dimensions where rows equals M1 rows and columns equals M2 columns */
        matrixPRows = matrix1Rows;
        matrixPCols = matrix2Cols;

        /**< Second matrix with user inputted columns */
        int matrix2[matrix2Rows][matrix2Cols];

        /**< Future product matrix with rows dimensions from M1 and columns from M2 */
        int productMatrix[matrix1Rows][matrix2Cols];

        /* Populate and print second matrix */
        populateMatrix(matrix2Rows, matrix2Cols, matrix2);
        printMatrix(matrix2Rows, matrix2Cols, matrix2);

        /* Multiply matrices with output in product matrix */
        multiplyMatrix(matrix1Rows, matrix1Cols, matrix1, matrix2Rows, matrix2Cols, matrix2,
                       matrixPRows, matrixPCols, productMatrix);

        /* Print product matrix */
        puts("The product of the two matrices:");
        printMatrix(matrixPRows, matrixPCols, productMatrix);
    }
    return 0;
}

/**
 * @brief Print exit message and return program output.
 *
 * @return Program output integer.
 */
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
               MAX_MATRIX_DIMENSION, " or -1 to eixt: ");
        scanf("%d", &input);

        if (-1 == input || 0 == input) {
            return 0;
        } else if (0 < input && input <= MAX_MATRIX_DIMENSION) {
            return input;
        }

        puts("Input invalid. Try again.");
    }
    return MAX_MATRIX_DIMENSION;
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
               MAX_MATRIX_DIMENSION, " or -1 to eixt: ");
        scanf("%d", &input);

        if (-1 == input) {
            return -1;
        } else if (0 < input && input <= MAX_MATRIX_DIMENSION) {
            return input;
        }
        puts("Input invalid. Try again.");
    }
    return MAX_MATRIX_DIMENSION;
}
