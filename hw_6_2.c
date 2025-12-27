#include<stdio.h>
char* strcat(char* dststr,char* srcstr){
    char* d=dststr;
    while(*d) d++;
    while((*d++=*srcstr++));
    return dststr;
}
int main(){
    char dststr[100],srcstr[100];
    scanf("%s",dststr);
    scanf("%s",srcstr);
    char* dest=strcat(dststr,srcstr);
    printf("%s\n",dststr);
}