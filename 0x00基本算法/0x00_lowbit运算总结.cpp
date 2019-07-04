#include<bits/stdc++.h>
using namespace std;
//配合hash输出遍非负整数n中所有为1的位置 
//lowbit解释：定义：lowbit(n)表示最低为的1和后面的0；
//1、先取反；2、+1；3、做&运算；即lowbit(n)=n&(~n+1),又~n=-1-n,所以lowbit(n)=n&-n;
int h[37],n;
int main(){
	 for(int i=0;i<36;i++) h[(1ll<<i)%37]=i; //此处的技巧是任取k=1~35，2^k mod 37 互不相等，且恰好取遍整数1~36; 
     while(cin>>n){
	 
		while(n>0){
			cout<<h[(n&-n)%37]<<endl;
			n-=n&-n;
		}
	}
	return 0;
} 
