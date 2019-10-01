#include<iostream>
#include<cstdio>
#include<cstdlib>
int n,st[100010],width,x[100010],cnt=0,wid[100010]; //st为高度的栈，wid为了储存单调优化后的栈中矩形的宽
long long ans=0;
long long max(long long x,long long y){
    return x>y ? x : y;
    }
int main(){
    while(1){
        ans=0;
        scanf("%d",&n);
        if(n==0) break;
        st[0]=-1;
        for(int i=1;i<=n;i++){
           scanf("%d",&x[i]);
        }
        x[n+1]=cnt=0;             //最后一个最小的矩形
        for(int i=1;i<=n+1;i++){
            if(st[cnt]<x[i]){
              st[++cnt]=x[i];
              wid[cnt]=1;
            }
            else{
              width=0;
              while(st[cnt]>x[i] && cnt>0){
              width+=wid[cnt];
              ans=max(ans,(long long)width*st[cnt]);
              cnt--;
              }
              st[++cnt]=x[i];
              wid[cnt]=width+1;
            }
        }
    printf("%lld\n",ans);
    }
    return 0;
}
