#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> cells;
int dr[4]={1,-1,0,0};
int dc[4]={0,0,1,-1};

int shortest(const set<pair<int,int>>& blocked,int n){
    pair<int,int> start={1,1};
    if(blocked.count(start)) return -1;
    queue<pair<pair<int,int>,int>>q;
    set<pair<int,int>> vis;
    q.push({start,0}); vis.insert(start);
    while(!q.empty()){
        auto cur=q.front();q.pop();
        auto p=cur.first; int d=cur.second;
        if(p.second==n && !blocked.count(p)) return d;
        for(int k=0;k<4;k++){
            int nr=p.first+dr[k], nc=p.second+dc[k];
            if(nr<1||nr>2||nc<1||nc>n) continue;
            pair<int,int> np={nr,nc};
            if(blocked.count(np)) continue;
            if(vis.count(np)) continue;
            vis.insert(np);
            q.push({np,d+1});
        }
    }
    return -1;
}

map<pair<vector<pair<int,int>>,int>,int> memo;

int solve(vector<pair<int,int>> blocked_vec,int turn,int n){
    sort(blocked_vec.begin(),blocked_vec.end());
    auto key=make_pair(blocked_vec,turn);
    if(memo.count(key)) return memo[key];
    set<pair<int,int>> blocked(blocked_vec.begin(),blocked_vec.end());
    vector<pair<int,int>> moves;
    for(int r=1;r<=2;r++) for(int c=1;c<=n;c++){
        pair<int,int> p={r,c};
        if(p==make_pair(1,1)) continue;
        if(blocked.count(p)) continue;
        blocked.insert(p);
        if(shortest(blocked,n)!=-1) moves.push_back(p);
        blocked.erase(p);
    }
    if(moves.empty()){
        int sp=shortest(blocked,n);
        return memo[key]=sp;
    }
    if(turn==0){ // red minimize
        int best=1e9;
        for(auto mv:moves){
            blocked_vec.push_back(mv);
            int val=solve(blocked_vec,1,n);
            blocked_vec.pop_back();
            best=min(best,val);
        }
        return memo[key]=best;
    } else {
        int best=-1;
        for(auto mv:moves){
            blocked_vec.push_back(mv);
            int val=solve(blocked_vec,0,n);
            blocked_vec.pop_back();
            best=max(best,val);
        }
        return memo[key]=best;
    }
}

int main(){
    for(int nn=1;nn<=12;nn++){
        memo.clear();
        int res=solve({},0,nn);
        cout<<nn<<" "<<res<<"\n";
    }
}
