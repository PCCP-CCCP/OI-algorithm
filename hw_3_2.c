#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdbool.h>
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
int main(){
    int number,guess,cnt=0;
    char opt;
    do{
        cnt=0;
        number=random_range(1,100);
        while(true){
            cnt++;
            printf("Please write the number you guess: ");
            scanf("%d",&guess);
            if(number==guess){
                printf("Right!\n");
                break;
            }
            else{
                printf("Wrong!");
                if(number<guess){
                    printf("Too high!\n");
                }
                else{
                    printf("Too low!\n");
                }
            }
            if(cnt>=10){
                printf("You lose!\n");
                break;
            }
        }
        printf("You have guessed %d times!\n",cnt);
        printf("Do you want to continue?[Y/y or N/n]:");
        scanf(" %c",&opt);
    }
    while(opt=='Y'||opt=='y');
}