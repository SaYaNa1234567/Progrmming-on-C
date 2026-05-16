#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

/* Написать программу с использованием нелокального перехода setjmp/longjmp, 
которая вычисляет сумму чисел Фибоначчи (начиная с1, 1,...). 
Использовать рекурсивную функции для вычисления суммы, 
в качестве механизма возврата из вложенных вызовов использовать нелокальный переход.*/

/*Рекурсивная формула
Последовательность Фибоначчи определяется так:
F(0) = 0
F(1) = 1
F(n) = F(n-1) + F(n-2) для n > 1*/

jmp_buf env = {0};

void form(int n, int a, int b, int F){
	if (n==0){
		longjmp(env,F);
	}
	form(n-1, b, a+b, F+a); //n=5 a= 1 b=1 sum = 0, ~ 12
}
int main() {
	printf("Input num of Fibanacci: ");
	int n;
	
	scanf("%d", &n);
	int val = setjmp(env);
	if (val == 0){
		form(n, 1, 1,0);
	}
	else{
		printf("%d", val);
	}
	return 0;
}
