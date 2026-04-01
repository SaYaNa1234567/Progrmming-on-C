#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void matrix_inp(int **m, int n, char name){
	int i, j;
	printf("Matrix %c: \n", name);
	for (i = 0; i<n; i++){
		for (j = 0; j<n; j++){
			printf(" %c[%d][%d]", name, i, j);
			scanf("%d", &m[i][j]);
		}
	}
}
void matrix_vivod(int **m, int n, char name){
	int i, j;
	printf("Matrix %c: \n", name);
	for (i = 0; i<n; i++){
		for (j = 0; j<n; j++){
			printf("%4d", m[i][j]);
		}
		printf("\n");
	}
}
int main() {
	int n;
	int i, j;
	int **a, **b, **c;
	char oper;
	printf("Matrix's size: ");
	scanf("%d", &n);
	a = (int**)malloc(n*sizeof(int*));
	for(i = 0;i<n;i++){
		a[i] = (int*)malloc(n*sizeof(int));
	}
	b = (int**)malloc(n*sizeof(int*));
	for(i = 0;i<n;i++){
		b[i] = (int*)malloc(n*sizeof(int));
	}
	matrix_inp(a, n, 'A');
	matrix_inp(b, n, 'B');
	matrix_vivod(a, n, 'A');
	matrix_vivod(b, n, 'B');
	printf("Matrix's operation(+-*): ");
	scanf(" %c", &oper);
	if (oper == '+'){
		c = matrix_sum(a,b,n);
	}
	else if (oper == '-'){
		c = matrix_min(a,b,n);
	}
	else if (oper == '*'){
		c = matrix_umn(a,b,n);
	}
	else{
		printf("Error! Choose +-*");
		free(a);
		free(b);
		return 1;
	}
	matrix_vivod(c, n, 'C');
	free(a);
	free(b);
	free(c);
	return 0;
}

