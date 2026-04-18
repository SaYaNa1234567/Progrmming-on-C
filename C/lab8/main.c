#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    char surname[50];
    int year;
    char sex[10];
    float tall;
} Person;

int cmp_year(const void *a, const void *b) {
    return ((Person*)a)->year - ((Person*)b)->year;
}

int cmp_name(const void *a, const void *b) {
    int r;
    r = strcmp(((Person*)a)->name, ((Person*)b)->name);
    if (r == 0) r = strcmp(((Person*)a)->surname, ((Person*)b)->surname);
    return r;
}

int cmp_sex(const void *a, const void *b) {
    return strcmp(((Person*)a)->sex, ((Person*)b)->sex);
}

int cmp_tall(const void *a, const void *b) {
    if (((Person*)a)->tall > ((Person*)b)->tall) return 1;
    if (((Person*)a)->tall < ((Person*)b)->tall) return -1;
    return 0;
}

int fld[10];
int fld_cnt;

int cmp_multi(const void *a, const void *b) {
    int i, r;
    for (i = 0; i < fld_cnt; i++) {
        if (fld[i] == 1) {
            r = ((Person*)a)->year - ((Person*)b)->year;
            if (r != 0) return r;
        }
        else if (fld[i] == 2) {
            r = strcmp(((Person*)a)->name, ((Person*)b)->name);
            if (r == 0) r = strcmp(((Person*)a)->surname, ((Person*)b)->surname);
            if (r != 0) return r;
        }
        else if (fld[i] == 3) {
            r = strcmp(((Person*)a)->sex, ((Person*)b)->sex);
            if (r != 0) return r;
        }
        else if (fld[i] == 4) {
            if (((Person*)a)->tall > ((Person*)b)->tall) return 1;
            if (((Person*)a)->tall < ((Person*)b)->tall) return -1;
        }
    }
    return 0;
}

int main() {
    Person p[100];
    int n = 0, ch, i, k;
    FILE *f;
    
    f = fopen("text.txt", "r");
    if (f == NULL) {
        printf("Error\n");
        return 1;
    }
    
    while (fscanf(f, "%s %s %d %s %f", p[n].name, p[n].surname, &p[n].year, p[n].sex, &p[n].tall) == 5 && n < 100) {
        n++;
    }
    fclose(f);
    
    printf("Sort by:\n");
    printf("1 - year\n");
    printf("2 - name\n");
    printf("3 - sex\n");
    printf("4 - tall\n");
    printf("5 - multi\n");
    printf("Choice: ");
    scanf("%d", &ch);
    
    if (ch >= 1 && ch <= 4) {
        if (ch == 1) qsort(p, n, sizeof(Person), cmp_year);
        else if (ch == 2) qsort(p, n, sizeof(Person), cmp_name);
        else if (ch == 3) qsort(p, n, sizeof(Person), cmp_sex);
        else if (ch == 4) qsort(p, n, sizeof(Person), cmp_tall);
    }
    else if (ch == 5) {
        printf("How many: ");
        scanf("%d", &k);
        fld_cnt = k;
        for (i = 0; i < k; i++) {
            printf("Field %d (1-year,2-name,3-sex,4-tall): ", i+1);
            scanf("%d", &fld[i]);
        }
        qsort(p, n, sizeof(Person), cmp_multi);
    }
    
    printf("\nResult:\n");
    for (i = 0; i < n; i++) {
        printf("%s %s, %d, %s, %.2f\n", p[i].name, p[i].surname, p[i].year, p[i].sex, p[i].tall);
    }
    
    return 0;
}
