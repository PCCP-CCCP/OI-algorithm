#include<stdio.h>
#include<math.h>
int main(){
    char ch;
    printf("Start\nAre you sure to start the program?[Y/N]\n");
    ch=getchar();
    if(ch!='Y'){
        return 0;
    }
    int year,month,day,mod400,mod100,mod4;
    do{
        scanf("%d%d",&year,&month);
        mod400=year%400;
        mod100=year%100;
        mod4=year%4;
        switch (month)
        {
            case 1:
                day=31;
                break;
            case 2:
                if(!mod400||(mod100&&!mod4)){
                    day=29;
                }
                else{
                    day=28;
                }
                break;
            case 3:
                day=31;
                break;
            case 4:
                day=30;
                break;
            case 5:
                day=31;
                break;
            case 6:
                day=30;
                break;
            case 7:
                day=31;
                break;
            case 8:
                day=31;
                break;
            case 9:
                day=30;
                break;
            case 10:
                day=31;
                break;
            case 11:
                day=30;
                break;
            case 12:
                day=31;
                break;
            default:
                break;
        }
        printf("This month in this year have %d days.\n",day);
        printf("Do you want to continue?[Y/N]\n");
        getchar();
        ch=getchar();
    }
    while(ch=='Y'||ch=='y');
}