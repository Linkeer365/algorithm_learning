//luogu1175
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
char s[110],st[110],fh[110]; //s是字符串，st是后缀表达式，也就是最终转化后的结果栈，fh是符号栈
int cnt=0,cntfh=0,val[4000]={},cntnum=0,lf,cntl=0; //cnt，cntfh，cntnum分别是st，fh和nusmt的栈顶下标
long long tmp,numst[1100]; //numset是算好后的的数字栈，为了方便输出
void csh(){
   val['('+'0']=1;
   val['+'+'0']=2;
   val['-'+'0']=2;
   val['*'+'0']=3;
   val['/'+'0']=3;
   val['^'+'0']=4;
   return ;
}
void out4(int x){            //每次要清空左括号后还有的合法的符号栈中的栈
    while(cntfh>0 && val[fh[cntfh]+'0']>val[x]){
        st[++cnt]=fh[cntfh--];
    }
    return ;
}
void out1(){ 
  while(cntfh>0 && fh[cntfh]!='('){
            st[++cnt]=fh[cntfh--];
        }
  cntfh--;
  cntl--;
  if(cntl==0 && cntfh!=0) out4(fh[cntfh]+'0'); 
 
  return ;
}
void out2(int x){
    while(cntfh>0 && val[fh[cntfh]+'0']>=val[x]){
        st[++cnt]=fh[cntfh--];
    }
    return ;
}
void out3(int x,int y){       //最终的输出，分两部分输出
    for(int i=1;i<=x;i++) cout<<numst[i]<<" ";
    for(int i=y;i<=cnt;i++) cout<<st[i]<<" ";
    lf=y+1;
    cout<<endl;
    return ;
}
long long f(int x,int y){
    int t=1;
    for(int i=1;i<=y;i++)
    t*=x;
    return t;
}
void convert(){
  for(unsigned int i=0;i<strlen(s);i++){
      //cout<<val[s[i]+'0']<<endl;
    if((s[i]>='0' && s[i]<='9')){  //数字直接入栈
        st[++cnt]=s[i];
    }
    else if(s[i]==')'){   //右括号把符号栈中的第一个左括号前的全部出栈
        out1();
    }
    else if(s[i]=='('){   //遇到左括号入栈
        fh[++cntfh]=s[i];
        cntl++;
            }
    else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='^'){ //如果是第一个符号直接入栈，如果符号栈中已经有符号，
                                                                            //则出到当前比栈顶符号大为止
           if(val[s[i]+'0']>val[fh[cntfh]+'0'] && cntfh!=0){
          fh[++cntfh]=s[i];
         }
        else if(cntfh==0){
          fh[++cntfh]=s[i];
         }
        else{
          out2(s[i]+'0');
          fh[++cntfh]=s[i];
         }
    }
  }
  while(cntfh>0) st[++cnt]=fh[cntfh--];            //清空符号栈
  for(int i=1;i<=cnt;i++) cout<<st[i]<<" ";
  return ;
}
void calculate(){
  for(int i=1;i<=cnt;i++){
  	if(st[i]=='+' && cntnum>1){
  	  tmp=numst[cntnum-1]+numst[cntnum];
  	  cntnum-=2;
      numst[++cntnum]=tmp;
      out3(cntnum,i+1);
  	}
  	else if(st[i]=='-'&& cntnum>1){
  	  tmp=numst[cntnum-1]-numst[cntnum];
  	  cntnum-=2;
      numst[++cntnum]=tmp;
      out3(cntnum,i+1);
  	}
  	else if(st[i]=='*'&& cntnum>1){
  	  tmp=numst[cntnum-1]*numst[cntnum];
  	  cntnum-=2;
      numst[++cntnum]=tmp;
      out3(cntnum,i+1);
  	}
  	else if(st[i]=='/' && numst[cntnum]!=0&& cntnum>1){
  	  tmp=numst[cntnum-1]/numst[cntnum];
	  cntnum-=2;
      numst[++cntnum]=tmp;
      out3(cntnum,i+1); 
  	}
    else if(st[i]=='^'&& cntnum>1){
  	  tmp=f(numst[cntnum-1],numst[cntnum]);
	  cntnum-=2;
      numst[++cntnum]=tmp;
      out3(cntnum,i+1); 
  	}
  	else if(st[i]>='0' && st[i]<='9'){
  	  numst[++cntnum]=st[i]-'0';
	  //cout<<numst[cntnum]<<endl;
  	}
  }
  return ;
}
void left(){
    while(lf<=cnt){
        for(int i=lf;i<=cnt;i++) cout<<st[i]<<" ";
        lf++;
        cout<<endl;
    }
}
int main(){
  csh();
  cin>>s;
  convert();//转化到中缀表达式
  cout<<endl;
  calculate();
  left(); //没啥用，当时怕字符串本身有问题
  return 0;
}
