#include<bits/stdc++.h>
using namespace std;
int n,a[10],m[10][10];
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
void change(int x,int y){
	m[x][y]^=1;
	m[x-1][y]^=1;
	m[x+1][y]^=1;
	m[x][y-1]^=1;
	m[x][y+1]^=1;
	return ;
}
bool judge(){
	for(int i=1;i<=5;i++)
	 for(int j=1;j<=5;j++)
	  if(!m[i][j]) return false;
	return true;
}
int main(){
	cin>>n;
	while(n--){
		for(int i=1;i<=5;i++) cin>>a[i]; 
		
		ans=0x3f3f3f3f;
		/*for(int i=1;i<=5;i++){
		 for(int j=1;j<=5;j++){
		  cout<<m[i][j];
		  
		  }cout<<endl;
		}*/
		
		for(int i=0;i<=31;i++){
			sum=0;
			pre();
			for(int j=0;j<=4;j++)
			if(((i>>j)&1)) {change(1,j+1);sum++;}
			for(int j=2;j<=5;j++){
				for(int k=1;k<=5;k++){
					if(!m[j-1][k]) {change(j,k);sum++;}
				}
			}
		if(judge()) ans=min(ans,sum);
		}
		if(ans<=6) cout<<ans<<endl;
		else cout<<"-1"<<endl;
	}
	return 0;
}
