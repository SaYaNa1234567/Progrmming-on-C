#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int **matrix_sum(int **a, int **b, int n){
	int i, j;
	int **c;
	c = (int**)malloc(n*sizeof(int*));
	for(i = 0;i<n;i++){
		c[i] = (int*)malloc(n*sizeof(int));
	}
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			c[i][j]=a[i][j]+b[i][j];
		}
	}
	return c;
}

int **matrix_min(int **a, int **b, int n){
	int i, j;
	int **c;
	c = (int**)malloc(n*sizeof(int*));
	for(i = 0;i<n;i++){
		c[i] = (int*)malloc(n*sizeof(int));
	}
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			c[i][j]=a[i][j]-b[i][j];
		}
	}
	return c;
}

int **matrix_umn(int **a, int **b, int n){
	int i, j, k;
	int **c;
	c = (int**)malloc(n*sizeof(int*));
	for(i = 0;i<n;i++){
		c[i] = (int*)malloc(n*sizeof(int));
	}
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			c[i][j] = 0;
			for (k = 0; k < n; k++){
				c[i][j] += a[i][k] + b[k][j];
				
			}
		}
	}
	return c;
}

