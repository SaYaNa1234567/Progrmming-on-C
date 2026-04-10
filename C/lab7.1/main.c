#include <stdio.h>
#include <stdlib.h>


struct humen{
	char name[40];
	char surname[40];
	int year;
};
int main() {
	struct humen m1[4];
	struct humen m2[4];
	struct humen m3[4];
	int i, j;
	printf("Info abt 4 people:\n\n");
    
    for(i = 0; i < 4; i++) {
        
        printf("Name: ");
        scanf("%s", m1[i].name);
        
        printf("Surname: ");
        scanf("%s", m1[i].surname);
        
        printf("Birth year: ");
        scanf("%d", &m1[i].year);
        
        printf("\n");
    }
    
    for(i = 0; i < 4; i++){
    	m2[i] = m1[i];
	}
    
    for(i = 0; i < 3; i++){
    	for(j = 0; j < 3 - i; j++){
    		if (m2[j].year > m2[j+1].year){
    			m3[j] = m2[j];
    			m2[j]= m2[j+1];
    			m2[j+1] = m3[j];
			}
		}
	}
    
    printf("Sorted!\n\n");
    
    for(i = 0; i < 4; i++) {
        printf("%d. %s %s, %d year\n", 
               i + 1, 
               m2[i].name, 
               m2[i].surname, 
               m2[i].year);
    }
    
	return 0;
}
