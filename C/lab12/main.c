#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


/*Написать программу-календарь. Пользователь может указать даты в формате:
	- гггг.мм.дд - программа вычисляет день недели соответствующий данной дате;
	- гггг.мм - программа выводит календарь за данный месяц;
	- гггг - календарь за год;
	- now - текущую дату.*/


/*Формула для григорианского календаря
Для даты с днем q, месяцем m и годом Y:
Если месяц январь или февраль, его считают 13-м или 14-м месяцем предыдущего года.
Разделяют год на две части:
K — последние две цифры года (год % 100)
J — первые две цифры года (целая часть от деления года на 100)
Вычисляют значение h по формуле:
h = (q + ?(13*(m+1))/5? + K + ?K/4? + ?J/4? ? 2*J) mod 7*/
int VISOK(int year){
	return (year % 4 == 0 && year % 100 != 0) || (year%400 == 0);
}
int DAYSINMONTH(int year, int month){
	int counts[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if (month == 2 && VISOK(year)){
		return 29;
	}
	return counts[month - 1];
}
int WEEKSDAY(int year, int month, int day)
{
	if (month<3){
		month += 12;
		year -=1;
	}
	int k = year % 100;
	int j = year / 100;
	int h = (day +(13*(month+1))/5 + k + k/4 + j/4 + 5*j)%7;
	return (h+6)%7;

}
void printDWeek(int dayOfWeek) {
    const char *days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    printf("%s\n", days[dayOfWeek]);
}
void printMONTH(int year, int month){
	const char *MONTHS[] = {"JAN","FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
	printf("%s, %d \n", MONTHS[month-1], year);
	printf(" Mon Tue Wed Thu Fri Sat Sun\n");
	int counts = DAYSINMONTH(year, month);
	int firstDAY = WEEKSDAY(year, month, 1);
	
	int PROBEL = (firstDAY + 6)%7;
	int i;
	for(i =0; i<PROBEL; i++){
		printf("    ");
	}
	int days;
	for (days = 1; days<=counts;days++){
		printf("%4d", days);
		if ((PROBEL + days)%7 == 0){
			printf("\n");
		}
	}
	printf("\n");
	
}
void printYEARCAL(int year){
	int month;
	for (month = 1; month<13; month++){
		printMONTH(year, month);
	}
}
void localT(){
	struct tm *local, *gm;
	time_t t;
	t = time(NULL);
	local = localtime(&t);
	printf("Local: %s", asctime(local));
}
int main() {
	/*int weekday = WEEKSDAY(2026, 5, 14);
	printf("Weekday: %d\n", weekday);
	printDWeek(weekday);
	printMONTH(2026, 5);
	localT();
	
	printYEARCAL(2026);*/
	int year, month, day;
	char input[256];
	printf("CHOOSE:\n yyyy.mm.dd - weekday\n yyyy.mm - month calendar\n yyyy - year calendar\n now - todays date and time\n");
	fgets(input, sizeof(input), stdin);
	input[strcspn(input, "\n")] = 0;
	int i;
	if (strcmp(input, "now") == 0){
		localT();
	}
	int dots = 0;
        for (i = 0; input[i]; i++) {
            if (input[i] == '.') dots++;
        }
    //printf("Найдено точек: %d\n", dots);
	if (dots == 2){
		sscanf(input, "%d.%d.%d", &year, &month, &day);
		int weekday = WEEKSDAY(year, month, day);
		printDWeek(weekday);
	}
	if(dots == 1){
		sscanf(input, "%d.%d", &year, &month);
		printMONTH(year, month);
	}
	if (dots == 0){
		sscanf(input, "%d", &year);
		printYEARCAL(year);
	}
	
	
	return 0;
	
}
