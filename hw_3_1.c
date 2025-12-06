#include<stdio.h>
#include<stdbool.h>
#include<math.h>
const int N=1e6+10;
int main(){
    int n,sq;
    double m;
    bool ans=true;
	scanf("%d",&n);
    m=sqrt(n);
    sq=ceill(m);
	for(int i=2;i<=sq;i++){
        if(!(n%i)&&i!=n){
            ans=false;
            break;
        }
    }
    if(n<=1){
        ans=false;
    }
	if(ans){
        printf("%d is prime number.\n",n);
    }
    else{
        printf("%d is not prime number.\n",n);
    }
}