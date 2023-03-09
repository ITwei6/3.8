#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int leap_year(int year) {
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) return 1;
    return 0;
}

int gap_days(int year, int month, int day) {
    int sum = day;
    int m[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int i, j;
    if (leap_year(year)) m[1] = 29;   // 闰年2月29天
    for (i = 1; i < year; i++) {
        if (leap_year(i)) sum += 366;
        else sum += 365;
    }
    for (j = 0; j < month - 1; j++) sum += m[j];
    return sum;
}
int main(void) {
    char num[20];
    int year, month, day,i;
    int m[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int days1,days2,result;

    scanf_s("%s", num);

    if (strlen(num)!=8) {
        printf("%s是不正确的日期\n", num);
        return -1;
    }    

    for (i=0; i<8; i++) {
        if (num[i]<'0'||num[i]>'9') {
            printf("%s是不正确的日期\n", num);
            return -1;
        }
    }

    year=1000*(int)(num[0]-'0')+100*(int)(num[1]-'0')+10*(int)(num[2]-'0')+(int)(num[3]-'0');
    month=10*(int)(num[4]-'0')+(int)(num[5]-'0');
    day=10*(int)(num[6]-'0')+(int)(num[7]-'0');

    if (leap_year(year)) m[1]=29;   // 闰年2月29天

    if (month>12||day>m[month-1]) {
        printf("%s是不正确的日期\n", num);
        return -1;
    }

    
    days1=gap_days(year, month, day);
    days2=gap_days(2022, 11, 28);
    result=(days1-days2)%7;
    if (days1>=days2)
		result=(days1-days2)%7;
    else
		result=(days1-days2)%7+7;

    switch (result) {
        case 0: printf("%s是星期一\n", num); break;
        case 1: printf("%s是星期二\n", num); break;
        case 2: printf("%s是星期三\n", num); break;
        case 3: printf("%s是星期四\n", num); break;
        case 4: printf("%s是星期五\n", num); break;
        case 5: printf("%s是星期六\n", num); break;
        case 6: printf("%s是星期日\n", num); break;
        default: printf("ERROR!");
    }
	
}
