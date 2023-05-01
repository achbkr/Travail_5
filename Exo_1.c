#include<stdio.h>
struct Time
{
    int hour,minute,second;
};

void To_seconds(struct Time T);
void To_Time(int Time_seconds,struct Time T);
int Sum(struct Time T,struct Time T_1,struct Time T_2);

int main(){
   int Time_seconds;
   struct Time T[2];
   struct Time sum;

   printf("Enter time \n");
   printf("Hours :\n");
   scanf("%d",&T[0].hour);
   printf("Minutes :\n");
   scanf("%d",&T[0].minute);
   printf("Seconds :\n");
   scanf("%d",&T[0].second);
   To_seconds(T[0]);
   printf("Enter a time in seonds :\n");
   scanf("%d",&Time_seconds);
   To_Time(Time_seconds,T[1]);
   printf("_____Exo 1_3\n\n");
   for(int i=0;i<=1;i++){
    printf("Enter the %d time\n",i+1);
    printf("Hours :\n");
    scanf("%d",&T[i].hour);
    printf("Minutes :\n");
    scanf("%d",&T[i].minute);
    printf("Seconds :\n");
    scanf("%d",&T[i].second);
    }
   Sum(sum,T[0],T[1]);
    return 0;
}


void To_seconds(struct Time T){
    printf("____Exo1_1\n\n");
     int S=0;
     S=T.hour*3600+T.minute*60+T.second;
     printf("time with seconds is %d Sec\n",S);
     printf("\n\n\n");
}

void To_Time(int Time_seconds,struct Time T){
    printf("____Exo1_2\n\n");
    T.hour=Time_seconds/3600;
    Time_seconds=Time_seconds-(T.hour*3600);
    T.minute=Time_seconds/60;
    T.second=Time_seconds%60;
    printf("Le temps est : %d H/%d M/%d S\n",T.hour,T.minute,T.second);
    printf("\n\n\n");
}

int Sum(struct Time T,struct Time T_1,struct Time T_2){
    T.hour=T_1.hour+T_2.hour;
    T.minute=T_1.minute+T_2.minute;
    T.second=T_1.second+T_2.second;
    printf("sum is %d H/%d M/%d S",T.hour,T.minute,T.second);
}