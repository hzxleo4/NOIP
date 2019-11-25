#include<cstdio>//tarjan缩点+DAGdp 
#include<cstring>
#define max(a,b) a > b ? a : b
using namespace std;
struct node{
	int a,b,n;
}d[100005],e[100005];
int f[10005],h[10005],v[10005],in[10005],dis[10005],w[10005],head,tail,q[100005];
int fans;
int find(int x){
	if(x == f[x])	return x;
	else	return f[x] = find(f[x]);
}
void input(int i,int a,int b){
	d[i].b = b;	d[i].a = a;
	d[i].n = h[a];	h[a] = i;
}
void dfs(int a){
	for(int i=h[a];i;i=d[i].n){
		int b = d[i].b;
		if(!v[b]){//如果b没找过 
			v[b] = v[a]+1;//深度+1 
			dfs(b);//搜索 
		}
		if(v[find(b)]  > 0){//如果搜索玩a的子树
		//b的祖先还在搜索里则a，b构成强联通分量 
			if(v[f[b]] > v[find(a)])	f[f[b]] = f[a];
			else						f[f[a]] = f[b];
		}
	}
	v[a] = -v[a];//结束a的搜索 
}
void spfa(int s){//详见spfa模版 
	head = tail = 1;
	q[1] = s;
	dis[s] = w[s];
	fans = max(fans,dis[s]);
	while(head <= tail){
		int x = q[head];
		for(int i=h[x];i;i=e[i].n){
			int b = e[i].b;
			if(dis[b] < dis[x]+w[b]){
				dis[b] = dis[x]+w[b];
				fans  = max(fans,dis[b]);
				if(!v[b]){
					v[b] = 1;
					q[++tail] = b;
				}
			}
		}
		head++;
		v[x] = 0;
	}
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);//n个点 m条边 
	for(int i=1;i<=n;++i){
		scanf("%d",&w[i]);//点权 
	}
	int a,b;
	for(int i=1;i<=m;++i){
		scanf("%d%d",&a,&b);
		input(i,a,b);//建图 
	}
	for(int i=1;i<=n;++i)	f[i] = i;//并查集 
	for(int i=1;i<=n;++i){ 
		if(!v[i]){//如果这个点没有搜索过 
			v[i] = 1;
			dfs(i);
		}
	}
	for(int i=1;i<=n;++i){
		find(i);
		if(i != f[i]){
			w[f[i]] += w[i];//环内加权 
		}
	}
	memset(h,0,sizeof h);
	int cnt = 0;
	for(int i=1;i<=m;++i){
		a = f[d[i].a];	b = f[d[i].b];
		if(a == b)	continue;
		else{//重新建图，一个环就成一个点 
			e[++cnt].a = a;	e[cnt].b = b;
			e[cnt].n = h[a];	h[a] = cnt;
			in[b]++;
		}
	}
	memset(v,0,sizeof v);
	for(int i=1;i<=n;++i){
		if(!in[i] && i == f[i]){//如果这个点不是环，没有入度 
			spfa(i);
		}
	}
	printf("%d",fans);
	return 0;
}
