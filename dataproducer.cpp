#include<Windows.h>
#include<bcrypt.h>
#include<iostream>
#include<cmath>
#pragma comment(lib, "bcrypt.lib")
using namespace std;
int random_int(void){
    int value;
    //使用 BCryptGenRandom 生成随机数
    NTSTATUS status=BCryptGenRandom(
        NULL,//算法句柄，NULL表示使用默认
        (BYTE*)&value,//输出缓冲区
        sizeof(value),//缓冲区大小（4字节）
        BCRYPT_USE_SYSTEM_PREFERRED_RNG //标志位
    );
    //检查是否成功
    if(status>=0){
        return value;
    }
    else{
        return 0;//如果失败，返回0
    }
}
int random_int_range(int min,int max){
    if(min>=max){
        return min;
    }
    //生成随机整数
    int random_val=random_int();
    //确保是正数
    if(random_val<0){
        random_val=-random_val;
    }
    //计算在[min, max]范围内的值
    return min+(random_val%(max-min+1));
}
const int N=2e5+10;
int n_lim,m_lim;
int n,k,r,m;
int fa[N],siz[N];
bool flag[N];
inline int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
inline void unify(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy){
		return;
	}
	if(siz[fx]<siz[fy]){
		swap(fx,fy);
	}
	fa[fy]=fx;
	siz[fx]+=siz[fy];
}
int main(){
    freopen("13.in","w",stdout);
    scanf("%d",&n_lim);
    scanf("%d",&m_lim);
    n=n_lim;
    int k_lim=log(n);
    k=10001;
    r=2;
    printf("%d %d %d\n",n,k,r);
    for(int i=1;i<n;i++){
        printf("%d %d\n",i,i+1);
    }
    printf("100000\n110002\n");
    m=m_lim;
    printf("%d\n",m);
    for(int i=1;i<=m;i++){
        int x,y;
        do{
            x=random_int_range(1,n);
            y=random_int_range(1,n);
        }
        while(x==y);
        printf("%d %d\n",x,y);
    }
}