#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using namespace std;

typedef struct Data{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    string thing;
};

struct Data data[50];

int itinerary(int num){
    int check;
    int yes = 1;
    int no = 2;

    printf("�п�J");
    printf("�~�G");
    scanf("%d",&data[num].year);
    printf("��G");
    scanf("%d",&data[num].month);
    printf("��G");
    scanf("%d",&data[num].day);
    printf("�ɡG");
    scanf("%d",&data[num].hour);
    printf("���G");
    scanf("%d",&data[num].minute);
    printf("�ƶ��G");
    scanf("%s",&data[num].thing);
    printf("%d�~%d��%d��%d��%d�� �ƶ��G%s\n",data[num].year,data[num].month,data[num].day,
           data[num].hour,data[num].minute,data[num].thing);
    do{
        printf("�T�{/�����]1/2�^�G");
        scanf("%d",&check);
        if(check == no){
            num = num - 1;
            break;
        }else if(check == yes){
            break;
        }else{
            printf("�Э��s��J\n");
            break;
        }
    }while(check != no || check != yes);
    return num;
}

void alarm_clock(){


    //printf("year:%d , month:%d , day:%d\n",year,month,day);

    printf("2\n");
}

void completion(){
    printf("3\n");
}

void suggest(int num,int ok){
    if(num >= 5 && num < 10){

    }else if(num >= 10 && num < 20){
        printf("");
    }else if(num >= 20){
        printf("");
    }else if(num == 0){
        printf("");
    }else{
        printf("error");
    }

    if((ok/num) >= 0.2 && (ok/num) < 0.5){
        printf("");
    }else if((ok/num) >= 0.5 && (ok/num) < 0.8){
        printf("");
    }else if((ok/num) >= 0.8 && (ok/num) < 1){
        printf("");
    }else if((ok/num) == 1){
        printf("");
    }else if((ok/num) == 0){
        printf("");
    }else{
        printf("error");
    }

    printf("4\n");
}

int main(){
    time_t p;
    tm *tp;
    time(&p);
    tp = localtime(&p);
    int year = (tp->tm_year) + 1900;
    int month = (tp->tm_mon) + 1;
    int day = tp->tm_mday;
    int hour = tp->tm_hour;
    int minute = tp->tm_min;

    int choose = 0;
    int num = 1;
    int i = 1;
    int ok = 0;

    do{
        printf("1.��J��{ 2.�]�w�x�� 3.�����ƶ� 4.��ĳ 5.����\n");
        printf("�п�J��ܡG");
        scanf("%d",&choose);
        switch(choose){
            case 1:
                num = itinerary(num);
                for (i = 1;i <= num;i++){
                    printf("%d %d�~%d��%d��%d��%d�� �ƶ��G%s\n",i,data[i].year,data[i].month,data[i].day,
                    data[i].hour,data[i].minute,data[i].thing);
                    printf("\n");
                }
                num++;
                break;
            case 2:
                alarm_clock();
                printf("\n");
                break;
            case 3:
                completion();
                printf("\n");
                break;
            case 4:
                suggest(num,ok);
                printf("\n");
                break;
            case 5:
                break;
            default:
                printf("�Э��s���\n\n");
                break;
        }
    }while(choose != 5 );

}
