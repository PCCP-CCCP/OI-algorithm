#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;
const int N=50;
char mp[N][N];
int n,m,sx,sy,tx[N],ty[N],blod=1,cnt=0;
int nx,ny;
string k;
void mov(){
    if(mp[nx][ny]=='X'){
        blod--;
    }
    else if(mp[nx][ny]=='*'){
        blod++;
        mp[nx][ny]='.';
    }
    else if(mp[nx][ny]=='T'){
        if(nx==tx[0]&&ny==ty[0]){
            nx=tx[1],ny=ty[1];
        }
        else{
            nx=tx[0],ny=ty[0];
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
            if(mp[i][j]=='S'){
                sx=i,sy=j;
            }
            else if(mp[i][j]=='T'){
                tx[cnt]=i,ty[cnt]=j;
                cnt++;
            }
        }
    }
    cin>>k;
    nx=sx,ny=sy;
    int len=k.length();
    for(int i=0;i<len;i++){
        int ox=nx,oy=ny;
        switch (k[i])
        {
            case 'W':
                nx--;
                break;
            case 'A':
                ny--;
                break;
            case 'S':
                nx++;
                break;
            case 'D':
                ny++;
                break;
            default:
                break;
        }
        if(nx<1||nx>n||ny<1||ny>m||mp[nx][ny]=='#'){
            nx=ox,ny=oy; //回到原位置
            continue;
        }
        mov();
        if(blod<=0){
            break;
        }
        //cout<<nx<<","<<ny<<" blood:"<<blod<<" "<<mp[nx][ny]<<endl;
    }
    if(blod<=0){
        printf("The Slime died...");
    }
    else{
        printf("%d\n",blod);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nx==i&&ny==j){
                    cout<<'@';
                }
                else{
                    if(mp[i][j]=='S'){
                        mp[i][j]='.';
                    }
                    cout<<mp[i][j];
                }
            }
            printf("\n");
        }
    }
}