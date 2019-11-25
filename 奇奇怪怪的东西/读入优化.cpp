#include<cstdio>
using namespace std;
int read(){
	int f=1,x=0;char ch=getchar();
	while(ch <'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
int main(){
	int n=read();
	return 0;
}
