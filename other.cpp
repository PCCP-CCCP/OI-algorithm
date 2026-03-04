#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
#define ll long long
#define pb push_back
#define FOR(i,j,k) for(register int i=j;(j<k)?(i<=k):(i>=k);i+=(j<k)?1:(-1))
#define N 233333

int n,m,k;
int f[2*N][21];//倍增father
int dep[2*N];//deep
int grf[2*N];//并查集的father
int vis[2*N];//bfs标记 （到驿站的dis）
vector<int> e[2*N];//边 
int gf(int x) {//路径压缩求祖先 
	if(grf[x]==x)return x;
	return grf[x]=gf(grf[x]);
}
int move(int x,int val) {//将x向祖先move val步后的id 
	FOR(i,20,0) {
		if((1<<i)<=val) {
			val-=(1<<i);
			x=f[x][i];
		}
	}
	return x;
}
int lca(int x,int y) {
	int xx,yy;
	if(dep[x]<dep[y])swap(x,y);
	x=move(x,dep[x]-dep[y]);
	if(x==y)return x;
	FOR(i,20,0) {
		xx=f[x][i];
		yy=f[y][i];
		if(xx!=yy) {
			x=xx;
			y=yy;
		}
	}
	return f[x][0];
}
void dfs(int rt,int fa) {
	dep[rt]=dep[fa]+1;
	f[rt][0]=fa;
	FOR(i,1,20)f[rt][i]=f[f[rt][i-1]][i-1];
	for(int i:e[rt]) {
		if(i==fa)continue;
		dfs(i,rt);
	}
}
signed main() {
    freopen("12.in","r",stdin);
    freopen("12.out","w",stdout);
	cin>>n>>m>>k;
	int x,y,z;
	FOR(i,1,n-1) {
		cin>>x>>y;//为判断奇偶方便虚拟点n+i 
		e[x].pb(n+i);//push_back 
		e[y].pb(n+i);
		e[n+i].pb(x);
		e[n+i].pb(y);
	}
	dfs(1,0);
	FOR(i,1,n*2)grf[i]=i;//init 
	queue<int> q;
	memset(vis,-1,sizeof vis);
	FOR(i,1,k) {
		cin>>x;
		q.push(x);
		vis[x]=0; 
	}
	while(!q.empty()) {//广搜 半径m 
		int tmp=q.front();
		q.pop();
		if(vis[tmp]==m)break;
		for(int i:e[tmp]) {
			grf[gf(i)]=gf(tmp);//并查集合并（多个驿站联合 商帮） 
			if(vis[i]==-1) {
				vis[i]=vis[tmp]+1;
				q.push(i);
			}
		}
	}
	int qu,ans1,ans2;
	cin>>qu; 
	FOR(i,1,qu) {
		cin>>x>>y;
		z=lca(x,y);
		int len=dep[x]+dep[y]-2*dep[z];//dis计算 
		if(len<=2*m)cout<<"YES"<<endl;//直接走 
		else {//抽屉原理：一定有一边从出发点至LCA距离>=m 
			ans1=(m<=dep[x]-dep[z])?gf(move(x,m)):gf(move(y,len-m));//x向y走m步 
			ans2=(m<=dep[y]-dep[z])?gf(move(y,m)):gf(move(x,len-m));//y向x走m步 
			cout<<(ans1==ans2?"YES":"NO")<<endl;//康康是否在一个并查集里 
		}
	}
	return 0;
}

