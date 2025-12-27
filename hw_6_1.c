#include<stdio.h>
int* max(int* x,int* y){
    return (*x>*y)?x:y;
}
int* min(int* x,int* y){
    return (*x<*y)?x:y;
}
int main(){
    int stdmax=-1e9,stdmin=1e9,a[11];
    int* maxp=&stdmax;
    int* minp=&stdmin;
    for(int i=1;i<=10;i++){
        scanf("%d",&a[i]);
        maxp=max(maxp,&a[i]);
        minp=min(minp,&a[i]);
    }
    printf("minium is:%d,maxium is:%d\n",*minp,*maxp);
}