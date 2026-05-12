#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {
	
	printf("Sum: %.2lf\n ", sum(3, 40.0, 34.5, 30.0));
	printf("MIN: %.2lf\n ", min(3, 40.0, 34.5, 30.0));
	printf("MAX: %.2lf\n ", max(3, 40.0, 34.5, 30.0));
	printf("Avg: %.2lf\n ", avg(3, 40.0, 34.5, 30.0));
	return 0;
}
