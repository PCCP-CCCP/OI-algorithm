#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<list>
#include<unordered_set>
#include<unordered_map>
#include<vector>
#define PII pair<int,int>
#define PLL pair<long long,long long>
#define II int,int
#define PLFII pair<double,PII>
#define PIP pair<int,PII>
using namespace std;
const int N=2e5+10;
const long long M=2147483648;
const int MOD=998244353;
const int INF=0x3f3f3f3f;
int t,n,x,y,a[N],insmin=INF;
vector<int> ins,outs;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&x,&y);
        insmin=INF;
        ins.clear();
        outs.clear();
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n;i++){
            if(x<i&&i<=y){
                ins.push_back(a[i]);
                insmin=min(insmin,a[i]);
            }
            else{
                outs.push_back(a[i]);
            }
        }
        vector<int>::iterator it_in,it_out;
        for(it_out=outs.begin();it_out!=outs.end();it_out++){
            if(*it_out<insmin){
                printf("%d ",*it_out);
            }
            else{
                break;
            }
        }
        for(it_in=ins.begin();it_in!=ins.end();it_in++){
            if(*it_in==insmin){
                break;
            }
        }
        for(it_in;it_in!=ins.end();it_in++){
            printf("%d ",*it_in);
        }
        for(it_in=ins.begin();it_in!=ins.end();it_in++){
            if(*it_in==insmin){
                break;
            }
            printf("%d ",*it_in);
        }
        for(it_out;it_out!=outs.end();it_out++){
            printf("%d ",*it_out);
        }
        printf("\n");
    }
}