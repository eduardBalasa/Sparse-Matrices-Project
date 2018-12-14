
#include"functions.h"
#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<conio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

matrix  *create(int lines, int columns) //!<function to create the official matrix
{
    int number_elements; //!< number of nonzero elements from matrix
    int i,n,x,y; //!< Index to move from an elelemnt to another. Increasing with 1 position in liked list (structure matrix)
    bool ok; //!< for verify something

    matrix *r; //!< new element (type: matrix (structure)
    number_elements= 0.4*lines*columns; //!< 40% of elements from matrix are nenulls

    mat = NULL;
    p = (matrix*)malloc(sizeof(matrix)); //!<  dynamic memory allocation for element

    p->column = rand()%columns+1; //!< the column of the nenzero element from structure will generate random using rand function
    p->line = rand()%lines+1; //!< the line of the nenzero element from structure will generate random using rand function
    p->data = rand()%10+1; //!< the data of the nenzero element from structure will generate random using rand function

    p->next = NULL; //!< next element after p is NULL
    mat = p;last = p; //!< first element and the last is p. Structure has no more than one element.

    for(i=1;i<=number_elements-1;i++){
        x = rand()%columns+1;//!< the column of the nenzero element from structure will generate random using rand function
        y = rand()%lines+1;//!< the lines of the nenzero element from structure will generate random using rand function
        ok = true;

        r = mat; //!< (element (structure, matrix) become the first element)
        while(r != NULL){//!< structure has elements
            if (x == r->column && y == r->line) //!< verify property
               ok = false;
            r = r->next;//!< go to next element
        }

        if (ok == true){//!< the element can be added in structure
            p = (matrix*)malloc(sizeof(matrix));//!<  dynamic memory allocation for element (type: matrix)
            p->data = rand()%10+1;//!< generate random
            p->line = y;
            p->column = x;
            last->next = p;//!<  last element after last become p
            last = p;//!<  updated new last.
            last->next = NULL;//!< linked list and structure -> corectly created
            }
    }

return mat;
}

/*! Function Create
    creates a structure like linked list with the nonzero elements of one matrix (in our case 40% percents -> nonzero elements)
    The elements are generated random with function rand().

*/

matrix *addition(matrix *matrix_one, matrix *matrix_two)
{
    bool ok;//!<  verify if the line of first matrix is equal with the line of the second matrix and the column of the first matrix is equal with the column of the second matrix

    matrix *last_two;//!< a new element (type: matrix (strcture))
    matrix *r;//!< a new element (type: matrix (strcture))

    last_two = matrix_two;//!< In the element (type: matrix(structure)) "last two", will be store the dates from matrix_two without delete the dates from matrix_two. Copy data.
    while(last_two->next != NULL)//!< a repetitive structure who goes to element with element until the next element is NULL
        last_two = last_two->next;//!< update the last element with the next element if this isn't NULL

    p = matrix_one;//!< In the element (type: matrix(structure)) "p", will be store the dates from matrix_one without delete the dates from matrix_one. Copy data.

    while(p != NULL){//!< a repetitive structure who goes to element with element untill the next element is NULL
        q = matrix_two;//!< In the element (type: matrix(structure)) "q", will be store the dates from matrix_two without delete the dates from matrix_two. Copy data.
        ok = false; //!<  matrix_one and matrix_two don't have the same line and the same column

        while(q!=NULL && ok == false){//!< a repetitive structure who goes to element with element untill the next element is NULL
            if(p->line == q->line && p->column == q->column){//!< verify that property
                ok = true;//!< if is true, ok become true
                q->data = q->data + p->data;//!< addition
            }
            q = q->next;//!< next element
        }

        if(ok == false){
            r = (matrix*)malloc(sizeof(matrix));

            r->data = p->data;
            r->line = p->line;
            r->column = p->column;

            last_two->next = r;//!< the last element become r
            r->next = NULL;//!< linked list is corectly store
            last_two = r;//!< updating last element
        }
        p = p->next;
    }

    matrix_three = matrix_two;

    return matrix_three;
}

