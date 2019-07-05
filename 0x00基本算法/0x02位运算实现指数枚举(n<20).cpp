#include<bits/stdc++.h>
using namespace std;
int n,k; 
int h[37];
int main(){
	for(int i=0;i<36;i++)
	 h[(1ll<<i)%37]=i;
	
	cin>>n;
	k=1<<n;
	for(int i=1;i<=k;i++){
		int j=i;
		while(j>0){
			if(h[(j&-j)%37]+1<=n)
			cout<<h[(j&-j)%37]+1<<' ';
			j-=j&-j;
		}
		cout<<endl;
	}
	
	return 0;
}
