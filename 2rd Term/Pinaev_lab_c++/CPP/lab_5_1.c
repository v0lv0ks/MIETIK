#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>


void fillMatrix(double *matrix, int rows, int cols) {
    srand(time(NULL)); // Инициализация генератора случайных чисел
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(matrix + i * cols + j) = rand()%10/3.3; // Генерация чисел
        }
    }
}

void printMatrix(double *matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
                printf("%.2f\t", *(matrix + i * cols + j));}
                printf("\n");}
}

// Функция для формирования массива результатов - возвращает указатели на нулевые элементы в нижней половине матрицы
double** findZeroes(double *matrix, int rows, int cols, int *numZeroes) {
    double **result = (double **)malloc(rows * sizeof(double *));
    if (result == NULL) {
        *numZeroes = 0;
        return NULL;
    }

    int count = 0;

    // Перебор элементов в нижней половине матрицы
    for (int i = rows / 2; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (*(matrix + i * cols + j) == 0) {
                result[count++] = (matrix + i * cols + j);
                
            }
        }
    }
    
    *numZeroes = count;
    return result;
}

int main() {
    
    int rows, cols;
    printf("input rows and col: ");
    scanf("%d %d", &rows, &cols);
    
    // Выделение памяти для матрицы
    double *matrix = (double *)malloc(rows * cols * sizeof(double));

    // Заполнение матрицы случайными вещественными числами
    fillMatrix(matrix, rows, cols);
    // Печать матрицы 
    printMatrix(matrix, rows , cols);
    printf("\n");
    int numZeroes;
    double **zeroPtrs = findZeroes(matrix, rows, cols, &numZeroes);

    printf("Pointers:\n");
    for (int i = 0; i < numZeroes; i++) {
           printf("%p -> value = %lf\n", *(zeroPtrs + i), **(zeroPtrs + i));
    }

    // Освобождение памяти
    free(matrix);
    free(zeroPtrs);

    return 0;
}