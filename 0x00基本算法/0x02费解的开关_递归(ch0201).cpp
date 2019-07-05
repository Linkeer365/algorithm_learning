#include<bits/stdc++.h>
using namespace std;
int n,a[10],m[10][10],p[10][10];
int ans,sum;
void pre(){
	for(int i=1;i<=5;i++){
		int t=10000,b=a[i];
		for(int j=1;j<=5;j++){
			m[i][j]=b/t;
			b=b-b/t*t;
			t/=10;
		}
	}
	return ;
}
int f(int x){
	sum=x;
	for(int i=1;i<=5;i++)
	 for(int j=1;j<=5;j++)
	  p[i][j]=m[i][j];
	for(int i=1;i<=4;i++)
	 for(int j=1;j<=5;j++)
	  if(!p[i][j]){
	  	sum++;
	  	p[i][j]^=1;
	  	p[i+1][j]^=1;
	  	p[i+1][j+1]^=1;
	  	p[i+1][j-1]^=1;
	  	p[i+2][j]^=1;
	  }
	for(int i=1;i<=5;i++)
	if(!p[5][i]) return 0x3f3f3f3f;
	 return sum;
}
void dfs(int lie,int step){
	if(lie>5){
		ans=min(ans,f(step));
		return ;
	}
	m[1][lie]^=1;
	m[2][lie]^=1;
	m[1][lie+1]^=1;
	m[1][lie-1]^=1;
	dfs(lie+1,step+1);
	m[1][lie]^=1;
	m[2][lie]^=1;
	m[1][lie+1]^=1;
	m[1][lie-1]^=1;
	dfs(lie+1,step);
	return ;
}
int main(){
	cin>>n;
	while(n--){
		ans=0x3f3f3f3f;
		sum=0;
		for(int i=1;i<=5;i++) cin>>a[i];
		pre();
		dfs(1,0);
		if(ans<=6) cout<<ans<<endl;
		else cout<<"-1"<<endl;
	}
	return 0;
}
