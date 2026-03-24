#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

double *matrix_sum(double *a, double *b, int n){
	int i;
	int size = n * n;
	double *c;
	c = malloc(size * sizeof(double));
	for (i = 0; i < size; i++){
		c[i]=a[i]+b[i];
	
	}
	return c;
}

double *matrix_min(double *a, double *b, int n){
	int i;
	int size = n * n;
	double *c;
	c = malloc(size * sizeof(double));
	for (i = 0; i < size; i++){
		c[i]=a[i]-b[i];
	}
	return c;
}

double *matrix_umn(double *a, double *b, int n){
	int i, j, k;
	int size = n * n;
	double *c;
	c = calloc(size, sizeof(double));
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			for (k = 0; k < n; k++){
				c[i*n+j]= c[i*n+j] + a[i*n+k] + b[k*n+j];
				
			}
		}
	}
	return c;
}