/*! Function Addition
        After than we created the linked lists with sparse matrix (also with the nonzero elements from sparse matrix)
        in this function, addition, the datas of first matrix with same line and column (for second matrix) is summing with the datas of the second matrix.
        Algebrical operation: "+"

*/

matrix *diference(matrix *matrix_one, matrix *matrix_two)
{
    bool ok;//!<  verify if the line of first matrix is equal with the line of the second matrix and the column of the first matrix is equal with the column of the second matrix
    matrix *last_two;//!< a new element (type: matrix (strcture))
    matrix *r;//!< a new element (type: matrix (strcture))

    last_two = matrix_two;//!< In the element (type: matrix(structure)) "last two", will be store the dates from matrix_two without delete the dates from matrix_two. Copy data.
    while(last_two->next != NULL)//!< a repetitive structure who covor ("parcurge") element with element untill the next element is NULL
        last_two = last_two->next;//!< update the last element with the next element if this isn't NULL

    p = matrix_one;//!< In the element (type: matrix(structure)) "p", will be store the dates from matrix_one without delete the dates from matrix_one. Copy data.
    while(p != NULL){//!< a repetitive structure who goes to) element with element untill the next element is NULL
        q = matrix_two;//!< In the element (type: matrix(structure)) "q", will be store the dates from matrix_two without delete the dates from matrix_two. Copy data.
        ok = false; //!< matrix_one and matrix_two don't have the same line and the same column

        while(q!=NULL && ok == false){//!< a repetitive structure who goes toelement with element untill the next element is NULL
            if(p->line == q->line && p->column == q->column){//!< verify that property
                ok = true;//!< if is true, ok become 1. TRUE
                q->data = q->data - p->data;//!< diference
            }
            q = q->next;
        }

        if(ok == false){
            r = (matrix*)malloc(sizeof(matrix));

            r->data = p->data * (-1);
            r->line=p->line;
            r->column=p->column;

            last_two->next = r;//!< the last element become r
            r->next = NULL;//!< linked list is corectly store
            last_two = r;//!< updating last element
        }
        p = p->next;
    }

    matrix_three = matrix_two;

    return matrix_three;
}

/*! Function Diference
        After than we created the linked lists with sparse matrix (also with the nonzero elements from sparse matrix)
        in this function, diference, the datas of first matrix with same line and column (for second matrix) with the datas of the second matrix.
        Algebrical operation: "-"

*/


matrix *multiplication(int line1, int column1,int column2, matrix *matrix_one, matrix *matrix_two)
{
    int sum,i,j,k,x,y;
    bool ok,okay;

    matrix *last_three,*prim_three; //!< news elements (type: matrix (structure))
    matrix *r,*p;

    r = (matrix*)malloc(sizeof(matrix));
    prim_three = r; //!< first element from structure is r;
    last_three = r; //!< last element from matrix is r;
    last_three->next = NULL; //!< next element from matrix is NULL;

    for (i=1;i<=line1;i++)//!< a repetitive structure who goes toelement with element untill the last
        for (j=1;j<=column2;j++){
        sum = 0; //!< sum from line i and column k
        for (k=1;k<=column1;k++){
              ok = false;
              p = matrix_one; //!< p become first element from structure
              while(p != NULL){ //!< go to element with element until the next is NULL
                    if (p->line == i && p->column == k){//!< condition -> TRUE
                          ok = true;
                          x = p->data; //!< to next element
                      }
                 p = p->next;//!< go to next
                }
                okay = false;
                p = matrix_two; //!< p become first element from structure (second matrix)
                while(p != NULL){//!< a repetitive structure who goes to element with element untill the next element is NULL
                    if (p->line==k && p->column==j){
                          okay = true;
                          y = p->data;
                      }
                 p = p->next;

                }
          if (ok == true && okay == true)
              sum = sum + x * y;
          }

          if (sum!=0){
                   r=(matrix*)malloc(sizeof(matrix));

                   r->data = sum;
                   r->line = i;
                   r->column = j;

                   last_three->next = r; //!< next element after last become r
                   last_three = r; //!< updating last element
                   r->next = NULL;
                   last_three->next = NULL; //!< last element after r become NULL
               }
   }

    p = prim_three;
    matrix_three=prim_three->next;
    free(p);


    return matrix_three;
}

