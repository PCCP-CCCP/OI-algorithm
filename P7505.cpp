#include<iostream>
#include<cmath>
#include<cstdio>
#include<deque>
using namespace std;
const int N=3e5+10;
int n,m;
long long sum,k,x;
deque<long long> q;
int main(){
    scanf("%d%d%lld",&n,&m,&k);
    int l=1,r=n,opt;
    for(int i=1;i<=n;i++){
        scanf("%lld",x);
        q.push_back(x);
    }
    while(m--){
        scanf("%d",&opt);
        if(opt==1){
            scanf("%lld",&x);
            sum+=x;
            long long bc=q.back();
            while(bc+sum>k){
                q.pop_back();
                bc=q.back();
            }
        }
        else if(opt==2){
            scanf("%lld",&x);
            sum-=x;
            long long ft=q.front();
            while(a[l]+sum<-k&&l<=r){
                l++;
            }
        }
        else{
            printf("%d\n",r-l+1);
        }
    }
}