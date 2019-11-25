#include<cstdio>
using namespace std;
struct node{
	int a,b,i;
}d[100005];
int n, m,a, b, x, y, ans, u[200005];
int h[100005],v[100005], zhi[100005], xiao[100005];
void input(int a,int b,int x){
	d[x].a = a;	d[x].b = b;
	d[x].i = h[a];	h[a] = x;
}
void dfs(int a,int p){
	int b,i;
	for(int i=h[a];i;i=d[i].i){
		if(!u[i])	u[i] = u[i^1] = 1;
		else	continue;
		b = d[i].b;
		if(b == p)	continue;
		if(!v[b]){
			xiao[b] = v[b] = v[a] + 1;
			zhi[a]++;
			dfs(b,a);
			if(xiao[b] < v[a]){
				if(xiao[b] < xiao[a])	xiao[a] = xiao[b];
				zhi[a]--;
			}
			else if(v[b] < xiao[a])	xiao[a] = v[b];
			
		}
	}
	v[a] = -v[a];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d",&a,&b);
		if(a == b)	continue;
		input(a,b,i);
		input(a,b,i+n);
	}
	for(int i=1;i<=n;++i){
		if(!v[i])	v[i] = 1;
		dfs(i,0);
	}
	for(int i=1; i<=n; i++){
		if(zhi[i] > 1) ans++;
		else if(zhi[i] == 1 && v[i]!=-1) ans++;
	}
	printf("%d\n", ans);
	for(int i=1;i<=n;++i){
		if(zhi[i] > 1)	printf("%d ",i);
		if(zhi[i] == 1 && v[i]!=-1)	printf("%d ",i);	 
	} 
	return 0;
} 
