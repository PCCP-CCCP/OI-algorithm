#include<windows.h>
#include<stdio.h>
#include<stdbool.h>
#include<bcrypt.h>
#include<conio.h>
#pragma comment(lib, "bcrypt.lib")
int random_int(void) {
    int value;
    //使用 BCryptGenRandom 生成随机数
    NTSTATUS status=BCryptGenRandom(
        NULL,//算法句柄，NULL表示使用默认
        (BYTE*)&value,//输出缓冲区
        sizeof(value),//缓冲区大小（4字节）
        BCRYPT_USE_SYSTEM_PREFERRED_RNG //标志位
    );
    //检查是否成功
    if(status>=0){
        return value;
    }
    else{
        return 0;//如果失败，返回0
    }
}
int random_int_range(int min,int max) {
    if(min>=max){
        return min;
    }
    //生成随机整数
    int random_val=random_int();
    //确保是正数
    if(random_val<0){
        random_val=-random_val;
    }
    //计算在[min, max]范围内的值
    return min+(random_val%(max-min+1));
}
void throw_dice(int* a,int* b){
    char ch;
    int dice;
    printf("Press 'Enter' to throw dices.\n");
    while(true){
        if (_kbhit()){//如果有按键按下，则_kbhit()函数返回真
            ch=_getch();//使用_getch()函数获取按下的键值
            if (ch==13){
                break;
            }//当按下Enter时循环
        }
    }
    *a=random_int_range(1,6);
    *b=random_int_range(1,6);
    printf("Your dice is %d and %d.\n",*a,*b);
}
void status_display(int gamestatus){
    if(gamestatus==-1){
        printf("You lost!\n");
    }
    else if(gamestatus==0){
        printf("The game is continue.\n");
    }
    else{
        printf("You won!\n");
    }
}
void go_on(int goal){
    int a,b,tot;
    printf("The goal is %d\n.",goal);
    for(int i=1;i<=7;i++){
        throw_dice(&a,&b);
        tot=a+b;
        if(tot==goal){
            status_display(1);
            return;
        }
        else{
            status_display(0);
        }
    }
    status_display(-1);
    return;
}
int main(){
    int a,b,tot;
    throw_dice(&a,&b);
    tot=a+b;
    if(tot==7||tot==11){
        status_display(1);
    }
    else if(tot==2||tot==3||tot==12){
        status_display(-1);
    }
    else{
        status_display(0);
        go_on(tot);
    }
}