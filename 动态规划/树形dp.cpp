#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int a,b,i,n;
}d[100005];
int h[100005],p[100005],f[100005],g[100005],n; 
void input(int i,int a,int b){
	d[i].a = a;		d[i].b = b;
	d[i].n = h[a];	h[a] = i;
}
void dfs(int a){
	f[a] = p[a];
	for(int i=h[a];i;i=d[i].n){
		int b = d[i].b;
		if(!f[b]){
			dfs(b);
			f[a] += g[b];
			g[a] += max(f[b],g[b]);
		}
	}
}
int main(){
	int a,b;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&p[i]);
	}
	for(int i=1;i<=n-1;++i){
		scanf("%d%d",&a,&b);
		input(i,a,b);
		input(i+n-1,b,a);
	}
	dfs(a);
	printf("%d",max(f[a],g[a]));
	return 0;
}
