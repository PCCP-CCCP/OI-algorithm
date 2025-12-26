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
static bool flag[11];
static int n,a[5],b[5],x;
int main(){
    for(int i=1;i<10;i++){
        flag[i]=false;
    }
    for(int i=1;i<=4;i++){
        do{
            a[i]=random_int_range(0,9);
        }
        while(flag[a[i]]);
        flag[a[i]]=true;
    }
    printf("请输入允许猜测的最大次数:\n");
    scanf("%d",&n);
    while(n--){
        printf("请输入你猜测的数字:\n");
        scanf("%d",&x);
        int cnt=0,A=0,B=0;
        while(x){
            cnt++;
            b[cnt]=x%10;
            x/=10;
        }
        for(int i=1;i<=4;i++){
            if(a[i]==b[i]){
                A++;
            }
            else if(flag[b[i]]){
                B++;
            }
        }
        if(A==4){
            printf("Congratulations!\n");
            return 0;
        }
        else{
            printf("%dA%dB\n",A,B);
            printf("Wrong!Continue.\n");
        }
    }
    printf("The answer is:");
    for(int i=4;i>=1;i--){
        printf("%d",a[i]);
    }
    printf("\nSorry, you haven't guess the right number!");
}