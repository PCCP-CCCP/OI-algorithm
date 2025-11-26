#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
    char ch,str[]="";
    double data1,data2;
    do{
        scanf("%lf",&data1);
        scanf("%s",str);
        scanf("%lf",&data2);
        switch (str[0])
        {
            case '+':
                printf("%lf + %lf = %lf\n",data1,data2,data1+data2);
                break;
            case '-':
                printf("%lf - %lf = %lf\n",data1,data2,data1-data2);
                break;
            case '*':
                printf("%lf * %lf = %lf\n",data1,data2,data1*data2);
                break;
            case '/':
                if(fabs(data2)<=1e-7){
                    printf("Division by zero!\n");
                }
                else{
                    printf("%lf + %lf = %lf\n",data1,data2,data1/data2);
                }
                break;
            default:
                break;
        }
        printf("Do you want to continue?[Y/N or y/n]\n");
        scanf(" %c",&ch);
    }
    while(ch=='Y'||ch=='y');
}