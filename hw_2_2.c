#include<stdio.h>
#include<math.h>
int triangle_check(double a,double b,double c){
    if(a+b<=c||a+c<=b||b+c<=a){
        return 0;
    }
    return 1;
}
int isosceles_triangle(double a,double b,double c){
    if(a==b||b==c||a==c){
        return 1;
    }
    return 0;
}
int right_triangle(double a,double b,double c){
    if(a*a==b*b+c*c||b*b==a*a+c*c||c*c==a*a+b*b){
        return 1;
    }
    return 0;
}
int main(){
    char ch;
    printf("Start\nAre you sure to start the program?[Y/N]\n");
    ch=getchar();
    if(ch!='Y'){
        return 0;
    }
    do{
        double a,b,c;
        scanf("%lf%lf%lf",&a,&b,&c);
        if(!triangle_check(a,b,c)){
            printf("The diagram is illegal!\n");
        }
        else{
            int iso=isosceles_triangle(a,b,c);
            int rig=right_triangle(a,b,c);
            if(iso&&rig){
                printf("This is a isosceles right triangle.\n");
            }
            else if(iso&&!rig){
                printf("This is a isosceles triangle.\n");
            }
            else if(!iso&&rig){
                printf("This is a right triangle.\n");
            }
            else{
                printf("This is a normal triangle.\n");
            }
        }
        printf("Do you want to continue?[Y/N]\n");
        getchar();
        ch=getchar();
    }
    while(ch=='Y');
}