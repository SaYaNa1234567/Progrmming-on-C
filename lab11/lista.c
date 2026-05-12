#include "lista.h"
#include <limits.h>
#include <stdio.h>
#include <stdarg.h>

double sum(int n, ...){
	double res = 0;
	va_list list;
	va_start(list, n);
	while (n){
		res += va_arg(list, double);
		--n;
	}
	va_end(list);
	return res;
}

double max(int n, ...){
	double maxN = INT_MIN;
	va_list list;
	va_start(list, n);
	while (n){
		int NOW = va_arg(list, double);
		if(NOW>maxN){
			maxN = NOW;
		}
		--n;
	}
	va_end(list);
	return maxN;
}
double min(int n, ...){
	double minN = INT_MAX;
	va_list list;
	va_start(list, n);
	while (n){
		int NOW = va_arg(list, double);
		if(NOW<minN){
			minN = NOW;
		}
		--n;
	}
	va_end(list);
	return minN;
}

double avg(int n, ...){
	double res = 0;
	va_list list;
	va_start(list, n);
	int suma = n;
	while (n){
		res += va_arg(list, double);
		--n;
	}
	double aveg = res/suma;
	va_end(list);
	return aveg;
}
