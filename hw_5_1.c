#include<Windows.h>
#include<stdio.h>
#include<stdbool.h>
#include<bcrypt.h>
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
int main(){
    int cnt[11];
    for(int i=1;i<=10;i++){
        cnt[i]=0;
    }
    for(int i=1;i<=40;i++){
        int x=random_int_range(1,10);
        cnt[x]++;
    }
    printf("Grade Count Histogram\n");
    for(int i=1;i<=10;i++){
        printf("%-5d %-5d ",i,cnt[i]);
        for(int j=1;j<=cnt[i];j++){
            printf("*");
        }
        printf("\n");
    }
}