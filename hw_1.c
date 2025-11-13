#include<math.h>
#include<stdio.h>
#define pai 3.1415926
void faliure(){
    printf("Sorry.This function is currently not supported.\n");
}
int triangle_check(double a,double b,double c){
    if(a+b<=c||a+c<=b||b+c<=a){
        return 0;
    }
    return 1;
}
void triangle_area(double a,double b,double c){
    double s,area;
    s=(a+b+c)/2;
    area=sqrt(s*(s-a)*(s-b)*(s-c));
    printf("The triangle's area is %lf\n",area);
}
void triangle(){
    char ch;
    printf("Enter the side lengths of the triangle\n");
    double a,b,c;
    scanf("%lf%lf%lf",&a,&b,&c);
    if(!triangle_check(a,b,c)){
        printf("The diagram is illegal!\n");
        return;
    }
    printf("Which data do you want to calculate?[area(A)]\n");
    getchar();
    ch=getchar();
    if(ch=='A'){
        triangle_area(a,b,c);
    }
    else{
        faliure();
    }
}
void circle_perimeter(double r){
    double perimeter=2*pai*r;
    printf("The circle's perimeter is %lf\n",perimeter);
}
void circle_area(double r){
    double area=pai*r*r;
    printf("The circle's area is %lf\n",area);
}
void circle(){
    char ch;
    printf("Enter the side radius of the circle\n");
    double r;
    scanf("%lf",&r);
    printf("Which data do you want to calculate?[perimeter(P)/area(A)]\n");
    getchar();
    ch=getchar();
    if(ch=='P'){
        circle_perimeter(r);
    }
    else if(ch=='A'){
        circle_area(r);
    }
    else{
        faliure();
    }
}
int main(){
    char ch;
    printf("Start\nAre you sure to start the program?[Y/N]\n");
    ch=getchar();
    if(ch!='Y'){
        return 0;
    }
    do{
        printf("Please select the diagram you want to calculate.[triangle(T)/circle(C)]\n");
        getchar();
        ch=getchar();
        if(ch=='T'){
            triangle();
        }
        else if(ch=='C'){
            circle();
        }
        else{
            faliure();
        }
        printf("Do you want to continue?[Y/N]\n");
        getchar();
        ch=getchar();
    }
    while(ch=='Y');
}