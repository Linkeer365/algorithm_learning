#include<bits/stdc++.h>
using namespace std;
int a,b,p;
int f(int a,int b,int p){
	int ans=1%p;
	for(;b;b>>=1){
		if(b&1) ans=(long long)ans*a%p;
		a=(long long)a*a%p;   //a^2^i=(a^2^i-1)^2
	}
	return ans;
}
int main(){
	cin>>a>>b>>p;
	cout<<a<<"^"<<b<<" "<<"mod"<<" "<<p<<"="<<f(a,b,p)<<endl;
	return 0;
}
