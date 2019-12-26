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
        printf("%d %d年%d月%d日%d時%d分 事項：%s\n",i+1,data[i].year,data[i].month,data[i].day,
        data[i].hour,data[i].minute,data[i].thing);
        printf("\n");
    }

    printf("請輸入");
    printf("年：");
    scanf("%d",&data[num].year);
    printf("月：");
    scanf("%d",&data[num].month);
    printf("日：");
    scanf("%d",&data[num].day);
    printf("時：");
    scanf("%d",&data[num].hour);
    printf("分：");
    scanf("%d",&data[num].minute);
    printf("事項：");
    scanf("%s",&data[num].thing);
    printf("%d年%d月%d日%d時%d分 事項：%s\n",data[num].year,data[num].month,data[num].day,
           data[num].hour,data[num].minute,data[num].thing);
    do{
        printf("確認/取消（1/2）：");
        scanf("%d",&check);
        if(check == no){
            num = num - 1;
            break;
        }else if(check == yes){
            break;
        }else{
            printf("請重新輸入\n");
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
    /*num = 今日待辦事項總數 , ok = 今日完成事項總數*/
    ok = 0;
    float percent;
    percent = (float)ok / (float)num;

    printf("==============================\n");
    printf("待辦事項總數：%d\n",num);
    if(num > 0 && num < 5){
        printf("今天有空餘的時間,放鬆一下吧");
    }else if(num >= 5 && num < 10){
        printf("今天事情不多不少,挑戰全部完成吧！");
    }else if(num >= 10 && num < 20){
        printf("今天事情有點多,要注意時間分配");
    }else if(num >= 20){
        printf("今天很忙,但也別忘了要注意健康哦");
    }else if(num == 0){
        printf("今天沒有待辦事項");
    }else{
        printf("error");
    }
    printf("\n------------------------------\n");
    if(num == 0){
        printf("無待辦事項");
    }else{
        printf("待辦事項完成率：%.2f\n",percent);
        if(percent > 0 && percent < 0.2){
            printf("完成度極低，請注意每天待辦事項!!");
        }else if(percent >= 0.2 && percent < 0.5){
            printf("完成度偏低，請繼續加油!!");
        }else if(percent >= 0.5 && percent < 0.8){
            printf("完成度超過一半，請繼續加油!!");
        }else if(percent >= 0.8 && percent < 1){
            printf("完成度高，距離全部完成不遠了!!");
        }else if(percent == 1){
            printf("待辦事項全部完成，請繼續保持!!");
        }else if(percent == 0){
            printf("沒有完成事項，請注意每天待辦事項!!");
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
        printf("1.輸入行程 2.設定睡眠鬧鐘 3.設定鬧鐘 4.完成事項 5.建議 6.結束\n");
        printf("請輸入選擇：");
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
                printf("請重新選擇\n\n");
                break;
        }
    }while(choose != 6 );
    return 0;
}
