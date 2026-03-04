#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<set>
#include<vector>
#include<map>
using namespace std;
typedef pair<int,int> PII;
const int N=4e5+10;
const int M=8e5+10;
int n,k,r,m,fa[N],siz[N],rt;
int he[N],ne[M<<1],to[M<<1],tot=1;
int fat[30][N],dep[N],yet[N];
bool st[N];
inline void addedge(int x,int y){
	to[++tot]=y;
	ne[tot]=he[x];
	he[x]=tot;
}
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
inline void bfs(int root){
	queue<int> q;
	q.push(root);
    dep[root]=1;
    fat[0][root]=root;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=he[x];i;i=ne[i]){
			int v=to[i];
			if(v==fat[0][x]){
				continue;
			}
			dep[v]=dep[x]+1;
			fat[0][v]=x;
			q.push(v);
		}
	}
}
inline int lca(int x,int y){
	int l=0;
	while((1<<l)<2*n){
		l++;
	}
	if(dep[x]<dep[y]){
		swap(x,y);
	}
	for(int i=l;i>=0;i--){
		if(dep[y]<=dep[x]-(1<<i)){
			x=fat[i][x];
		}
	}
	if(x==y){
		return x;
	}
	for(int i=l;i>=0;i--){
		if(fat[i][x]!=fat[i][y]){
			x=fat[i][x];
			y=fat[i][y];
		}
	}
	return fat[0][x];
}
inline int getori(int x,int len){
	for(int i=30;i>=0;i--){
		if((1<<i)<=len){
			x=fat[i][x];
			len-=(1<<i);
		}
	}
	return x;
}
int main(){
    // freopen("12.in","r",stdin);
    // freopen("12.out","w",stdout);
	scanf("%d%d%d",&n,&k,&r);
	memset(yet,-1,sizeof yet);
	k*=2;
	int x,y,z;
	for(int i=1;i<2*n;i++){
		fa[i]=i;
		siz[i]=1;
	}
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		addedge(x,n+i);
		addedge(n+i,x);
		addedge(n+i,y);
		addedge(y,n+i);
	}
	bfs(1);
	for(int i=1;(1<<i)<2*n;i++){
		for(int j=1;j<2*n;j++){
			fat[i][j]=fat[i-1][fat[i-1][j]];
		}
	}
    queue<int> q;
	for(int i=1;i<=r;i++){
		scanf("%d",&x);
		st[x]=true;
		q.push(x);
		yet[x]=0;
	}
	while(q.size()){
		int t=q.front();
		q.pop();
		if(yet[t]>=k/2){
			continue;
		}
		for(int i=he[t];i;i=ne[i]){
			int v=to[i];
			unify(v,t);
			if(yet[v]==-1){
				yet[v]=yet[t]+1;
				q.push(v);
			}
		}
	}
	scanf("%d",&m);
	while(m--){
		scanf("%d%d",&x,&y);
		if(dep[x]>dep[y]){
			swap(x,y);
		}
		int LCA=lca(x,y);
		if(find(x)==find(y)||dep[x]+dep[y]-2*dep[LCA]<=k){
			printf("YES\n");
			continue;
		}
		int lx,ly,len;
		if(dep[x]-dep[LCA]<k/2){
			len=dep[y]-dep[LCA]-(k/2-(dep[x]-dep[LCA]));
			lx=getori(y,len);
			ly=getori(y,k/2);
		}
		else if(dep[y]-dep[LCA]<k/2){
			len=dep[x]-dep[LCA]-(k/2-(dep[y]-dep[LCA]));
			ly=getori(x,len);
			lx=getori(x,k/2);
		}
		else{
			lx=getori(x,k/2);
			ly=getori(y,k/2);
		}
		if(find(lx)==find(ly)){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
}
