#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=1e5+10;
int n,cnt,num,last,ans[N<<1];
queue<int> q;
struct node{
    int val,l,r;
    bool yet;
} tree[N<<1];
void insert(int x){
    ++cnt;
    tree[cnt].val=x;
    if(x==1){
        tree[cnt].yet=true;
    }
    else{
        tree[cnt].yet=false;
    }
    int father=q.front();
    if(!tree[father].l){
        tree[father].l=cnt;
    }
    else{
        tree[father].r=cnt;
        q.pop();
    }
    if(x>=0){
        q.push(cnt);
    }
}
void update_tree(int now){
    if(!tree[now].l&&!tree[now].r){
        return;
    }
    if(tree[now].l){
        update_tree(tree[now].l);
        tree[now].yet|=tree[tree[now].l].yet;
    }
    if(tree[now].r){
        update_tree(tree[now].r);
        tree[now].yet|=tree[tree[now].r].yet;
    }
    return;
}
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    char ch;
    while((ch=getchar())!=']'){
        if(ch=='0'){
            insert(0);
        }
        else if(ch=='1'){
            insert(1);
        }
        else if(ch=='n'){
            insert(-1);
        }
    }
    while(q.size()){
        q.pop();
    }
    update_tree(1);
    q.push(1);
    while(q.size()){
        int father=q.front();
        ++num;
        ans[num]=father;
        q.pop();
        if((!tree[father].l&&!tree[father].r)||!father){
            continue;
        }
        if(tree[tree[father].l].yet){
            q.push(tree[father].l);
        }
        else{
            q.push(0);
        }
        if(tree[tree[father].r].yet){
            q.push(tree[father].r);
        }
        else{
            q.push(0);
        }
    }
    for(int i=num;i>0;i--){
        if(ans[i]!=0){
            last=i;
            break;
        }
    }
    printf("[");
    for(int i=1;i<last;i++){
        if(ans[i]){
            printf("%d,",tree[ans[i]].val);
        }
        else{
            printf("null,");
        }
    }
    printf("%d]\n",tree[ans[last]].val);
}