#include<cstdio>
using namespace std;
int n,r[1005],p[1005],ans,m=1;
void exgcd(int a,int b,int &x,int &y){
	if(b == 0)	{
		x = 1;	y = 0;
	}
	else{
		exgcd(b,a%b,y,x);
		y -= a/b * x;
	}
}
int niyuan(int a,int b){
	int x;int y;
	exgcd(a,b,x,y);
	return (x%b+b)%b;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&r[i],&p[i]);
		m *= p[i];
	}
	for(int i=1;i<=n;++i){
		p[i] = m / p[i];
	}
	for(int i=1;i<=n;++i){
		ans += r[i] * p[i]  * niyuan(p[i],m/p[i]) % m;
	}
	printf("%d",ans%m);
	return 0;
}
