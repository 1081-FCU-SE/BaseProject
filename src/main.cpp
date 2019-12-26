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

    for (int i = 0;i <= (num - 1);i++){
        printf("%d %d�~%d��%d��%d��%d�� �ƶ��G%s\n",i+1,data[i].year,data[i].month,data[i].day,
        data[i].hour,data[i].minute,data[i].thing);
        printf("\n");
    }

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

void sleep_alarm_clock(){
    printf("2\n");
}

void alarm_clock(){



    printf("3\n");
}

void completion(){
    printf("4\n");
}

void suggest(int num,int ok){
    /*num = ����ݿ�ƶ��`�� , ok = ���駹���ƶ��`��*/
    ok = 0;
    float percent;
    percent = (float)ok / (float)num;

    printf("==============================\n");
    printf("�ݿ�ƶ��`�ơG%d\n",num);
    if(num > 0 && num < 5){
        printf("���Ѧ��žl���ɶ�,���P�@�U�a");
    }else if(num >= 5 && num < 10){
        printf("���ѨƱ����h����,�D�ԥ��������a�I");
    }else if(num >= 10 && num < 20){
        printf("���ѨƱ����I�h,�n�`�N�ɶ����t");
    }else if(num >= 20){
        printf("���ѫܦ�,���]�O�ѤF�n�`�N���d�@");
    }else if(num == 0){
        printf("���ѨS���ݿ�ƶ�");
    }else{
        printf("error");
    }
    printf("\n------------------------------\n");
    if(num == 0){
        printf("�L�ݿ�ƶ�");
    }else{
        printf("�ݿ�ƶ������v�G%.2f\n",percent);
        if(percent > 0 && percent < 0.2){
            printf("�����׷��C�A�Ъ`�N�C�ѫݿ�ƶ�!!");
        }else if(percent >= 0.2 && percent < 0.5){
            printf("�����װ��C�A���~��[�o!!");
        }else if(percent >= 0.5 && percent < 0.8){
            printf("�����׶W�L�@�b�A���~��[�o!!");
        }else if(percent >= 0.8 && percent < 1){
            printf("�����װ��A�Z���������������F!!");
        }else if(percent == 1){
            printf("�ݿ�ƶ����������A���~��O��!!");
        }else if(percent == 0){
            printf("�S�������ƶ��A�Ъ`�N�C�ѫݿ�ƶ�!!");
        }else{
            printf("error");
        }
    }

    printf("\n==============================\n");
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
    int num = 0;
    int ok = 0;

    do{
        printf("1.��J��{ 2.�]�w�ίv�x�� 3.�]�w�x�� 4.�����ƶ� 5.��ĳ 6.����\n");
        printf("�п�J��ܡG");
        scanf("%d",&choose);
        switch(choose){
            case 1:
                num = itinerary(num);
                num++;
                break;
            case 2:
                sleep_alarm_clock();
                printf("\n");
                break;
            case 3:
                alarm_clock();
                printf("\n");
                break;
            case 4:
                completion();
                printf("\n");
                break;
            case 5:
                suggest((num),ok);
                printf("\n");
                break;
            case 6:
                break;
            default:
                printf("�Э��s���\n\n");
                break;
        }
    }while(choose != 6 );
    return 0;
}
