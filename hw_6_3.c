#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int main(){
    char str[10000];
    scanf(" %s",&str);
    int len=strlen(str);
    char* front=str;
    char* back=str;
    while(*back) ++back;
    --back;
    bool flag=true;
    while(front<=back){
        flag&=(*front==*back);
        if(!flag) break;
        ++front,--back;
    }
    if(flag) printf("yes\n");
    else printf("not\n");
}