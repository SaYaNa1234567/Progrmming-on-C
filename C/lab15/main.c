#include <stdio.h>
#include <stdlib.h>

/*ƒано натуральное число N. ¬ыведите все его цифры по одной, в обычном пор€дке (а потом в обратном), раздел€€ их пробелами или новыми строками. Ќапример: 179 => 1 7 9; 179 => 9 7 1
ѕри решении этой задачи нельз€ использовать строки, списки, массивы (ну и циклы, разумеетс€).
*/

/*int n = 179;
	
	printf("%d\n", n/10); 17
	printf("%d", n%10); 9*/
	
void forw(int n){
	if (n<10){
		printf("%d ", n);
		return;
	}
	forw(n/10);
	printf("%d ", n%10);
}
void backw(int n){
	if (n<10){
		printf("%d ", n);
		return;
	}
	printf("%d ", n%10);
	backw(n/10);
}
int main() {
	printf("Input Num: ");
	int n;
	scanf("%d", &n);
	
	forw(n);
	printf("\n");
	backw(n);

	return 0;
}
