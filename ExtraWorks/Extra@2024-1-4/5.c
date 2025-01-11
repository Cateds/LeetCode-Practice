#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int *data;
} Matrix;

Matrix Multiple(Matrix M1, Matrix M2) {
    Matrix Ans;
    Ans.row = M1.row; Ans.col = M2.col;
    Ans.data = malloc(Ans.col * Ans.row * sizeof(int));
    for (int target_row=0; target_row<Ans.row; target_row++) {
        for (int target_col=0; target_col<Ans.col; target_col++) {
            int *target = Ans.data + target_col + target_row * Ans.col;
            *target = 0;
            for (int i=0; i<M1.col; i++) {
                *target += M1.data[target_row * M1.col + i] * M2.data[i * M2.col + target_col];
            }
        }
    }
    return Ans;
}

Matrix Multiple_3(Matrix M1, Matrix M2, Matrix M3) {
    Matrix Temp = Multiple(M1,M2);
    Matrix Ans = Multiple(Temp,M3);
    free(Temp.data);
    return Ans;
}

int main(void) {
    Matrix A1,A2,A3;
    scanf("%d%d%d%d",&A1.row,&A2.row,&A3.row,&A3.col);
    A1.col = A2.row;
    A2.col = A3.row;
    A1.data = malloc(A1.col*A1.row*sizeof(int));
    A2.data = malloc(A2.col*A2.row*sizeof(int));
    A3.data = malloc(A3.col*A3.row*sizeof(int));
    for (int i=0; i<A1.row*A1.col; i++)
        scanf("%d",&A1.data[i]);
    for (int i=0; i<A2.row*A2.col; i++)
        scanf("%d",&A2.data[i]);
    for (int i=0; i<A3.row*A3.col; i++)
        scanf("%d",&A3.data[i]);
    Matrix B = Multiple_3(A1,A2,A3);
    for (int i=0; i<B.row; i++) {
        for (int j=0; j<B.col; j++) {
            printf("%d ",B.data[i*B.col+j]);
        }
        putchar('\n');
    }
    free(A1.data);
    free(A2.data);
    free(A3.data);
    free(B.data);
    return 0;
}