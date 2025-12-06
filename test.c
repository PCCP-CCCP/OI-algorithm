#include<stdio.h>
#include<math.h>
#include<stdbool.h>
void swapi(int* pa,int* pb){
    int temp=*pa;
    *pa=*pb;
    *pb=temp;
}
void swapf(double* pa,double* pb){
    double temp=*pa;
    *pa=*pb;
    *pb=temp;
}
int maxi(int pa,int pb){
    if(pa>pb){
        return pa;
    }
    return pb;
}
int mini(int pa,int pb){
    if(pa>pb){
        return pb;
    }
    return pa;
}
void qsint(int a[],int len){
    if(len<=1){
        return;
    }
    int pivot=maxi(mini(a[0],a[(len-1)/2]),mini(maxi(a[0],a[(len-1)/2]),a[len-1]));
    int i=0,j=0,k=len;
    while(i<k){
        if(a[i]<pivot){
            swapi(&a[i++],&a[j++]);
        }
        else if(pivot<a[i]){
            swapi(&a[i],&a[--k]);
        }
        else{
            ++i;
        }
    }
    qsint(a,j);
    qsint(a+k,len-k);
}
int main(){
    const int N=1e5+10;
    int n,m,a[N],b[N];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&b[i]);
    }
    qsint(b,m);
    qsint(a,n);
    int ar=n-1,br=m-1;
    while(ar>=0||br>=0){
        if(a[ar]>b[br]||br<0){
            printf("%d ",a[ar]);
            ar--;
        }
        else if(a[ar]<b[br]||ar<0){
            printf("%d ",b[br]);
            br--;
        }
        else{
            do{
                ar--;
            }
            while(a[ar]==a[ar+1]);
            do{
                br--;
            }
            while(b[br]==b[br+1]);
        }
    }
}