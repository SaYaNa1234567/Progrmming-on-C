#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void matrix_inp(double *m, int n, char name){
	int i, j;
	printf("Matrix %c: \n", name);
	for (i = 0; i<n; i++){
		for (j = 0; j<n; j++){
			printf(" %c[%d][%d]", name, i, j);
			scanf("%lf", &m[i*n+j]);
		}
	}
}
void matrix_vivod(double *m, int n, char name){
	int i, j;
	printf("Matrix %c: \n", name);
	for (i = 0; i<n; i++){
		for (j = 0; j<n; j++){
			printf("%8.2lf", m[i*n+j]);
		}
		printf("\n");
	}
}
int main() {
	int n;
	int size;
	double *a, *b, *c;
	char oper;
	printf("Matrix's size: ");
	scanf("%d", &n);
	size = n*n;
	a = malloc(size * sizeof(double));
	b = malloc(size * sizeof(double));
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
