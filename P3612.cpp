#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    string s;
    long long n,tmp;
    cin>>s>>n;
    int len=s.length(),tim;
    while(n>len){
        tmp=len;
        while(n>tmp){
            tmp*=2;
        }
        tmp=tmp/2;
        n-=(tmp+1);
        if(!n){
            n=tmp;
        }
    }
cout<<s[n-1];
}