/*! Function Multiplication
        I created a new linked list of type structure with a only element.
        This new linked list will memory the results of multiplication of the two matrix.

        After than the multiplication is done, I will delete the first element created in that structure, and the first element in the list
        become the first element who results from multiplication.

        Algebrical operation: "*"

        Two cases:
        - the computer generates random line and columns for the two matrix , and after verify the property: columns of first is equal with lines of second.
        - the computer generates random line for first, columns of first is equal with lines of first (using only a variable) and the columns of second, because multiplication is possible all time.


        matrix_three become matrix_two (the values from matrix_two will be stored into matrix_three without delete them)
*/

matrix *involution(int l, matrix *matrix_one, matrix *matrix_two)
{
    int ok1,ok2,s,i,j,k,x,y;

    matrix *last_three,*prim_three;
    matrix *r,*p;

    r = (matrix*)malloc(sizeof(matrix));
    prim_three=r; //!< first element from structure is r;
    last_three=r; //!< last element from structure is r;

    for (i=1;i<=l;i++) //!< goes to element with element until the last element
    for (j=1;j<=l;j++){
       s=0; //!< init sum with 0
       for (k=1;k<=l;k++){
              ok1=0;
              p=matrix_one; //!< p become first element
              while(p!=NULL){ //!< goes to element with element until NULL
                    if (p->line==i && p->column==k){
                          ok1=1;
                          x=p->data;
                      }
                 p=p->next; //!< goes to next
                }

                ok2=0;
                p=matrix_two;
                while(p!=NULL){
                    if (p->line==k && p->column==j){
                          ok2=1;
                          y=p->data;
                      }
                 p=p->next;
                }

          if (ok1==1 && ok2==1)//!< conditions are true
              s=s+x*y;
          }
          if (s!=0){
                   r=(matrix*)malloc(sizeof(matrix));
                   r->data=s;
                   r->line=i;
                   r->column=j;
                   last_three->next=r; //!< next element after last become r
                   last_three=r; //!< updating last element
                   r->next=NULL;
                   last_three->next=NULL; //!< last element after r become NULL
               }

   }

    p = prim_three;
    matrix_three=prim_three->next;
    free(p);


    return matrix_three;
}

/*! Function Involution
        After than we created the linked list with sparse matrix (also with the nonzero elements from sparse matrix)
        The computer generates number of lines (number of lines is equal with number of columns) for just one matrice.
        After generates the power. Eg: pow(a,b); b - is power, a - is matrice

*/

void print_matrix (matrix *mat, int lines, int columns)
{
    int i,j; //!; integers
    bool ok;

    for(i=1;i<=lines;i++){//!< go to element with element
        for(j=1;j<=columns;j++){
            ok = false;//!< false
            p = mat;//!< the data from mat is stored into p, without delete

            while(p!=NULL && ok == false){//!< go to element with element while the conditions are true
                if(p->line == i && p->column == j){
                    ok = true;//!< true
                    printf("%d ", p->data);//!< show the element
                }
                p = p->next;//!< go to next element
            }
            if(ok == false)
                printf("0 ");
        }
        printf("\n");
    }
}

void print_matrix_file (matrix *mat, int lines, int columns)
{
    FILE *f;
    f = fopen("date.txt", "w");

    int i,j; //!; integers
    bool ok;

    for(i=1;i<=lines;i++){//!< go to element with element
        for(j=1;j<=columns;j++){
            ok = false;//!< false
            p = mat;//!< the data from mat is stored into p, without delete

            while(p!=NULL && ok == false){//!< go to element with element while the conditions are true
                if(p->line == i && p->column == j){
                    ok = true;//!< true
                    fprintf(f, "%d ", p->data);//!< show the element
                }
                p = p->next;//!< go to next element
            }
            if(ok == false)
                fprintf(f, "0 ");
        }
        fprintf(f, "\n");
    }
    fclose(f);
}
