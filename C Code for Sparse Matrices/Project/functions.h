#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<conio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

typedef struct{
    int line,column,data;
    struct matrix *next;
}matrix;



matrix *matrix_one, *matrix_two, *p, *q, *last, *matrix_three;

matrix *mat;

matrix  *create(int lines, int columns); //!<function that creates one sparse matrix with the nonzero elements

matrix *addition(matrix *matrix_one, matrix *matrix_two);

matrix *diference(matrix *matrix_one, matrix *matrix_two);

matrix *multiplication(int line1, int column1,int column2, matrix *matrix_one, matrix *matrix_two);

matrix *involution(int line, matrix *matrix_one, matrix *matrix_two);

void print_matrix (matrix *mat, int lines, int columns);

void print_matrix_file (matrix *mat, int lines, int columns);
