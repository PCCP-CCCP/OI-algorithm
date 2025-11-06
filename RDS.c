#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<fcntl.h>
#define N 100000
int hit[N],size;
int get_random_bytes(void *buffer,size_t size) {
    int fd=open("/dev/urandom",O_RDONLY);
    if(fd==-1){
        return -1;
    }
    ssize_t result=read(fd,buffer,size);
    close(fd);
    return (result==(ssize_t)size)?0:-1;
}
int random_range(int min,int max) {
    unsigned int rand_val;
    get_random_bytes(&rand_val,sizeof(rand_val));
    return min+(rand_val%(max-min+1));
}
int check(int x){
    for(int i=0;i<size;i++){
        if(hit[i]==x){
            return 1;
        }
    }
    return 0;
}
int get(int max){
    int x=-1;
    if(size>=max){
        return x;
    }
    do{
        x=random_range(1,max);
        if(!check(x)){
            hit[size]=x;
            ++size;
            return x;
        }
    }
    while(x);
}
int main(void){
    int n;
    char ch;
    printf("Start\nAre you sure to start the program? [Y/N]");
    ch=getchar();
    if(ch=='N'){
        return 0;
    }
    printf("Please key the total number of your class: ");
    scanf("%d",&n);
    do{
        int x=get(n);
        if(x>0){
            printf("The luckydog is: %d\n",x);
        }
        else{
            printf("No one left!\n");
            break;
        }
        printf("Do you want to continue? [Y/N]");
        getchar();
        ch=getchar();
    }
    while(ch=='Y');
}