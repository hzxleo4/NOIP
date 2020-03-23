#include<cstdio>
#define p 998244353
#define n 10000000
using namespace std;
int inv[10000005],jie[10000005],ni[10000005],t,k;
int exgcd(int a,int b,int &x,int &y){
	if(b == 0){
		x = 1;		y = 0;
	}
	exgcd(b,a%b,y,x);
	y -= a/b * x;
} 
int main(){
	//Ë³ÍÆ inv[1]=1
	for(int i=2;i<=n;++i){
		inv[i] = (p - p/i) * inv[p % i] % p;
	}
	//ÄæÍÆ 
	jie[0] = 1;
	for(int i=1;i<=n;++i){
		jie[i] = jie[i-1] * i % p; 
	}
	int x,y;
	exgcd(jie[n],p,x,y);
	ni[n] = x;
	ni[n] = (ni[n] % p + p) % p;
	for(int i=n-1;i>=1;--i){
		ni[i] = (i+1) * ni[i+1] % p;
	}
	int T;
	scanf("%d",&T);
	long long z = 1;
	while(T--){
		scanf("%d%d",&t,&k);
		printf("%lld",z * jie[t] * ni[k] % p * ni[t-k]%p);
	}
	return 0;
}
