#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

struct humen{
    char name[50];
    char surname[50];
    int year;
    char sex[10];
    float tall;
};

int main() {
	setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);     
    SetConsoleOutputCP(1251);
	FILE *f1;
	struct humen *m = malloc(100 * sizeof(struct humen));
	
    struct humen temp;
	
	int i, j;
	int k = 0;
	
	int choice;
	int numofmulti;
	int multirazmer[4];
	f1 = fopen("data.txt", "r, ccs=ANSI");
	
    while (fscanf(f1, "%s %s %d %s %f", 
                  m[k].name, m[k].surname, 
                  &m[k].year, m[k].sex, &m[k].tall) == 5) {
        k = k + 1;
        if (k >= 100) break;
    }
    fclose(f1);
    
    printf("What sort?\n");
    printf("1 - year\n");
    printf("2 - name/surname\n");
    printf("3 - sex\n");
    printf("4 - tall\n");
    printf("5 - multi\n");
    printf("Choice: ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        for (i = 0; i < k - 1; i++) {
            for (j = 0; j < k - 1 - i; j++) {
                if (m[j].year > m[j+1].year) {
                    temp = m[j];
                    m[j] = m[j+1];
                    m[j+1] = temp;
                }
            }
        }
    }
    else if (choice == 2) {
        
        for (i = 0; i < k - 1; i++) {
            for (j = 0; j < k - 1 - i; j++) {
                int cmp_name = strcmp(m[j].name, m[j+1].name);
                if (cmp_name > 0) {
                    temp = m[j];
                    m[j] = m[j+1];
                    m[j+1] = temp;
                }
                else if (cmp_name == 0) {
                    
                    if (strcmp(m[j].surname, m[j+1].surname) > 0) {
                        temp = m[j];
                        m[j] = m[j+1];
                        m[j+1] = temp;
                    }
                }
            }
        }
    }
    if (choice == 3) {
        for (i = 0; i < k - 1; i++) {
            for (j = 0; j < k - 1 - i; j++) {
            	int cmp_sex = strcmp(m[j].sex, m[j+1].sex);
                if (m[j].sex > m[j+1].sex) {
                    temp = m[j];
                    m[j] = m[j+1];
                    m[j+1] = temp;
                }
            }
        }
    }
    if (choice == 4) {
        for (i = 0; i < k - 1; i++) {
            for (j = 0; j < k - 1 - i; j++) {
                if (m[j].tall > m[j+1].tall) {
                    temp = m[j];
                    m[j] = m[j+1];
                    m[j+1] = temp;
                }
            }
        }
    }
    printf("Sorted!\n\n");
    
    for (i = 0; i < k; i++) {
        printf("%d. %s %s, %d ???, %s, %.2f ?\n", 
               i + 1, 
               m[i].name, 
               m[i].surname, 
               m[i].year,
               m[i].sex,
               m[i].tall);
    }
    
    free(m);
	return 0;
}
